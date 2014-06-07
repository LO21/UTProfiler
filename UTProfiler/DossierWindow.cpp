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
   /* tedescription = new QTextEdit();
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
    pbannuler = new QPushButton("Annuler");
    pbsauver = new QPushButton("Sauver");
    hlayout4->addWidget(pbannuler);
    hlayout4->addWidget(pbsauver); */
    mainlayout->addLayout(hlayout1);
    mainlayout->addLayout(hlayout2);
   /* mainlayout->addLayout(hlayout2);
    mainlayout->addLayout(hlayout3);
    mainlayout->addLayout(hlayout4); */
    this->setLayout(mainlayout);
   /* QObject::connect(pbrechercher,SIGNAL(clicked()),this,SLOT(rechercher()));
    QObject::connect(pbsauver,SIGNAL(clicked()),this,SLOT(sauver()));
    QObject::connect(leresponsable,SIGNAL(textChanged(QString)),this,SLOT(pbsauverEnable()));
    QObject::connect(tedescription,SIGNAL(textChanged()),this,SLOT(pbsauverEnable()));
    QObject::connect(lecs,SIGNAL(textChanged(QString)),this,SLOT(pbsauverEnable()));
    QObject::connect(letm,SIGNAL(textChanged(QString)),this,SLOT(pbsauverEnable()));
    QObject::connect(letsh,SIGNAL(textChanged(QString)),this,SLOT(pbsauverEnable()));
    QObject::connect(lesp,SIGNAL(textChanged(QString)),this,SLOT(pbsauverEnable()));
    QObject::connect(cbprintemps,SIGNAL(stateChanged(int)),this,SLOT(pbsauverEnable()));
    QObject::connect(cbautomne,SIGNAL(stateChanged(int)),this,SLOT(pbsauverEnable())); */
}

/*
void UVWindow::associerUV(UV *uv) {
    lecode->setText(uv->getCode());
    leresponsable->setText(uv->getResponsable());
    tedescription->setText(uv->getTitre());
    lecs->setText(QString::number(uv->getCreditsCS()));
    letm->setText(QString::number(uv->getCreditsTM()));
    letsh->setText(QString::number(uv->getCreditsTSH()));
    lesp->setText(QString::number(uv->getCreditsSP()));
    cbautomne->setChecked(uv->getAutomne());
    cbprintemps->setChecked(uv->getPrintemps());
    pbsauver->setEnabled(false);
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
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    pbsauver->setEnabled(false);
    sql->execQuery(q);
}

void UVWindow::pbsauverEnable() {
    pbsauver->setEnabled(true);
}

void UVWindow::rechercher() {
    QString q = "SELECT * FROM UV WHERE code = '";
    q.append(lecode->text());
    q.append("';");
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    UV *uv = sql->selectUV(q);
    associerUV(uv);
}
*/
