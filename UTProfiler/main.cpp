#include "UTProfiler.h"

InterfaceSQL *InterfaceSQL::instanceUnique=0;

int main (int argc, char* argv[]) {
    QApplication app(argc, argv);
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    sql->load();
    sql->load();
    sql->load();
    sql->load();
    sql->load();
    sql->load();
    DossierWindow *fen = new DossierWindow;
    fen->show();
    return app.exec();

}
