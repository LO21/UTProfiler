#ifndef UTPROFILER_H
#define UTPROFILER_H

/**
 * \file UTProfiler.h
 * \brief Ce header recense les déclarations de toutes nos classes.
 * \author Gabrielle Rit Timothée Monceaux
 * \version 0.1
 */

#include <iostream>
#include <string>
#include <QString>
#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QCheckBox>
#include <QtSql>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QProgressBar>
#include <QRadioButton>
#include <QDebug>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QSqlDriver>
#include <QComboBox>
#include <QToolTip>

using namespace std;

/**
 * \enum Saison
 * \brief Recense les deux différents semestres d'une année à l'UTC : Printemps et Automne.
 */
enum Saison {
    Printemps,
    Automne
};

/**
 * \enum Resultat
 * \brief Recense les différents statuts possibles quant à la validation d'une UV : de A à F, En Cours, ou Réservé.
 */
enum Resultat {
    //Mention
    A,
    //Admis
    B,
    C,
    D,
    E,
    //Insuffisant
    FX,
    F,
    //Reserve
    RES,
    //En Cours
    EC
};

/**
 * \enum Categorie
 * \brief Recense les 4 Catégories d'UV : CS, TM, TSH et SP.
 */
enum Categorie {
    //Connaissances Scientifiques
    CS,
    //Techniques et Méthodes
    TM,
    //Technologie et Sciences Humaines
    TSH,
    //Stages et Projets
    SP
};
/**
 * \class UTProfilerException
 * \brief Classe permettant de gérer l'ensemble des exceptions de l'application
 *
 * Cette classe reçoit un message en paramètre du constructeur, qu'elle affiche dans une QMsgBox pour informer l'utilisateur quant à l'exception soulevée.
 */
class UTProfilerException {
    QString msg;
   public :
    /**
     * \brief Constructeur
     * Constructeur de la classe UTProfilerException, il crée une QMsgBox avec le message passé en paramètre
     * \param s : Le message à afficher
     */
    UTProfilerException(const QString& s);
    /**
     * \brief Destructeur
     * Destructeur de la classe UTProfilerException
     */
    ~UTProfilerException() {}
};

/**
 * \class UV
 * \brief Classe permettant de décrire une des UVs de l'UTC.
 *
 * Cette classe permet de garder temporairement en mémoire l'ensemble des attributs d'une UV et de les manipuler facilement. Cependant, un objet de cette classe n'est que temporaire, puisque toutes nos UVs sont stockées dans notre Base de Données.
 */
