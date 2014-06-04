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

bool InterfaceSQL::load() { //une barre de chargement ?
    QString msgerr;
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
    if (!query->exec(q)) {throw UTProfilerException(QString::fromStdString("Erreur : La requête :\n")+q+QString::fromStdString("\n n'a pas fonctionné.\nDernière Erreur : ")+query->lastError().text());}
    return *query;
}
