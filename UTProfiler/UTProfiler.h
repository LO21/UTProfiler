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

class Dossier {
    //friend class DossierManager;
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
    QPushButton *pbannuler;
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
    void annuler();
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
    QPushButton *pbannuler;
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
