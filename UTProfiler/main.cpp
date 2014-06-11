#include "UTProfiler.h"

InterfaceSQL *InterfaceSQL::instanceUnique=0;
//UVManager *UVManager::instanceUnique=0;

int main (int argc, char* argv[]) {
    QApplication app(argc, argv);
    //DossierWindow *fen = new DossierWindow;
    //fen->show();
    UVWindow *fen = new UVWindow();
    InterfaceSQL *sql= InterfaceSQL::getInstance();
    UV *lo21=sql->selectUV("SELECT * FROM UV WHERE code = 'LO21';");
    fen->associerUV(lo21);

    fen->show();
    return app.exec();

}
