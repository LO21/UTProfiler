#ifndef UTPROFILER_H
#define UTPROFILER_H

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

enum Saison {
    Printemps,
    Automne
};

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

class UTProfilerException {
    QString msg;
   public :
    UTProfilerException(const QString& s);
    //UTProfilerException(const string& s);
    ~UTProfilerException() {}
};

//template <typename T> class Manager;
//class UVManager;

class UV {
    //friend class UVManager;
    //friend class Manager<UV>;
    QString *code;
    QString *titre;
    QString *responsable;
    unsigned int creditsCS;
    unsigned int creditsTM;
    unsigned int creditsTSH;
    unsigned int creditsSP;
    bool printemps;
    bool automne;
    bool *branche;
   public :
    UV& operator=(UV& other) {code=new QString(other.getCode());titre=new QString(other.getTitre());responsable=new QString(other.getResponsable());creditsCS=other.getCreditsCS();creditsTM=other.getCreditsTM();creditsTSH=other.getCreditsTSH();creditsSP=other.creditsSP;printemps=other.getPrintemps();automne=other.getAutomne();return *this;}
    UV(const QString& c, const QString& t, const QString& r,unsigned int cs, unsigned int tm, unsigned int tsh, unsigned int sp, bool p, bool a) : creditsCS(cs), creditsTM(tm), creditsTSH(tsh), creditsSP(sp), printemps(p), automne(a) {code = new QString(c); titre = new QString(t); responsable = new QString(r); branche = new bool[8];}
    UV() : creditsCS(0), creditsTM(0), creditsTSH(0), creditsSP(0), printemps(false), automne(false) {code = new QString(""); titre = new QString(""); responsable = new QString(""); branche = new bool[8];}
   //public :
    QString getCode() const {return *code;}
    QString getTitre() const {return *titre;}
    QString getResponsable() const {return *responsable;}
    unsigned int getCreditsCS() const {return creditsCS;}
    unsigned int getCreditsTM() const {return creditsTM;}
    unsigned int getCreditsTSH() const {return creditsTSH;}
    unsigned int getCreditsSP() const {return creditsSP;}
    bool getPrintemps() const {return printemps;}
    bool getAutomne() const {return automne;}
    void setCode(QString *s) {code=s;}
    void setTitre(QString *s) {titre=s;}
    void setResponsable(QString *s) {responsable=s;}
    void setCreditsCS(unsigned int cs) {creditsCS=cs;}
    void setCreditsTM(unsigned int tm) {creditsTM=tm;}
    void setCreditsTSH(unsigned int tsh) {creditsTSH=tsh;}
    void setCreditsSP(unsigned int sp) {creditsSP=sp;}
    void setPrintemps (bool b) {printemps=b;}
    void setAutomne (bool b) {automne=b;}
    bool* getBranche();
    bool operator!=(UV& other);
};

class Inscription {
    string uv;
    Resultat resultat;
   public :
    Inscription();
    string getUV() const {return uv;}
    Resultat getResultat() const {return resultat;}
    void setUv (const string& s) {uv=s;}
    void setResultat(Resultat& r) {resultat=r;}
};

class FormationExterieure {
    string nom;
    string lieu;
    unsigned int creditsCS;
    unsigned int creditsTM;
    unsigned int creditsTSH;
    unsigned int creditsSP;
   public :
    FormationExterieure (const string& n, const string& l, unsigned int cs, unsigned int tm, unsigned int tsh, unsigned int sp) : nom(n), lieu(l), creditsCS(cs), creditsTM(tm), creditsTSH(tsh), creditsSP(sp) {}
    FormationExterieure (FormationExterieure& other) : nom(other.getNom()), lieu(other.getLieu()), creditsCS(other.getCreditsCS()), creditsTM(other.getCreditsTM()), creditsTSH(other.getCreditsTSH()), creditsSP(other.getCreditsSP()) {}
    ~FormationExterieure() {}
    string getNom() const {return nom;}
    string getLieu() const {return lieu;}
    unsigned int getCreditsCS() const {return creditsCS;}
    unsigned int getCreditsTM() const {return creditsTM;}
    unsigned int getCreditsTSH() const {return creditsTSH;}
    unsigned int getCreditsSP() const {return creditsSP;}
    void setNom (const string& s) {nom=s;}
    void setLieu (const string& s) {lieu=s;}
    void setCreditsCS (unsigned int i) {creditsCS=i;}
    void setCreditsTM (unsigned int i) {creditsTM=i;}
    void setCreditsTSH (unsigned int i) {creditsTSH=i;}
    void setCreditsSP (unsigned int i) {creditsSP=i;}
};