class UV {
    QString *code; /**< Code de l'UV*/
    QString *titre; /**< Description de l'UV*/
    QString *responsable; /**< Nom du responsable de l'UV*/
    unsigned int creditsCS; /**< Nombre de crédits CS que rapporte cette UV*/
    unsigned int creditsTM; /**< Nombre de crédits TM que rapporte cette UV*/
    unsigned int creditsTSH; /**< Nombre de crédits TSH que rapporte cette UV*/
    unsigned int creditsSP; /**< Nombre de crédits SP que rapporte cette UV*/
    bool printemps; /**< Indique si l'UV est disponible au printemps ou non*/
    bool automne; /**< Indique si l'UV est disponible en automne ou non*/
    bool *branche; /**< Tableau de booléens facilitant la manipulation des formations dans lesquelles cette UV est diplomante*/
   public :
    /**
     * \brief Constructeur par recopie
     * Permet de créer une nouvelle UV qui soit la copie d'une UV existante
     * \param other : référence vers une UV qui existe déjà
     */
    UV& operator=(UV& other) {code=new QString(other.getCode());titre=new QString(other.getTitre());responsable=new QString(other.getResponsable());creditsCS=other.getCreditsCS();creditsTM=other.getCreditsTM();creditsTSH=other.getCreditsTSH();creditsSP=other.creditsSP;printemps=other.getPrintemps();automne=other.getAutomne();return *this;}
    /**
     * \brief Constructeur
     * Permet de créer une nouvelle UV
     * \param c : Code de la nouvelle UV
     * \param t : Description de la nouvelle UV
     * \param r : Nom du responsable de la nouvelle UV
     * \param cs : Nombre de crédits CS de la nouvelle UV
     * \param tm : Nombre de crédits TM de la nouvelle UV
     * \param tsh : Nombre de crédits TSH de la nouvelle UV
     * \param sp : Nombre de crédits SP de la nouvelle UV
     * \param p : Disponibilité au printemps de la nouvelle UV
     * \param a : Disponibilité à l'automne de la nouvelle UV
     */
    UV(const QString& c, const QString& t, const QString& r,unsigned int cs, unsigned int tm, unsigned int tsh, unsigned int sp, bool p, bool a) : creditsCS(cs), creditsTM(tm), creditsTSH(tsh), creditsSP(sp), printemps(p), automne(a) {code = new QString(c); titre = new QString(t); responsable = new QString(r); branche = new bool[8];}
    /**
     * \brief Constructeur Vide
     * Permet de créer un objet UV non initialisé
     */
    UV() : creditsCS(0), creditsTM(0), creditsTSH(0), creditsSP(0), printemps(false), automne(false) {code = new QString(""); titre = new QString(""); responsable = new QString(""); branche = new bool[8];}
    /**
     * \brief Destructeur
     */
    ~UV() {delete branche;}
    /**
     * \brief Accesseur en lecture pour le code de l'UV
     * \return Le code de l'UV
     */
    QString getCode() const {return *code;}
    /**
     * \brief Accesseur en lecture pour la description de l'UV
     * \return La description de l'UV
     */
    QString getTitre() const {return *titre;}
    /**
     * \brief Accesseur en lecture pour le responsable de l'UV
     * \return Le nom du responsable de l'UV
     */
    QString getResponsable() const {return *responsable;}
    /**
     * \brief Accesseur en lecture pour le nombre de crédits CS de l'UV
     * \return Le nombre de credits CS que permet de valider cette UV
     */
    unsigned int getCreditsCS() const {return creditsCS;}
    /**
     * \brief Accesseur en lecture pour le nombre de crédits TM de l'UV
     * \return Le nombre de credits TM que permet de valider cette UV
     */
    unsigned int getCreditsTM() const {return creditsTM;}
    /**
     * \brief Accesseur en lecture pour le nombre de crédits TSH de l'UV
     * \return Le nombre de credits TSH que permet de valider cette UV
     */
    unsigned int getCreditsTSH() const {return creditsTSH;}
    /**
     * \brief Accesseur en lecture pour le nombre de crédits SP de l'UV
     * \return Le nombre de credits SP que permet de valider cette UV
     */
    unsigned int getCreditsSP() const {return creditsSP;}
    /**
     * \brief Accesseur en lecture pour la disponibilité au printemps de l'UV
     * \return True si l'UV est disponible au printemps, false sinon
     */
    bool getPrintemps() const {return printemps;}
    /**
     * \brief Accesseur en lecture pour la disponibilité à l'automne de l'UV
     * \return True si l'UV est disponible à l'automne, false sinon
     */
    bool getAutomne() const {return automne;}
    /**
     * \brief Accesseur en écriture pour le code de l'UV
     * \param s : nouveau code de l'UV
     */
    void setCode(QString *s) {code=s;}
    /**
     * \brief Accesseur en écriture de la description de l'UV
     * \param s : nouvelle description de l'UV
     */
    void setTitre(QString *s) {titre=s;}
    /**
     * \brief Accesseur en écriture du nom du responsable de l'UV
     * \param s : nouvau responsable de l'UV
     */
    void setResponsable(QString *s) {responsable=s;}
    /**
     * \brief Accesseur en écriture du nombre de crédits CS que permet de valider cette UV
     * \param cs : nouveau nombre de credits CS de l'UV
     */
    void setCreditsCS(unsigned int cs) {creditsCS=cs;}
    /**
     * \brief Accesseur en écriture du nombre de crédits TM que permet de valider cette UV
     * \param tm : nouveau nombre de credits TM de l'UV
     */
    void setCreditsTM(unsigned int tm) {creditsTM=tm;}
    /**
     * \brief Accesseur en écriture du nombre de crédits TSH que permet de valider cette UV
     * \param tsh : nouveau nombre de credits TSH de l'UV
     */
    void setCreditsTSH(unsigned int tsh) {creditsTSH=tsh;}
    /**
     * \brief Accesseur en écriture du nombre de crédits SP que permet de valider cette UV
     * \param sp : nouveau nombre de credits SP de l'UV
     */
    void setxCreditsSP(unsigned int sp) {creditsSP=sp;}
    /**
     * \brief Accesseur en écriture de la disponibilité au printemps de cette UV
     * \param b : nouvelle disponibilité au printemps de l'UV
     */
    void setPrintemps (bool b) {printemps=b;}
    /**
     * \brief Accesseur en écriture de la disponibilité à l'automne de cette UV
     * \param b : nouvelle disponibilité à l'automne de l'UV
     */
    void setAutomne (bool b) {automne=b;}
    /**
     * \brief Interroge la base de données et complète dynamiquement le tableau de booléens branches en fonction des formations dans laquelle cette UV est diplomante
     * \return Le tableau de booléens complété dynamiquement.
     */
    bool* getBranche();
    /**
     * \brief Teste l'égalité entre tous les champs de deux UVs
     * \param other : l'autre UV
     * \return false si au moins un des deux champs diffère entre les deux UVs, true sinon
     */
    bool operator!=(UV& other);
};

/**
 * \class Inscription
 * \brief Classe permettant de décrire l'inscription d'un étudiant à une UV de l'UTC.
 *
 * Cette classe permet de garder temporairement en mémoire l'inscription d'un étudiant à une UV. Cependant, un objet de cette classe n'est que temporaire, puisque toutes nos Inscriptions sont stockées dans notre Base de Données.
 */
class Inscription {
    string uv; /**< L'UV auquel l'étudiant est inscrit*/
    Resultat resultat; /**< Le statut de la validation de l'UV par l'étudiant*/
    string login; /**< Le login de l'étudiant*/
   public :
    /**
     * \brief Constructeur vide
     * Crée un nouvel objet Inscription non initialisé
     */
    Inscription();
    /**
     * \brief Destructeur
     */
    ~Inscription();
    /**
     * \brief Accesseur en lecture pour le code de l'UV auquel l'étudiant est inscrit
     * \return Le code de l'UV en question
     */
    string getUV() const {return uv;}
    /**
     * \brief Accesseur en lecture pour le statut de la validation de l'UV par l'étudiant
     * \return Le statut de la validation de cette UV
     */
    Resultat getResultat() const {return resultat;}
    /**
     * \brief Accesseur en lecture pour le login de l'étudiant
     * \return Le login de l'étudiant en question
     */
    string getLogin() const {return login;}
    /**
     * \brief Accesseur en écriture pour le code de l'UV dont il est question
     * \param s : Le nouveau code de l'UV
     */
    void setUv (const string& s) {uv=s;}
    /**
     * \brief Accesseur en écriture pour le statut de la validation de l'UV en question
     * \param r : Le nouveau statut
     */
    void setResultat(Resultat& r) {resultat=r;}
    /**
     * \brief Accesseur en écriture pour le login de l'étudiant concerné
     * \param l : le login du nouvel étudiant lié à cette inscription
     */
    void setLogin(const string& l) {login=l;}
};

