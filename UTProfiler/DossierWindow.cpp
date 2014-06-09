#include "UTProfiler.h"

DossierWindow::DossierWindow() {
    mainlayout = new QVBoxLayout();
    hlayout1 = new QHBoxLayout();
    llogin = new QLabel("Dossier du login : ");
    lelogin = new QLineEdit();
    pbrechercher = new QPushButton("Rechercher");
    lnom = new QLabel("Nom : ");
    lenom = new QLineEdit();
    lprenom = new QLabel("Prénom : ");
    leprenom = new QLineEdit();
    hlayout1->addWidget(llogin);
    hlayout1->addWidget(lelogin);
    hlayout1->addWidget(pbrechercher);
    hlayout1->addWidget(lnom);
    hlayout1->addWidget(lenom);
    hlayout1->addWidget(lprenom);
    hlayout1->addWidget(leprenom);
    hlayout2 = new QHBoxLayout();
    lconseiller = new QLabel("Conseiller : ");
    leconseiller = new QLineEdit();
    lactiviteEU = new QLabel ("Activité Extra-Universitaire validée : ");
    lAEUOui = new QRadioButton("oui");
    lAEUNon = new QRadioButton("non");
    hlayout2->addWidget(lconseiller);
    hlayout2->addWidget(leconseiller);
    hlayout2->addWidget(lactiviteEU);
    hlayout2->addWidget(lAEUOui);
    hlayout2->addWidget(lAEUNon);
    hlayout3 = new QHBoxLayout();
    lformationext = new QLabel("Formations extérieures : ");
    pbajouterformext = new QPushButton("Ajouter");
    hlayout3->addWidget(lformationext);
    hlayout3->addWidget(pbajouterformext);

    /* Tableau Formations Extérieures */

    hlayout10 = new QHBoxLayout();
    table = new QTableWidget(this);
    table->setColumnCount(7);
    table->setHorizontalHeaderLabels(QStringList()<<"Nom"<<"Lieu"<<"Crédits CS"<<"Crédits TM"<<"Crédits TSH"<<"Crédits SP"<<"");
    hlayout10->addWidget(table);


    hlayout4 = new QHBoxLayout();
    lmineurs = new QLabel("Mineurs :");
    hlayout4->addWidget(lmineurs);

    hlayout5 = new QHBoxLayout();
    cbCCT = new QCheckBox("CCT");
    cbFIRME = new QCheckBox("FIRME");
    cbPHITECO = new QCheckBox("PHITECO");
    cbTCN = new QCheckBox("TCN");
    cbDDRESET = new QCheckBox("DD-RESET");
    cbINTENT = new QCheckBox("INTENT");
    cbST = new QCheckBox("ST");
    hlayout5->addWidget(cbCCT);
    hlayout5->addWidget(cbFIRME);
    hlayout5->addWidget(cbPHITECO);
    hlayout5->addWidget(cbTCN);
    hlayout5->addWidget(cbDDRESET);
    hlayout5->addWidget(cbINTENT);
    hlayout5->addWidget(cbST);

    hlayout6 = new QHBoxLayout();
    lsemestres = new QLabel("Semestres :");
    pbajoutersemestres = new QPushButton("Ajouter");
    hlayout6->addWidget(lsemestres);
    hlayout6->addWidget(pbajoutersemestres);

    /* Tableau Formations Extérieures */
    // A implémenter

    hlayout8 = new QHBoxLayout();
    lbranche = new QLabel("Branche :");
    hlayout8->addWidget(lbranche);

    hlayout9 = new QHBoxLayout();
    cbGI = new QCheckBox("GI");
    cbGM = new QCheckBox("GM");
    cbGSM = new QCheckBox("GSM");
    cbGP = new QCheckBox("GP");
    cbGB = new QCheckBox("GB");
    cbGSU = new QCheckBox("GSU");
    cbTC = new QCheckBox("TC");
    cbHutech = new QCheckBox("HUTECH");
    hlayout9->addWidget(cbGI);
    hlayout9->addWidget(cbGM);
    hlayout9->addWidget(cbGSM);
    hlayout9->addWidget(cbGP);
    hlayout9->addWidget(cbGB);
    hlayout9->addWidget(cbGSU);
    hlayout9->addWidget(cbTC);
    hlayout9->addWidget(cbHutech);

    hlayout7 = new QHBoxLayout();
    pbannuler = new QPushButton("Annuler");
    pbsauver = new QPushButton("Sauver");
    hlayout7->addWidget(pbannuler);
    hlayout7->addWidget(pbsauver);

    mainlayout->addLayout(hlayout1);
    mainlayout->addLayout(hlayout2);
    mainlayout->addLayout(hlayout3);
    mainlayout->addLayout(hlayout10);
    mainlayout->addLayout(hlayout8);
    mainlayout->addLayout(hlayout9);
    mainlayout->addLayout(hlayout6);
    mainlayout->addLayout(hlayout4);
    mainlayout->addLayout(hlayout5);
    mainlayout->addLayout(hlayout7);
    this->setLayout(mainlayout);

    QString l = lelogin->text();

    QObject::connect(pbrechercher,SIGNAL(clicked()),this,SLOT(rechercher()));
    QObject::connect(pbsauver,SIGNAL(clicked()),this,SLOT(sauver()));
    QObject::connect(lenom,SIGNAL(textChanged(QString)),this,SLOT(pbsauverEnable()));
    QObject::connect(leprenom,SIGNAL(textChanged(QString)),this,SLOT(pbsauverEnable()));
    QObject::connect(lAEUOui,SIGNAL(clicked()),this,SLOT(pbsauverEnable()));
    QObject::connect(lAEUNon,SIGNAL(clicked()),this,SLOT(pbsauverEnable()));
    QObject::connect(leconseiller,SIGNAL(textChanged(QString)),this,SLOT(pbsauverEnable()));
    QObject::connect(cbGI,SIGNAL(stateChanged(int)),this,SLOT(pbsauverEnable()));
    QObject::connect(cbGM,SIGNAL(stateChanged(int)),this,SLOT(pbsauverEnable()));
    QObject::connect(cbGSM,SIGNAL(stateChanged(int)),this,SLOT(pbsauverEnable()));
    QObject::connect(cbGB,SIGNAL(stateChanged(int)),this,SLOT(pbsauverEnable()));
    QObject::connect(cbGP,SIGNAL(stateChanged(int)),this,SLOT(pbsauverEnable()));
    QObject::connect(cbGSU,SIGNAL(stateChanged(int)),this,SLOT(pbsauverEnable()));
    QObject::connect(cbTC,SIGNAL(stateChanged(int)),this,SLOT(pbsauverEnable()));
    QObject::connect(cbHutech,SIGNAL(stateChanged(int)),this,SLOT(pbsauverEnable()));
    QObject::connect(pbajouterformext, SIGNAL(clicked()), this, SLOT(ajouterFormExt()));
    QObject::connect(table,SIGNAL(cellChanged(int,int)),this,SLOT(pbsauverEnable()));
    QObject::connect(table,SIGNAL(cellClicked(int,int)),this,SLOT(supprFormExt(int, int)));


}


