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
    string intitule;
    string responsable;
    unsigned int *nbCredits;
    Categorie *categorie;
    bool printemps;
    bool automne;
    //unsigned int nbCategories;
};

class Inscription {
    string uv;
    Resultat resultat;
};

class Semestre {
    unsigned int annee;
    Saison saison;
    Inscription *inscriptions;
    string commentaire;
};

class Dossier {
    string login;
    string nom;
    string prenom;
    string conseiller;
    bool validationAEU;
    Semestre *semestres;
};

class UVManager {
    //Singleton
};

#endif // UTPROFILER_H
