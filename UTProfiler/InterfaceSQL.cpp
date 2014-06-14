#include "UTProfiler.h"

InterfaceSQL* InterfaceSQL::getInstance() {
    if (instanceUnique==0) {
        instanceUnique = new InterfaceSQL;
    }
    return instanceUnique;
}

void InterfaceSQL::libererInstance() {
    if (instanceUnique!=0) {delete instanceUnique;}
}

InterfaceSQL::InterfaceSQL() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("UTProfiler.db");
    if (!db.open()) {QMessageBox::critical(0,"Erreur de connexion à  la base de données",db.lastError().text());}
    query = new QSqlQuery(db);
}

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

QSqlQuery& InterfaceSQL::execQuery(const QString &q) {
    if (!query->exec(q)) {throw UTProfilerException(QString::fromStdString("Erreur : La requête suivante n'a pas fonctionné :\n")+q+QString::fromStdString("\n\nDernière Erreur : ")+query->lastError().text());}
    return *query;
}

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

Semestre* InterfaceSQL::selectSemestre(const QString &q) {
    if (!query->exec(q)) {throw UTProfilerException(QString::fromStdString("Erreur : La requête :\n")+q+QString::fromStdString("\n n'a pas fonctionné.\nDernière Erreur : ")+query->lastError().text());}
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
