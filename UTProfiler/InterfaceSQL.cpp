#include "UTProfiler.h"

/**
 * \file InterfaceSQL.cpp
 * \brief Fichier source où sont implémentées les méthodes de la classe InterfaceSQL
 * \author Gabrielle Rit Timothée Monceaux
 * \version 0.1
 */

/**
 * @brief Méthode permettant de gérer l'existance d'un et d'un seul objet InterfaceSQL
 * @return L'adresse de l'unique objet InterfaceSQL
 */
InterfaceSQL* InterfaceSQL::getInstance() {
    if (instanceUnique==0) {
        instanceUnique = new InterfaceSQL;
    }
    return instanceUnique;
}

/**
 * @brief Méthode permettant de gérer la destruction de l'unique objet InterfaceSQL
 */
void InterfaceSQL::libererInstance() {
    if (instanceUnique!=0) {delete instanceUnique;}
}

/**
 * @brief Constructeur
 *
 * Le constructeur est ici déclaré en privé car la classe InterfaceSQL est un singleton. Il ne peut donc être appelé
 * que par la méthode getInstance(), et uniquement lors de son premier appel.
 * Ce constructeur crée l'unique objet InterfaceSQL et s'occuppe également de la connection à la base de données.
 */
InterfaceSQL::InterfaceSQL() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("UTProfiler.db");
    if (!db.open()) {QMessageBox::critical(0,"Erreur de connexion à  la base de données",db.lastError().text());}
    query = new QSqlQuery(db);
}

/**
 * @brief Méthode permettant de charger un fichier en mémoire
 * Cette méthode ouvre un explorateur de fichier, permettant à l'utilisateur de rechercher un fichier sql, puis
 * le découpe de manière à séparer les différentes requêtes (obligatoire avec SQLITE), puis les exécute une par une.
 * @return True si l'execution a fonctionné, false sinon.
 */
bool InterfaceSQL::load() {
    QString chemin = QFileDialog::getOpenFileName();
    QFile f(chemin);
    if (!f.exists()) {throw UTProfilerException(QString::fromStdString("Erreur : Le fichier '"+chemin.toStdString()+"' n'existe pas.")); return false;}
    if (!f.open(QIODevice::ReadOnly)) {throw UTProfilerException(QString::fromStdString("Erreur : Le fichier '"+chemin.toStdString()+"' ne s'ouvre' pas.")); return false;}
    QTextStream lecture(&f);
    QString s=lecture.readAll();
    unsigned int i=0;
    QString q = "";
    while (s[i]!='\0') {
        if (s[i]==';') {
            q.append(s[i]);
            execQuery(q);
            q.clear();
            i+=3;
        }
        q.append(s[i]);
        ++i;
    }
    return true;
}

/**
 * @brief Méthode permettant de charger un fichier en mémoire
 * Cette méthode est identique à InterfaceSQL::load(), sauf qu'il n'y a pas d'explorateur de fichier, mais que le chemin
 * du fichier à charger est passé en paramètre.
 * @param chemin : Chemin du fichier à charger
 * @return True si l'execution a fonctionné, false sinon.
 */
bool InterfaceSQL::load(const QString &chemin) {
    QFile f(chemin);
    if (!f.exists()) {throw UTProfilerException(QString::fromStdString("Erreur : Le fichier '"+chemin.toStdString()+"' n'existe pas.")); return false;}
    if (!f.open(QIODevice::ReadOnly)) {throw UTProfilerException(QString::fromStdString("Erreur : Le fichier '"+chemin.toStdString()+"' ne s'ouvre' pas.")); return false;}
    QTextStream lecture(&f);
    QString s=lecture.readAll();
    unsigned int i=0;
    QString q = "";
    while (s[i]!='\0') {
        if (s[i]==';') {
            q.append(s[i]);
            execQuery(q);
            q.clear();
            i+=3;
        }
        q.append(s[i]);
        ++i;
    }
    return true;
}

/**
 * @brief Méthode pour l'execution d'une requête SQL quelconque.
 * Cette méthode exécute n'importe quelle requête SQL passée en paramètre et retourne une référence vers l'objet query
 * contenant le résultat de la requête. Pour cette méthode générique, c'est à l'utilisateur de se débrouiller pour obtenir le résultat.
 * @param q : La requête à exécuter
 * @return Une référence vers l'objet QSqlQuery contenant le résultat
 */
QSqlQuery& InterfaceSQL::execQuery(const QString &q) {
    if (!query->exec(q)) {throw UTProfilerException(QString::fromStdString("Erreur : La requête suivante n'a pas fonctionné :\n")+q+QString::fromStdString("\n\nDernière Erreur : ")+query->lastError().text());}
    return *query;
}

