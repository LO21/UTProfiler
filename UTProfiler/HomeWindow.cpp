#include "UTProfiler.h"

HomeWindow::HomeWindow() {
    sql = InterfaceSQL::getInstance();
    setWindowTitle("UTProfiler");
    uvwindow = new UVWindow();
    //uvwindow->associerUV(sql->selectUV("SELECT * FROM UV WHERE code = 'LO21';"));
    formationwindow = new FormationWindow();
    //formationwindow->associerFormation(sql->selectFormation("SELECT * FROM Formation WHERE nom='GI';"));
    dossierwindow = new DossierWindow();
    completionprofilwindow = new CompletionProfilWindow();
    mainlayout = new QVBoxLayout();
    hlayout6 = new QHBoxLayout();
    lbienvenue = new QLabel("Bienvenue sur UTProfiler. Que souhaitez-vous faire ?");
    hlayout6->addWidget(lbienvenue);
    hlayout1 = new QHBoxLayout();
    pbuv = new QPushButton("Gestionnaire des UVs");
    pbuv->setToolTip("Le gestionnaire d'UV permet de consulter les uvs existantes, les modifier, les supprimer et en ajouter de nouvelles.");
    hlayout1->addWidget(pbuv);
    hlayout2 = new QHBoxLayout();
    pbformation = new QPushButton("Gestionnaire des Formations");
    pbformation->setToolTip("Le gestionnaire des formations permet de consulter les formations existantes, les modifier, les supprimer et en ajouter de nouvelles.");
    hlayout2->addWidget(pbformation);
    hlayout3 = new QHBoxLayout();
    pbdossier = new QPushButton("Gestionnaire des Dossiers");
    pbdossier->setToolTip("Le gestionnaire de dossiers permet de consulter les dossiers existants, les modifier, les supprimer et en ajouter de nouveaux.");
    hlayout3->addWidget(pbdossier);
    hlayout4 = new QHBoxLayout();
    pbcompletion = new QPushButton("Complétion d'un Dossier");
    pbcompletion->setToolTip("La complétion de dossier vous propose des semestres pour compléter votre profil.");
    hlayout4->addWidget(pbcompletion);
    hlayout5 = new QHBoxLayout();
    pbquitter = new QPushButton("Quitter");
    hlayout5->addWidget(pbquitter);

    mainlayout->addLayout(hlayout6);
    mainlayout->addLayout(hlayout1);
    mainlayout->addLayout(hlayout2);
    mainlayout->addLayout(hlayout3);
    mainlayout->addLayout(hlayout4);
    mainlayout->addLayout(hlayout5);

    this->setLayout(mainlayout);
    QObject::connect(pbuv,SIGNAL(clicked()),uvwindow,SLOT(show()));
    QObject::connect(pbuv,SIGNAL(clicked()),this,SLOT(hide()));
    QObject::connect(uvwindow->pbretour,SIGNAL(clicked()),this,SLOT(show()));
    QObject::connect(dossierwindow->pbretour,SIGNAL(clicked()),this,SLOT(show()));
    QObject::connect(pbformation,SIGNAL(clicked()),formationwindow,SLOT(show()));
    QObject::connect(pbformation,SIGNAL(clicked()),this,SLOT(hide()));
    QObject::connect(formationwindow->pbretour,SIGNAL(clicked()),this,SLOT(show()));
    QObject::connect(pbdossier,SIGNAL(clicked()),dossierwindow,SLOT(show()));
    QObject::connect(pbdossier,SIGNAL(clicked()),this,SLOT(hide()));
    QObject::connect(pbquitter,SIGNAL(clicked()),qApp,SLOT(quit()));
    QObject::connect(pbcompletion,SIGNAL(clicked()),this,SLOT(hide()));
    QObject::connect(pbcompletion,SIGNAL(clicked()),completionprofilwindow,SLOT(rechercher()));
    QObject::connect(completionprofilwindow->pbok,SIGNAL(clicked()),this,SLOT(show()));
    QObject::connect(completionprofilwindow->searchdossierwindow->pbannuler,SIGNAL(clicked()),this,SLOT(show()));
}
