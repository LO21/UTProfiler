#ifndef UTPROFILER_H
#define UTPROFILER_H

#include <iostream>
#include <string>
#include <QApplication>
#include <QPushButton>

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

class UV {
    string code;
    string titre;
    string responsable;
    unsigned int nbCredits;
    Categorie categorie;
    bool printemps;
    bool automne;
    //unsigned int nbCategories;
   public :
    UV();//à voir
    string getCode() const;
    string getTitre() const;
    string getResponsable() const;
    Categorie getCategorie() const;
    unsigned int getNbCredits() const;
    bool getPrintemps() const;
    bool getAutomne() const;
};

class Inscription {
    string uv;
    Resultat resultat;
   public :
    Inscription();
    string getUV() const;
    Resultat getResultat() const;
    void setResultat(Resultat r);
};

class FormationExterieure { //à revoir si stage => formations exterieures
    string nom;
    string lieu;
    unsigned int creditsCS;
    unsigned int creditsTM;
    unsigned int creditsTSH;
    unsigned int creditsSP;
   public :
    FormationExterieure();
    ~FormationExterieure();
    string getNom() const;
    string getLieu() const;
    unsigned int getCreditsCS() const;
    unsigned int getCreditsTM() const;
    unsigned int getCreditsTSH() const;
    unsigned int getCreditsSP() const;
};

class Semestre {
    unsigned int annee;
    Saison saison;
    string commentaire;
    Inscription *inscriptions;
    bool ext;
    FormationExterieure *formationsExt;
   public :
    Semestre();
    ~Semestre();
    unsigned int getAnnee() const;
    Saison getSaison() const;
    string getCommentaire() const;
    bool getExt() const;
};

class Dossier {
    string login;
    string nom;
    string prenom;
    string conseiller;
    bool validationAEU;
    Semestre *semestres;
   public :
    Dossier();
    ~Dossier();
    string getLogin() const;
    string getNom() const;
    string getPrenom() const;
    string getConseiller() const;
    bool getValidationAEU() const;
};

class Formation { //à retravailler
};

class UVManager {
    //Singleton
};

class FormationManager {
    //Singleton
};

#endif // UTPROFILER_H
