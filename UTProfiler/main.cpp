#include "UTProfiler.h"

InterfaceSQL *InterfaceSQL::instanceUnique=0;
//UVManager *UVManager::instanceUnique=0;

int main (int argc, char* argv[]) {
    QApplication app(argc, argv);
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    //sql->load("G:\\Documents\\LO21\\UTProfiler\\build-UTProfiler-Desktop-Debug\\tsh.sql");
    HomeWindow *fen = new HomeWindow();
    fen->show();
    return app.exec();

}