/**
 * \class FormationExterieure
 * \brief Classe permettant de décrire une formation extérieure à l'UTC mais rapportant un certain nombre de crédits par équivalence.
 *
 * Cette classe permet de garder temporairement en mémoire une formation d'un étudiant à l'extérieur de l'UTC. Cependant, un objet de cette classe n'est que temporaire, puisque toutes nos FormationsExterieures sont stockées dans notre Base de Données.
 */
class FormationExterieure {
    string nom; /**< Le nom de cette formation*/
    string lieu; /**< Le lieu où l'étudiant a suivi cette formation*/
    unsigned int creditsCS; /**< Le nombre de credits CS que cette formation lui a rapporté par équivalence*/
    unsigned int creditsTM; /**< Le nombre de credits TM que cette formation lui a rapporté par équivalence*/
    unsigned int creditsTSH; /**< Le nombre de credits TSH que cette formation lui a rapporté par équivalence*/
    unsigned int creditsSP; /**< Le nombre de credits SP que cette formation lui a rapporté par équivalence*/
   public :
    /**
     * @brief Constructeur
     * Permet de créer un nouvel objet FormationExterieure initialisé avec les valeurs passés en paramètre
     * @param n : le nom de cette nouvelle formation
     * @param l : le lieu de cette nouvelle formation
     * @param cs : le nombre de crédits CS obtenus par cette nouvelle formation
     * @param tm : le nombre de crédits TM obtenus par cette nouvelle formation
     * @param tsh: le nombre de crédits TSH obtenus par cette nouvelle formation
     * @param sp: le nombre de crédits SP obtenus par cette nouvelle formation
     */
    FormationExterieure (const string& n, const string& l, unsigned int cs, unsigned int tm, unsigned int tsh, unsigned int sp) : nom(n), lieu(l), creditsCS(cs), creditsTM(tm), creditsTSH(tsh), creditsSP(sp) {}
    /**
     * @brief Constructeur par recopie
     * Permet de créer un nouvel objet FormationExterieure identique à un autre objet de la même classe déjà existant
     * @param other : l'objet à recopier
     */
    FormationExterieure (FormationExterieure& other) : nom(other.getNom()), lieu(other.getLieu()), creditsCS(other.getCreditsCS()), creditsTM(other.getCreditsTM()), creditsTSH(other.getCreditsTSH()), creditsSP(other.getCreditsSP()) {}
    /**
     * \brief Destructeur
     */
    ~FormationExterieure() {}
    /**
     * @brief Accesseur en lecture du nom de cette formation
     * @return Le nom de cette formation
     */
    string getNom() const {return nom;}
    /**
     * @brief Accesseur en lecture du lieu de cette formation
     * @return Le lieu de cette formation
     */
    string getLieu() const {return lieu;}
    /**
     * @brief Accesseur en lecture du nombre de crédits CS validés par cette formation
     * @return Le nombre de crédits CS validés par cette formation
     */
    unsigned int getCreditsCS() const {return creditsCS;}
    /**
     * @brief Accesseur en lecture du nombre de crédits TM validés par cette formation
     * @return Le nombre de crédits TM validés par cette formation
     */
    unsigned int getCreditsTM() const {return creditsTM;}
    /**
     * @brief Accesseur en lecture du nombre de crédits TSH validés par cette formation
     * @return Le nombre de crédits TSH validés par cette formation
     */
    unsigned int getCreditsTSH() const {return creditsTSH;}
    /**
     * @brief Accesseur en lecture du nombre de crédits SP validés par cette formation
     * @return Le nombre de crédits SP validés par cette formation
     */
    unsigned int getCreditsSP() const {return creditsSP;}
    /**
     * @brief Accesseur en écriture du nom de cette formation
     * @param s : Le nouveau nom de cette formation
     */
    void setNom (const string& s) {nom=s;}
    /**
     * @brief Accesseur en écriture du nouveau lieu de cette formation
     * @param s : Le nouveau lieu de cette formation
     */
    void setLieu (const string& s) {lieu=s;}
    /**
     * @brief Accesseur en écriture du nombre de crédits CS validés par cette formation
     * @param i : Nouveau nombre de crédits CS validés par cette formation
     */
    void setCreditsCS (unsigned int i) {creditsCS=i;}
    /**
     * @brief Accesseur en écriture du nombre de crédits TM validés par cette formation
     * @param i : Nouveau nombre de crédits TM validés par cette formation
     */
    void setCreditsTM (unsigned int i) {creditsTM=i;}
    /**
     * @brief Accesseur en écriture du nombre de crédits TSH validés par cette formation
     * @param i : Nouveau nombre de crédits TSH validés par cette formation
     */
    void setCreditsTSH (unsigned int i) {creditsTSH=i;}
    /**
     * @brief Accesseur en écriture du nombre de crédits SP validés par cette formation
     * @param i : Nouveau nombre de crédits SP validés par cette formation
     */
    void setCreditsSP (unsigned int i) {creditsSP=i;}
};