void DossierWindow::sauver() {
    /* Sauvegarde des modifications liées au dossier */

    QString q="UPDATE Dossier SET nom = '";
    q.append(lenom->text());
    q.append("', prenom = '");
    q.append(leprenom->text());
    q.append("', conseiller = '");
    q.append(leconseiller->text());
    q.append("', validationAEU = '");
    if (lAEUOui->isChecked()) {q.append("1");}
    else {q.append("0");}
    q.append("', branche = '");
    if (cbGI->isChecked()) {q.append("GI'");}
    else if (cbGB->isChecked()) {q.append("GB'");}
    else if (cbGM->isChecked()) {q.append("GM'");}
    else if (cbGSM->isChecked()) {q.append("GSM'");}
    else if (cbGP->isChecked()) {q.append("GP'");}
    else if (cbGSU->isChecked()) {q.append("GSU'");}
    else if (cbTC->isChecked()) {q.append("TC'");}
    else if (cbHutech->isChecked()) {q.append("HUTECH'");}
    q.append(" WHERE login = '");
    q.append(lelogin->text());
    q.append("';");
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    sql->execQuery(q);

    /* Sauvegarde des modifications liées aux formations extérieures */

    for (int i=0; i<table->rowCount(); i++){
        QString q2 = "UPDATE FormationExt SET lieu = '";
        q2.append((table->item(i,1)->data(Qt::EditRole)).toString());
        q2.append("', creditsCS = '");
        q2.append((table->item(i,2)->data(Qt::EditRole)).toString());
        q2.append("', creditsTM = '");
        q2.append((table->item(i,3)->data(Qt::EditRole)).toString());
        q2.append("', creditsTSH = '");
        q2.append((table->item(i,4)->data(Qt::EditRole)).toString());
        q2.append("', creditsSP = '");
        q2.append((table->item(i,5)->data(Qt::EditRole)).toString());
        q2.append("' WHERE login = '");
        q2.append(lelogin->text());
        q2.append("' AND nom = '");
        q2.append((table->item(i,0)->data(Qt::EditRole)).toString());
        q2.append("';");
        sql->execQuery(q2);
    }
    pbsauver->setEnabled(false);
}

