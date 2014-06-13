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
    twuvs = new QTableWidget(150,6);
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
    pbnouveau = new QPushButton("Nouveau");
    pbsupprimer = new QPushButton("Supprimer");
    pbannuler = new QPushButton("Annuler");
    pbsauver = new QPushButton("Sauver");
    hlayout3->addWidget(pbnouveau);
    hlayout3->addWidget(pbsupprimer);
    hlayout3->addWidget(pbannuler);
    hlayout3->addWidget(pbsauver);
    mainlayout->addLayout(hlayout1);
    mainlayout->addLayout(hlayout2);
    mainlayout->addWidget(twuvs);
    mainlayout->addLayout(hlayout3);
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

}

void FormationWindow::supprimer() {
}

void FormationWindow::annuler() {
    associerFormation(formation);
}

void FormationWindow::sauver() {

}
