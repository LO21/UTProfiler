#include "UTProfiler.h"

int main (int argc, char* argv[]) {
    QApplication app(argc, argv);
    QPushButton fermer("Fermer");
    fermer.show();
    return app.exec();
}