void DossierWindow::pbsauverEnable() {
    pbsauver->setEnabled(true);
}


void DossierWindow::associerDossier(Dossier *d) {
    lelogin->setText(d->getLogin());
    lenom->setText(d->getNom());
    leprenom->setText(d->getPrenom());
    leconseiller->setText(d->getConseiller());
    if (d->getValidationAEU() == true)
        lAEUOui->setChecked(true);
    else lAEUNon->setChecked(true);
    cbCCT->setChecked(d->checkMineurCCT());
    cbFIRME->setChecked(d->checkMineurFIRME());
    cbPHITECO->setChecked(d->checkMineurPHITECO());
    cbTCN->setChecked(d->checkMineurTCN());
    cbDDRESET->setChecked(d->checkMineurDDRESET());
    cbINTENT->setChecked(d->checkMineurINTENT());
    cbST->setChecked(d->checkMineurST());
    cbGI->setChecked(d->checkGI());
    cbGM->setChecked(d->checkGM());
    cbGSM->setChecked(d->checkGSM());
    cbGP->setChecked(d->checkGP());
    cbGB->setChecked(d->checkGB());
    cbGSU->setChecked(d->checkGSU());
    cbTC->setChecked(d->checkTC());
    cbHutech->setChecked(d->checkHutech());

    // Afficher ici les semestres sous forme de tableau avec les UV et les notes obtenues
    QString qu="SELECT nom, lieu, creditsCS, creditsTM, creditsTSH, creditsSP FROM FormationExt WHERE login = '";
    qu.append(lelogin->text());
    qu.append("';");
    InterfaceSQL *sql2 = InterfaceSQL::getInstance();
    QSqlQuery query = sql2->execQuery(qu);

    while(query.next())
        {
            QString nom = query.value(0).toString();
            QString lieu = query.value(1).toString();
            int creditsCS = query.value(2).toInt();
            int creditsTM = query.value(3).toInt();
            int creditsTSH = query.value(4).toInt();
            int creditsSP = query.value(5).toInt();
            table->insertRow(table->currentRow() + 1);

            QTableWidgetItem *itemNom = new QTableWidgetItem(nom);
            table->setItem(table->currentRow() + 1, 0, itemNom);
            itemNom->setFlags(itemNom->flags() & ~ Qt::ItemIsEditable);
            QTableWidgetItem *itemLieu = new QTableWidgetItem(lieu);
            table->setItem(table->currentRow() + 1, 1, itemLieu);
            QTableWidgetItem *itemCS = new QTableWidgetItem();
            itemCS->setData(Qt::DisplayRole,creditsCS);
            table->setItem(table->currentRow() + 1, 2, itemCS);
            QTableWidgetItem *itemTM = new QTableWidgetItem();
            itemTM->setData(Qt::DisplayRole,creditsTM);
            table->setItem(table->currentRow() + 1, 3, itemTM);
            QTableWidgetItem *itemTSH = new QTableWidgetItem();
            itemTSH->setData(Qt::DisplayRole,creditsTSH);
            table->setItem(table->currentRow() + 1, 4, itemTSH);
            QTableWidgetItem *itemSP = new QTableWidgetItem();
            itemSP->setData(Qt::DisplayRole,creditsSP);
            table->setItem(table->currentRow() + 1, 5, itemSP);
            QTableWidgetItem *itemSuppr = new QTableWidgetItem("Supprimer");
            table->setItem(table->currentRow() + 1, 6, itemSuppr);
            itemSuppr->setFlags(itemNom->flags() & ~ Qt::ItemIsEditable);

        }
    pbsauver->setEnabled(false);
    //qDebug()<<"Nombre de lignes :"<<table->rowCount();

}

