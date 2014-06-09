#include "UTProfiler.h"

UVWindow::UVWindow() {
    uv = new UV("","","",0,0,0,0,0,0);
    mainlayout = new QVBoxLayout();
    hlayout1 = new QHBoxLayout();
    lcode = new QLabel("Code : ");
    lecode = new QLineEdit();
    pbrechercher = new QPushButton("Rechercher");
    lresponsable = new QLabel("Responsable : ");
    leresponsable = new QLineEdit();
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
    pbannuler = new QPushButton("Annuler");
    pbsauver = new QPushButton("Sauver");
    hlayout5->addWidget(pbnouveau);
    hlayout5->addWidget(pbannuler);
    hlayout5->addWidget(pbsauver);
    mainlayout->addLayout(hlayout1);
    mainlayout->addLayout(hlayout2);
    mainlayout->addLayout(hlayout3);
    mainlayout->addLayout(hlayout4);
    mainlayout->addLayout(hlayout5);
    this->setLayout(mainlayout);
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
    uv->getBranche();
    cbtc->setChecked(uv->branche[0]);
    cbhutech->setChecked(uv->branche[1]);
    cbgb->setChecked(uv->branche[2]);
    cbgi->setChecked(uv->branche[3]);
    cbgm->setChecked(uv->branche[4]);
    cbgp->setChecked(uv->branche[5]);
    cbgsm->setChecked(uv->branche[6]);
    cbgsu->setChecked(uv->branche[7]);
    pbsauver->setEnabled(false);
    pbannuler->setEnabled(false);
}

void UVWindow::sauver() {
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
    uv->getBranche();
    if (uv->branche[0]!=cbtc->isChecked()) {changeTC();}
    if (uv->branche[1]!=cbhutech->isChecked()) {changeHUTECH();}
    if (uv->branche[2]!=cbgb->isChecked()) {changeGB();}
    if (uv->branche[3]!=cbgi->isChecked()) {changeGI();}
    if (uv->branche[4]!=cbgm->isChecked()) {changeGM();}
    if (uv->branche[5]!=cbgp->isChecked()) {changeGP();}
    if (uv->branche[6]!=cbgsm->isChecked()) {changeGSM();}
    if (uv->branche[7]!=cbgsu->isChecked()) {changeGSU();}
}

void UVWindow::pbsauverEnable() {
    pbsauver->setEnabled(true);
    pbannuler->setEnabled(true);
}

void UVWindow::annuler() {
    associerUV(uv);
}

void UVWindow::rechercher() {
    QString q = "SELECT * FROM UV WHERE code = '";
    q.append(lecode->text());
    q.append("';");
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    UV *uv = sql->selectUV(q);
    associerUV(uv);
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

void NewUVWindow::nouveau_valider() {//degager la partie titre
    QString q = "INSERT INTO UV(code) VALUES ('";
    QString code = lecode->text();
    q.append(code);
    q.append("');");
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    sql->execQuery(q);
    q.clear();
    q.append("SELECT * FROM UV WHERE code = '");
    q.append(code);
    q.append("';");
    UV *uv = sql->selectUV(q);
    master->associerUV(uv);
    close();
}

void UVWindow::changeTC() {
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    if (cbhutech->isChecked()) {
        sql->execQuery(QString::fromStdString("INSERT INTO AssociationUVBranche(uv,branche) VALUES ('"+uv->getCode().toStdString()+"', 'TC');"));
    }
    else {
        sql->execQuery(QString::fromStdString("DELETE FROM AssociationUVBranche WHERE uv = '"+uv->getCode().toStdString()+"' AND branche = 'TC';"));
    }
}

void UVWindow::changeHUTECH() {
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    if (cbgb->isChecked()) {
        sql->execQuery(QString::fromStdString("INSERT INTO AssociationUVBranche(uv,branche) VALUES ('"+uv->getCode().toStdString()+"', 'HUTECH');"));
    }
    else {
        sql->execQuery(QString::fromStdString("DELETE FROM AssociationUVBranche WHERE uv = '"+uv->getCode().toStdString()+"' AND branche = 'HUTECH';"));
    }
}

void UVWindow::changeGB() {
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    if (cbgb->isChecked()) {
        sql->execQuery(QString::fromStdString("INSERT INTO AssociationUVBranche(uv,branche) VALUES ('"+uv->getCode().toStdString()+"', 'GB');"));
    }
    else {
        sql->execQuery(QString::fromStdString("DELETE FROM AssociationUVBranche WHERE uv = '"+uv->getCode().toStdString()+"' AND branche = 'GB';"));
    }
}

void UVWindow::changeGI() {
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    if (cbgi->isChecked()) {
        sql->execQuery(QString::fromStdString("INSERT INTO AssociationUVBranche(uv,branche) VALUES ('"+uv->getCode().toStdString()+"', 'GI');"));
    }
    else {
        sql->execQuery(QString::fromStdString("DELETE FROM AssociationUVBranche WHERE uv = '"+uv->getCode().toStdString()+"' AND branche = 'GI';"));
    }
}

void UVWindow::changeGM() {
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    if (cbgm->isChecked()) {
        sql->execQuery(QString::fromStdString("INSERT INTO AssociationUVBranche(uv,branche) VALUES ('"+uv->getCode().toStdString()+"', 'GM');"));
    }
    else {
        sql->execQuery(QString::fromStdString("DELETE FROM AssociationUVBranche WHERE uv = '"+uv->getCode().toStdString()+"' AND branche = 'GM';"));
    }
}

void UVWindow::changeGP() {
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    if (cbgp->isChecked()) {
        sql->execQuery(QString::fromStdString("INSERT INTO AssociationUVBranche(uv,branche) VALUES ('"+uv->getCode().toStdString()+"', 'GP');"));
    }
    else {
        sql->execQuery(QString::fromStdString("DELETE FROM AssociationUVBranche WHERE uv = '"+uv->getCode().toStdString()+"' AND branche = 'GP';"));
    }
}

void UVWindow::changeGSM() {
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    if (cbgsm->isChecked()) {
        sql->execQuery(QString::fromStdString("INSERT INTO AssociationUVBranche(uv,branche) VALUES ('"+uv->getCode().toStdString()+"', 'GSM');"));
    }
    else {
        sql->execQuery(QString::fromStdString("DELETE FROM AssociationUVBranche WHERE uv = '"+uv->getCode().toStdString()+"' AND branche = 'GSM';"));
    }
}

void UVWindow::changeGSU() {
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    if (cbgsu->isChecked()) {
        sql->execQuery(QString::fromStdString("INSERT INTO AssociationUVBranche(uv,branche) VALUES ('"+uv->getCode().toStdString()+"', 'GSU');"));
    }
    else {
        sql->execQuery(QString::fromStdString("DELETE FROM AssociationUVBranche WHERE uv = '"+uv->getCode().toStdString()+"' AND branche = 'GSU';"));
    }
}
