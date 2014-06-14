#include "UTProfiler.h"

CompletionProfilWindow::CompletionProfilWindow() {
    searchdossierwindow = new SearchDossierWindow(this);
    mainlayout = new QVBoxLayout();
    lresultat = new QLabel("Voici les UVs que nous vous proposons : ");
    hlayout1 = new QHBoxLayout();
    luv1 = new QLabel("UV n°1 (CS) : ");
    leuv1 = new QLineEdit();
    pbconfirmer1 = new QPushButton("Confirmer");
    pbrefuser1 = new QPushButton("Refuser");
    hlayout2 = new QHBoxLayout();
    luv2 = new QLabel("UV n°2 (CS) : ");
    leuv2 = new QLineEdit();
    pbconfirmer2 = new QPushButton("Confirmer");
    pbrefuser2 = new QPushButton("Refuser");
    hlayout3 = new QHBoxLayout();
    luv3 = new QLabel("UV n°3 (TM) : ");
    leuv3 = new QLineEdit();
    pbconfirmer3 = new QPushButton("Confirmer");
    pbrefuser3 = new QPushButton("Refuser");
    hlayout4 = new QHBoxLayout();
    luv4 = new QLabel("UV n°4 (TM): ");
    leuv4 = new QLineEdit();
    pbconfirmer4 = new QPushButton("Confirmer");
    pbrefuser4 = new QPushButton("Refuser");
    hlayout5 = new QHBoxLayout();
    luv5 = new QLabel("UV n°5 (TSH) : ");
    leuv5 = new QLineEdit();
    pbconfirmer5 = new QPushButton("Confirmer");
    pbrefuser5 = new QPushButton("Refuser");
    hlayout6 = new QHBoxLayout();
    luv6 = new QLabel("UV n°6 (TSH): ");
    leuv6 = new QLineEdit();
    pbconfirmer6 = new QPushButton("Confirmer");
    pbrefuser6 = new QPushButton("Refuser");
    pbok = new QPushButton("OK");
    hlayout1->addWidget(luv1);
    hlayout1->addWidget(leuv1);
    hlayout1->addWidget(pbconfirmer1);
    hlayout1->addWidget(pbrefuser1);
    hlayout2->addWidget(luv2);
    hlayout2->addWidget(leuv2);
    hlayout2->addWidget(pbconfirmer2);
    hlayout2->addWidget(pbrefuser2);
    hlayout3->addWidget(luv3);
    hlayout3->addWidget(leuv3);
    hlayout3->addWidget(pbconfirmer3);
    hlayout3->addWidget(pbrefuser3);
    hlayout4->addWidget(luv4);
    hlayout4->addWidget(leuv4);
    hlayout4->addWidget(pbconfirmer4);
    hlayout4->addWidget(pbrefuser4);
    hlayout5->addWidget(luv5);
    hlayout5->addWidget(leuv5);
    hlayout5->addWidget(pbconfirmer5);
    hlayout5->addWidget(pbrefuser5);
    hlayout6->addWidget(luv6);
    hlayout6->addWidget(leuv6);
    hlayout6->addWidget(pbconfirmer6);
    hlayout6->addWidget(pbrefuser6);
    mainlayout->addWidget(lresultat);
    mainlayout->addLayout(hlayout1);
    mainlayout->addLayout(hlayout2);
    mainlayout->addLayout(hlayout3);
    mainlayout->addLayout(hlayout4);
    mainlayout->addLayout(hlayout5);
    mainlayout->addLayout(hlayout6);
    mainlayout->addWidget(pbok);
    setLayout(mainlayout);
    QObject::connect(pbrefuser1,SIGNAL(clicked()),this,SLOT(refuser1()));
    QObject::connect(pbrefuser2,SIGNAL(clicked()),this,SLOT(refuser2()));
    QObject::connect(pbrefuser3,SIGNAL(clicked()),this,SLOT(refuser3()));
    QObject::connect(pbrefuser4,SIGNAL(clicked()),this,SLOT(refuser4()));
    QObject::connect(pbrefuser5,SIGNAL(clicked()),this,SLOT(refuser5()));
    QObject::connect(pbrefuser6,SIGNAL(clicked()),this,SLOT(refuser6()));
    QObject::connect(pbconfirmer1,SIGNAL(clicked()),this,SLOT(confirmer1()));
    QObject::connect(pbconfirmer2,SIGNAL(clicked()),this,SLOT(confirmer2()));
    QObject::connect(pbconfirmer3,SIGNAL(clicked()),this,SLOT(confirmer3()));
    QObject::connect(pbconfirmer4,SIGNAL(clicked()),this,SLOT(confirmer4()));
    QObject::connect(pbconfirmer5,SIGNAL(clicked()),this,SLOT(confirmer5()));
    QObject::connect(pbconfirmer6,SIGNAL(clicked()),this,SLOT(confirmer6()));
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
        if (test->getCreditsCS()>0 && compteurCS<2) {res[compteurCS++] = test; compteurCS==1?pbrefuser1->setEnabled(false):pbrefuser2->setEnabled(false);}
        else if (test->getCreditsTM()>0 && compteurTM<2) {res[2+compteurTM++] = test; compteurTM==1?pbrefuser3->setEnabled(false):pbrefuser4->setEnabled(false);}
        else if (test->getCreditsTSH()>0 && compteurTSH<2) {res[4+compteurTSH++] = test; compteurTSH==1?pbrefuser5->setEnabled(false):pbrefuser6->setEnabled(false);}
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
    while (compteurTSH<2 && uvsNonValidees[i]->getCode().toStdString()!="fin") {
        rejet=false;
        compteurRejet=0;
        while (rejet==false && rejets[compteurRejet]->toStdString()!="fin") {if (uvsNonValidees[i]->getCode().toStdString()==rejets[compteurRejet++]->toStdString()) {rejet=true;} }
        if (!rejet) {
            if (saison==Saison(Printemps)) {
                if (uvsNonValidees[i]->getPrintemps()) {res[4+compteurTSH++] = uvsNonValidees[i];}
                }
            else {
                if (uvsNonValidees[i]->getAutomne()) {res[4+compteurTSH++] = uvsNonValidees[i];}
            }
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
    dossier = sql->selectDossier(QString::fromStdString("SELECT * FROM Dossier WHERE login = '"+lenom->currentText().toStdString()+"';"));
    unsigned int i=0,j=0;
    souhaits = new QString*[20];
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
    rejets = new QString*[20];
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


void CompletionProfilWindow::confirmer1() {
    pbconfirmer1->setEnabled(false);
    pbrefuser1->setEnabled(false);
}

void CompletionProfilWindow::confirmer2() {
    pbconfirmer2->setEnabled(false);
    pbrefuser2->setEnabled(false);
}

void CompletionProfilWindow::confirmer3() {
    pbconfirmer3->setEnabled(false);
    pbrefuser3->setEnabled(false);
}

void CompletionProfilWindow::confirmer4() {
    pbconfirmer4->setEnabled(false);
    pbrefuser4->setEnabled(false);
}

void CompletionProfilWindow::confirmer5() {
    pbconfirmer5->setEnabled(false);
    pbrefuser5->setEnabled(false);
}

void CompletionProfilWindow::confirmer6() {
    pbconfirmer6->setEnabled(false);
    pbrefuser6->setEnabled(false);
}

void CompletionProfilWindow::refuser1() {
    unsigned int i=0;
    while (searchdossierwindow->rejets[i]->toStdString()!="fin") {++i;}
    *searchdossierwindow->rejets[i]=leuv1->text();
    searchdossierwindow->rejets[++i] = new QString("fin");
    CompletionProfil(searchdossierwindow->dossier,searchdossierwindow->souhaits,searchdossierwindow->rejets);
}

void CompletionProfilWindow::refuser2() {
    unsigned int i=0;
    while (searchdossierwindow->rejets[i]->toStdString()!="fin") {++i;}
    *searchdossierwindow->rejets[i]=leuv2->text();
    searchdossierwindow->rejets[++i] = new QString("fin");
    CompletionProfil(searchdossierwindow->dossier,searchdossierwindow->souhaits,searchdossierwindow->rejets);
}

void CompletionProfilWindow::refuser3() {
    unsigned int i=0;
    while (searchdossierwindow->rejets[i]->toStdString()!="fin") {++i;}
    *searchdossierwindow->rejets[i]=leuv3->text();
    searchdossierwindow->rejets[++i] = new QString("fin");
    CompletionProfil(searchdossierwindow->dossier,searchdossierwindow->souhaits,searchdossierwindow->rejets);
}

void CompletionProfilWindow::refuser4() {
    unsigned int i=0;
    while (searchdossierwindow->rejets[i]->toStdString()!="fin") {++i;}
    *searchdossierwindow->rejets[i]=leuv4->text();
    searchdossierwindow->rejets[++i] = new QString("fin");
    CompletionProfil(searchdossierwindow->dossier,searchdossierwindow->souhaits,searchdossierwindow->rejets);
}

void CompletionProfilWindow::refuser5() {
    unsigned int i=0;
    while (searchdossierwindow->rejets[i]->toStdString()!="fin") {++i;}
    *searchdossierwindow->rejets[i]=leuv5->text();
    searchdossierwindow->rejets[++i] = new QString("fin");
    CompletionProfil(searchdossierwindow->dossier,searchdossierwindow->souhaits,searchdossierwindow->rejets);
}

void CompletionProfilWindow::refuser6() {
    unsigned int i=0;
    while (searchdossierwindow->rejets[i]->toStdString()!="fin") {++i;}
    *searchdossierwindow->rejets[i]=leuv6->text();
    searchdossierwindow->rejets[++i] = new QString("fin");
    CompletionProfil(searchdossierwindow->dossier,searchdossierwindow->souhaits,searchdossierwindow->rejets);
}