void DossierWindow::rechercher() {
    QString q = "SELECT * FROM Dossier WHERE login = '";
    q.append(lelogin->text());
    q.append("';");
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    Dossier *d = sql->selectDossier(q);
    table->clearContents();
    table->setRowCount(0);
    associerDossier(d);

}

void DossierWindow::ajouterFormExt(){
    QString l = lelogin->text();
    FormationExtWindow *fenetre = new FormationExtWindow(l);
    fenetre->show();
}

void DossierWindow::supprFormExt(int r, int c){
    if (c == 6){
        QString q = "DELETE FROM FormationExt WHERE login = '";
        q.append(lelogin->text());
        q.append("' AND nom = '");
        q.append((table->item(r,0)->data(Qt::EditRole)).toString());
        q.append("';");
        InterfaceSQL *sql = InterfaceSQL::getInstance();
        sql->execQuery(q);
        table->removeRow(r);
    }
}

FormationExtWindow::FormationExtWindow(const QString& l): login(l) {
    mainlayout = new QVBoxLayout();

    hlayout1 = new QHBoxLayout();
    lnom = new QLabel("Nom de la formation :");
    lenom = new QLineEdit;
    llieu = new QLabel("Lieu :");
    lelieu = new QLineEdit;
    hlayout1->addWidget(lnom);
    hlayout1->addWidget(lenom);
    hlayout1->addWidget(llieu);
    hlayout1->addWidget(lelieu);

    hlayout2 = new QHBoxLayout();
    lequivalences = new QLabel("Equivalences obtenues :");
    hlayout2->addWidget(lequivalences);

    hlayout3 = new QHBoxLayout();
    lcs = new QLabel("CS");
    lecs = new QLineEdit;
    ltm = new QLabel("TM");
    letm = new QLineEdit;
    ltsh = new QLabel("TSH");
    letsh = new QLineEdit;
    lsp = new QLabel("SP");
    lesp = new QLineEdit;

    hlayout3->addWidget(lcs);
    hlayout3->addWidget(lecs);
    hlayout3->addWidget(ltm);
    hlayout3->addWidget(letm);
    hlayout3->addWidget(ltsh);
    hlayout3->addWidget(letsh);
    hlayout3->addWidget(lsp);
    hlayout3->addWidget(lesp);

    hlayout4 = new QHBoxLayout();
    pbajouter = new QPushButton("Ajouter");
    hlayout4->addWidget(pbajouter);

    mainlayout->addLayout(hlayout1);
    mainlayout->addLayout(hlayout2);
    mainlayout->addLayout(hlayout3);
    mainlayout->addLayout(hlayout4);

    this->setLayout(mainlayout);

    QObject::connect(pbajouter,SIGNAL(clicked()),this,SLOT(ajouter()));

}

void FormationExtWindow::ajouter() {
    qDebug() <<"login : "<<getLogin();
    if (getLogin() == '\0'){
        QMessageBox msg;
        msg.setText("Pour ajouter une formation, il faut chercher au préalable un login.");
        msg.exec();
    }
    else {
        QString q="INSERT INTO FormationExt(login, nom, lieu, creditsCS, creditsTM, creditsTSH, creditsSP) VALUES ('";
        q.append(getLogin());
        q.append("','");
        q.append(lenom->text());
        q.append("','");
        q.append(lelieu->text());
        q.append("','");
        q.append(lecs->text());
        q.append("','");
        q.append(letm->text());
        q.append("','");
        q.append(letsh->text());
        q.append("','");
        q.append(lesp->text());
        q.append("');");
        InterfaceSQL *sql = InterfaceSQL::getInstance();
        sql->execQuery(q);
    }
    close();


}