class Semestre {
    unsigned int annee;
    Saison saison;
    string commentaire;
    Inscription *inscriptions;
    bool ext;
    FormationExterieure *formationExt;
   public :
    Semestre(unsigned int a, Saison s, string c="") : annee(a), saison(s), commentaire(c), ext(false) {}
    ~Semestre();
    unsigned int getAnnee() const {return annee;}
    Saison getSaison() const {return saison;}
    string getCommentaire() const {return commentaire;}
    bool getExt() const {return ext;}
    FormationExterieure* getFormationExterieure() const {return formationExt;}

    void setAnnee (unsigned int i) {annee=i;}
    void setSaison (Saison& s) {saison=s;}
    void setCommentaire (const string& s) {commentaire=s;}
    void setFormationExterieure (FormationExterieure* fe) {formationExt=fe;}
    /*Explication du fonctionnement de cette classe :
     * Un Semestre (pour un étudiant) est soit un semestre à l'UTC, au quel cas l'étudiant suit un certain nombre d'UV,
     * alors répertoriées dans le tableau inscriptions. le pointeur formationExt
     * Remarque : un stage est un semestre contenant une inscription à une unique UV : TN09/TN10.
     *
     * S'il a suivi une formation exterieure (équivalence ou Erasmus), alors on lève le flag ext, le pointeur inscriptions
     * doit alors pointer vers NULL et aucun iterateur ne doit exister. La formation exterieure est alors décrite
     * par le pointeur prévu à cet effet.
     *
     * Tout ceci doit être géré dans le constructeur. */

    //iterator pour naviguer entre les inscriptions
    void ajouterInscription();
    void supprimerInscription();
    void modifierInscription();
};

/*! \class Dossier
  * \brief Classe représentant un dossier
  *
  */
class Dossier {
    //friend class DossierManager;
    QString login; /*!< Login du dossier */
    QString nom; /*!< Nom de l'étudiant */
    QString prenom; /*!< Prénom de l'étudiant */
    QString conseiller; /*!< Conseille de l'étudiant */
    bool validationAEU; /*!< Booléen représentant si l'étudiant a validé son Activité Extra Universitaire */
    QString branche; /*!< Branche de l'étudiant */
    Semestre *semestres; /*!< Semestres effectués par l'étudiant */
    FormationExterieure *formationsExterieures; /*!< Formations extérieures effectuées par l'étudiant */
    bool mineurCCT; /*!< Booléen représentant si l'étudiant a validé le mineur CCT */
    bool mineurDDRESET; /*!< Booléen représentant si l'étudiant a validé le mineur DDRESET */
    bool mineurFIRME; /*!< Booléen représentant si l'étudiant a validé le mineur FIRME */
    bool mineurINTENT; /*!< Booléen représentant si l'étudiant a validé le mineur INTENT */
    bool mineurPHITECO; /*!< Booléen représentant si l'étudiant a validé le mineur PHITECO */
    bool mineurST; /*!< Booléen représentant si l'étudiant a validé le mineur ST */
    bool mineurTCN; /*!< Booléen représentant si l'étudiant a validé le mineur TCN */
   public :
    /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe Dossier
         *
         *  \param l : login du dossier
         *  \param n : Nom de l'étudiant
         *  \param p : Prénom de l'étudiant
         *  \param c : Conseiller de l'étudiant
         *  \param AEU : Booléen représentant si l'étudiant a validé son Activité Extra Universitaire
         *  \param b : Branche de l'étudiant
         */
    Dossier(const QString& l, const QString& n, const QString& p, const QString& c, bool AEU, const QString& b) : login(l), nom(n),
        prenom(p), conseiller(c), validationAEU(AEU), branche(b), mineurCCT(false), mineurDDRESET(false), mineurFIRME(false),
        mineurINTENT(false), mineurPHITECO(false), mineurST(false), mineurTCN(false){}