/**
 * \class Semestre
 * \brief Classe permettant de décrire un semestre d'un étudiant de l'UTC.
 *
 * Cette classe permet de garder temporairement en mémoire un semestre d'un étudiant à l'UTC. Cependant, un objet de cette classe n'est que temporaire, puisque tous nos semestres sont stockés dans notre Base de Données.
 */
class Semestre {
    unsigned int annee; /**< L'année en cours au moment du semestre*/
    Saison saison; /**< La saison en cours (Printemps ou Automne) au moment du semestre*/
    string commentaire; /**< Le commentaire du jury sur les résultats de l'étudiant ce semestre*/
    Inscription *inscriptions; /**< Les différentes inscriptions aux UVs de l'étudiant ce semestre, si il était à Compiègne*/
    bool ext; /**< Booléen décrivant si l'étudiant suivait une formation à l'extérieur de l'UTC ce semestre*/
    FormationExterieure *formationExt; /**< Si l'étudiant suivait une formation à l'extérieur de l'UTC ce semestre, elle est décrite ici*/
   public :
    /**
     * @brief Constructeur
     * Permet de créer un objet Semestre initialisé avec les valeurs passées en paramètres
     * @param a : L'année de ce semestre
     * @param s : La saison de ce semestre
     * @param c : Le commentaire du jury de ce semestre
     */
    Semestre(unsigned int a, Saison s, string c="") : annee(a), saison(s), commentaire(c), ext(false) {}
    /**
     * @brief Destructeur
     */
    ~Semestre() {delete inscriptions; delete formationExt;}
    /**
     * @brief Accesseur en lecture de l'année en cours au moment du semestre
     * @return L'année en cours au moment du semestre
     */
    unsigned int getAnnee() const {return annee;}
    /**
     * @brief Accesseur en lecture de la saison en cours au moment du semestre
     * @return La saison en cours au moment du semestre
     */
    Saison getSaison() const {return saison;}
    /**
     * @brief Accesseur en lecture du commentaire du jury quant aux résultats de l'étudiant ce semestre
     * @return Le commentaire du jury quant aux résultats de l'étudiant ce semestre
     */
    string getCommentaire() const {return commentaire;}
    /**
     * @brief Accesseur en lecture du tableau des inscritptions aux UVs de l'étudiant ce semestre
     * @return Le tableau des inscritptions aux UVs de l'étudiant ce semestre
     */
    Inscription* getInscriptions() const {return inscriptions;}
    /**
     * @brief Accesseur en lecture du booléen décrivant si l'étudiant était ou non en formation extérieure durant ce semestre
     * @return True si l'étudiant suivait une formation extérieure ce semestre, False si il était à Compiègne
     */
    bool getExt() const {return ext;}
    /**
     * @brief Accesseur en lecture du pointeur vers la formation extérieure suivie par l'étudiant ce semestre, s'il en a suivi une
     * @return Le pointeur vers la formation extérieure suivie par l'étudiant ce semestre
     */
    FormationExterieure* getFormationExterieure() const {return formationExt;}
    /**
     * @brief Accesseur en écriture de l'année au moment du semestre
     * @param i : La nouvelle année de ce semestre
     */
    void setAnnee (unsigned int i) {annee=i;}
    /**
     * @brief Accesseur en écriture de la saison (Printemps ou Automne) au moment du semestre
     * @param s : La nouvelle saison de ce semestre
     */
    void setSaison (Saison& s) {saison=s;}
    /**
     * @brief Accesseur en écriture du commentaire du jury quant à la réussite de l'étudiant ce semestre
     * @param s : Le nouveau commentaire du jury
     */
    void setCommentaire (const string& s) {commentaire=s;}
    /**
     * @brief Accesseur en écriture du tableau d'inscriptions aux UVs de l'étudiant ce semestre
     * @param i : Le nouveau tableau d'inscriptions aux UVs
     */
    void setInscriptions (Inscription *i) {inscriptions=i;}
    /**
     * @brief Accesseur en écriture du booléen décrivant si l'étudiant suivait ou non une formation exterieure ce semestre
     * @param e : La nouvelle valeur du booléen
     */
    void setExt (bool e) {ext=e;}
    /**
     * @brief Accesseur en écriture du pointeur vers la formation extérieure suivie par l'étudiant, s'il en a suivi une ce semestre
     * @param fe : La nouvelle valeur de ce pointeur
     */
    void setFormationExterieure (FormationExterieure* fe) {formationExt=fe;}
};

