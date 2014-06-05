#include "UTProfiler.h"

InterfaceSQL *InterfaceSQL::instanceUnique=0;

int main (int argc, char* argv[]) {
    QApplication app(argc, argv);
    InterfaceSQL *interfacesql = InterfaceSQL::getInstance();
    UVWindow *fen = new UVWindow;
    UV* test=interfacesql->selectUV("SELECT * FROM UV WHERE code='LO21';");
    fen->associerUV(test);
    fen->show();
    return app.exec();
}