    /*!
     *  \brief Destructeur
     *
     *  Destructeur de la classe Dossier
     */
    ~Dossier();
    /*!
         *  \brief Accès en lecture au login du dossier
         *
         *
         *  \return le login du dossier
         */
    QString getLogin() const {return login;}
    /*!
         *  \brief Accès en lecture au nom de l'étudiant
         *
         *
         *  \return le nom de l'étudiant
         */
    QString getNom() const {return nom;}
    /*!
         *  \brief Accès en lecture au prénom de l'étudiant
         *
         *
         *  \return le prénom de l'étudiant
         */
    QString getPrenom() const {return prenom;}
    /*!
         *  \brief Accès en lecture au conseiller de l'étudiant
         *
         *
         *  \return le conseiller de l'étudiant
         */
    QString getConseiller() const {return conseiller;}
    /*!
         *  \brief Accès en lecture à la branche de l'étudiant
         *
         *
         *  \return la branche de l'étudiant
         */
    QString getBranche() const {return branche;}
    /*!
         *  \brief Accès en lecture à la validation d'activité extra universiatire de l'étudiant
         *
         *
         *  \return la validation d'activité extra universiatire de l'étudiant
         */
    bool getValidationAEU() const {return validationAEU;}
    /*!
         *  \brief Accès en écriture au login du dossier
         *
         *
         *  \return le login du dossier
         */
    void setLogin (const QString& s) {login=s;}
    /*!
         *  \brief Accès en écriture au nom de l'étudiant
         *
         *
         *  \return le nom de l'étudiant
         */
    void setNom (const QString& s) {nom=s;}
    /*!
         *  \brief Accès en écriture au prénom de l'étudiant
         *
         *
         *  \return le prénom de l'étudiant
         */
    void setPrenom (const QString& s) {prenom=s;}
    /*!
         *  \brief Accès en écriture au conseiller de l'étudiant
         *
         *
         *  \return le conseiller de l'étudiant
         */
    void setConseiller (const QString& s) {conseiller=s;}
    /*!
         *  \brief Accès en écriture à la branche de l'étudiant
         *
         *
         *  \return la branche de l'étudiant
         */
    void setBranche(const QString& s) {branche=s;}
    /*!
         *  \brief Accès en écriture à la validation d'activité extra universiatire de l'étudiant
         *
         *
         *  \return la validation d'activité extra universiatire de l'étudiant
         */
    void setValidationAEU (bool b) {validationAEU=b;}
    /*!
         *  \brief Vérifie si l'étudiant a validé le mineur CCT
         *
         *
         *  \return vrai si l'étudiant a validé le mineur CCT, faux sinon
         */
    bool checkMineurCCT() const;
    /*!
         *  \brief Vérifie si l'étudiant a validé le mineur DD-RESET
         *
         *
         *  \return vrai si l'étudiant a validé le mineur DD-RESET, faux sinon
         */
    bool checkMineurDDRESET() const;
    /*!
         *  \brief Vérifie si l'étudiant a validé le mineur FIRME
         *
         *
         *  \return vrai si l'étudiant a validé le mineur FIRME, faux sinon
         */
    bool checkMineurFIRME() const;
    /*!
         *  \brief Vérifie si l'étudiant a validé le mineur INTENT
         *
         *
         *  \return vrai si l'étudiant a validé le mineur INTENT, faux sinon
         */
    bool checkMineurINTENT() const;
    /*!
         *  \brief Vérifie si l'étudiant a validé le mineur PHITECO
         *
         *
         *  \return vrai si l'étudiant a validé le mineur PHITECO, faux sinon
         */
    bool checkMineurPHITECO() const;
    /*!
         *  \brief Vérifie si l'étudiant a validé le mineur ST
         *
         *
         *  \return vrai si l'étudiant a validé le mineur ST, faux sinon
         */
    bool checkMineurST() const;
    /*!
         *  \brief Vérifie si l'étudiant a validé le mineur TCN
         *
         *
         *  \return vrai si l'étudiant a validé le mineur TCN, faux sinon
         */
    bool checkMineurTCN() const;
    /*!
         *  \brief Vérifie la branche de l'étudiant
         *
         *
         *  \return vrai si l'étudiant est en GI, faux sinon
         */
    bool checkGI() const{
        QString b = "GI";
        if (branche == b) {return true;}
        return false;}
    /*!
         *  \brief Vérifie la branche de l'étudiant
         *
         *
         *  \return vrai si l'étudiant est en GM, faux sinon
         */
    bool checkGM()const{
        QString b = "GM";
        if (branche == b) {return true;}
        return false;}
    /*!
         *  \brief Vérifie la branche de l'étudiant
         *
         *
         *  \return vrai si l'étudiant est en GP, faux sinon
         */
    bool checkGP()const{
        QString b = "GP";
        if (branche == b) {return true;}
        return false;}
    /*!
         *  \brief Vérifie la branche de l'étudiant
         *
         *
         *  \return vrai si l'étudiant est en GSM, faux sinon
         */
    bool checkGSM()const{
        QString b = "GSM";
        if (branche == b) {return true;}
        return false;}
    /*!
         *  \brief Vérifie la branche de l'étudiant
         *
         *
         *  \return vrai si l'étudiant est en GSU, faux sinon
         */
    bool checkGSU()const{
        QString b = "GSU";
        if (branche == b) {return true;}
        return false;}
    /*!
         *  \brief Vérifie la branche de l'étudiant
         *
         *
         *  \return vrai si l'étudiant est en GB, faux sinon
         */
    bool checkGB()const{
        QString b = "GB";
        if (branche == b) {return true;}
        return false;}
    /*!
         *  \brief Vérifie la branche de l'étudiant
         *
         *
         *  \return vrai si l'étudiant est en TC, faux sinon
         */
    bool checkTC()const{
        QString b = "TC";
        if (branche == b) {return true;}
        return false;}
    /*!
         *  \brief Vérifie la branche de l'étudiant
         *
         *
         *  \return vrai si l'étudiant est en HUTECH, faux sinon
         */
    bool checkHutech()const{
        QString b = "HUTECH";
        if (branche == b) {return true;}
        return false;}
    /*!
         *  \brief Propositions de prochain semestre pour ce dossier
         *
         *
         */
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

/*! \class Formation
  * \brief Classe représentant une formation
  *
  */
class Formation {
    QString *nom; /*!< Nom de la formation*/
    QString *responsable; /*!< Responsable de la formation */
    QString *type; /*!< Type de la formation : Branche, filière ou mineur */
    UV *uvs; /*!< uvs associées à la formation */
    unsigned int nbCreditsTot; /*!< Nombre de crédits total requis pour valider la formation */
    unsigned int nbCreditsCS;/*!< Nombre de crédits CS requis pour valider la formation */
    unsigned int nbCreditsTM; /*!< Nombre de crédits TM requis pour valider la formation */
    unsigned int nbCreditsCSTM; /*!< Nombre de crédits CS + TM requis pour valider la formation */
    unsigned int nbCreditsTSH; /*!< Nombre de crédits TSH requis pour valider la formation */
    unsigned int nbCreditsSP; /*!< Nombre de crédits SP requis pour valider la formation */
   public :
    /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe Formation
         *
         *  \param n : nom de la formation
         *  \param r : responsable de la formation
         *  \param t : type de la formation
         *  \param tot : nombre de crédits total requis pour valider la formation
         *  \param cs : nombre de crédits CS requis pour valider la formation
         *  \param tm : nombre de crédits TM requis pour valider la formation
         *  \param cstm : nombre de crédits CS + TM requis pour valider la formation
         *  \param tsh : nombre de crédits TSH requis pour valider la formation
         *  \param sp : nombre de crédits SP requis pour valider la formation
         */
    Formation(const QString& n, const QString& r, const QString& t, unsigned int tot, unsigned int cs, unsigned int tm, unsigned int cstm, unsigned int tsh, unsigned int sp) : nbCreditsTot(tot), nbCreditsCS(cs), nbCreditsTM(tm), nbCreditsCSTM(cstm), nbCreditsTSH(tsh), nbCreditsSP(sp) {nom = new QString(n); responsable = new QString(r); type = new QString(t);}
    /*!
         *  \brief Constructeur
         *
         *  Constructeur sans arguments de la classe Formation
         *
         */
    Formation() : nbCreditsTot(0), nbCreditsCS(0), nbCreditsTM(0), nbCreditsCSTM(0), nbCreditsTSH(0), nbCreditsSP(0) {nom = new QString(""); responsable = new QString(""); type = new QString("");}
    /*!
         *  \brief Accès en lecture au nom de la formation
         *
         *
         *  \return le nom de la formation
         */
    QString getNom() const {return *nom;}
    /*!
         *  \brief Accès en lecture au responsable de la formation
         *
         *
         *  \return le responsable de la formation
         */
    QString getResponsable() const {return *responsable;}
    /*!
         *  \brief Accès en lecture au type de la formation
         *
         *
         *  \return le type de la formation
         */
    QString getType() const {return *type;}
    /*!
         *  \brief Accès en lecture aux uvs associées à la formation
         *
         *
         *  \return les uvs associées à la formation
         */
    UV *getUVs() const {return uvs;}
    /*!
         *  \brief Accès en lecture au nombre de crédits total requis pour valider la formation
         *
         *
         *  \return le nom de crédits total requis pour valider la formation
         */
    unsigned int getNbCreditsTot() const {return nbCreditsTot;}
    /*!
         *  \brief Accès en lecture au nombre de crédits CS requis pour valider la formation
         *
         *
         *  \return le nom de crédits CS requis pour valider la formation
         */
    unsigned int getNbCreditsCS() const {return nbCreditsCS;}
    /*!
         *  \brief Accès en lecture au nombre de crédits TM requis pour valider la formation
         *
         *
         *  \return le nom de crédits TM requis pour valider la formation
         */
    unsigned int getNbCreditsTM() const {return nbCreditsTM;}
    /*!
         *  \brief Accès en lecture au nombre de crédits CS + TM requis pour valider la formation
         *
         *
         *  \return le nom de crédits CS + TM requis pour valider la formation
         */
    unsigned int getNbCreditsCSTM() const {return nbCreditsCSTM;}
    /*!
         *  \brief Accès en lecture au nombre de crédits TSH requis pour valider la formation
         *
         *
         *  \return le nom de crédits TSH requis pour valider la formation
         */
    unsigned int getNbCreditsTSH() const {return nbCreditsTSH;}
    /*!
         *  \brief Accès en lecture au nombre de crédits SP requis pour valider la formation
         *
         *
         *  \return le nom de crédits SP requis pour valider la formation
         */
    unsigned int getNbCreditsSP() const {return nbCreditsSP;}
};

/*template <typename T> class Manager {
    friend class UVManager;
    T **tab;
    unsigned int nbElem;
    unsigned int nbElemMax;
    Manager() : nbElem(0), nbElemMax(10) {tab = new T*[10];}
    Manager(Manager& copy);
    Manager& operator=(Manager& other);
   public :
    unsigned int getNbElem() const {return nbElem;}
    unsigned int getNbElemMax() const {return nbElem;}
    virtual T* creerItem()=0;
    virtual int trouverItem(const QString& s)=0;
    int trouverItem(T *item) {
        Iterator it = begin();
        int place=0;
        while (*it!=*end() || *it!=item) {++it;++place;}
        if (it!=end()) {return place;}
        else {return -1;}
    }
    virtual void ajouterItem(T *item) {
        if (nbElem==nbElemMax) {
            nbElemMax+=5;
            T **copy = new T*[nbElem];
            for (unsigned int i=0;i<nbElem;++i) {copy[i]=tab[i];}
            delete tab;
            tab = new T*[nbElemMax];
            for (unsigned int i=0;i<nbElem;++i) {tab[i]=copy[i];}
            delete copy;}
        if (nbElem!=0) {
            if (trouverItem(item)==-1)
                {tab[nbElem++]=item; nbElem++;}
            else
                {supprimerItem(item); tab[nbElem++]=item;}
        }
        else {tab[nbElem++]=item;}
    }
    virtual void supprimerItem(T *item) {
        int place = trouverItem(item);
        if (place!=-1) {
            for (unsigned int i=place;i<nbElem;++i) {tab[i]=tab[i+1];}
            nbElem--;}
    }

    class Iterator {
        T **current;
       public :
        Iterator(T **cur) : current(cur) {}
        Iterator(Iterator& other) {current = new T*(*other);}
        Iterator& operator=(Iterator& other) {current=*other;}
        unsigned int getNbElem() const {return nbElem;}
        unsigned int getNbElemMax() const {return nbElemMax;}
        T* operator*() const {return *current;}
        void operator++() {current++;}
        void operator++(int) {current++;}
        void operator--() {current--;}
        void operator--(int) {current--;}
        bool operator==(Iterator& other) {return *current==*other.current;}
        bool operator!=(Iterator& other) {return *current!=*other.current;}
        bool operator<(Iterator& other) {return *current<*other.current;}
        bool operator<=(Iterator& other) {return *current<=*other.current;}
        bool operator>(Iterator& other) {return *current>*other.current;}
        bool operator>=(Iterator& other) {return *current>=*other.current;}
    };
    Iterator& begin() {Iterator *it = new Iterator(tab); return *it;}
    Iterator& end() {Iterator *it = new Iterator(tab+this->getNbElem()); return *it;}
    Iterator& getIterator(T *item) {Iterator *it = new Iterator(item); return *it;}
};

class UVManager : public Manager<UV> {
    static UVManager *instanceUnique;
    UVManager() : Manager<UV>() {}
   public :
    static UVManager* getInstance() {
        if (instanceUnique==0) {instanceUnique = new UVManager(); instanceUnique->creerItem();}
        return instanceUnique;
    }
    UV* creerItem (const QString& c, const QString& t, const QString& r,unsigned int cs, unsigned int tm, unsigned int tsh, unsigned int sp, bool p, bool a) {
        UV *res = new UV(c,t,r,cs,tm,tsh,sp,p,a);
        ajouterItem(res);
        return res;}
    UV* creerItem() {
        UV *res = new UV();
        ajouterItem(res);
        return res;}
    int trouverItem(const QString& s) {
        Iterator it = begin();
        unsigned int place=0;
        UV *uv= *it;
        while (it!=end() || uv->getCode()!=s) {++it;uv=*it;++place;}
        return place;
    }
};

class FormationManager : public Manager<Formation> {

};

class DossierManager : public Manager<Dossier> {

};
*/
class InterfaceSQL {
    static InterfaceSQL *instanceUnique;
    QSqlDatabase db;
    QSqlQuery *query;
    InterfaceSQL();
    InterfaceSQL(InterfaceSQL&) {throw UTProfilerException("Erreur : Un objet InterfaceSQL existe déjà.");}
    InterfaceSQL& operator=(InterfaceSQL& other) {throw UTProfilerException("Erreur : Un objet InterfaceSQL existe déjà."); return other;}
    ~InterfaceSQL() {}
   public :
    static InterfaceSQL* getInstance();
    static void libererInstance();
    bool load();
    bool load(const QString& chemin);
    QSqlQuery& execQuery(const QString& q);
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

/*! \class DossierWindow
  * \brief Classe pour la fenêtre qui permet de consulter, modifier, ajouter, supprimer un dossier
  *
  */
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

/*! \class FormationExtWindow
  * \brief Classe qui permet d'ajouter une formation extérieure à un login existant
  *
  */
class FormationExtWindow : public QWidget {
    Q_OBJECT

