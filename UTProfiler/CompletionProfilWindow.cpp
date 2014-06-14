#include "UTProfiler.h"

CompletionProfilWindow::CompletionProfilWindow() {
    searchdossierwindow = new SearchDossierWindow(this);
    mainlayout = new QVBoxLayout();
    lresultat = new QLabel("Voici les UVs que nous vous proposons : ");
    hlayout1 = new QHBoxLayout();
    luv1 = new QLabel("UV n°1 (CS) : ");
    leuv1 = new QLineEdit();
    hlayout2 = new QHBoxLayout();
    luv2 = new QLabel("UV n°2 (CS) : ");
    leuv2 = new QLineEdit();
    hlayout3 = new QHBoxLayout();
    luv3 = new QLabel("UV n°3 (TM) : ");
    leuv3 = new QLineEdit();
    hlayout4 = new QHBoxLayout();
    luv4 = new QLabel("UV n°4 (TM): ");
    leuv4 = new QLineEdit();
    hlayout5 = new QHBoxLayout();
    luv5 = new QLabel("UV n°5 (TSH) : ");
    leuv5 = new QLineEdit();
    hlayout6 = new QHBoxLayout();
    luv6 = new QLabel("UV n°6 (TSH): ");
    leuv6 = new QLineEdit();
    pbok = new QPushButton("OK");
    hlayout1->addWidget(luv1);
    hlayout1->addWidget(leuv1);
    hlayout2->addWidget(luv2);
    hlayout2->addWidget(leuv2);
    hlayout3->addWidget(luv3);
    hlayout3->addWidget(leuv3);
    hlayout4->addWidget(luv4);
    hlayout4->addWidget(leuv4);
    hlayout5->addWidget(luv5);
    hlayout5->addWidget(leuv5);
    hlayout6->addWidget(luv6);
    hlayout6->addWidget(leuv6);
    mainlayout->addWidget(lresultat);
    mainlayout->addLayout(hlayout1);
    mainlayout->addLayout(hlayout2);
    mainlayout->addLayout(hlayout3);
    mainlayout->addLayout(hlayout4);
    mainlayout->addLayout(hlayout5);
    mainlayout->addLayout(hlayout6);
    mainlayout->addWidget(pbok);
    setLayout(mainlayout);
    QObject::connect(pbok,SIGNAL(clicked()),this,SLOT(close()));
}

void CompletionProfilWindow::CompletionProfil(Dossier *dossier, QString **souhaits, QString **rejets) {
    UV** res = new UV*[6];
    UV *test;
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    UV** uvsNonValidees = sql->getAllUvs(QString::fromStdString("SELECT * FROM UV,AssociationFormationUV A WHERE A.formation = '"+dossier->getBranche().toStdString()+"' AND A.uv=UV.code AND UV.code NOT IN (SELECT code FROM UV,Inscription WHERE Inscription.login = '"+dossier->getLogin().toStdString()+"' AND Inscription.uv=UV.code);"));
    Semestre *semestre = sql->selectSemestre(QString::fromStdString("SELECT * FROM Semestre WHERE dossier='"+dossier->getLogin().toStdString()+"' ORDER BY annee DESC, saison DESC;"));
    Saison saison;
    semestre->getSaison()==Saison(Printemps)?saison=Saison(Automne):saison=Saison(Printemps);
    unsigned int i=0,compteurCS=0,compteurTM=0,compteurTSH=0,compteurSouhaits=0,compteurRejet=0;
    bool rejet;
    while ((compteurCS<2 || compteurTM<2 || compteurTSH<2) && souhaits[compteurSouhaits]->toStdString()!="fin") {
        test=sql->selectUV(QString::fromStdString("SELECT * FROM UV WHERE code = '"+souhaits[compteurSouhaits++]->toStdString()+"';"));
        if (test->getCreditsCS()>0 && compteurCS<2) {res[compteurCS++] = test;}
        else if (test->getCreditsTM()>0 && compteurTM<2) {res[2+compteurTM++] = test;}
        else if (test->getCreditsTSH()>0 && compteurTSH<2) {res[4+compteurTSH++] = test;}
    }
    while ((compteurCS<2 || compteurTM<2) && uvsNonValidees[i]->getCode().toStdString()!="fin") {
        rejet=false;
        compteurRejet=0;
        while (rejet==false && rejets[compteurRejet]->toStdString()!="fin") {if (uvsNonValidees[i]->getCode().toStdString()==rejets[compteurRejet++]->toStdString()) {rejet=true;} }
        if (!rejet) {
            if (saison==Saison(Printemps)) {
                if (uvsNonValidees[i]->getPrintemps()) {
                    if (uvsNonValidees[i]->getCreditsCS()>0 && compteurCS<2) {res[compteurCS++] = uvsNonValidees[i];}
                    else if (uvsNonValidees[i]->getCreditsTM()>0 && compteurTM<2) {res[2+compteurTM++] = uvsNonValidees[i];}
                }
            }
            else {
                if (uvsNonValidees[i]->getAutomne()) {
                    if (uvsNonValidees[i]->getCreditsCS()>0 && compteurCS<2) {res[compteurCS++] = uvsNonValidees[i];}
                    else if (uvsNonValidees[i]->getCreditsTM()>0 && compteurTM<2) {res[2+compteurTM++] = uvsNonValidees[i];}
                }
            }
        }
        i++;
    }
    uvsNonValidees = sql->getAllUvs(QString::fromStdString("SELECT * FROM UV WHERE creditsTSH>0 AND code NOT IN (SELECT code FROM UV,Inscription WHERE Inscription.login = '"+dossier->getLogin().toStdString()+"' AND Inscription.uv=UV.code);"));
    i=0;
    while (compteurTSH<2) {
        if (saison==Saison(Printemps)) {
            if (uvsNonValidees[i]->getPrintemps()) {res[4+compteurTSH++] = uvsNonValidees[i];}
            }
        else {
            if (uvsNonValidees[i]->getAutomne()) {res[4+compteurTSH++] = uvsNonValidees[i];}
        }
        i++;
    }
    compteurCS>0?leuv1->setText(res[0]->getCode()):leuv1->setText("Aucune CS disponible");
    compteurCS>1?leuv2->setText(res[1]->getCode()):leuv2->setText("Aucune CS disponible");
    compteurTM>0?leuv3->setText(res[2]->getCode()):leuv3->setText("Aucune TM disponible");
    compteurTM>1?leuv4->setText(res[3]->getCode()):leuv4->setText("Aucune TM disponible");
    compteurTSH>0?leuv5->setText(res[4]->getCode()):leuv5->setText("Aucune TSH disponible");
    compteurTSH>1?leuv6->setText(res[5]->getCode()):leuv6->setText("Aucune TSH disponible");
}