class Dossier {
    QString login;
    QString nom;
    QString prenom;
    QString conseiller;
    bool validationAEU;
    QString branche;
    Semestre *semestres;
    FormationExterieure *formationsExterieures;
    bool mineurCCT;
    bool mineurDDRESET;
    bool mineurFIRME;
    bool mineurINTENT;
    bool mineurPHITECO;
    bool mineurST;
    bool mineurTCN;
   public :
    Dossier(const QString& l, const QString& n, const QString& p, const QString& c, bool AEU, const QString& b) : login(l), nom(n),
        prenom(p), conseiller(c), validationAEU(AEU), branche(b), mineurCCT(false), mineurDDRESET(false), mineurFIRME(false),
        mineurINTENT(false), mineurPHITECO(false), mineurST(false), mineurTCN(false){}
    ~Dossier();
    QString getLogin() const {return login;}
    QString getNom() const {return nom;}
    QString getPrenom() const {return prenom;}
    QString getConseiller() const {return conseiller;}
    QString getBranche() const {return branche;}
    bool getValidationAEU() const {return validationAEU;}
    void setLogin (const QString& s) {login=s;}
    void setNom (const QString& s) {nom=s;}
    void setPrenom (const QString& s) {prenom=s;}
    void setConseiller (const QString& s) {conseiller=s;}
    void setBranche(const QString& s) {branche=s;}
    void setValidationAEU (bool b) {validationAEU=b;}
    bool checkMineurCCT() const;
    bool checkMineurDDRESET() const;
    bool checkMineurFIRME() const;
    bool checkMineurINTENT() const;
    bool checkMineurPHITECO() const;
    bool checkMineurST() const;
    bool checkMineurTCN() const;
    bool checkGI() const{
        QString b = "GI";
        if (branche == b) {return true;}
        return false;}
    bool checkGM()const{
        QString b = "GM";
        if (branche == b) {return true;}
        return false;}
    bool checkGP()const{
        QString b = "GP";
        if (branche == b) {return true;}
        return false;}
    bool checkGSM()const{
        QString b = "GSM";
        if (branche == b) {return true;}
        return false;}
    bool checkGSU()const{
        QString b = "GSU";
        if (branche == b) {return true;}
        return false;}
    bool checkGB()const{
        QString b = "GB";
        if (branche == b) {return true;}
        return false;}
    bool checkTC()const{
        QString b = "TC";
        if (branche == b) {return true;}
        return false;}
    bool checkHutech()const{
        QString b = "HUTECH";
        if (branche == b) {return true;}
        return false;}
    void suggestionsProchainSemestre();

    //iterator pour naviguer entre les semestres
    void ajouterSemestre();
    void supprimerSemestre();
    void modifierSemestre();

    //iterator pour naviguer entre les formations exterieures
    void ajouterFormationExterieure();
    void supprimerFormationExterieure();
    void modiferFormationExterieure();
};

class Formation {
    QString *nom;
    QString *responsable;
    QString *type;
    UV *uvs;
    unsigned int nbCreditsTot;
    unsigned int nbCreditsCS;
    unsigned int nbCreditsTM;
    unsigned int nbCreditsCSTM;
    unsigned int nbCreditsTSH;
    unsigned int nbCreditsSP;
   public :
    Formation(const QString& n, const QString& r, const QString& t, unsigned int tot, unsigned int cs, unsigned int tm, unsigned int cstm, unsigned int tsh, unsigned int sp) : nbCreditsTot(tot), nbCreditsCS(cs), nbCreditsTM(tm), nbCreditsCSTM(cstm), nbCreditsTSH(tsh), nbCreditsSP(sp) {nom = new QString(n); responsable = new QString(r); type = new QString(t);}
    Formation() : nbCreditsTot(0), nbCreditsCS(0), nbCreditsTM(0), nbCreditsCSTM(0), nbCreditsTSH(0), nbCreditsSP(0) {nom = new QString(""); responsable = new QString(""); type = new QString("");}
    QString getNom() const {return *nom;}
    QString getResponsable() const {return *responsable;}
    QString getType() const {return *type;}
    UV *getUVs() const {return uvs;}
    unsigned int getNbCreditsTot() const {return nbCreditsTot;}
    unsigned int getNbCreditsCS() const {return nbCreditsCS;}
    unsigned int getNbCreditsTM() const {return nbCreditsTM;}
    unsigned int getNbCreditsCSTM() const {return nbCreditsCSTM;}
    unsigned int getNbCreditsTSH() const {return nbCreditsTSH;}
    unsigned int getNbCreditsSP() const {return nbCreditsSP;}
};

/**
 * @class InterfaceSQL
 * @brief Classe permettant la communication avec la base de données
 *
 * La classe InterfaceSQL fait l'intermédiaire entre les différentes classes et notre base de données. Elle s'occuppe
 * de s'y connecter, de charger les fichiers sql pour la remplir, d'exécuter les requêtes et de renvoyer les réponses sous
 * forme de pointeur vers un objet.
 *
 * Cette classe est un singleton, c'est à dire qu'un unique objet de cette classe peut exister à la fois et qu'un pointeur
 * vers cet unique objet est disponible à tout moment à l'aide d'une méthode statique.
 */