    QString login; /*!< login pour lequel on souhaite ajouter une formation extérieure */

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
    /*!
         *  \brief Accès en lecture au login
         *
         *
         *  \return l'attribut login
         */
    QString getLogin() const {return login;}

   public slots :
    void ajouter();
};

/*! \class SemestreWindow
  * \brief Classe qui permet d'ajouter un semestre/une inscription à un uv, à un login existant
  *
  */
class SemestreWindow : public QWidget {
    Q_OBJECT

    QString login; /*!< login pour lequel on souhaite ajouter un semestre */

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
    /*!
         *  \brief Accès en lecture au login
         *
         *
         *  \return l'attribut login
         */
    QString getLogin() const {return login;}

   public slots :
    void ajouter();
};

class FormationWindow;

/*! \class NewFormationWindow
  * \brief Classe qui permet d'ajouter une nouvelle formation
  *
  */
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

/*! \class FormationWindow
  * \brief Classe de la fenêtre pour la gestion des formations
  *
  */
class FormationWindow : public QWidget {
    Q_OBJECT
    friend class HomeWindow;
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

/*! \class HomeWindow
  * \brief Classe de la fenêtre d'accueil de UTProfiler
  *
  */
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

/*! \class AssocierUVWindow
  * \brief Classe de la fenêtre pour associer une uv à une formation
  *
  */
class AssocierUVWindow : public QWidget{
    Q_OBJECT
    QString formation; /*!< Formation pour laquelle on souhaite associer une uv */

