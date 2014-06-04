#include "UTProfiler.h"

InterfaceSQL *InterfaceSQL::instanceUnique=0;

int main (int argc, char* argv[]) {
    QApplication app(argc, argv);
    InterfaceSQL* sql = InterfaceSQL::getInstance();
    sql->load();
    sql->execQuery("CREATE TABLE test (nom VARCHAR(20), num INTEGER(10))");
    /*QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("test");
        if (!db.open()) {QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());}
        QSqlQuery query;
        if(!query.exec("SELECT code FROM uv;")) QMessageBox::critical(0,"erreur",query.lastError().text());
    query.next();*/
    QPushButton fermer("Fermer");
    QObject::connect(&fermer,SIGNAL(clicked()),&fermer,SLOT(close()));
    fermer.show();
    return app.exec();
}
