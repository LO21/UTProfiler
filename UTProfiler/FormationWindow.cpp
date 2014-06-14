#include "UTProfiler.h"

FormationWindow::FormationWindow() {
    setWindowTitle("UTProfiler");
    mainlayout = new QVBoxLayout();

    hlayout1 = new QHBoxLayout();
    pbretour = new QPushButton("Retour");
    lnom = new QLabel("Nom : ");
    lenom = new QLineEdit();
    pbrechercher = new QPushButton("Rechercher");
    lresponsable = new QLabel("Responsable : ");
    leresponsable = new QLineEdit();
    ltype = new QLabel("Type : ");
    cbtype = new QComboBox;

    QString qu="SELECT type FROM TypeFormation;";
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    QSqlQuery query = sql->execQuery(qu);

    QStringList res;

    while(query.next())
    {
        res<<query.value(0).toString();
    }
    cbtype->addItems(res);

    hlayout1->addWidget(pbretour);
    hlayout1->addWidget(lnom);
    hlayout1->addWidget(lenom);
    hlayout1->addWidget(pbrechercher);
    hlayout1->addWidget(lresponsable);
    hlayout1->addWidget(leresponsable);
    hlayout1->addWidget(ltype);
    hlayout1->addWidget(cbtype);

    /* Crédits à valider */

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

    /* Filières associées aux branches */


        hlayout5 = new QHBoxLayout();
        lfilieres = new QLabel("Filières associées à cette branche :");
        pbajoutfil = new QPushButton("Ajouter");
        hlayout5->addWidget(lfilieres);
        hlayout5->addWidget(pbajoutfil);

        table = new QTableWidget;
        table->setColumnCount(4);
        table->setRowCount(0);
        table->setHorizontalHeaderLabels(QStringList()<<"Filière"<<"Responsable"<<""<<"");


    /* UV associées */

    hlayout4 = new QHBoxLayout();
    luvs = new QLabel("UV associées à cette formation :");
    pbajoutuv = new QPushButton("Ajouter");
    hlayout4->addWidget(luvs);
    hlayout4->addWidget(pbajoutuv);

    twuvs = new QTableWidget;
    twuvs->setColumnCount(8);
    twuvs->setRowCount(0);
    twuvs->setHorizontalHeaderLabels(QStringList()<<"UV"<<"Titre"<<"Crédits CS"<<"Crédits TM"<<"Crédits TSH"<<"Crédits SP"<<""<<"");

    /* Boutons Nouveau / Supprimer / Annuler / Sauver */

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
    mainlayout->addLayout(hlayout5);
    mainlayout->addWidget(table);

    mainlayout->addLayout(hlayout4);
    mainlayout->addWidget(twuvs);
    mainlayout->addLayout(hlayout3);
    this->setLayout(mainlayout);

    QObject::connect(pbretour,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(leresponsable,SIGNAL(textChanged(QString)),this,SLOT(setenabled()));
    QObject::connect(cbtype,SIGNAL(currentTextChanged(QString)),this,SLOT(setenabled()));
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
    QObject::connect(pbajoutfil,SIGNAL(clicked()),this,SLOT(ajouterfil()));
    QObject::connect(twuvs,SIGNAL(cellClicked(int,int)),this,SLOT(sauveruv(int, int)));
    QObject::connect(table,SIGNAL(cellClicked(int,int)),this,SLOT(sauverfil(int, int)));
    QObject::connect(pbajoutuv, SIGNAL(clicked()), this, SLOT(ajouteruv()));
    QObject::connect(table,SIGNAL(cellChanged(int,int)),this,SLOT(setenabled()));
    QObject::connect(twuvs,SIGNAL(cellChanged(int,int)),this,SLOT(setenabled()));
    QObject::connect(pbajouteruv,SIGNAL(clicked()),this,SLOT(ajouteruv()));
    QObject::connect(pbsupprimeruv,SIGNAL(clicked()),this,SLOT(supprimeruv()));

}

void FormationWindow::associerFormation(Formation *newformation) {

    formation=newformation;
    lenom->setText(formation->getNom());
    leresponsable->setText(formation->getResponsable());
    cbtype->setCurrentText(formation->getType());
    letot->setText(QString::number(formation->getNbCreditsTot()));
    lecs->setText(QString::number(formation->getNbCreditsCS()));
    letm->setText(QString::number(formation->getNbCreditsTM()));
    lecstm->setText(QString::number(formation->getNbCreditsCSTM()));
    letsh->setText(QString::number(formation->getNbCreditsTSH()));
    lesp->setText(QString::number(formation->getNbCreditsSP()));

    /* Filières associées */
    if (cbtype->currentText() == "Branche"){
        lfilieres->show();
        pbajoutfil->show();
        table->show();
        QString qu="SELECT f.nom, f.responsable FROM Formation f, AssociationBrancheFiliere A WHERE f.nom = A.filiere AND A.branche ='";
        qu.append(lenom->text());
        qu.append("';");
        InterfaceSQL *sql2 = InterfaceSQL::getInstance();
        QSqlQuery query = sql2->execQuery(qu);

        while(query.next())
            {
                QString nom = query.value(0).toString();
                QString responsable = query.value(1).toString();
                table->insertRow(table->currentRow() + 1);

                QTableWidgetItem *itemNom = new QTableWidgetItem(nom);
                table->setItem(table->currentRow() + 1, 0, itemNom);
                itemNom->setFlags(itemNom->flags() & ~ Qt::ItemIsEditable);
                QTableWidgetItem *itemResponsable = new QTableWidgetItem(responsable);
                table->setItem(table->currentRow() + 1, 1, itemResponsable);

                QTableWidgetItem *itemEnr = new QTableWidgetItem("Enregister");
                table->setItem(table->currentRow() + 1, 2, itemEnr);
                itemEnr->setFlags(itemEnr->flags() & ~ Qt::ItemIsEditable);

                QTableWidgetItem *itemSuppr = new QTableWidgetItem("Supprimer");
                table->setItem(table->currentRow() + 1, 3, itemSuppr);
                itemSuppr->setFlags(itemSuppr->flags() & ~ Qt::ItemIsEditable);

        }
    } else {
        lfilieres->hide();
        pbajoutfil->hide();
        table->hide();
    }

    /* UVs associées */

    QString qu="SELECT u.code, u.titre, u.creditsCS, u.creditsTM, u.creditsTSH, u.creditsSP FROM UV u, AssociationFormationUV A WHERE u.code = A.uv AND A.formation ='";
    qu.append(lenom->text());
    qu.append("';");
    InterfaceSQL *sql2 = InterfaceSQL::getInstance();
    QSqlQuery query = sql2->execQuery(qu);

    while(query.next())
        {
            QString code = query.value(0).toString();
            QString titre = query.value(1).toString();
            int creditsCS = query.value(2).toInt();
            int creditsTM = query.value(3).toInt();
            int creditsTSH = query.value(4).toInt();
            int creditsSP = query.value(5).toInt();
            twuvs->insertRow(twuvs->currentRow() + 1);

            QTableWidgetItem *itemCode = new QTableWidgetItem(code);
            twuvs->setItem(twuvs->currentRow() + 1, 0, itemCode);
            itemCode->setFlags(itemCode->flags() & ~ Qt::ItemIsEditable);
            QTableWidgetItem *itemTitre = new QTableWidgetItem(titre);
            twuvs->setItem(twuvs->currentRow() + 1, 1, itemTitre);
            QTableWidgetItem *itemCS = new QTableWidgetItem();
            itemCS->setData(Qt::DisplayRole,creditsCS);
            twuvs->setItem(twuvs->currentRow() + 1, 2, itemCS);
            QTableWidgetItem *itemTM = new QTableWidgetItem();
            itemTM->setData(Qt::DisplayRole,creditsTM);
            twuvs->setItem(twuvs->currentRow() + 1, 3, itemTM);
            QTableWidgetItem *itemTSH = new QTableWidgetItem();
            itemTSH->setData(Qt::DisplayRole,creditsTSH);
            twuvs->setItem(twuvs->currentRow() + 1, 4, itemTSH);
            QTableWidgetItem *itemSP = new QTableWidgetItem();
            itemSP->setData(Qt::DisplayRole,creditsSP);
            twuvs->setItem(twuvs->currentRow() + 1, 5, itemSP);

            QTableWidgetItem *itemEnr = new QTableWidgetItem("Enregister");
            twuvs->setItem(twuvs->currentRow() + 1, 6, itemEnr);
            itemEnr->setFlags(itemEnr->flags() & ~ Qt::ItemIsEditable);

            QTableWidgetItem *itemSuppr = new QTableWidgetItem("Supprimer");
            twuvs->setItem(twuvs->currentRow() + 1, 7, itemSuppr);
            itemSuppr->setFlags(itemSuppr->flags() & ~ Qt::ItemIsEditable);

        }

    pbsauver->setEnabled(false);
    pbannuler->setEnabled(false);
}

void FormationWindow::setenabled() {
    pbsauver->setEnabled(true);
    pbannuler->setEnabled(true);
}
void FormationWindow::rechercher() {
    if (lenom->text() == ""){ // Vérification qu'il y ait bien une uv à rechercher
        QMessageBox msg;
        msg.setText("Veuillez rentrer le nom de la formation.");
        msg.exec();
    } else {

        QString q = "SELECT * FROM Formation WHERE nom = '";
        q.append(lenom->text());
        q.append("';");
        InterfaceSQL *sql = InterfaceSQL::getInstance();
        QSqlQuery query = sql->execQuery(q);
        query.next();
        if (query.value(0).toString() == ""){ // La formation recherchée n'existe pas
            QMessageBox msg;
            msg.setText("La formation recherchée n'existe pas.");
            msg.exec();
        } else {
            InterfaceSQL *sql = InterfaceSQL::getInstance();
            Formation *formation = sql->selectFormation(QString::fromStdString("SELECT * FROM Formation WHERE nom = '"+lenom->text().toStdString()+"';"));
            twuvs->clearContents();
            twuvs->setRowCount(0);
            table->clearContents();
            table->setRowCount(0);
            associerFormation(formation);
        }
    }
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

    /* Sauvegardes des modifications liées à la formation */

    QString q="UPDATE Formation SET responsable = '";
    q.append(leresponsable->text());
    q.append("', type = '");
    q.append(cbtype->currentText());
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

    /* InterfaceSQL *sql = InterfaceSQL::getInstance();
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
    } */
    pbsauver->setEnabled(false);
    pbannuler->setEnabled(false);
}


void FormationWindow::sauveruv(int r, int c){
    /* Sauvegardes des modifications des uvs associées */
        if (c == 6){
            InterfaceSQL *sql = InterfaceSQL::getInstance();
            QString titre = (twuvs->item(r,1)->data(Qt::EditRole)).toString();
            unsigned int j=0;
            while (titre[j]!='\0') {
                if (titre[j]=='\'') {titre.insert(j,'\'');}
                ++j;
            }

            QString q2 = "UPDATE UV SET titre = '";
            q2.append(titre);
            q2.append("', creditsCS = '");
            q2.append((twuvs->item(r,2)->data(Qt::EditRole)).toString());
            q2.append("', creditsTM = '");
            q2.append((twuvs->item(r,3)->data(Qt::EditRole)).toString());
            q2.append("', creditsTSH = '");
            q2.append((twuvs->item(r,4)->data(Qt::EditRole)).toString());
            q2.append("', creditsSP = '");
            q2.append((twuvs->item(r,5)->data(Qt::EditRole)).toString());
            q2.append("' WHERE code = '");
            q2.append((twuvs->item(r,0)->data(Qt::EditRole)).toString());
            q2.append("';");
            qDebug()<<q2;
            sql->execQuery(q2);
        }
        if (c == 7){ // Supression de l'association entre l'UV et la formation
            QString q = "DELETE FROM AssociationFormationUV WHERE formation = '";
            q.append(lenom->text());
            q.append("' AND uv = '");
            q.append((twuvs->item(r,0)->data(Qt::EditRole)).toString());
            q.append("';");
            InterfaceSQL *sql = InterfaceSQL::getInstance();
            sql->execQuery(q);
            twuvs->removeRow(r);
        }
}

void FormationWindow::sauverfil(int r, int c){
    /* Sauvegardes des modifications des uvs associées */
        qDebug()<<r<<c;
        if (c == 2){
            InterfaceSQL *sql = InterfaceSQL::getInstance();
            QString responsable = (table->item(r,1)->data(Qt::EditRole)).toString();
            unsigned int j=0;
            while (responsable[j]!='\0') {
                if (responsable[j]=='\'') {responsable.insert(j,'\'');}
                ++j;
            }

            QString q2 = "UPDATE Formation SET responsable = '";
            q2.append(responsable);
            q2.append("' WHERE nom = '");
            q2.append((table->item(r,0)->data(Qt::EditRole)).toString());
            q2.append("';");
            qDebug()<<q2;
            sql->execQuery(q2);
        }
        if (c == 3){ // Suppression de l'association entre l'UV et la formation
            QString q = "DELETE FROM AssociationBrancheFiliere WHERE branche = '";
            q.append(lenom->text());
            q.append("' AND filiere = '");
            q.append((table->item(r,0)->data(Qt::EditRole)).toString());
            q.append("';");
            InterfaceSQL *sql = InterfaceSQL::getInstance();
            sql->execQuery(q);
            table->removeRow(r);
        }
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

void FormationWindow::ajouteruv(){
    QString f = lenom->text();
    AssocierUVWindow *fenetre = new AssocierUVWindow(f);
    fenetre->show();
}

void FormationWindow::ajouterfil(){
    if (cbtype->currentText() == "Branche"){
        QString b = lenom->text();
        AssocierFiliereWindow *fenetre = new AssocierFiliereWindow(b);
        fenetre->show();
    }
}

AssocierUVWindow::AssocierUVWindow(const QString& f): formation(f) {
    setWindowTitle("UTProfiler");
    mainlayout = new QVBoxLayout();

    hlayout1 = new QHBoxLayout();

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

    hlayout1->addWidget(luv);
    hlayout1->addWidget(cbuv);


    hlayout2 = new QHBoxLayout();
    pbajouter = new QPushButton("Ajouter");
    hlayout2->addWidget(pbajouter);

    mainlayout->addLayout(hlayout1);
    mainlayout->addLayout(hlayout2);

    this->setLayout(mainlayout);

    QObject::connect(pbajouter,SIGNAL(clicked()),this,SLOT(ajouter()));

}

void AssocierUVWindow::ajouter() {

    if (getFormation() == '\0'){
        QMessageBox msg;
        msg.setText("Pour associer une UV à une formation, il faut rentrer au préalable le nom d'une formation.");
        msg.exec();
    }
    else {
        QString q = "SELECT * FROM AssociationFormationUV WHERE uv = '";
        q.append(cbuv->currentText());
        q.append("' AND formation ='");
        q.append(getFormation());
        q.append("';");
        InterfaceSQL *sql = InterfaceSQL::getInstance();
        QSqlQuery query = sql->execQuery(q);
        query.next();
        if (query.value(0).toString() != ""){ // L'UV est déjà associée à cette formation
            QMessageBox msg;
            msg.setText("L'UV choisie est déjà associée à cette formation.");
            msg.exec();
        } else {

            QString q2="INSERT INTO AssociationFormationUV(uv, formation) VALUES ('";
            q2.append(cbuv->currentText());
            q2.append("','");
            q2.append(getFormation());
            q2.append("');");
            InterfaceSQL *sql = InterfaceSQL::getInstance();
            sql->execQuery(q2);
        }
    }
    close();
}

AssocierFiliereWindow::AssocierFiliereWindow(const QString& b): branche(b) {
    setWindowTitle("UTProfiler");
    mainlayout = new QVBoxLayout();

    hlayout1 = new QHBoxLayout();

    lnom = new QLabel("Nom : ");
    lenom = new QLineEdit;

    hlayout1->addWidget(lnom);
    hlayout1->addWidget(lenom);

    hlayout2 = new QHBoxLayout();
    pbajouter = new QPushButton("Ajouter");
    hlayout2->addWidget(pbajouter);

    mainlayout->addLayout(hlayout1);
    mainlayout->addLayout(hlayout2);

    this->setLayout(mainlayout);

    QObject::connect(pbajouter,SIGNAL(clicked()),this,SLOT(ajouter()));

}

void AssocierFiliereWindow::ajouter() {

    if (getBranche() == '\0'){
        QMessageBox msg;
        msg.setText("Pour associer une filière à une branche, il faut rentrer au préalable le nom d'une branche.");
        msg.exec();
    }
    else {
        QString q = "SELECT * FROM AssociationBrancheFiliere WHERE filiere = '";
        q.append(lenom->text());
        q.append("' AND branche ='");
        q.append(getBranche());
        q.append("';");
        InterfaceSQL *sql = InterfaceSQL::getInstance();
        QSqlQuery query = sql->execQuery(q);
        query.next();
        if (query.value(0).toString() != ""){ // La formation est déjà associée à cette formation
            QMessageBox msg;
            QString text = "Cette filière est déjà associée à la branche ";
            text.append(getBranche());
            text.append(".");
            msg.setText(text);
            msg.exec();
        } else {
            QString q2="INSERT INTO AssociationBrancheFiliere(filiere, branche) VALUES ('";
            q2.append(lenom->text());
            q2.append("','");
            q2.append(getBranche());
            q2.append("');");
            InterfaceSQL *sql = InterfaceSQL::getInstance();
            sql->execQuery(q2);

            QString q3="INSERT INTO Formation(nom) VALUES ('";
            q3.append(lenom->text());
            q3.append("');");
            sql->execQuery(q3);
        }
    }
    close();
}
