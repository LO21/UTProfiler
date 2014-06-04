#include "UTProfiler.h"

InterfaceSQL *InterfaceSQL::instanceUnique=0;

int main (int argc, char* argv[]) {
    QApplication app(argc, argv);
    InterfaceSQL* sql = InterfaceSQL::getInstance();
    sql->load();
    QPushButton fermer("Fermer");
    QObject::connect(&fermer,SIGNAL(clicked()),&fermer,SLOT(close()));
    fermer.show();
    return app.exec();
}