class InterfaceSQL {
    static InterfaceSQL *instanceUnique; /**< Le pointeur vers l'unique objet de cette classe*/
    QSqlDatabase db; /**< L'objet Qt référençant notre base de données*/
    QSqlQuery *query; /**< L'objet Qt référençant la requête en cours ainsi que ses résultats*/
    InterfaceSQL();
    /**
     * @brief Constructeur par recopie
     * Le constructeur par recopie est ici déclaré en privé car la classe InterfaceSQL est un singleton.
     * Si toutefois il était tout de même utilisé, il soulèverait une exception.
     */
    InterfaceSQL(InterfaceSQL&) {throw UTProfilerException("Erreur : Un objet InterfaceSQL existe déjà.");}
    /**
     * @brief Opérateur d'affectation
     * L'opérateur d'affectation est ici déclaré en privé car la classe InterfaceSQL est un singleton.
     * Si toutefois il était tout de même utilisé, il soulèverait une exception.
     */
    InterfaceSQL& operator=(InterfaceSQL& other) {throw UTProfilerException("Erreur : Un objet InterfaceSQL existe déjà."); return other;}
    /**
     * @brief destructeur
     */
    ~InterfaceSQL() {delete query;}
   public :
    static InterfaceSQL* getInstance();
    static void libererInstance();
    bool load();
    bool load(const QString& chemin);
    QSqlQuery& execQuery(const QString& q);
    /**
     * @brief Méthode permettant de tester si l'exécution d'une requête retourne un résultat valide.
     * @param q : La requête à tester
     * @return True si la requête trouve une donnée à retourner, False si aucun élément de la base de données ne correspond.
     */
    bool tupleExiste(const QString& q) {query->exec(q); query->next(); return query->isValid();}
    UV* selectUV(const QString& q);
    UV** getAllUvs(const QString& q);
    Formation* selectFormation(const QString& q);
    Dossier* selectDossier(const QString& q);
    Semestre* selectSemestre(const QString& q);
    QString*** selectCompletion(const QString& q);
};

class UVWindow;

class NewUVWindow : public QWidget {
    Q_OBJECT
   friend class UVWindow;
    UVWindow *master;
    QLabel *label;
    QLineEdit *lecode;
    QHBoxLayout *hlayout1;
    QPushButton *pbannuler;
    QPushButton *pbvalider;
    QHBoxLayout *hlayout2;
    QVBoxLayout *vlayout;
    NewUVWindow(UVWindow *m);
   public slots :
    void pbvaliderEnable();
    void nouveau_annuler();
    void nouveau_valider();
};

class UVWindow : public QWidget {
    Q_OBJECT
    friend class HomeWindow;
    UV *uv;
    NewUVWindow *newuvwindow;
    QVBoxLayout *mainlayout;
    QHBoxLayout *hlayout1;
    QPushButton *pbretour;
    QLabel *lcode;
    QLineEdit *lecode;
    QPushButton *pbrechercher;
    QLabel *lresponsable;
    QLineEdit *leresponsable;
    QHBoxLayout *hlayout2;
    QTextEdit *tedescription;
    QVBoxLayout *vlayout21;
    QHBoxLayout *hlayout211;
    QLabel *lprintemps;
    QCheckBox *cbprintemps;
    QHBoxLayout *hlayout212;
    QLabel *lautomne;
    QCheckBox *cbautomne;
    QHBoxLayout *hlayout3;
    QLabel *lcs;
    QLineEdit *lecs;
    QLabel *ltm;
    QLineEdit *letm;
    QLabel *ltsh;
    QLineEdit *letsh;
    QLabel *lsp;
    QLineEdit *lesp;
    QHBoxLayout *hlayout4;
    QPushButton *pbnouveau;
    QPushButton *pbsupprimer;
    QPushButton *pbsauver;
    QHBoxLayout *hlayout5;
    QLabel *ltc;
    QCheckBox *cbtc;
    QLabel *lhutech;
    QCheckBox *cbhutech;
    QLabel *lgb;
    QCheckBox *cbgb;
    QLabel *lgi;
    QCheckBox *cbgi;
    QLabel *lgm;
    QCheckBox *cbgm;
    QLabel *lgp;
    QCheckBox *cbgp;
    QLabel *lgsm;
    QCheckBox *cbgsm;
    QLabel *lgsu;
    QCheckBox *cbgsu;
   public :
    UVWindow();
    void associerUV(UV *uv);
    void changeTC();
    void changeHUTECH();
    void changeGB();
    void changeGI();
    void changeGM();
    void changeGP();
    void changeGSM();
    void changeGSU();
   public slots :
    void sauver();
    void supprimer();
    void pbsauverEnable();
    void rechercher();
    void nouveau();
};

class DossierWindow : public QWidget {
    Q_OBJECT
    friend class HomeWindow;
    Semestre *semestre;
    QVBoxLayout *mainlayout;
    QHBoxLayout *hlayout1;
    QHBoxLayout *hlayout2;
    QHBoxLayout *hlayout3;
    QHBoxLayout *hlayout4;
    QHBoxLayout *hlayout5;
    QHBoxLayout *hlayout6;
    QHBoxLayout *hlayout7;
    QHBoxLayout *hlayout8;
    QHBoxLayout *hlayout9;
    QHBoxLayout *hlayout10;
    QHBoxLayout *hlayout11;
    QHBoxLayout *hlayout12;
    QHBoxLayout *hlayout13;
    QLabel *llogin;
    QLineEdit *lelogin;
    QPushButton *pbrechercher;
    QLabel *lnom;
    QLineEdit *lenom;
    QLabel *lprenom;
    QLineEdit *leprenom;
    QPushButton *pbsauver;
    QLabel *lconseiller;
    QLineEdit *leconseiller;
    QLabel *lactiviteEU;
    QRadioButton *lAEUOui;
    QRadioButton *lAEUNon;
    QLabel *lformationext;
    QPushButton *pbajouterformext;
    QLabel *lmineurs;
    QCheckBox *cbCCT;
    QCheckBox *cbFIRME;
    QCheckBox *cbPHITECO;
    QCheckBox *cbTCN;
    QCheckBox *cbDDRESET;
    QCheckBox *cbINTENT;
    QCheckBox *cbST;
    QLabel *lsemestres;
    QPushButton *pbajoutersemestres;
    QLabel *lbranche;
    QComboBox *cbbranche;
    QTableWidget *table;
    QTableWidget *table2;
    QPushButton *pbsuppr;
    QPushButton *pbretour;
    QLabel *lcommentaire;
    QTableWidget *table3;


