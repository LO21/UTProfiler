#include "UTProfiler.h"

/**
 * @brief Constructeur
 * Ce constructeur initialise toutes les fonctions de l'Interface Graphique de cette fenêtre : créer et organiser les
 * objets graphiques, et les connecter avec les bons slots.
 */
CompletionProfilWindow::CompletionProfilWindow() : compteurConfirme(6) {
    searchdossierwindow = new SearchDossierWindow(this);
    mainlayout = new QVBoxLayout();
    lresultat = new QLabel("Voici les UVs que nous vous proposons : ");
    hlayout1 = new QHBoxLayout();
    luv1 = new QLabel("UV n°1 (CS) : ");
    leuv1 = new QLineEdit();
    pbconfirmer1 = new QPushButton("Confirmer");
    pbrefuser1 = new QPushButton("Refuser");
    hlayout2 = new QHBoxLayout();
    luv2 = new QLabel("UV n°2 (CS) : ");
    leuv2 = new QLineEdit();
    pbconfirmer2 = new QPushButton("Confirmer");
    pbrefuser2 = new QPushButton("Refuser");
    hlayout3 = new QHBoxLayout();
    luv3 = new QLabel("UV n°3 (TM) : ");
    leuv3 = new QLineEdit();
    pbconfirmer3 = new QPushButton("Confirmer");
    pbrefuser3 = new QPushButton("Refuser");
    hlayout4 = new QHBoxLayout();
    luv4 = new QLabel("UV n°4 (TM): ");
    leuv4 = new QLineEdit();
    pbconfirmer4 = new QPushButton("Confirmer");
    pbrefuser4 = new QPushButton("Refuser");
    hlayout5 = new QHBoxLayout();
    luv5 = new QLabel("UV n°5 (TSH) : ");
    leuv5 = new QLineEdit();
    pbconfirmer5 = new QPushButton("Confirmer");
    pbrefuser5 = new QPushButton("Refuser");
    hlayout6 = new QHBoxLayout();
    luv6 = new QLabel("UV n°6 (TSH): ");
    leuv6 = new QLineEdit();
    pbconfirmer6 = new QPushButton("Confirmer");
    pbrefuser6 = new QPushButton("Refuser");
    hlayout7 = new QHBoxLayout();
    pbok = new QPushButton("OK");
    pbenregistrer = new QPushButton("Enregistrer");
    pbenregistrer->setEnabled(false);
    hlayout1->addWidget(luv1);
    hlayout1->addWidget(leuv1);
    hlayout1->addWidget(pbconfirmer1);
    hlayout1->addWidget(pbrefuser1);
    hlayout2->addWidget(luv2);
    hlayout2->addWidget(leuv2);
    hlayout2->addWidget(pbconfirmer2);
    hlayout2->addWidget(pbrefuser2);
    hlayout3->addWidget(luv3);
    hlayout3->addWidget(leuv3);
    hlayout3->addWidget(pbconfirmer3);
    hlayout3->addWidget(pbrefuser3);
    hlayout4->addWidget(luv4);
    hlayout4->addWidget(leuv4);
    hlayout4->addWidget(pbconfirmer4);
    hlayout4->addWidget(pbrefuser4);
    hlayout5->addWidget(luv5);
    hlayout5->addWidget(leuv5);
    hlayout5->addWidget(pbconfirmer5);
    hlayout5->addWidget(pbrefuser5);
    hlayout6->addWidget(luv6);
    hlayout6->addWidget(leuv6);
    hlayout6->addWidget(pbconfirmer6);
    hlayout6->addWidget(pbrefuser6);
    hlayout7->addWidget(pbok);
    hlayout7->addWidget(pbenregistrer);
    mainlayout->addWidget(lresultat);
    mainlayout->addLayout(hlayout1);
    mainlayout->addLayout(hlayout2);
    mainlayout->addLayout(hlayout3);
    mainlayout->addLayout(hlayout4);
    mainlayout->addLayout(hlayout5);
    mainlayout->addLayout(hlayout6);
    mainlayout->addLayout(hlayout7);
    setLayout(mainlayout);
    QObject::connect(pbrefuser1,SIGNAL(clicked()),this,SLOT(refuser1()));
    QObject::connect(pbrefuser2,SIGNAL(clicked()),this,SLOT(refuser2()));
    QObject::connect(pbrefuser3,SIGNAL(clicked()),this,SLOT(refuser3()));
    QObject::connect(pbrefuser4,SIGNAL(clicked()),this,SLOT(refuser4()));
    QObject::connect(pbrefuser5,SIGNAL(clicked()),this,SLOT(refuser5()));
    QObject::connect(pbrefuser6,SIGNAL(clicked()),this,SLOT(refuser6()));
    QObject::connect(pbconfirmer1,SIGNAL(clicked()),this,SLOT(confirmer1()));
    QObject::connect(pbconfirmer2,SIGNAL(clicked()),this,SLOT(confirmer2()));
    QObject::connect(pbconfirmer3,SIGNAL(clicked()),this,SLOT(confirmer3()));
    QObject::connect(pbconfirmer4,SIGNAL(clicked()),this,SLOT(confirmer4()));
    QObject::connect(pbconfirmer5,SIGNAL(clicked()),this,SLOT(confirmer5()));
    QObject::connect(pbconfirmer6,SIGNAL(clicked()),this,SLOT(confirmer6()));
    QObject::connect(pbok,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(pbenregistrer,SIGNAL(clicked()),this,SLOT(enregistrer()));
}

/**
 * @brief Algorithme de Completion de Profil
 *
 * Cette méthode est l'algorithme de completion de profil. S'il devait être modifié, il n'y aurait que cette méthode à changer.
 * Il cherche et récupère 2 CS, 2 TM et 2 TSH diplomantes selon la branche et disponible au prochain semestre et se charge de
 * les afficher dans la fenetre, en tenant compte des souhaits et des rejets de l'utilisateur
 * @param dossier : Etudiant dont le profil est à compléter
 * @param souhaits : Liste des UVs souhaitées par l'étudiant pour le prochain semestre
 * @param rejets : Liste des UVs non souhaitées par l'étudiant pour le prochain semestre
 */
void CompletionProfilWindow::CompletionProfil(Dossier *dossier, QString **souhaits, QString **rejets) {
    UV** res = new UV*[6];
    UV *test;
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    UV** uvsNonValidees = sql->getAllUvs(QString::fromStdString("SELECT * FROM UV,AssociationFormationUV A WHERE A.formation = '"+dossier->getBranche().toStdString()+"' AND A.uv=UV.code AND UV.code NOT IN (SELECT code FROM UV,Inscription WHERE Inscription.login = '"+dossier->getLogin().toStdString()+"' AND Inscription.uv=UV.code);"));
    Semestre *semestre = sql->selectSemestre(QString::fromStdString("SELECT * FROM Semestre WHERE dossier='"+dossier->getLogin().toStdString()+"' ORDER BY annee DESC, saison DESC;"));
    Saison saison;
    semestre->getSaison()==Saison(Printemps)?saison=Saison(Automne):saison=Saison(Printemps);
    unsigned int i=0,compteurCS=0,compteurTM=0,compteurTSH=0,compteurSouhaits=0,compteurRejet=0;
    bool rejet;
    while ((compteurCS<2 || compteurTM<2 || compteurTSH<2) && souhaits[compteurSouhaits]->toStdString()!="fin") {
        test=sql->selectUV(QString::fromStdString("SELECT * FROM UV WHERE code = '"+souhaits[compteurSouhaits++]->toStdString()+"';"));
        if (test->getCreditsCS()>0 && compteurCS<2) {res[compteurCS++] = test; compteurCS==1?pbrefuser1->setEnabled(false):pbrefuser2->setEnabled(false);}
        else if (test->getCreditsTM()>0 && compteurTM<2) {res[2+compteurTM++] = test; compteurTM==1?pbrefuser3->setEnabled(false):pbrefuser4->setEnabled(false);}
        else if (test->getCreditsTSH()>0 && compteurTSH<2) {res[4+compteurTSH++] = test; compteurTSH==1?pbrefuser5->setEnabled(false):pbrefuser6->setEnabled(false);}
    }
    while ((compteurCS<2 || compteurTM<2) && uvsNonValidees[i]->getCode().toStdString()!="fin") {
        rejet=false;
        compteurRejet=0;
        while (rejet==false && rejets[compteurRejet]->toStdString()!="fin") {if (uvsNonValidees[i]->getCode().toStdString()==rejets[compteurRejet++]->toStdString()) {rejet=true;} }
        if (!rejet) {
            if (saison==Saison(Printemps)) {
                if (uvsNonValidees[i]->getPrintemps()) {
                    if (uvsNonValidees[i]->getCreditsCS()>0 && compteurCS<2) {res[compteurCS++] = uvsNonValidees[i];}
                    else if (uvsNonValidees[i]->getCreditsTM()>0 && compteurTM<2) {res[2+compteurTM++] = uvsNonValidees[i];}
                }
            }
            else {
                if (uvsNonValidees[i]->getAutomne()) {
                    if (uvsNonValidees[i]->getCreditsCS()>0 && compteurCS<2) {res[compteurCS++] = uvsNonValidees[i];}
                    else if (uvsNonValidees[i]->getCreditsTM()>0 && compteurTM<2) {res[2+compteurTM++] = uvsNonValidees[i];}
                }
            }
        }
        i++;
    }
    uvsNonValidees = sql->getAllUvs(QString::fromStdString("SELECT * FROM UV WHERE creditsTSH>0 AND code NOT IN (SELECT code FROM UV,Inscription WHERE Inscription.login = '"+dossier->getLogin().toStdString()+"' AND Inscription.uv=UV.code);"));
    i=0;
    while (compteurTSH<2 && uvsNonValidees[i]->getCode().toStdString()!="fin") {
        rejet=false;
        compteurRejet=0;
        while (rejet==false && rejets[compteurRejet]->toStdString()!="fin") {if (uvsNonValidees[i]->getCode().toStdString()==rejets[compteurRejet++]->toStdString()) {rejet=true;} }
        if (!rejet) {
            if (saison==Saison(Printemps)) {
                if (uvsNonValidees[i]->getPrintemps()) {res[4+compteurTSH++] = uvsNonValidees[i];}
                }
            else {
                if (uvsNonValidees[i]->getAutomne()) {res[4+compteurTSH++] = uvsNonValidees[i];}
            }
        }
        i++;
    }
    compteurCS>0?leuv1->setText(res[0]->getCode()):leuv1->setText("Aucune CS disponible");
    compteurCS>1?leuv2->setText(res[1]->getCode()):leuv2->setText("Aucune CS disponible");
    compteurTM>0?leuv3->setText(res[2]->getCode()):leuv3->setText("Aucune TM disponible");
    compteurTM>1?leuv4->setText(res[3]->getCode()):leuv4->setText("Aucune TM disponible");
    compteurTSH>0?leuv5->setText(res[4]->getCode()):leuv5->setText("Aucune TSH disponible");
    compteurTSH>1?leuv6->setText(res[5]->getCode()):leuv6->setText("Aucune TSH disponible");
}

/**
 * @brief Slot ouvrant la fenetre de recherche de dossier
 */
void CompletionProfilWindow::rechercher() {
    compteurConfirme=6;
    pbconfirmer1->setEnabled(true);
    pbrefuser1->setEnabled(true);
    pbconfirmer2->setEnabled(true);
    pbrefuser2->setEnabled(true);
    pbconfirmer3->setEnabled(true);
    pbrefuser3->setEnabled(true);
    pbconfirmer4->setEnabled(true);
    pbrefuser4->setEnabled(true);
    pbconfirmer5->setEnabled(true);
    pbrefuser5->setEnabled(true);
    pbconfirmer6->setEnabled(true);
    pbrefuser6->setEnabled(true);
    searchdossierwindow->show();
    hide();
}

/**
 * @brief Constructeur
 * Ce constructeur initialise toutes les fonctions de l'Interface Graphique de cette fenêtre : créer et organiser les
 * objets graphiques, et les connecter avec les bons slots.
 * @param fw : pointeur vers la classe CompletionProfilWindow qui gère son cycle de vie
 */
SearchDossierWindow::SearchDossierWindow(CompletionProfilWindow *fw) : master(fw) {
    mainlayout = new QVBoxLayout();
    hlayout1 = new QHBoxLayout();
    lnom = new QLabel("Login : ");
    lenom = new QComboBox();
    QString qu="SELECT * FROM Dossier;";
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    QSqlQuery query = sql->execQuery(qu);
    QStringList res;
    while(query.next()){res<<query.value(0).toString();}
    lenom->addItems(res);
    hlayout1->addWidget(lnom);
    hlayout1->addWidget(lenom);
    hlayout2 = new QHBoxLayout();
    lsouhaits = new QLabel("Souhaitées (espace entre les UVs) : ");
    lesouhaits = new QLineEdit();
    hlayout2->addWidget(lsouhaits);
    hlayout2->addWidget(lesouhaits);
    hlayout3 = new QHBoxLayout();
    lrejets = new QLabel("Non Souhaitées (espace entre les UVs) : ");
    lerejets = new QLineEdit();
    hlayout3->addWidget(lrejets);
    hlayout3->addWidget(lerejets);
    hlayout4 = new QHBoxLayout();
    pbannuler = new QPushButton("Annuler");
    pbretrouver = new QPushButton("Retrouver");
    pbrechercher = new QPushButton("Rechercher");
    hlayout4->addWidget(pbannuler);
    hlayout4->addWidget(pbretrouver);
    hlayout4->addWidget(pbrechercher);
    mainlayout->addLayout(hlayout1);
    mainlayout->addLayout(hlayout2);
    mainlayout->addLayout(hlayout3);
    mainlayout->addLayout(hlayout4);
    setLayout(mainlayout);
    QObject::connect(pbannuler,SIGNAL(clicked()),this,SLOT(annuler()));
    QObject::connect(pbretrouver,SIGNAL(clicked()),this,SLOT(retrouver()));
    QObject::connect(pbrechercher,SIGNAL(clicked()),this,SLOT(rechercher()));
}

/**
 * @brief Slot permettant de revenir à l'écran précédent
 */
void SearchDossierWindow::annuler() {
    master->close();
    close();
}

/**
 * @brief Slot permettant de rechercher un dossier dans la base de données
 */
void SearchDossierWindow::rechercher() {
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    dossier = sql->selectDossier(QString::fromStdString("SELECT * FROM Dossier WHERE login = '"+lenom->currentText().toStdString()+"';"));
    unsigned int i=0,j=0;
    souhaits = new QString*[20];
    souhaits[0] = new QString;
    QString sparse = lesouhaits->text();
    while (sparse[i]!='\0') {
        if (sparse[i]==' ') {souhaits[++j] = new QString;}
        else {souhaits[j]->append(sparse[i]);}
        ++i;
    }
    if (i==0) {souhaits[0]->append(QString::fromStdString("fin"));}
    else {souhaits[++j] = new QString("fin");}
    i=0;
    j=0;
    rejets = new QString*[20];
    rejets[0] = new QString;
    QString rparse = lerejets->text();
    while (rparse[i]!='\0') {
        if (rparse[i]==' ') {rejets[++j] = new QString;}
        else {rejets[j]->append(rparse[i]);}
        ++i;
    }

    if (i==0) {rejets[0]->append(QString::fromStdString("fin"));}
    else {rejets[++j] = new QString("fin");}
    master->CompletionProfil(dossier,souhaits,rejets);
    master->show();
    close();
}

/**
 * @brief Slot permettant de valider une UV parmi les suggestions
 */
void CompletionProfilWindow::confirmer1() {
    pbconfirmer1->setEnabled(false);
    pbrefuser1->setEnabled(false);
    compteurConfirme--;
    if (compteurConfirme==0) {pbenregistrer->setEnabled(true);}
}

/**
 * @brief Slot permettant de valider une UV parmi les suggestions
 */
void CompletionProfilWindow::confirmer2() {
    pbconfirmer2->setEnabled(false);
    pbrefuser2->setEnabled(false);
    compteurConfirme--;
    if (compteurConfirme==0) {pbenregistrer->setEnabled(true);}
}

/**
 * @brief Slot permettant de valider une UV parmi les suggestions
 */
void CompletionProfilWindow::confirmer3() {
    pbconfirmer3->setEnabled(false);
    pbrefuser3->setEnabled(false);
    compteurConfirme--;
    if (compteurConfirme==0) {pbenregistrer->setEnabled(true);}
}

/**
 * @brief Slot permettant de valider une UV parmi les suggestions
 */
void CompletionProfilWindow::confirmer4() {
    pbconfirmer4->setEnabled(false);
    pbrefuser4->setEnabled(false);
    compteurConfirme--;
    if (compteurConfirme==0) {pbenregistrer->setEnabled(true);}
}

void CompletionProfilWindow::confirmer5() {
    pbconfirmer5->setEnabled(false);
    pbrefuser5->setEnabled(false);
    compteurConfirme--;
    if (compteurConfirme==0) {pbenregistrer->setEnabled(true);}
}

/**
 * @brief Slot permettant de valider une UV parmi les suggestions
 */
void CompletionProfilWindow::confirmer6() {
    pbconfirmer6->setEnabled(false);
    pbrefuser6->setEnabled(false);
    compteurConfirme--;
    if (compteurConfirme==0) {pbenregistrer->setEnabled(true);}
}

/**
 * @brief Slot permettant de refuser une UV parmi les suggestions, et de demander à l'algorithme d'en proposer une autre à la place
 */
void CompletionProfilWindow::refuser1() {
    unsigned int i=0;
    while (searchdossierwindow->rejets[i]->toStdString()!="fin") {++i;}
    *searchdossierwindow->rejets[i]=leuv1->text();
    searchdossierwindow->rejets[++i] = new QString("fin");
    CompletionProfil(searchdossierwindow->dossier,searchdossierwindow->souhaits,searchdossierwindow->rejets);
}

/**
 * @brief Slot permettant de refuser une UV parmi les suggestions, et de demander à l'algorithme d'en proposer une autre à la place
 */
void CompletionProfilWindow::refuser2() {
    unsigned int i=0;
    while (searchdossierwindow->rejets[i]->toStdString()!="fin") {++i;}
    *searchdossierwindow->rejets[i]=leuv2->text();
    searchdossierwindow->rejets[++i] = new QString("fin");
    CompletionProfil(searchdossierwindow->dossier,searchdossierwindow->souhaits,searchdossierwindow->rejets);
}

/**
 * @brief Slot permettant de refuser une UV parmi les suggestions, et de demander à l'algorithme d'en proposer une autre à la place
 */
void CompletionProfilWindow::refuser3() {
    unsigned int i=0;
    while (searchdossierwindow->rejets[i]->toStdString()!="fin") {++i;}
    *searchdossierwindow->rejets[i]=leuv3->text();
    searchdossierwindow->rejets[++i] = new QString("fin");
    CompletionProfil(searchdossierwindow->dossier,searchdossierwindow->souhaits,searchdossierwindow->rejets);
}

/**
 * @brief Slot permettant de refuser une UV parmi les suggestions, et de demander à l'algorithme d'en proposer une autre à la place
 */
void CompletionProfilWindow::refuser4() {
    unsigned int i=0;
    while (searchdossierwindow->rejets[i]->toStdString()!="fin") {++i;}
    *searchdossierwindow->rejets[i]=leuv4->text();
    searchdossierwindow->rejets[++i] = new QString("fin");
    CompletionProfil(searchdossierwindow->dossier,searchdossierwindow->souhaits,searchdossierwindow->rejets);
}

/**
 * @brief Slot permettant de refuser une UV parmi les suggestions, et de demander à l'algorithme d'en proposer une autre à la place
 */
void CompletionProfilWindow::refuser5() {
    unsigned int i=0;
    while (searchdossierwindow->rejets[i]->toStdString()!="fin") {++i;}
    *searchdossierwindow->rejets[i]=leuv5->text();
    searchdossierwindow->rejets[++i] = new QString("fin");
    CompletionProfil(searchdossierwindow->dossier,searchdossierwindow->souhaits,searchdossierwindow->rejets);
}

/**
 * @brief Slot permettant de refuser une UV parmi les suggestions, et de demander à l'algorithme d'en proposer une autre à la place
 */
void CompletionProfilWindow::refuser6() {
    unsigned int i=0;
    while (searchdossierwindow->rejets[i]->toStdString()!="fin") {++i;}
    *searchdossierwindow->rejets[i]=leuv6->text();
    searchdossierwindow->rejets[++i] = new QString("fin");
    CompletionProfil(searchdossierwindow->dossier,searchdossierwindow->souhaits,searchdossierwindow->rejets);
}

/**
 * @brief Slot permettant d'enregistrer une completion dont toutes les UVs sont confirmées dans la base de données pour qu'elle puisse être reconsultée plus tard
 */
void CompletionProfilWindow::enregistrer() {
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    QString q=QString::fromStdString("INSERT INTO CompletionProfil VALUES (");
    q.append(QString::number((long int)&compteurConfirme*(rand()%500)));
    q.append(", '");
    q.append(searchdossierwindow->dossier->getLogin());
    q.append("', '");
    q.append(leuv1->text());
    q.append("', '");
    q.append(leuv2->text());
    q.append("', '");
    q.append(leuv3->text());
    q.append("', '");
    q.append(leuv4->text());
    q.append("', '");
    q.append(leuv5->text());
    q.append("', '");
    q.append(leuv6->text());
    q.append("');");
    sql->execQuery(q);
    pbenregistrer->setEnabled(false);
}

/**
 * @brief Slot permettant d'ouvrir la fenêtre de consultation des completions de profil enrigistrées après avoir séléctionné un dossier
 */
void SearchDossierWindow::retrouver() {
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    QString ***completions = sql->selectCompletion(QString::fromStdString("SELECT * FROM CompletionProfil WHERE dossier ='"+lenom->currentText().toStdString()+"';"));
    retrouvercompletionwindow = new RetrouverCompletionWindow(completions);
    QObject::connect(retrouvercompletionwindow->pbfermer,SIGNAL(clicked()),this,SLOT(show()));
    retrouvercompletionwindow->show();
    hide();
}

/**
 * @brief Constructeur
 * Ce constructeur initialise toutes les fonctions de l'Interface Graphique de cette fenêtre : créer et organiser les
 * objets graphiques, et les connecter avec les bons slots.
 * De plus, il remplit automatiquement les champs grâce au tableau passé en paramètre
 * @param c : tableau des différentes complétions enregistrées
 */
RetrouverCompletionWindow::RetrouverCompletionWindow(QString ***c) : completions(c), indice(0) {
    mainlayout = new QVBoxLayout();
    lresultat = new QLabel("Voici les UVs que nous vous proposons : ");
    hlayout1 = new QHBoxLayout();
    luv1 = new QLabel("UV n°1 (CS) : ");
    leuv1 = new QLineEdit();
    hlayout2 = new QHBoxLayout();
    luv2 = new QLabel("UV n°2 (CS) : ");
    leuv2 = new QLineEdit();
    hlayout3 = new QHBoxLayout();
    luv3 = new QLabel("UV n°3 (TM) : ");
    leuv3 = new QLineEdit();
    hlayout4 = new QHBoxLayout();
    luv4 = new QLabel("UV n°4 (TM): ");
    leuv4 = new QLineEdit();
    hlayout5 = new QHBoxLayout();
    luv5 = new QLabel("UV n°5 (TSH) : ");
    leuv5 = new QLineEdit();
    hlayout6 = new QHBoxLayout();
    luv6 = new QLabel("UV n°6 (TSH): ");
    leuv6 = new QLineEdit();
    hlayout7 = new QHBoxLayout();
    pbprecedent = new QPushButton("Précédent");
    pbprecedent->setEnabled(false);
    pbfermer = new QPushButton("Fermer");
    pbsuivant = new QPushButton("Suivant");
    if (completions[indice+1][0]->toStdString()=="fin") {pbsuivant->setEnabled(false);}
    hlayout1->addWidget(luv1);
    hlayout1->addWidget(leuv1);
    hlayout2->addWidget(luv2);
    hlayout2->addWidget(leuv2);
    hlayout3->addWidget(luv3);
    hlayout3->addWidget(leuv3);
    hlayout4->addWidget(luv4);
    hlayout4->addWidget(leuv4);
    hlayout5->addWidget(luv5);
    hlayout5->addWidget(leuv5);
    hlayout6->addWidget(luv6);
    hlayout6->addWidget(leuv6);
    hlayout7->addWidget(pbprecedent);
    hlayout7->addWidget(pbfermer);
    hlayout7->addWidget(pbsuivant);
    mainlayout->addWidget(lresultat);
    mainlayout->addLayout(hlayout1);
    mainlayout->addLayout(hlayout2);
    mainlayout->addLayout(hlayout3);
    mainlayout->addLayout(hlayout4);
    mainlayout->addLayout(hlayout5);
    mainlayout->addLayout(hlayout6);
    mainlayout->addLayout(hlayout7);
    setLayout(mainlayout);
    associercompletion(completions[0]);
    QObject::connect(pbprecedent,SIGNAL(clicked()),this,SLOT(precedent()));
    QObject::connect(pbfermer,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(pbsuivant,SIGNAL(clicked()),this,SLOT(suivant()));
}

/**
 * @brief Slot permettant de naviguer entre les completions de profil sauvegardées
 */
void RetrouverCompletionWindow::precedent() {
    pbsuivant->setEnabled(true);
    indice--;
    associercompletion(completions[indice]);
    if (indice==0) {pbprecedent->setEnabled(false);}
}

/**
 * @brief Slot permettant de naviguer entre les completions de profil sauvegardées
 */
void RetrouverCompletionWindow::suivant() {
    pbprecedent->setEnabled(true);
    indice++;
    associercompletion(completions[indice]);
    if (completions[indice+1][0]->toStdString()=="fin") {pbsuivant->setEnabled(false);}
}

/**
 * @brief Méthode permettant de remplir les champs texte avec une completion de profil
 * @param completion : tableau contenant les QString à distribuer dans les champs texte
 */
void RetrouverCompletionWindow::associercompletion(QString **completion) {
    if (completion[0]->toStdString()!="fin") {
        leuv1->setText(*completion[1]);
        leuv2->setText(*completion[2]);
        leuv3->setText(*completion[3]);
        leuv4->setText(*completion[4]);
        leuv5->setText(*completion[5]);
        leuv6->setText(*completion[6]);
    }

}
