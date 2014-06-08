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

    // J'aimerais ajouter ici les formations extérieures déjà disponibles avec une requete en SELECT

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

    // Afficher ici les semestres sous forme de tableau avec les UV et les notes obtenues

    hlayout7 = new QHBoxLayout();
    pbannuler = new QPushButton("Annuler");
    pbsauver = new QPushButton("Sauver");
    hlayout7->addWidget(pbannuler);
    hlayout7->addWidget(pbsauver);

    mainlayout->addLayout(hlayout1);
    mainlayout->addLayout(hlayout2);
    mainlayout->addLayout(hlayout3);
    mainlayout->addLayout(hlayout8);
    mainlayout->addLayout(hlayout9);
    mainlayout->addLayout(hlayout6);
    mainlayout->addLayout(hlayout4);
    mainlayout->addLayout(hlayout5);
    mainlayout->addLayout(hlayout7);
    this->setLayout(mainlayout);

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
}


void DossierWindow::sauver() {
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
    pbsauver->setEnabled(false);
    sql->execQuery(q);
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
    pbsauver->setEnabled(false);
}

void DossierWindow::rechercher() {
    QString q = "SELECT * FROM Dossier WHERE login = '";
    q.append(lelogin->text());
    q.append("';");
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    Dossier *d = sql->selectDossier(q);
    associerDossier(d);
}