   public :
    DossierWindow();
    void associerDossier(Dossier* d);
   public slots :
    void sauver();
    void pbsauverEnable();
    void rechercher();
    void ajouterFormExt();
    void supprFormExt(int r, int c);
    void ajouterSemestre();
    void supprSemestre(int r, int c);
    void supprimer();
};

class FormationExtWindow : public QWidget {
    Q_OBJECT

    QString login;

    QVBoxLayout *mainlayout;
    QHBoxLayout *hlayout1;
    QHBoxLayout *hlayout2;
    QHBoxLayout *hlayout3;
    QHBoxLayout *hlayout4;
    QLabel *lnom;
    QLineEdit *lenom;
    QLabel *llieu;
    QLineEdit *lelieu;
    QLabel *lequivalences;
    QLabel *lcs;
    QLineEdit *lecs;
    QLabel *ltm;
    QLineEdit *letm;
    QLabel *ltsh;
    QLineEdit *letsh;
    QLabel *lsp;
    QLineEdit *lesp;

    QPushButton *pbajouter;


   public :
    FormationExtWindow(const QString& l);
    QString getLogin() const {return login;}

   public slots :
    void ajouter();
};

class SemestreWindow : public QWidget {
    Q_OBJECT

    QString login;

    QVBoxLayout *mainlayout;
    QHBoxLayout *hlayout1;
    QHBoxLayout *hlayout2;
    QHBoxLayout *hlayout3;
    QHBoxLayout *hlayout4;
    QHBoxLayout *hlayout5;

    QLabel *lsaison;
    QComboBox *cbsaison;
    QLabel *lannee;
    QLineEdit *leannee;
    QLabel *luv;
    QComboBox *cbuv;
    QLabel *lnote;
    QComboBox *cbnote;

    QPushButton *pbajouter;


   public :
    SemestreWindow(const QString& l);
    QString getLogin() const {return login;}

   public slots :
    void ajouter();
};

class FormationWindow;

class NewFormationWindow : public QWidget {
    Q_OBJECT
    friend class FormationWindow;
    FormationWindow *master;
    QVBoxLayout *mainlayout;
    QHBoxLayout *hlayout1;
    QLabel *lnom;
    QLineEdit *lenom;
    QHBoxLayout *hlayout2;
    QPushButton *pbannuler;
    QPushButton *pbajouter;
   public :
    NewFormationWindow(FormationWindow *fw);
   public slots :
    void setenabled();
    void ajouter();
    void annuler();
};

class FormationWindow : public QWidget {
    Q_OBJECT
    friend class HomeWindow;
    friend class BindUVWindow;
    friend class UnbindUVWindow;
    NewFormationWindow *newformationwindow;
    Formation *formation;
    QVBoxLayout *mainlayout;
    QHBoxLayout *hlayout1;
    QPushButton *pbretour;
    QLabel *lnom;
    QLineEdit *lenom;
    QPushButton *pbrechercher;
    QLabel *lresponsable;
    QLineEdit *leresponsable;
    QLabel *ltype;
    QComboBox *cbtype;
    QHBoxLayout *hlayout2;
    QLabel *lcredits;
    QLabel *ltot;
    QLineEdit *letot;
    QLabel *lcs;
    QLineEdit *lecs;
    QLabel *ltm;
    QLineEdit *letm;
    QLabel *lcstm;
    QLineEdit *lecstm;
    QLabel *ltsh;
    QLineEdit *letsh;
    QLabel *lsp;
    QLineEdit *lesp;
    QHBoxLayout *hlayout3;
    QTableWidget *twuvs;
    QVBoxLayout *vlayout31;
    QPushButton *pbajouteruv;
    QPushButton *pbsupprimeruv;
    QHBoxLayout *hlayout4;
    QPushButton *pbnouveau;
    QPushButton *pbsupprimer;
    QPushButton *pbsauver;
    QLabel *luvs;
    QPushButton *pbajoutuv;
    QHBoxLayout *hlayout5;
    QLabel *lfilieres;
    QPushButton *pbajoutfil;
    QTableWidget *table;
   public :
    FormationWindow();
    void associerFormation(Formation *formation);
   public slots :
    void setenabled();
    void rechercher();
    void nouveau();
    void supprimer();
    void sauver();
    void sauveruv(int r, int c);
    void ajouteruv();
    void sauverfil(int r, int c);
    void ajouterfil();

};

QString checkSyntax(QString s);

class CompletionProfilWindow;
class RetrouverCompletionWindow;

class SearchDossierWindow : public QWidget {
    Q_OBJECT
    friend class CompletionProfilWindow;
    friend class HomeWindow;
    RetrouverCompletionWindow *retrouvercompletionwindow;
    Dossier *dossier;
    CompletionProfilWindow *master;
    QVBoxLayout *mainlayout;
    QHBoxLayout *hlayout1;
    QLabel *lnom;
    QComboBox *lenom;
    QHBoxLayout *hlayout2;
    QLabel *lsouhaits;
    QLineEdit *lesouhaits;
    QHBoxLayout *hlayout3;
    QLabel *lrejets;
    QLineEdit *lerejets;
    QHBoxLayout *hlayout4;
    QPushButton *pbannuler;
    QPushButton *pbretrouver;
    QPushButton *pbrechercher;
    QString **souhaits;
    QString **rejets;
   public :
    SearchDossierWindow(CompletionProfilWindow *fw);
   public slots :
    void rechercher();
    void retrouver();
    void annuler();
};

