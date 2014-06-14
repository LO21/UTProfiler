#include "UTProfiler.h"

UVWindow::UVWindow() {
    //UVManager *uvm = UVManager::getInstance();
    setWindowTitle("UTProfiler");
    mainlayout = new QVBoxLayout();
    hlayout1 = new QHBoxLayout();
    pbretour = new QPushButton("Retour");
    lcode = new QLabel("Code : ");
    lecode = new QLineEdit();
    pbrechercher = new QPushButton("Rechercher");
    lresponsable = new QLabel("Responsable : ");
    leresponsable = new QLineEdit();
    hlayout1->addWidget(pbretour);
    hlayout1->addWidget(lcode);
    hlayout1->addWidget(lecode);
    hlayout1->addWidget(pbrechercher);
    hlayout1->addWidget(lresponsable);
    hlayout1->addWidget(leresponsable);
    hlayout2 = new QHBoxLayout();
    tedescription = new QTextEdit();
    vlayout21 = new QVBoxLayout();
    hlayout211 = new QHBoxLayout();
    lprintemps = new QLabel("Printemps : ");
    cbprintemps = new QCheckBox();
    hlayout211->addWidget(lprintemps);
    hlayout211->addWidget(cbprintemps);
    hlayout212 = new QHBoxLayout();
    lautomne = new QLabel("Automne : ");
    cbautomne = new QCheckBox();
    hlayout212->addWidget(lautomne);
    hlayout212->addWidget(cbautomne);
    vlayout21->addLayout(hlayout211);
    vlayout21->addLayout(hlayout212);
    hlayout2->addWidget(tedescription);
    hlayout2->addLayout(vlayout21);
    hlayout3 = new QHBoxLayout();
    lcs = new QLabel("CS : ");
    lecs = new QLineEdit();
    ltm = new QLabel("TM : ");
    letm = new QLineEdit();
    ltsh = new QLabel("TSH :");
    letsh = new QLineEdit();
    lsp = new QLabel("SP : ");
    lesp = new QLineEdit();
    hlayout3->addWidget(lcs);
    hlayout3->addWidget(lecs);
    hlayout3->addWidget(ltm);
    hlayout3->addWidget(letm);
    hlayout3->addWidget(ltsh);
    hlayout3->addWidget(letsh);
    hlayout3->addWidget(lsp);
    hlayout3->addWidget(lesp);
    hlayout4 = new QHBoxLayout();
    ltc = new QLabel("TC : ");
    cbtc = new QCheckBox();
    lhutech = new QLabel("HUTECH : ");
    cbhutech = new QCheckBox();
    lgb = new QLabel("GB : ");
    cbgb = new QCheckBox();
    lgi = new QLabel("GI : ");
    cbgi = new QCheckBox();
    lgm = new QLabel("GM : ");
    cbgm = new QCheckBox();
    lgp = new QLabel("GP : ");
    cbgp = new QCheckBox();
    lgsm = new QLabel("GSM : ");
    cbgsm = new QCheckBox();
    lgsu = new QLabel("GSU : ");
    cbgsu = new QCheckBox();
    hlayout4->addWidget(ltc);
    hlayout4->addWidget(cbtc);
    hlayout4->addWidget(lhutech);
    hlayout4->addWidget(cbhutech);
    hlayout4->addWidget(lgb);
    hlayout4->addWidget(cbgb);
    hlayout4->addWidget(lgi);
    hlayout4->addWidget(cbgi);
    hlayout4->addWidget(lgm);
    hlayout4->addWidget(cbgm);
    hlayout4->addWidget(lgp);
    hlayout4->addWidget(cbgp);
    hlayout4->addWidget(lgsm);
    hlayout4->addWidget(cbgsm);
    hlayout4->addWidget(lgsu);
    hlayout4->addWidget(cbgsu);
    hlayout5 = new QHBoxLayout();
    pbnouveau = new QPushButton("Nouveau");
    pbsupprimer = new QPushButton("Supprimer");
    pbannuler = new QPushButton("Annuler");
    pbsauver = new QPushButton("Sauver");
    hlayout5->addWidget(pbnouveau);
    hlayout5->addWidget(pbsupprimer);
    hlayout5->addWidget(pbannuler);
    hlayout5->addWidget(pbsauver);
    mainlayout->addLayout(hlayout1);
    mainlayout->addLayout(hlayout2);
    mainlayout->addLayout(hlayout3);
    mainlayout->addLayout(hlayout4);
    mainlayout->addLayout(hlayout5);
    this->setLayout(mainlayout);
    QObject::connect(pbretour,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(pbsupprimer,SIGNAL(clicked()),this,SLOT(supprimer()));
    QObject::connect(pbnouveau,SIGNAL(clicked()),this,SLOT(nouveau()));
    QObject::connect(lecode,SIGNAL(returnPressed()),this,SLOT(rechercher()));
    QObject::connect(pbrechercher,SIGNAL(clicked()),this,SLOT(rechercher()));
    QObject::connect(pbsauver,SIGNAL(clicked()),this,SLOT(sauver()));
    QObject::connect(pbannuler,SIGNAL(clicked()),this,SLOT(annuler()));
    QObject::connect(leresponsable,SIGNAL(textChanged(QString)),this,SLOT(pbsauverEnable()));
    QObject::connect(tedescription,SIGNAL(textChanged()),this,SLOT(pbsauverEnable()));
    QObject::connect(lecs,SIGNAL(textChanged(QString)),this,SLOT(pbsauverEnable()));
    QObject::connect(letm,SIGNAL(textChanged(QString)),this,SLOT(pbsauverEnable()));
    QObject::connect(letsh,SIGNAL(textChanged(QString)),this,SLOT(pbsauverEnable()));
    QObject::connect(lesp,SIGNAL(textChanged(QString)),this,SLOT(pbsauverEnable()));
    QObject::connect(cbprintemps,SIGNAL(stateChanged(int)),this,SLOT(pbsauverEnable()));
    QObject::connect(cbautomne,SIGNAL(stateChanged(int)),this,SLOT(pbsauverEnable()));
    QObject::connect(cbtc,SIGNAL(stateChanged(int)),this,SLOT(pbsauverEnable()));
    QObject::connect(cbhutech,SIGNAL(stateChanged(int)),this,SLOT(pbsauverEnable()));
    QObject::connect(cbgb,SIGNAL(stateChanged(int)),this,SLOT(pbsauverEnable()));
    QObject::connect(cbgi,SIGNAL(stateChanged(int)),this,SLOT(pbsauverEnable()));
    QObject::connect(cbgm,SIGNAL(stateChanged(int)),this,SLOT(pbsauverEnable()));
    QObject::connect(cbgp,SIGNAL(stateChanged(int)),this,SLOT(pbsauverEnable()));
    QObject::connect(cbgsm,SIGNAL(stateChanged(int)),this,SLOT(pbsauverEnable()));
    QObject::connect(cbgsu,SIGNAL(stateChanged(int)),this,SLOT(pbsauverEnable()));
}

void UVWindow::associerUV(UV *newuv) {
    //UVManager *uvm = UVManager::getInstance();
    //uvm->ajouterItem(newuv);
    uv=newuv;
    lecode->setText(uv->getCode());
    leresponsable->setText(uv->getResponsable());
    tedescription->setText(uv->getTitre());
    lecs->setText(QString::number(uv->getCreditsCS()));
    letm->setText(QString::number(uv->getCreditsTM()));
    letsh->setText(QString::number(uv->getCreditsTSH()));
    lesp->setText(QString::number(uv->getCreditsSP()));
    cbautomne->setChecked(uv->getAutomne());
    cbprintemps->setChecked(uv->getPrintemps());
    bool *tab=uv->getBranche();
    cbtc->setChecked(tab[0]);
    cbhutech->setChecked(tab[1]);
    cbgb->setChecked(tab[2]);
    cbgi->setChecked(tab[3]);
    cbgm->setChecked(tab[4]);
    cbgp->setChecked(tab[5]);
    cbgsm->setChecked(tab[6]);
    cbgsu->setChecked(tab[7]);
    pbsauver->setEnabled(false);
    pbannuler->setEnabled(false);
}

void UVWindow::sauver() {
    if (lecode->text() == ""){ // Vérification qu'il y ait bien une uv à sauvegarder
        QMessageBox msg;
        msg.setText("Veuillez rentrer un code d'UV.");
        msg.exec();
    } else {
        QString q = "SELECT * FROM UV WHERE code = '";
        q.append(lecode->text());
        q.append("';");
        InterfaceSQL *sql = InterfaceSQL::getInstance();
        QSqlQuery query = sql->execQuery(q);
        query.next();
        if (query.value(0).toString() == ""){ // Le code d'UV n'existe pas
            QMessageBox msg;
            msg.setText("Cette UV n'existe pas. Pour créer une nouvelle UV, cliquez sur Nouveau.");
            msg.exec();
        } else {
            QString q="UPDATE UV SET responsable = '";
            q.append(leresponsable->text());
            q.append("', titre = '");
            QString checkSyntax = tedescription->toPlainText();
            unsigned int i=0;
            while (checkSyntax[i]!='\0') {
                if (checkSyntax[i]=='\'') {checkSyntax.insert(i,'\'');}
                ++i;
            }
            q.append(checkSyntax);
            q.append("', creditsCS = '");
            q.append(lecs->text());
            q.append("', creditsTM = '");
            q.append(letm->text());
            q.append("', creditsTSH = '");
            q.append(letsh->text());
            q.append("', creditsSP = '");
            q.append(lesp->text());
            q.append("', automne = ");
            if (cbautomne->isChecked()) {q.append("1");}
            else {q.append("0");}
            q.append(", printemps = ");
            if (cbprintemps->isChecked()) {q.append("1");}
            else {q.append("0");}
            q.append(" WHERE code = '");
            q.append(lecode->text());
            q.append("';");
            pbsauver->setEnabled(false);
            pbannuler->setEnabled(false);
            InterfaceSQL *sql = InterfaceSQL::getInstance();
            sql->execQuery(q);
            bool* tab=uv->getBranche();
            if (tab[0]!=cbtc->isChecked()) {changeTC();}
            if (tab[1]!=cbhutech->isChecked()) {changeHUTECH();}
            if (tab[2]!=cbgb->isChecked()) {changeGB();}
            if (tab[3]!=cbgi->isChecked()) {changeGI();}
            if (tab[4]!=cbgm->isChecked()) {changeGM();}
            if (tab[5]!=cbgp->isChecked()) {changeGP();}
            if (tab[6]!=cbgsm->isChecked()) {changeGSM();}
            if (tab[7]!=cbgsu->isChecked()) {changeGSU();}
        }
    }
}

void UVWindow::supprimer() {
    //UVManager *uvm = UVManager::getInstance();
    //uvm->supprimerItem(uv);
    if (lecode->text() == ""){ // Vérification qu'il y ait bien une uv à supprimer
        QMessageBox msg;
        msg.setText("Veuillez rentrer un code d'UV.");
        msg.exec();
    } else {
        QString q = "SELECT * FROM UV WHERE code = '";
        q.append(lecode->text());
        q.append("';");
        InterfaceSQL *sql = InterfaceSQL::getInstance();
        QSqlQuery query = sql->execQuery(q);
        query.next();
        if (query.value(0).toString() == ""){ // Le code d'UV n'existe pas
            QMessageBox msg;
            msg.setText("Cette UV n'existe pas.");
            msg.exec();
        } else {
            QString q = QString::fromStdString("DELETE FROM UV WHERE code = '"+uv->getCode().toStdString()+"';");
            InterfaceSQL *sql = InterfaceSQL::getInstance();
            sql->execQuery(q);
            //UVManager::Iterator it = uvm->end();
            //it--;
            //associerUV(*it);
        }
    }
}

void UVWindow::pbsauverEnable() {
    pbsauver->setEnabled(true);
    pbannuler->setEnabled(true);
}

void UVWindow::annuler() {
    associerUV(uv);
}

void UVWindow::rechercher() {
    if (lecode->text() == ""){ // Vérification qu'il y ait bien une uv à rechercher
        QMessageBox msg;
        msg.setText("Veuillez rentrer un code d'UV.");
        msg.exec();
    } else {

        QString q = "SELECT * FROM UV WHERE code = '";
        q.append(lecode->text());
        q.append("';");
        InterfaceSQL *sql = InterfaceSQL::getInstance();
        QSqlQuery query = sql->execQuery(q);
        query.next();
        if (query.value(0).toString() == ""){ // Le code d'UV recherché n'existe pas
            QMessageBox msg;
            msg.setText("L'UV recherchée n'existe pas.");
            msg.exec();
        } else {
            UV *uv = sql->selectUV(q);
            associerUV(uv);
        }
    }
}

void UVWindow::nouveau() {
    newuvwindow = new NewUVWindow(this);
}

NewUVWindow::NewUVWindow (UVWindow *m) : master(m) {
    label = new QLabel("Code : ");
    lecode = new QLineEdit;
    hlayout1 = new QHBoxLayout;
    hlayout1->addWidget(label);
    hlayout1->addWidget(lecode);
    pbannuler = new QPushButton("Annuler");
    pbvalider = new QPushButton("Valider");
    pbvalider->setEnabled(false);
    QObject::connect(lecode,SIGNAL(textChanged(QString)),this,SLOT(pbvaliderEnable()));
    hlayout2 = new QHBoxLayout;
    hlayout2->addWidget(pbannuler);
    hlayout2->addWidget(pbvalider);
    QObject::connect(pbannuler,SIGNAL(clicked()),this,SLOT(nouveau_annuler()));
    QObject::connect(pbvalider,SIGNAL(clicked()),this,SLOT(nouveau_valider()));
    vlayout = new QVBoxLayout;
    vlayout->addLayout(hlayout1);
    vlayout->addLayout(hlayout2);
    setLayout(vlayout);
    show();
}

void NewUVWindow::pbvaliderEnable() {
    pbvalider->setEnabled(true);
}


void NewUVWindow::nouveau_annuler() {
    close();
}

void NewUVWindow::nouveau_valider() {
    /* Vérification que l'UV n'existe pas déjà */
    QString q = "SELECT * FROM UV WHERE code = '";
    q.append(lecode->text());
    q.append("';");
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    QSqlQuery query = sql->execQuery(q);
    query.next();
    if (query.value(0).toString() != ""){ // L'UV existe déjà
        QMessageBox msg;
        msg.setText("L'UV existe déjà.");
        msg.exec();
    } else {
        QString q2 = "INSERT INTO UV(code) VALUES ('";
        QString code = lecode->text();
        q2.append(code);
        q2.append("');");
        sql->execQuery(q2);
        q2.clear();
        q2.append("SELECT * FROM UV WHERE code = '");
        q2.append(code);
        q2.append("';");
        UV *uv = sql->selectUV(q2);
        master->associerUV(uv);
        close();
    }
}

void UVWindow::changeTC() {
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    if (cbtc->isChecked()) {
        sql->execQuery(QString::fromStdString("INSERT INTO AssociationFormationUV(uv,formation) VALUES ('"+uv->getCode().toStdString()+"', 'TC');"));
    }
    else {
        sql->execQuery(QString::fromStdString("DELETE FROM AssociationFormationUV WHERE uv = '"+uv->getCode().toStdString()+"' AND formation = 'TC';"));
    }
}

void UVWindow::changeHUTECH() {
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    if (cbhutech->isChecked()) {
        sql->execQuery(QString::fromStdString("INSERT INTO AssociationFormationUV(uv,formation) VALUES ('"+uv->getCode().toStdString()+"', 'HUTECH');"));
    }
    else {
        sql->execQuery(QString::fromStdString("DELETE FROM AssociationFormationUV WHERE uv = '"+uv->getCode().toStdString()+"' AND formation = 'HUTECH';"));
    }
}

void UVWindow::changeGB() {
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    if (cbgb->isChecked()) {
        sql->execQuery(QString::fromStdString("INSERT INTO AssociationFormationUV(uv,formation) VALUES ('"+uv->getCode().toStdString()+"', 'GB');"));
    }
    else {
        sql->execQuery(QString::fromStdString("DELETE FROM AssociationFormationUV WHERE uv = '"+uv->getCode().toStdString()+"' AND formation = 'GB';"));
    }
}

void UVWindow::changeGI() {
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    if (cbgi->isChecked()) {
        sql->execQuery(QString::fromStdString("INSERT INTO AssociationFormationUV(uv,formation) VALUES ('"+uv->getCode().toStdString()+"', 'GI');"));
    }
    else {
        sql->execQuery(QString::fromStdString("DELETE FROM AssociationFormationUV WHERE uv = '"+uv->getCode().toStdString()+"' AND formation = 'GI';"));
    }
}

void UVWindow::changeGM() {
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    if (cbgm->isChecked()) {
        sql->execQuery(QString::fromStdString("INSERT INTO AssociationFormationUV(uv,formation) VALUES ('"+uv->getCode().toStdString()+"', 'GM');"));
    }
    else {
        sql->execQuery(QString::fromStdString("DELETE FROM AssociationFormationUV WHERE uv = '"+uv->getCode().toStdString()+"' AND formation = 'GM';"));
    }
}

void UVWindow::changeGP() {
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    if (cbgp->isChecked()) {
        sql->execQuery(QString::fromStdString("INSERT INTO AssociationFormationUV(uv,formation) VALUES ('"+uv->getCode().toStdString()+"', 'GP');"));
    }
    else {
        sql->execQuery(QString::fromStdString("DELETE FROM AssociationFormationUV WHERE uv = '"+uv->getCode().toStdString()+"' AND formation = 'GP';"));
    }
}

void UVWindow::changeGSM() {
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    if (cbgsm->isChecked()) {
        sql->execQuery(QString::fromStdString("INSERT INTO AssociationFormationUV(uv,formation) VALUES ('"+uv->getCode().toStdString()+"', 'GSM');"));
    }
    else {
        sql->execQuery(QString::fromStdString("DELETE FROM AssociationFormationUV WHERE uv = '"+uv->getCode().toStdString()+"' AND formation = 'GSM';"));
    }
}

void UVWindow::changeGSU() {
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    if (cbgsu->isChecked()) {
        sql->execQuery(QString::fromStdString("INSERT INTO AssociationFormationUV(uv,formation) VALUES ('"+uv->getCode().toStdString()+"', 'GSU');"));
    }
    else {
        sql->execQuery(QString::fromStdString("DELETE FROM AssociationFormationUV WHERE uv = '"+uv->getCode().toStdString()+"' AND formation = 'GSU';"));
    }
}
