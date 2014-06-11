#include "UTProfiler.h"

HomeWindow::HomeWindow() {
    sql = InterfaceSQL::getInstance();
    uvwindow = new UVWindow();
    uvwindow->associerUV(sql->selectUV("SELECT * FROM UV WHERE code = 'LO21';"));
    formationwindow = new FormationWindow();
    dossierwindow = new DossierWindow();
    mainlayout = new QVBoxLayout();
    hlayout1 = new QHBoxLayout();
    pbuv = new QPushButton("Consulter les UVs");
    pbnewuv = new QPushButton("Ajouter une UV");
    hlayout1->addWidget(pbuv);
    hlayout1->addWidget(pbnewuv);
    hlayout2 = new QHBoxLayout();
    pbformation = new QPushButton("Consulter les Formations");
    pbnewformation = new QPushButton("Ajouter une Formation");
    hlayout2->addWidget(pbformation);
    hlayout2->addWidget(pbnewformation);
    hlayout3 = new QHBoxLayout();
    pbdossier = new QPushButton("Consulter les Dossiers");
    pbnewdossier = new QPushButton("Ajouter un Dossier");
    hlayout3->addWidget(pbdossier);
    hlayout3->addWidget(pbnewdossier);
    mainlayout->addLayout(hlayout1);
    mainlayout->addLayout(hlayout2);
    mainlayout->addLayout(hlayout3);
    this->setLayout(mainlayout);
    QObject::connect(pbuv,SIGNAL(clicked()),uvwindow,SLOT(show()));
    QObject::connect(pbuv,SIGNAL(clicked()),this,SLOT(hide()));
    QObject::connect(pbnewuv,SIGNAL(clicked()),uvwindow,SLOT(show()));
    QObject::connect(pbnewuv,SIGNAL(clicked()),uvwindow,SLOT(nouveau()));
    QObject::connect(pbnewuv,SIGNAL(clicked()),this,SLOT(hide()));
    QObject::connect(pbformation,SIGNAL(clicked()),formationwindow,SLOT(show()));
    //QObject::connect(pbnewformation,SIGNAL(clicked()),formationwindow,SLOT(show()));
    QObject::connect(pbdossier,SIGNAL(clicked()),dossierwindow,SLOT(show()));
    QObject::connect(pbdossier,SIGNAL(clicked()),this,SLOT(hide()));
    //QObject::connect(pbnewdossier,SIGNAL(clicked()),formationwindow,SLOT(show()));
}