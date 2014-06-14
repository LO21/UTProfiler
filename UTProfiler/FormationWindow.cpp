#include "UTProfiler.h"

/*Table widgets can be constructed with the required numbers of rows and columns:

    tableWidget = new QTableWidget(12, 3, this);
Alternatively, tables can be constructed without a given size and resized later:

    tableWidget = new QTableWidget(this);
    tableWidget->setRowCount(10);
    tableWidget->setColumnCount(5);
Items are created ouside the table (with no parent widget) and inserted into the table with setItem():

    QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg(
        (row+1)*(column+1)));
    tableWidget->setItem(row, column, newItem);*/

FormationWindow::FormationWindow() {
    mainlayout = new QVBoxLayout();
    hlayout1 = new QHBoxLayout();
    pbretour = new QPushButton("Retour");
    lnom = new QLabel("Nom : ");
    lenom = new QLineEdit();
    pbrechercher = new QPushButton("Rechercher");
    lresponsable = new QLabel("Responsable : ");
    leresponsable = new QLineEdit();
    ltype = new QLabel("Type : ");
    letype= new QLineEdit();
    hlayout1->addWidget(pbretour);
    hlayout1->addWidget(lnom);
    hlayout1->addWidget(lenom);
    hlayout1->addWidget(pbrechercher);
    hlayout1->addWidget(lresponsable);
    hlayout1->addWidget(leresponsable);
    hlayout1->addWidget(ltype);
    hlayout1->addWidget(letype);
    hlayout2 = new QHBoxLayout();
    lcredits = new QLabel("Crédits à Valider   | ");
    ltot = new QLabel("Total : ");
    letot = new QLineEdit();
    lcs = new QLabel("CS : ");
    lecs = new QLineEdit();
    ltm = new QLabel("TM : ");
    letm = new QLineEdit();
    lcstm = new QLabel("CS + TM : ");
    lecstm = new QLineEdit();
    ltsh = new QLabel("TSH : ");
    letsh = new QLineEdit();
    lsp = new QLabel("SP : ");
    lesp = new QLineEdit();
    hlayout2->addWidget(lcredits);
    hlayout2->addWidget(ltot);
    hlayout2->addWidget(letot);
    hlayout2->addWidget(lcs);
    hlayout2->addWidget(lecs);
    hlayout2->addWidget(ltm);
    hlayout2->addWidget(letm);
    hlayout2->addWidget(lcstm);
    hlayout2->addWidget(lecstm);
    hlayout2->addWidget(ltsh);
    hlayout2->addWidget(letsh);
    hlayout2->addWidget(lsp);
    hlayout2->addWidget(lesp);
    hlayout3 = new QHBoxLayout();
    twuvs = new QTableWidget(150,6);
    vlayout31 = new QVBoxLayout();
    pbajouteruv = new QPushButton("Lier une UV à cette Formation");
    pbsupprimeruv = new QPushButton("Délier une UV de cette Formation");
    vlayout31->addWidget(pbajouteruv);
    vlayout31->addWidget(pbsupprimeruv);
    hlayout3->addWidget(twuvs);
    hlayout3->addLayout(vlayout31);
    hlayout4 = new QHBoxLayout();
    pbnouveau = new QPushButton("Nouveau");
    pbsupprimer = new QPushButton("Supprimer");
    pbannuler = new QPushButton("Annuler");
    pbsauver = new QPushButton("Sauver");
    hlayout4->addWidget(pbnouveau);
    hlayout4->addWidget(pbsupprimer);
    hlayout4->addWidget(pbannuler);
    hlayout4->addWidget(pbsauver);
    mainlayout->addLayout(hlayout1);
    mainlayout->addLayout(hlayout2);
    mainlayout->addLayout(hlayout3);
    mainlayout->addLayout(hlayout4);
    this->setLayout(mainlayout);
    QObject::connect(pbretour,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(leresponsable,SIGNAL(textChanged(QString)),this,SLOT(setenabled()));
    QObject::connect(letype,SIGNAL(textChanged(QString)),this,SLOT(setenabled()));
    QObject::connect(letot,SIGNAL(textChanged(QString)),this,SLOT(setenabled()));
    QObject::connect(lecs,SIGNAL(textChanged(QString)),this,SLOT(setenabled()));
    QObject::connect(letm,SIGNAL(textChanged(QString)),this,SLOT(setenabled()));
    QObject::connect(lecstm,SIGNAL(textChanged(QString)),this,SLOT(setenabled()));
    QObject::connect(letsh,SIGNAL(textChanged(QString)),this,SLOT(setenabled()));
    QObject::connect(lesp,SIGNAL(textChanged(QString)),this,SLOT(setenabled()));
    QObject::connect(pbrechercher,SIGNAL(clicked()),this,SLOT(rechercher()));
    QObject::connect(lenom,SIGNAL(returnPressed()),this,SLOT(rechercher()));
    QObject::connect(pbannuler,SIGNAL(clicked()),this,SLOT(annuler()));
    QObject::connect(pbnouveau,SIGNAL(clicked()),this,SLOT(nouveau()));
    QObject::connect(pbsupprimer,SIGNAL(clicked()),this,SLOT(supprimer()));
    QObject::connect(pbsauver,SIGNAL(clicked()),this,SLOT(sauver()));
    QObject::connect(twuvs,SIGNAL(cellChanged(int,int)),this,SLOT(setenabled()));
    QObject::connect(pbajouteruv,SIGNAL(clicked()),this,SLOT(ajouteruv()));
    QObject::connect(pbsupprimeruv,SIGNAL(clicked()),this,SLOT(supprimeruv()));
}

void FormationWindow::associerFormation(Formation *newformation) {
    formation=newformation;
    lenom->setText(formation->getNom());
    leresponsable->setText(formation->getResponsable());
    letype->setText(formation->getType());
    letot->setText(QString::number(formation->getNbCreditsTot()));
    lecs->setText(QString::number(formation->getNbCreditsCS()));
    letm->setText(QString::number(formation->getNbCreditsTM()));
    lecstm->setText(QString::number(formation->getNbCreditsCSTM()));
    letsh->setText(QString::number(formation->getNbCreditsTSH()));
    lesp->setText(QString::number(formation->getNbCreditsSP()));
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    twuvs->setRowCount(150);
    UV** uvs = sql->getAllUvs(QString::fromStdString("SELECT * FROM UV, AssociationFormationUV A WHERE UV.code = A.uv AND A.formation = '"+formation->getNom().toStdString()+"' ;"));
    unsigned int i=0;
    QTableWidgetItem *code;
    QTableWidgetItem *categorie;
    QTableWidgetItem *nbcredits;
    QTableWidgetItem *titre;
    QTableWidgetItem *responsable;
    QTableWidgetItem *saison;
    while (uvs[i]->getCode()!=QString::fromStdString("fin")) {
        code = new QTableWidgetItem(uvs[i]->getCode());
        twuvs->setItem(i,0,code);
        if (uvs[i]->getCreditsCS()>0) {categorie = new QTableWidgetItem("CS"); nbcredits = new QTableWidgetItem(QString::number(uvs[i]->getCreditsCS()));}
        else if (uvs[i]->getCreditsTM()>0) {categorie = new QTableWidgetItem("TM"); nbcredits = new QTableWidgetItem(QString::number(uvs[i]->getCreditsTM()));}
        else if (uvs[i]->getCreditsTSH()>0) {categorie = new QTableWidgetItem("TSH"); nbcredits = new QTableWidgetItem(QString::number(uvs[i]->getCreditsTSH()));}
        else if (uvs[i]->getCreditsSP()>0) {categorie = new QTableWidgetItem("SP"); nbcredits = new QTableWidgetItem(QString::number(uvs[i]->getCreditsSP()));}
        else {categorie = new QTableWidgetItem(""); nbcredits = new QTableWidgetItem("");}
        twuvs->setItem(i,1,categorie);
        twuvs->setItem(i,2,nbcredits);
        titre = new QTableWidgetItem(uvs[i]->getTitre());
        twuvs->setItem(i,3,titre);
        responsable = new QTableWidgetItem(uvs[i]->getResponsable());
        twuvs->setItem(i,4,responsable);
        if (uvs[i]->getAutomne()) {
            if(uvs[i]->getPrintemps()) {saison = new QTableWidgetItem("A/P");}
            else {saison = new QTableWidgetItem("A");} }
        else if (uvs[i]->getPrintemps()) {saison = new QTableWidgetItem("P");}
        else {saison = new QTableWidgetItem("");}
        twuvs->setItem(i,5,saison);
        ++i;
    }
    twuvs->setRowCount(i);
    pbsauver->setEnabled(false);
    pbannuler->setEnabled(false);
}

void FormationWindow::setenabled() {
    pbsauver->setEnabled(true);
    pbannuler->setEnabled(true);
}
void FormationWindow::rechercher() {
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    Formation *formation = sql->selectFormation(QString::fromStdString("SELECT * FROM Formation WHERE nom = '"+lenom->text().toStdString()+"';"));
    associerFormation(formation);
}

void FormationWindow::nouveau() {
    newformationwindow = new NewFormationWindow(this);
}

void FormationWindow::supprimer() {
    QString q = QString::fromStdString("DELETE FROM Formation WHERE nom = '"+formation->getNom().toStdString()+"';");
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    sql->execQuery(q);
}

void FormationWindow::annuler() {
    associerFormation(formation);
}

void FormationWindow::sauver() {
    QString q="UPDATE Formation SET responsable = '";
    q.append(leresponsable->text());
    q.append("', type = '");
    q.append(letype->text());
    q.append("', creditsTot = '");
    q.append(letot->text());
    q.append("', creditsCS = '");
    q.append(lecs->text());
    q.append("', creditsTM = '");
    q.append(letm->text());
    q.append("', creditsCSTM = '");
    q.append(lecstm->text());
    q.append("', creditsTSH = '");
    q.append(letsh->text());
    q.append("', creditsSP = '");
    q.append(lesp->text());
    q.append("' WHERE nom = '");
    q.append(lenom->text());
    q.append("';");
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    sql->execQuery(q);
    UV** uvs = sql->getAllUvs(QString::fromStdString("SELECT * FROM UV, AssociationFormationUV A WHERE UV.code = A.uv AND A.formation = '"+formation->getNom().toStdString()+"' ;"));
    UV checkChanges;
    QString *code = new QString;
    QString *description = new QString;
    QString *responsable = new QString;
    unsigned int i=0;
    int boolean;
    while (uvs[i]->getCode()!=QString::fromStdString("fin")) {
        code->clear();
        code->append(twuvs->item(i,0)->text());
        checkChanges.setCode(code);
        if (twuvs->item(i,1)->text()==QString::fromStdString("CS")) {checkChanges.setCreditsCS(twuvs->item(i,2)->text().toUInt());}
        if (twuvs->item(i,1)->text()==QString::fromStdString("TM")) {checkChanges.setCreditsTM(twuvs->item(i,2)->text().toUInt());}
        if (twuvs->item(i,1)->text()==QString::fromStdString("TSH")) {checkChanges.setCreditsTSH(twuvs->item(i,2)->text().toUInt());}
        if (twuvs->item(i,1)->text()==QString::fromStdString("SP")) {checkChanges.setCreditsSP(twuvs->item(i,2)->text().toUInt());}
        description->clear();
        description->append(twuvs->item(i,3)->text());
        checkChanges.setTitre(description);
        responsable->clear();
        responsable->append(twuvs->item(i,4)->text());
        checkChanges.setResponsable(responsable);
        if (twuvs->item(i,5)->text()==QString::fromStdString("A/P")) {checkChanges.setAutomne(true); checkChanges.setPrintemps(true);}
        if (twuvs->item(i,5)->text()==QString::fromStdString("A")) {checkChanges.setAutomne(true);}
        if (twuvs->item(i,5)->text()==QString::fromStdString("P")) {checkChanges.setPrintemps(true);}
        //if (checkChanges!=*uvs[i]) {
            if (checkChanges.getCode()==uvs[i]->getCode()) {
                q.clear();
                q.append(QString::fromStdString("UPDATE UV SET titre='"));
                q.append(checkSyntax(checkChanges.getTitre()));
                q.append(QString::fromStdString("', responsable='"));
                q.append(checkChanges.getResponsable());
                q.append(QString::fromStdString("', creditsCS='"));
                q.append(QString::number(checkChanges.getCreditsCS()));
                q.append(QString::fromStdString("', creditsTM='"));
                q.append(QString::number(checkChanges.getCreditsTM()));
                q.append(QString::fromStdString("', creditsTSH='"));
                q.append(QString::number(checkChanges.getCreditsTSH()));
                q.append(QString::fromStdString("', creditsSP='"));
                q.append(QString::number(checkChanges.getCreditsSP()));
                q.append(QString::fromStdString("', printemps='"));
                checkChanges.getPrintemps()?boolean=1:boolean=0;
                q.append(QString::number(boolean));
                q.append(QString::fromStdString("', automne='"));
                checkChanges.getAutomne()?boolean=1:boolean=0;
                q.append(QString::number(boolean));
                q.append(QString::fromStdString("' WHERE code='"));
                q.append(checkChanges.getCode());
                q.append(QString::fromStdString("';"));
                sql->execQuery(q);
            //}
        }
        i++;
    }
    pbsauver->setEnabled(false);
    pbannuler->setEnabled(false);
}


void FormationWindow::ajouteruv() {
    binduvwindow = new BindUVWindow(this);
}

void FormationWindow::supprimeruv() {
    unbinduvwindow = new UnbindUVWindow(this);
}

NewFormationWindow::NewFormationWindow(FormationWindow *fw) : master(fw) {
    mainlayout = new QVBoxLayout();
    hlayout1 = new QHBoxLayout();
    lnom = new QLabel("Nom : ");
    lenom = new QLineEdit();
    hlayout1->addWidget(lnom);
    hlayout1->addWidget(lenom);
    hlayout2 = new QHBoxLayout();
    pbannuler = new QPushButton("Annuler");
    pbajouter = new QPushButton("Ajouter");
    pbajouter->setEnabled(false);
    hlayout2->addWidget(pbannuler);
    hlayout2->addWidget(pbajouter);
    mainlayout->addLayout(hlayout1);
    mainlayout->addLayout(hlayout2);
    setLayout(mainlayout);
    QObject::connect(lenom,SIGNAL(textChanged(QString)),this,SLOT(setenabled()));
    QObject::connect(lenom,SIGNAL(returnPressed()),this,SLOT(ajouter()));
    QObject::connect(pbajouter,SIGNAL(clicked()),this,SLOT(ajouter()));
    QObject::connect(pbannuler,SIGNAL(clicked()),this,SLOT(annuler()));
    show();
}

void NewFormationWindow::setenabled() {
    pbajouter->setEnabled(true);
}

void NewFormationWindow::annuler() {
    close();
}

void NewFormationWindow::ajouter() {
    QString q = "INSERT INTO Formation(nom) VALUES ('";
    QString nom = lenom->text();
    q.append(nom);
    q.append("');");
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    sql->execQuery(q);
    q.clear();
    q.append("SELECT * FROM Formation WHERE nom = '");
    q.append(nom);
    q.append("';");
    Formation *formation = sql->selectFormation(q);
    master->associerFormation(formation);
    close();

}

BindUVWindow::BindUVWindow(FormationWindow *fw) : master(fw) {
    mainlayout = new QVBoxLayout();
    hlayout1 = new QHBoxLayout();
    lnom = new QLabel("Code : ");
    lenom = new QLineEdit();
    hlayout1->addWidget(lnom);
    hlayout1->addWidget(lenom);
    hlayout2 = new QHBoxLayout();
    pbannuler = new QPushButton("Annuler");
    pbajouter = new QPushButton("Ajouter");
    pbajouter->setEnabled(false);
    hlayout2->addWidget(pbannuler);
    hlayout2->addWidget(pbajouter);
    mainlayout->addLayout(hlayout1);
    mainlayout->addLayout(hlayout2);
    setLayout(mainlayout);
    QObject::connect(lenom,SIGNAL(textChanged(QString)),this,SLOT(setenabled()));
    QObject::connect(lenom,SIGNAL(returnPressed()),this,SLOT(ajouter()));
    QObject::connect(pbajouter,SIGNAL(clicked()),this,SLOT(ajouter()));
    QObject::connect(pbannuler,SIGNAL(clicked()),this,SLOT(annuler()));
    show();
}

void BindUVWindow::setenabled() {
    pbajouter->setEnabled(true);
}

void BindUVWindow::annuler() {
    close();
}

void BindUVWindow::ajouter() {
    QString q = "INSERT INTO AssociationFormationUV VALUES ('";
    QString nom = lenom->text();
    q.append(nom);
    q.append(QString::fromStdString("','"));
    nom = master->lenom->text();
    q.append(nom);
    q.append(QString::fromStdString("');"));
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    sql->execQuery(q);
    q.clear();
    q.append("SELECT * FROM Formation WHERE nom = '");
    q.append(nom);
    q.append("';");
    Formation *formation = sql->selectFormation(q);
    master->associerFormation(formation);
    close();

}

UnbindUVWindow::UnbindUVWindow(FormationWindow *fw) : master(fw) {
    mainlayout = new QVBoxLayout();
    hlayout1 = new QHBoxLayout();
    lnom = new QLabel("Code : ");
    lenom = new QLineEdit();
    hlayout1->addWidget(lnom);
    hlayout1->addWidget(lenom);
    hlayout2 = new QHBoxLayout();
    pbannuler = new QPushButton("Annuler");
    pbdelier = new QPushButton("Délier");
    pbdelier->setEnabled(false);
    hlayout2->addWidget(pbannuler);
    hlayout2->addWidget(pbdelier);
    mainlayout->addLayout(hlayout1);
    mainlayout->addLayout(hlayout2);
    setLayout(mainlayout);
    QObject::connect(lenom,SIGNAL(textChanged(QString)),this,SLOT(setenabled()));
    QObject::connect(lenom,SIGNAL(returnPressed()),this,SLOT(supprimer()));
    QObject::connect(pbdelier,SIGNAL(clicked()),this,SLOT(supprimer()));
    QObject::connect(pbannuler,SIGNAL(clicked()),this,SLOT(annuler()));
    show();
}

void UnbindUVWindow::setenabled() {
    pbdelier->setEnabled(true);
}

void UnbindUVWindow::annuler() {
    close();
}

void UnbindUVWindow::supprimer() {
    QString q = "DELETE FROM AssociationFormationUV WHERE uv='";
    QString nom = lenom->text();
    q.append(nom);
    q.append(QString::fromStdString("' AND formation='"));
    nom = master->lenom->text();
    q.append(nom);
    q.append(QString::fromStdString("';"));
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    sql->execQuery(q);
    q.clear();
    q.append("SELECT * FROM Formation WHERE nom = '");
    q.append(nom);
    q.append("';");
    Formation *formation = sql->selectFormation(q);
    master->associerFormation(formation);
    close();
}