/**
 * @brief Méthode pour la séléction d'une UV dans la base de donnée
 * Cette méthode facilite la séléction d'une UV dans la base de donnée. En effet, elle crée un objet UV contenant le
 * premier résultat de la requête passée en paramètre et le retourne.
 * Cette méthode vérifie également que la requête est bien destinée à récupérer une UV.
 * @param q : La requête à executer
 * @return Un pointeur vers un objet UV contenant le premier résultat de la requête.
 */
UV* InterfaceSQL::selectUV(const QString& q) {
    string check1 = "SELECT * FROM UV";
    string check2 = q.toStdString();
    int check3 = check2.find(check1);
    if (check3==-1) {throw UTProfilerException(QString::fromStdString("Erreur sur InterfaceSQL::selectUV(const QString&) : La requête doit être de la forme : 'SELECT * FROM UV'"));}
    if (!query->exec(q)) {throw UTProfilerException(QString::fromStdString("Erreur : La requête suivante n'a pas fonctionné :\n")+q+QString::fromStdString("\n\nDernière Erreur : ")+query->lastError().text());}
    query->next();
    if (query->isValid()) {
        //UVManager *uvm = UVManager::getInstance();
        UV* res = /*uvm->creerItem*/new UV(query->value(0).toString(),query->value(1).toString(),query->value(2).toString(),query->value(3).toUInt(),query->value(4).toUInt(),query->value(5).toUInt(),query->value(6).toUInt(),query->value(7).toBool(),query->value(8).toBool());
        return res;
    }
    else {
        throw UTProfilerException(QString::fromStdString("Erreur : la requête suivante n'a pas fonctionné :\n"+q.toStdString()+"\nL'UV demandée n'existe pas"));
        return 0;
    }
}

/**
 * @brief Méthode pour la séléction de plusieurs UVs dans la base de donnée
 * Cette méthode facilite la séléction de plusieurs UVs dans la base de donnée. En effet, elle crée un tableau d'UVs contenant tous
 * les résultats de la requête passée en paramètre et le retourne.
 * Cette méthode vérifie également que la requête est bien destinée à récupérer des UVs.
 * @param q : La requête à executer
 * @return Un tableau de pointeurs vers des objets UV contenant l'ensemble des résultats de la requête.
 */
UV** InterfaceSQL::getAllUvs(const QString& q) {
    string check1 = "SELECT * FROM UV";
    string check2 = q.toStdString();
    int check3 = check2.find(check1);
    if (check3==-1) {throw UTProfilerException(QString::fromStdString("Erreur sur InterfaceSQL::selectUV(const QString&) : La requête doit être de la forme : 'SELECT * FROM UV'"));}
    if (!query->exec(q)) {throw UTProfilerException(QString::fromStdString("Erreur : La requête suivante n'a pas fonctionné :\n")+q+QString::fromStdString("\n\nDernière Erreur : ")+query->lastError().text());}
    query->next();
    UV** res =new UV*[150];
    unsigned int i=0;
    if (query->isValid()) {
        //UVManager *uvm = UVManager::getInstance();
        while (query->next()) {
            res[i++] = /*uvm->creerItem*/new UV(query->value(0).toString(),query->value(1).toString(),query->value(2).toString(),query->value(3).toUInt(),query->value(4).toUInt(),query->value(5).toUInt(),query->value(6).toUInt(),query->value(7).toBool(),query->value(8).toBool());
            query->next();
        }
    }
    res[i++] = new UV ("fin","","",0,0,0,0,false,false);
    return res;
}

/**
 * @brief Méthode pour la séléction de toutes les Completions de Profil sauvegardées dans la base de donnée
 * Cette méthode facilite la séléction de plusieurs Completions de Profil dans la base de donnée. En effet, elle crée un tableau
 * de Completion de Profils contenant tous les résultats de la requête passée en paramètre et le retourne.
 * @param q : La requête à executer
 * @return Un tableau de tableaux de pointeurs vers des objets QString exploitable pour la completion de Profil constitué de l'ensemble des résultats de la requête.
 */
QString*** InterfaceSQL::selectCompletion(const QString& q) {
    if (!query->exec(q)) {throw UTProfilerException(QString::fromStdString("Erreur : La requête suivante n'a pas fonctionné :\n")+q+QString::fromStdString("\n\nDernière Erreur : ")+query->lastError().text());}
    query->next();
    QString*** res = new QString**[10];
    unsigned int i=0,j;
    if (query->isValid()) {
        while (query->next()) {
            res[i] = new QString*[10];
            for (j=0;j<7;++j) {res[i][j] = new QString(query->value(j+1).toString());}
            ++i;
        }
        res[i]=new QString*[10];
        res[i][0] = new QString("fin");
    }
    return res;
}

