#include "UTProfiler.h"

InterfaceSQL *InterfaceSQL::instanceUnique=0;

int main (int argc, char* argv[]) {
    QApplication app(argc, argv);
    //InterfaceSQL *sql = InterfaceSQL::getInstance();
    //sql->load();
    HomeWindow *fen = new HomeWindow();
    fen->show();
    return app.exec();
}
