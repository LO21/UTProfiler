#include "UTProfiler.h"

UVWindow::UVWindow() {
    mainlayout = new QVBoxLayout();
    hlayout1 = new QHBoxLayout();
    lcode = new QLabel("Code : ");
    lecode = new QLineEdit();
    lresponsable = new QLabel("Responsable : ");
    leresponsable = new QLineEdit();
    hlayout1->addWidget(lcode);
    hlayout1->addWidget(lecode);
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
    pbannuler = new QPushButton("Annuler");
    pbsauver = new QPushButton("Sauver");
    hlayout4->addWidget(pbannuler);
    hlayout4->addWidget(pbsauver);
    mainlayout->addLayout(hlayout1);
    mainlayout->addLayout(hlayout2);
    mainlayout->addLayout(hlayout3);
    mainlayout->addLayout(hlayout4);
    this->setLayout(mainlayout);
}

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
}
