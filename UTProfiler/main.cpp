#include "UTProfiler.h"

InterfaceSQL *InterfaceSQL::instanceUnique=0;

int main (int argc, char* argv[]) {
    QApplication app(argc, argv);
    UVWindow fen;
    fen.show();
    return app.exec();
}
