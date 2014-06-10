#include "UTProfiler.h"

InterfaceSQL *InterfaceSQL::instanceUnique=0;

int main (int argc, char* argv[]) {
    QApplication app(argc, argv);
    DossierWindow *fen = new DossierWindow;
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    //sql->load("/Users/Gabou/Dropbox/Cours/GI02/LO21/UTProfiler/formation.sql");
    fen->show();
    return app.exec();

}