    QVBoxLayout *mainlayout;
    QHBoxLayout *hlayout1;
    QHBoxLayout *hlayout2;
    QLabel *luv;
    QComboBox *cbuv;
    QPushButton *pbajouter;

    public :
        AssocierUVWindow(const QString& f);
        /*!
             *  \brief Accès en lecture à la formation
             *
             *
             *  \return l'attribut formation
             */
        QString getFormation() const {return formation;}
    public slots :
        void ajouter();
};

/*! \class AssocierFiliereWindow
  * \brief Classe de la fenêtre pour associer une filière à une branche
  *
  */
class AssocierFiliereWindow : public QWidget{
    Q_OBJECT
    QString branche; /*!< Branche pour laquelle on souhaite associer une filière */

    QVBoxLayout *mainlayout;
    QHBoxLayout *hlayout1;
    QHBoxLayout *hlayout2;
    QLabel *lnom;
    QLineEdit *lenom;
    QPushButton *pbajouter;

    public :
        AssocierFiliereWindow(const QString& b);
        /*!
             *  \brief Accès en lecture à la branche
             *
             *
             *  \return l'attribut branche
             */
        QString getBranche() const {return branche;}
    public slots :
        void ajouter();
};

QString checkSyntax(QString s);

void CompletionProfil(Dossier *dossier);


#endif // UTPROFILER_H
