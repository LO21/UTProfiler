#include "UTProfiler.h"

InterfaceSQL *InterfaceSQL::instanceUnique=0;
//UVManager *UVManager::instanceUnique=0;

int main (int argc, char* argv[]) {
    QApplication app(argc, argv);
<<<<<<< HEAD
    DossierWindow *fen = new DossierWindow;
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    sql->load("/Users/Gabou/Dropbox/Cours/GI02/LO21/UTProfiler/formation.sql");

=======
    //DossierWindow *fen = new DossierWindow;
    //fen->show();
    UVWindow *fen = new UVWindow();
    InterfaceSQL *sql= InterfaceSQL::getInstance();
    UV *lo21=sql->selectUV("SELECT * FROM UV WHERE code = 'LO21';");
    fen->associerUV(lo21);
>>>>>>> f8a3bcff64b1c5ce29040df037482e2c698eef32

    fen->show();
    return app.exec();

}