class RetrouverCompletionWindow : public QWidget {
    Q_OBJECT
    friend class SearchDossierWindow;
    QString ***completions;
    QVBoxLayout *mainlayout;
    QLabel *lresultat;
    QHBoxLayout *hlayout1;
    QLabel *luv1;
    QLineEdit *leuv1;
    QHBoxLayout *hlayout2;
    QLabel *luv2;
    QLineEdit *leuv2;
    QHBoxLayout *hlayout3;
    QLabel *luv3;
    QLineEdit *leuv3;
    QHBoxLayout *hlayout4;
    QLabel *luv4;
    QLineEdit *leuv4;
    QHBoxLayout *hlayout5;
    QLabel *luv5;
    QLineEdit *leuv5;
    QHBoxLayout *hlayout6;
    QLabel *luv6;
    QLineEdit *leuv6;
    QHBoxLayout *hlayout7;
    QPushButton *pbprecedent;
    QPushButton *pbfermer;
    QPushButton *pbsuivant;
    int indice;
   public :
    RetrouverCompletionWindow(QString ***c);
    void associercompletion (QString **completion);
   public slots :
    void precedent();
    void suivant();
};

class CompletionProfilWindow : public QWidget {
    Q_OBJECT
    friend class HomeWindow;
    SearchDossierWindow *searchdossierwindow;
    QVBoxLayout *mainlayout;
    QLabel *lresultat;
    QHBoxLayout *hlayout1;
    QLabel *luv1;
    QLineEdit *leuv1;
    QPushButton *pbconfirmer1;
    QPushButton *pbrefuser1;
    QHBoxLayout *hlayout2;
    QLabel *luv2;
    QLineEdit *leuv2;
    QPushButton *pbconfirmer2;
    QPushButton *pbrefuser2;
    QHBoxLayout *hlayout3;
    QLabel *luv3;
    QLineEdit *leuv3;
    QPushButton *pbconfirmer3;
    QPushButton *pbrefuser3;
    QHBoxLayout *hlayout4;
    QLabel *luv4;
    QLineEdit *leuv4;
    QPushButton *pbconfirmer4;
    QPushButton *pbrefuser4;
    QHBoxLayout *hlayout5;
    QLabel *luv5;
    QLineEdit *leuv5;
    QPushButton *pbconfirmer5;
    QPushButton *pbrefuser5;
    QHBoxLayout *hlayout6;
    QLabel *luv6;
    QLineEdit *leuv6;
    QPushButton *pbconfirmer6;
    QPushButton *pbrefuser6;
    QHBoxLayout *hlayout7;
    QPushButton *pbok;
    QPushButton *pbenregistrer;
    int compteurConfirme;
   public :
    CompletionProfilWindow();
    void CompletionProfil(Dossier *dossier, QString** souhaits, QString** rejets);
    void associercompletion(UV **uvs);
   public slots :
    void rechercher();
    void enregistrer();
    void confirmer1();
    void confirmer2();
    void confirmer3();
    void confirmer4();
    void confirmer5();
    void confirmer6();
    void refuser1();
    void refuser2();
    void refuser3();
    void refuser4();
    void refuser5();
    void refuser6();
};


class HomeWindow : public QWidget {
    Q_OBJECT
    UVWindow *uvwindow;
    FormationWindow *formationwindow;
    DossierWindow *dossierwindow;
    CompletionProfilWindow *completionprofilwindow;
    QVBoxLayout *mainlayout;
    QHBoxLayout *hlayout1;
    QPushButton *pbuv;
    QHBoxLayout *hlayout2;
    QPushButton *pbformation;
    QHBoxLayout *hlayout3;
    QPushButton *pbdossier;
    QPushButton *pbcompletion;
    QPushButton *pbquitter;
    QHBoxLayout *hlayout4;
    QHBoxLayout *hlayout5;
    QHBoxLayout *hlayout6;
    QLabel *lbienvenue;
   public :
    InterfaceSQL *sql;
    HomeWindow();
};

class AssocierUVWindow : public QWidget{
    Q_OBJECT
    QString formation;

    QVBoxLayout *mainlayout;
    QHBoxLayout *hlayout1;
    QHBoxLayout *hlayout2;
    QLabel *luv;
    QComboBox *cbuv;
    QPushButton *pbajouter;

    public :
        AssocierUVWindow(const QString& f);
        QString getFormation() const {return formation;}
    public slots :
        void ajouter();
};

class AssocierFiliereWindow : public QWidget{
    Q_OBJECT
    QString branche;

    QVBoxLayout *mainlayout;
    QHBoxLayout *hlayout1;
    QHBoxLayout *hlayout2;
    QLabel *lnom;
    QLineEdit *lenom;
    QPushButton *pbajouter;

    public :
        AssocierFiliereWindow(const QString& b);
        QString getBranche() const {return branche;}
    public slots :
        void ajouter();
};

QString checkSyntax(QString s);

void CompletionProfil(Dossier *dossier);


#endif // UTPROFILER_H
