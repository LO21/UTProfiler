#include "UTProfiler.h"

InterfaceSQL *InterfaceSQL::instanceUnique=0;

int main (int argc, char* argv[]) {
    QApplication app(argc, argv);
    InterfaceSQL *interfacesql = InterfaceSQL::getInstance();
    //interfacesql->load("/Users/Gabou/Dropbox/Cours/GI02/LO21/UTProfiler/dossier.sql");
    DossierWindow *fen = new DossierWindow;
    //UV* test=interfacesql->selectUV("SELECT * FROM UV WHERE code='LO21';");
    //fen->associerUV(test);
    fen->show();
    return app.exec();

}
