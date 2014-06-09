#include "UTProfiler.h"

InterfaceSQL *InterfaceSQL::instanceUnique=0;

int main (int argc, char* argv[]) {
    QApplication app(argc, argv);
    UVWindow *fen = new UVWindow;
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    UV* test = sql->selectUV("SELECT * FROM UV WHERE code='LO21';");
    fen->associerUV(test);
    fen->show();
    return app.exec();
}
