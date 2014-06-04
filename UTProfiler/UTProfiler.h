#ifndef UTPROFILER_H
#define UTPROFILER_H

#include <iostream>
#include <string>
#include <QString>
#include <QApplication>
#include <QPushButton>
#include <QtSql>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

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

class UV {
    string code;
    string titre;
    string responsable;
    unsigned int creditsCS;
    unsigned int creditsTM;
    unsigned int creditsTSH;
    unsigned int creditsSP;
    bool printemps;
    bool automne;
   public :
    UV();//à voir : c'est à UVManager de gérer leurs cycles de vie
    string getCode() const {return code;}
    string getTitre() const {return titre;}
    string getResponsable() const {return responsable;}
    unsigned int getCreditsCS() const {return creditsCS;}
    unsigned int getCreditsTM() const {return creditsTM;}
    unsigned int getCreditsTSH() const {return creditsTSH;}
    unsigned int getCreditsSP() const {return creditsSP;}
    bool getPrintemps() const {return printemps;}
    bool getAutomne() const {return automne;}
    void setCode(const string& s) {code=s;}
    void setTitre(const string& s) {titre=s;}
    void getCreditsCS(unsigned int cs) {creditsCS=cs;}
    void getCreditsTM(unsigned int tm) {creditsTM=tm;}
    void getCreditsTSH(unsigned int tsh) {creditsTSH=tsh;}
    void getCreditsSP(unsigned int sp) {creditsSP=sp;}
    void setPrintemps (bool b) {printemps=b;}
    void setAutomne (bool b) {automne=b;}
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
    Semestre(unsigned int a, Saison s, string c="");// ???
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
    string login;
    string nom;
    string prenom;
    string conseiller;
    bool validationAEU;
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
    Dossier();
    ~Dossier();
    string getLogin() const {return login;}
    string getNom() const {return nom;}
    string getPrenom() const {return prenom;}
    string getConseiller() const {return conseiller;}
    bool getValidationAEU() const {return validationAEU;}
    void setLogin (const string& s) {login=s;}
    void setNom (const string& s) {nom=s;}
    void setPrenom (const string& s) {prenom=s;}
    void setConseiller (const string& s) {conseiller=s;}
    void setValidationAEU (bool b) {validationAEU=b;}
    void checkMineurs();
    void checkMineurCCT();
    void checkMineurDDRESET();
    void checkMineurFIRME();
    void checkMineurINTENT();
    void checkMineurPHITECO();
    void checkMineurST();
    void checkMineurTCN();
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
    string nom;
    string responsable;
    string *uvs;
    unsigned int nbCreditsTot;
    unsigned int nbCreditsCS;
    unsigned int nbCreditsTM;
    unsigned int nbCreditsTSH;
    unsigned int nbCreditsSP;
};

class Manager {
    Manager();
    Manager(Manager& copy);
    Manager& operator=(Manager& other);
   public :
    virtual Manager* getInstance()=0;
    virtual void libererInstance()=0;
};

class UVManager : public Manager {
    UV *uvs;
   public :
    UV* trouverUV(const string& s);
    void ajouterUV();
    void supprimerUV();
    void modifierUV();
};

class FormationManager : public Manager {
    Formation *formations;
   public :
    Formation* trouverFormation(const string& s);
    void ajouterFormation();
    void supprimerFormation();
    void modifierFormation();
};

class DossierManager : public Manager {
    Dossier *dossiers;
   public :
    Dossier* trouverDossier(const string& s);
    void ajouterDossier();
    void supprimerDossier();
    void modifierDossier();
};

class InterfaceSQL {
    static InterfaceSQL *instanceUnique;
    QSqlDatabase db;
    QSqlQuery *query;
    InterfaceSQL();
    InterfaceSQL(InterfaceSQL& copy) {throw UTProfilerException("Erreur : Un objet InterfaceSQL existe déjà.");}
    InterfaceSQL& operator=(InterfaceSQL& other) {throw UTProfilerException("Erreur : Un objet InterfaceSQL existe déjà."); return other;}
    ~InterfaceSQL() {}
   public :
    static InterfaceSQL* getInstance();
    static void libererInstance();
    bool load();
    bool load(const QString& chemin);
    QSqlQuery& execQuery(const QString& q);
};

#endif // UTPROFILER_H
