#include "UTProfiler.h"

InterfaceSQL *InterfaceSQL::instanceUnique=0;

int main (int argc, char* argv[]) {
    QApplication app(argc, argv);
<<<<<<< HEAD
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    sql->load();
    sql->load();
    sql->load();
    sql->load();
    sql->load();
    sql->load();
    DossierWindow *fen = new DossierWindow;
=======
    DossierWindow *fen = new DossierWindow;
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    //sql->load("G:\\Documents\\LO21\\UTProfiler\\formation.sql");
>>>>>>> b166c9b65c3d4937d3d0ddab2ffea1806a57cb78
    fen->show();
    return app.exec();

}