void CompletionProfilWindow::rechercher() {
    searchdossierwindow->show();
    hide();
}

SearchDossierWindow::SearchDossierWindow(CompletionProfilWindow *fw) : master(fw) {
    mainlayout = new QVBoxLayout();
    hlayout1 = new QHBoxLayout();
    lnom = new QLabel("Login : ");
    lenom = new QComboBox();
    QString qu="SELECT * FROM Dossier;";
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    QSqlQuery query = sql->execQuery(qu);
    QStringList res;
    while(query.next()){res<<query.value(0).toString();}
    lenom->addItems(res);
    hlayout1->addWidget(lnom);
    hlayout1->addWidget(lenom);
    hlayout2 = new QHBoxLayout();
    lsouhaits = new QLabel("Souhaitées (espace entre les UVs) : ");
    lesouhaits = new QLineEdit();
    hlayout2->addWidget(lsouhaits);
    hlayout2->addWidget(lesouhaits);
    hlayout3 = new QHBoxLayout();
    lrejets = new QLabel("Non Souhaitées (espace entre les UVs) : ");
    lerejets = new QLineEdit();
    hlayout3->addWidget(lrejets);
    hlayout3->addWidget(lerejets);
    hlayout4 = new QHBoxLayout();
    pbannuler = new QPushButton("Annuler");
    pbrechercher = new QPushButton("Rechercher");
    hlayout4->addWidget(pbannuler);
    hlayout4->addWidget(pbrechercher);
    mainlayout->addLayout(hlayout1);
    mainlayout->addLayout(hlayout2);
    mainlayout->addLayout(hlayout3);
    mainlayout->addLayout(hlayout4);
    setLayout(mainlayout);
    QObject::connect(pbannuler,SIGNAL(clicked()),this,SLOT(annuler()));
    QObject::connect(pbrechercher,SIGNAL(clicked()),this,SLOT(rechercher()));
}

void SearchDossierWindow::annuler() {
    master->close();
    close();
}
void SearchDossierWindow::rechercher() {
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    Dossier *dossier = sql->selectDossier(QString::fromStdString("SELECT * FROM Dossier WHERE login = '"+lenom->currentText().toStdString()+"';"));
    unsigned int i=0,j=0;
    QString **souhaits = new QString*[20];
    souhaits[0] = new QString;
    QString sparse = lesouhaits->text();
    while (sparse[i]!='\0') {
        if (sparse[i]==' ') {souhaits[++j] = new QString;}
        else {souhaits[j]->append(sparse[i]);}
        ++i;
    }
    if (i==0) {souhaits[0]->append(QString::fromStdString("fin"));}
    else {souhaits[++j] = new QString("fin");}
    i=0;
    j=0;
    QString **rejets = new QString*[20];
    rejets[0] = new QString;
    QString rparse = lerejets->text();
    while (rparse[i]!='\0') {
        if (rparse[i]==' ') {rejets[++j] = new QString;}
        else {rejets[j]->append(rparse[i]);}
        ++i;
    }

    if (i==0) {rejets[0]->append(QString::fromStdString("fin"));}
    else {rejets[++j] = new QString("fin");}
    master->CompletionProfil(dossier,souhaits,rejets);
    master->show();
    close();
}