/**
 * @brief Méthode pour la séléction d'un Dossier dans la base de donnée
 * Cette méthode facilite la séléction d'un Dossier dans la base de donnée. En effet, elle crée un objet Dossier contenant le
 * premier résultat de la requête passée en paramètre et le retourne.
 * Cette méthode vérifie également que la requête est bien destinée à récupérer un Dossier.
 * @param q : La requête à executer
 * @return Un pointeur vers un objet Dossier contenant le premier résultat de la requête.
 */
Dossier* InterfaceSQL::selectDossier(const QString& q) {
    string check1 = "SELECT * FROM Dossier";
    string check2 = q.toStdString();
    int check3 = check2.find(check1);
    if (check3==-1) {throw UTProfilerException(QString::fromStdString("Erreur sur InterfaceSQL::selectDossier(const QString&) : La requête doit être de la forme : 'SELECT * FROM Dossier'"));}
    if (!query->exec(q)) {throw UTProfilerException(QString::fromStdString("Erreur : La requête :\n")+q+QString::fromStdString("\n n'a pas fonctionné.\nDernière Erreur : ")+query->lastError().text());}
    query->next();
    if (query->isValid()) {
        Dossier* res = new Dossier(query->value(0).toString(),query->value(1).toString(),query->value(2).toString(),query->value(3).toString(),query->value(4).toBool(), query->value(5).toString());
        return res;
    }
    else {
        throw UTProfilerException(QString::fromStdString("Erreur : la requête suivante n'a pas fonctionné :\n"+q.toStdString()+"\nLa Formation demandée n'existe pas"));
        return 0;
    }
}

/**
 * @brief Méthode pour la séléction d'une Formation dans la base de donnée
 * Cette méthode facilite la séléction d'une Formation dans la base de donnée. En effet, elle crée un objet Formation contenant le
 * premier résultat de la requête passée en paramètre et le retourne.
 * Cette méthode vérifie également que la requête est bien destinée à récupérer une Formation.
 * @param q : La requête à executer
 * @return Un pointeur vers un objet Formation contenant le premier résultat de la requête.
 */
Formation* InterfaceSQL::selectFormation(const QString &q) {
    /*string check1 = "SELECT * FROM Formation";
    string check2 = q.toStdString();
    int check3 = check2.find(check1);
    if (check3==-1) {throw UTProfilerException(QString::fromStdString("Erreur sur InterfaceSQL::selectFormation(const QString&) : La requête doit être de la forme : 'SELECT * FROM Formation'"));}
  */if (!query->exec(q)) {throw UTProfilerException(QString::fromStdString("Erreur : La requête :\n")+q+QString::fromStdString("\n n'a pas fonctionné.\nDernière Erreur : ")+query->lastError().text());}
    query->next();
    if (query->isValid()) {
        Formation* res = new Formation(query->value(0).toString(),query->value(1).toString(),query->value(2).toString(),query->value(3).toUInt(),query->value(4).toUInt(), query->value(5).toUInt(), query->value(6).toUInt(), query->value(7).toUInt(), query->value(8).toUInt());
        return res;
    }
    else {
        throw UTProfilerException(QString::fromStdString("Erreur : la requête suivante n'a pas fonctionné :\n"+q.toStdString()+"\nLa Formation demandée n'existe pas"));
        return 0;
    }
}

/**
 * @brief Méthode pour la séléction d'un Semestre dans la base de donnée
 * Cette méthode facilite la séléction d'un Semestre dans la base de donnée. En effet, elle crée un objet Semestre contenant le
 * premier résultat de la requête passée en paramètre et le retourne.
 * Cette méthode vérifie également que la requête est bien destinée à récupérer un Semestre.
 * @param q : La requête à executer
 * @return Un pointeur vers un objet Semestre contenant le premier résultat de la requête.
 */
Semestre* InterfaceSQL::selectSemestre(const QString &q) {
    /*string check1 = "SELECT * FROM Semestre";
    string check2 = q.toStdString();
    int check3 = check2.find(check1);
    if (check3==-1) {throw UTProfilerException(QString::fromStdString("Erreur sur InterfaceSQL::selectSemestre(const QString&) : La requête doit être de la forme : 'SELECT * FROM Semestre'"));}
  */if (!query->exec(q)) {throw UTProfilerException(QString::fromStdString("Erreur : La requête :\n")+q+QString::fromStdString("\n n'a pas fonctionné.\nDernière Erreur : ")+query->lastError().text());}
    query->next();
    if (query->isValid()) {
        Semestre *res;
        if (query->value(0).toChar()=='A') {res = new Semestre(query->value(1).toUInt(),Saison(Automne),query->value(2).toString().toStdString());}
        else {res = new Semestre(query->value(1).toUInt(),Saison(Printemps),query->value(2).toString().toStdString());}
        return res;
    }
    else {
        throw UTProfilerException(QString::fromStdString("Erreur : la requête suivante n'a pas fonctionné :\n"+q.toStdString()+"\nLe Semestre demandé n'existe pas"));
        return 0;
    }
}
