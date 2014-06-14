#include "UTProfiler.h"

DossierWindow::DossierWindow() {
    mainlayout = new QVBoxLayout();
    hlayout1 = new QHBoxLayout();
    pbretour = new QPushButton("Retour");
    llogin = new QLabel("Dossier du login : ");
    lelogin = new QLineEdit();
    pbrechercher = new QPushButton("Rechercher");
    lnom = new QLabel("Nom : ");
    lenom = new QLineEdit();
    lprenom = new QLabel("Prénom : ");
    leprenom = new QLineEdit();
    hlayout1->addWidget(pbretour);
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

    /* Mineurs */

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

    /* Tableau Semestres */

    hlayout6 = new QHBoxLayout();
    lsemestres = new QLabel("Semestres :");
    pbajoutersemestres = new QPushButton("Ajouter");
    hlayout6->addWidget(lsemestres);
    hlayout6->addWidget(pbajoutersemestres);

    hlayout11 = new QHBoxLayout();
    table2 = new QTableWidget(this);
    table2->setColumnCount(8);
    table2->setHorizontalHeaderLabels(QStringList()<<"Semestre"<<"UV"<<"Note"<<"Crédits CS"<<"Crédits TM"<<"Crédits TSH"<<"Crédits SP"<<"");
    hlayout11->addWidget(table2);

    /* Appréciations semestrielles */

    hlayout12 = new QHBoxLayout();
    lcommentaire = new QLabel("Appréciations semestrielles :");
    hlayout12->addWidget(lcommentaire);

    hlayout13 = new QHBoxLayout();
    table3 = new QTableWidget(this);
    table3->setColumnCount(2);
    table3->setHorizontalHeaderLabels(QStringList()<<"Semestre"<<"Commentaire");
    hlayout13->addWidget(table3);


    /* Branche */

    hlayout8 = new QHBoxLayout();
    lbranche = new QLabel("Branche :");
    cbbranche = new QComboBox;

    QString qu="SELECT * FROM Formation WHERE type ='Branche';";
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    QSqlQuery query = sql->execQuery(qu);

    QStringList res;

    while(query.next())
    {
        res<<query.value(0).toString();
    }
    cbbranche->addItems(res);

    hlayout8->addWidget(lbranche);
    hlayout8->addWidget(cbbranche);

    hlayout7 = new QHBoxLayout();
    pbannuler = new QPushButton("Annuler");
    pbsauver = new QPushButton("Sauver");
    pbsuppr = new QPushButton("Supprimer");
    hlayout7->addWidget(pbannuler);
    hlayout7->addWidget(pbsauver);
    hlayout7->addWidget(pbsuppr);

    mainlayout->addLayout(hlayout1);
    mainlayout->addLayout(hlayout2);
    mainlayout->addLayout(hlayout3);
    mainlayout->addLayout(hlayout10);
    mainlayout->addLayout(hlayout8);
    mainlayout->addLayout(hlayout6);
    mainlayout->addLayout(hlayout11);
    mainlayout->addLayout(hlayout12);
    mainlayout->addLayout(hlayout13);
    mainlayout->addLayout(hlayout4);
    mainlayout->addLayout(hlayout5);
    mainlayout->addLayout(hlayout7);
    this->setLayout(mainlayout);

    QString l = lelogin->text();

    QObject::connect(pbretour,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(pbrechercher,SIGNAL(clicked()),this,SLOT(rechercher()));
    QObject::connect(pbsauver,SIGNAL(clicked()),this,SLOT(sauver()));
    QObject::connect(lenom,SIGNAL(textChanged(QString)),this,SLOT(pbsauverEnable()));
    QObject::connect(leprenom,SIGNAL(textChanged(QString)),this,SLOT(pbsauverEnable()));
    QObject::connect(lAEUOui,SIGNAL(clicked()),this,SLOT(pbsauverEnable()));
    QObject::connect(lAEUNon,SIGNAL(clicked()),this,SLOT(pbsauverEnable()));
    QObject::connect(leconseiller,SIGNAL(textChanged(QString)),this,SLOT(pbsauverEnable()));
    QObject::connect(pbajouterformext, SIGNAL(clicked()), this, SLOT(ajouterFormExt()));
    QObject::connect(table,SIGNAL(cellChanged(int,int)),this,SLOT(pbsauverEnable()));
    QObject::connect(table3,SIGNAL(cellChanged(int,int)),this,SLOT(pbsauverEnable()));
    QObject::connect(table,SIGNAL(cellClicked(int,int)),this,SLOT(supprFormExt(int, int)));
    QObject::connect(pbajoutersemestres, SIGNAL(clicked()), this, SLOT(ajouterSemestre()));
    QObject::connect(table2,SIGNAL(cellClicked(int,int)),this,SLOT(supprSemestre(int, int)));
    QObject::connect(cbbranche,SIGNAL(currentTextChanged(QString)),this,SLOT(pbsauverEnable()));
    QObject::connect(pbsuppr,SIGNAL(clicked()),this,SLOT(supprimer()));


}


void DossierWindow::sauver() {
    if (lelogin->text() == ""){ // Vérification qu'il y ait bien un dossier à sauvegarder
        QMessageBox msg;
        msg.setText("Veuillez rentrer un login.");
        msg.exec();
    } else {

        QString q3="SELECT login FROM Dossier WHERE login = '";
        q3.append(lelogin->text());
        q3.append("';");
        InterfaceSQL *sql = InterfaceSQL::getInstance();
        QSqlQuery query3 = sql->execQuery(q3);
        query3.next();

        if (query3.value(0).toString() == ""){ // Le dossier n'existe pas, il faut le créer
            QString q4="INSERT INTO Dossier(login, nom, prenom, conseiller, validationAEU, branche) VALUES ('";
            q4.append(lelogin->text());
            q4.append("', '");
            q4.append(lenom->text());
            q4.append("','");
            q4.append(leprenom->text());
            q4.append("','");
            q4.append(leconseiller->text());
            q4.append("','");
            if (lAEUOui->isChecked()) {q4.append("1");}
            else {q4.append("0");}
            q4.append("','");
            q4.append(cbbranche->currentText());
            q4.append("');");

            QSqlQuery query4 = sql->execQuery(q4);
        } else { // Le dossier existe déjà, il faut le mettre à jour


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
            q.append(cbbranche->currentText());
            q.append("' WHERE login = '");
            q.append(lelogin->text());
            q.append("';");
            sql->execQuery(q);

        }

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

         /* Sauvegarde des modifications liées aux appréciations semestrielles */

            for (int i=0; i<table3->rowCount(); i++){

                QString sem = (table3->item(i,0)->data(Qt::EditRole)).toString(); // Récupération du semestre
                QString annee = "";
                annee.append(sem[1]);
                annee.append(sem[2]);
                annee.append(sem[3]);
                annee.append(sem[4]);

                QString q5 = "UPDATE Semestre SET commentaire = '";
                q5.append((table3->item(i,1)->data(Qt::EditRole)).toString());
                q5.append("' WHERE dossier = '");
                q5.append(lelogin->text());
                q5.append("' AND saison = '");
                q5.append(sem[0]);
                q5.append("' AND annee = '");
                q5.append(annee);
                q5.append("';");
                sql->execQuery(q5);
            }

        pbsauver->setEnabled(false);
    }
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
    cbbranche->setCurrentText(d->getBranche());
    /* cbGI->setChecked(d->checkGI());
    cbGM->setChecked(d->checkGM());
    cbGSM->setChecked(d->checkGSM());
    cbGP->setChecked(d->checkGP());
    cbGB->setChecked(d->checkGB());
    cbGSU->setChecked(d->checkGSU());
    cbTC->setChecked(d->checkTC());
    cbHutech->setChecked(d->checkHutech()); */

    /* Affichage des formations extérieures */

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

    /* Affichage des semestres */

    QString qu2="SELECT uv, saison, annee, resultat FROM Inscription WHERE login = '";
    qu2.append(lelogin->text());
    qu2.append("';");
    QSqlQuery query2 = sql2->execQuery(qu2);

    while(query2.next())
        {
            QString uv = query2.value(0).toString();
            QString saison = query2.value(1).toString();
            QString annee = query2.value(2).toString();
            QString resultat = query2.value(3).toString();
            QString sem = saison.append(annee);
            table2->insertRow(table2->currentRow() + 1);

            QTableWidgetItem *itemSem = new QTableWidgetItem(sem);
            table2->setItem(table2->currentRow() + 1, 0, itemSem);
            itemSem->setFlags(itemSem->flags() & ~ Qt::ItemIsEditable);
            QTableWidgetItem *itemUV = new QTableWidgetItem(uv);
            table2->setItem(table2->currentRow() + 1, 1, itemUV);
            itemUV->setFlags(itemUV->flags() & ~ Qt::ItemIsEditable);
            QTableWidgetItem *itemRes = new QTableWidgetItem(resultat);
            itemRes->setFlags(itemRes->flags() & ~ Qt::ItemIsEditable);
            table2->setItem(table2->currentRow() + 1, 2, itemRes);

            /* Récupération des crédits de l'UV concernée*/

            QString qu3="SELECT creditsCS, creditsTM, creditsTSH, creditsSP FROM UV WHERE code = '";
            qu3.append(uv);

            qu3.append("';");

            QSqlQuery query3 = sql2->execQuery(qu3);

            query3.next();

            int creditsCS = query3.value(0).toInt();
            int creditsTM = query3.value(1).toInt();
            int creditsTSH = query3.value(2).toInt();
            int creditsSP = query3.value(3).toInt();

            QTableWidgetItem *itemCS = new QTableWidgetItem();
            itemCS->setData(Qt::DisplayRole,creditsCS);
            itemCS->setFlags(itemCS->flags() & ~ Qt::ItemIsEditable);
            table2->setItem(table2->currentRow() + 1, 3, itemCS);
            QTableWidgetItem *itemTM = new QTableWidgetItem();
            itemTM->setData(Qt::DisplayRole,creditsTM);
            itemTM->setFlags(itemTM->flags() & ~ Qt::ItemIsEditable);
            table2->setItem(table2->currentRow() + 1, 4, itemTM);
            QTableWidgetItem *itemTSH = new QTableWidgetItem();
            itemTSH->setData(Qt::DisplayRole,creditsTSH);
            itemTSH->setFlags(itemTSH->flags() & ~ Qt::ItemIsEditable);
            table2->setItem(table2->currentRow() + 1, 5, itemTSH);
            QTableWidgetItem *itemSP = new QTableWidgetItem();
            itemSP->setData(Qt::DisplayRole,creditsSP);
            itemSP->setFlags(itemSP->flags() & ~ Qt::ItemIsEditable);
            table2->setItem(table2->currentRow() + 1, 6, itemSP);

            QTableWidgetItem *itemSuppr = new QTableWidgetItem("Supprimer");
            table2->setItem(table2->currentRow() + 1, 7, itemSuppr);
            itemSuppr->setFlags(itemSuppr->flags() & ~ Qt::ItemIsEditable);

        }

    /* Affichage des appréciations semestrielles */

    QString qu4="SELECT saison, annee, commentaire FROM Semestre WHERE dossier = '";
    qu4.append(lelogin->text());
    qu4.append("';");
    QSqlQuery query4 = sql2->execQuery(qu4);

    while(query4.next())
        {
            QString saison = query4.value(0).toString();
            QString annee = query4.value(1).toString();
            QString sem = saison.append(annee);
            QString commentaire =query4.value(2).toString();

            table3->insertRow(table3->currentRow() + 1);

            QTableWidgetItem *itemSem = new QTableWidgetItem(sem);
            table3->setItem(table3->currentRow() + 1, 0, itemSem);
            itemSem->setFlags(itemSem->flags() & ~ Qt::ItemIsEditable);
            QTableWidgetItem *itemComm = new QTableWidgetItem(commentaire);
            table3->setItem(table3->currentRow() + 1, 1, itemComm);

        }
    pbsauver->setEnabled(false);


}

void DossierWindow::rechercher() {
    if (lelogin->text() == ""){ // Vérification qu'il y ait bien un dossier à rechercher
        QMessageBox msg;
        msg.setText("Veuillez rentrer un login.");
        msg.exec();
    } else {

        QString q = "SELECT * FROM Dossier WHERE login = '";
        q.append(lelogin->text());
        q.append("';");
        InterfaceSQL *sql = InterfaceSQL::getInstance();
        QSqlQuery query = sql->execQuery(q);
        query.next();
        if (query.value(0).toString() == ""){ // Le login recherché n'existe pas
            QMessageBox msg;
            msg.setText("Le login recherché n'existe pas.");
            msg.exec();
        } else {
            Dossier *d = sql->selectDossier(q);
            table->clearContents();
            table->setRowCount(0);
            table2->clearContents();
            table2->setRowCount(0);
            table3->clearContents();
            table3->setRowCount(0);
            associerDossier(d);
        }
    }

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

void DossierWindow::ajouterSemestre(){
    QString l = lelogin->text();
    SemestreWindow *fenetre = new SemestreWindow(l);
    fenetre->show();
}

void DossierWindow::supprSemestre(int r, int c){
    if (c == 7){

        QString sem = (table2->item(r,0)->data(Qt::EditRole)).toString();
        QString annee = "";
        annee.append(sem[1]);
        annee.append(sem[2]);
        annee.append(sem[3]);
        annee.append(sem[4]);

        QString q = "DELETE FROM Inscription WHERE login = '";
        q.append(lelogin->text());
        q.append("' AND uv = '");
        q.append((table2->item(r,1)->data(Qt::EditRole)).toString());
        q.append("' AND saison ='");
        q.append(sem[0]);
        q.append("' AND annee = '");
        q.append(annee);
        q.append("';");
        InterfaceSQL *sql = InterfaceSQL::getInstance();
        sql->execQuery(q);
        table2->removeRow(r);
    }
}

void DossierWindow::supprimer(){
    if (lelogin->text() == ""){ // Vérification qu'il y ait bien un dossier à supprimer
        QMessageBox msg;
        msg.setText("Veuillez rentrer un login.");
        msg.exec();
    } else {
        QString q = "SELECT * FROM Dossier WHERE login = '";
        q.append(lelogin->text());
        q.append("';");
        InterfaceSQL *sql = InterfaceSQL::getInstance();
        QSqlQuery query = sql->execQuery(q);
        query.next();
        if (query.value(0).toString() == ""){ // Le login n'existe pas
            QMessageBox msg;
            msg.setText("Le login que vous cherchez à supprimer n'existe pas.");
            msg.exec();
        } else {
            /* Suppression des formations extérieures associées */

            QString q2 = "DELETE FROM FormationExt WHERE login = '";
            q2.append(lelogin->text());
            q2.append("';");
            sql->execQuery(q2);

            /* Suppression de toutes les inscriptions */

            QString q3 = "DELETE FROM Inscription WHERE login = '";
            q3.append(lelogin->text());
            q3.append("';");
            sql->execQuery(q3);

            /* Suppression de tous les semestres */

            QString q4 = "DELETE FROM Semestre WHERE dossier = '";
            q4.append(lelogin->text());
            q4.append("';");
            sql->execQuery(q4);

            /* Suppression du dossier */

            QString q5 = "DELETE FROM Dossier WHERE login = '";
            q5.append(lelogin->text());
            q5.append("';");
            sql->execQuery(q5);

        }

    }
}

/* Fonctions liées à l'affichage des formations extérieures */

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

    if (getLogin() == '\0'){
        QMessageBox msg;
        msg.setText("Pour ajouter une formation, il faut rentrer au préalable un login.");
        msg.exec();
    }
    else if  (lenom->text() == '\0') {
        QMessageBox msg;
        msg.setText("Veuillez remplir le nom de la formation.");
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

/* Fonctions liées à l'affichage des semestres */

SemestreWindow::SemestreWindow(const QString& l): login(l) {
    mainlayout = new QVBoxLayout();

    hlayout1 = new QHBoxLayout();
    lsaison = new QLabel("Saison : ");
    cbsaison = new QComboBox;
    cbsaison->addItems(QStringList()<<"Automne"<<"Printemps");
    hlayout1->addWidget(lsaison);
    hlayout1->addWidget(cbsaison);

    hlayout2 = new QHBoxLayout();
    lannee = new QLabel("Année");
    leannee = new QLineEdit;
    hlayout2->addWidget(lannee);
    hlayout2->addWidget(leannee);

    hlayout3 = new QHBoxLayout();
    luv = new QLabel("UV : ");
    cbuv = new QComboBox;
    QString qu="SELECT code FROM UV;";
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    QSqlQuery query = sql->execQuery(qu);

    QStringList res;

    while(query.next())
    {
        res<<query.value(0).toString();
    }
    cbuv->addItems(res);

    hlayout3->addWidget(luv);
    hlayout3->addWidget(cbuv);

    hlayout5 = new QHBoxLayout();
    lnote = new QLabel("Note : ");
    cbnote = new QComboBox;

    QString qu2="SELECT r FROM Resultat;";
    QSqlQuery query2 = sql->execQuery(qu2);

    QStringList res2;

    while(query2.next())
    {
        res2<<query2.value(0).toString();
    }
    cbnote->addItems(res2);

    hlayout5->addWidget(lnote);
    hlayout5->addWidget(cbnote);

    hlayout4 = new QHBoxLayout();
    pbajouter = new QPushButton("Ajouter");
    hlayout4->addWidget(pbajouter);

    mainlayout->addLayout(hlayout1);
    mainlayout->addLayout(hlayout2);
    mainlayout->addLayout(hlayout3);
    mainlayout->addLayout(hlayout5);
    mainlayout->addLayout(hlayout4);

    this->setLayout(mainlayout);

    QObject::connect(pbajouter,SIGNAL(clicked()),this,SLOT(ajouter()));

}

void SemestreWindow::ajouter() {

    if (getLogin() == '\0'){
        QMessageBox msg;
        msg.setText("Pour ajouter un semestre, il faut rentrer au préalable un login.");
        msg.exec();
    }
    else if  (leannee->text() == '\0') {
        QMessageBox msg;
        msg.setText("Veuillez remplir l'année du semestre.");
        msg.exec();
    } else if  ((leannee->text()).size() != 4) {
        QMessageBox msg;
        msg.setText("Merci de remplir l'année sous la forme AAAA.");
        msg.exec();
    }
    else {

            /* Test pour voir si le semestre demandé existe déjà */

            QString q = "SELECT saison, annee FROM Semestre WHERE dossier = '";
            q.append(getLogin());
            q.append("' AND saison = '");

            if (cbsaison->currentText() == "Printemps" )
                q.append("P");
            else q.append("A");
            q.append("' AND annee = '");
            q.append(leannee->text());
            q.append("';");


            InterfaceSQL *sql = InterfaceSQL::getInstance();
            QSqlQuery query = sql->execQuery(q);
            query.next();

            if (query.value(0).toString() == ""){ // Le semestre n'existe pas

                /* Ajout du semestre */

                QString q2 = "INSERT INTO Semestre(saison, annee, dossier) VALUES ('";
                if (cbsaison->currentText() == "Printemps" )
                    q2.append("P");
                else q2.append("A");
                q2.append("', '");
                q2.append(leannee->text());
                q2.append("', '");
                q2.append(getLogin());
                q2.append("');");

                QSqlQuery query2 = sql->execQuery(q2);

                /* Ajout de l'UV dans inscription */

                QString q3 = "INSERT INTO Inscription(uv, saison, annee, login, resultat) VALUES ('";
                q3.append(cbuv->currentText());
                q3.append("', '");
                if (cbsaison->currentText() == "Printemps" )
                    q3.append("P");
                else q3.append("A");
                q3.append("', '");
                q3.append(leannee->text());
                q3.append("', '");
                q3.append(getLogin());
                q3.append("', '");
                q3.append(cbnote->currentText());
                q3.append("');");

                QSqlQuery query3 = sql->execQuery(q3);

            } else { /* Le semestre existe déjà --> Vérfier que l'UV est disponible pour la saison demandée / ! \

                Vérification que l'UV n'existe pas déjà dans Inscription pour ce semestre */

                QString q4 = "SELECT uv FROM Inscription WHERE login = '";
                q4.append(getLogin());
                q4.append("' AND saison = '");
                if (cbsaison->currentText() == "Printemps" )
                    q4.append("P");
                else q4.append("A");
                q4.append("' AND annee = '");
                q4.append(leannee->text());
                q4.append("' AND uv = '");
                q4.append(cbuv->currentText());
                q4.append("';");

                QSqlQuery query4 = sql->execQuery(q4);
                query4.next();

                if (query4.value(0).toString() != '\0'){
                    QMessageBox msg;
                    msg.setText("Vous avez déjà rajouté cette UV pour ce semestre.");
                    msg.exec();
                } else {

                    /* Ajout de l'UV dans inscription */

                    QString q5 = "INSERT INTO Inscription(uv, saison, annee, login, resultat) VALUES ('";
                    q5.append(cbuv->currentText());
                    q5.append("', '");
                    if (cbsaison->currentText() == "Printemps" )
                        q5.append("P");
                    else q5.append("A");
                    q5.append("', '");
                    q5.append(leannee->text());
                    q5.append("', '");
                    q5.append(getLogin());
                    q5.append("', '");
                    q5.append(cbnote->currentText());
                    q5.append("');");

                    QSqlQuery query5 = sql->execQuery(q5);

                }
            }
    }
    close();
}
