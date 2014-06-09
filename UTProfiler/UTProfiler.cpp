#include "UTProfiler.h"

UTProfilerException::UTProfilerException(const QString& s) {
    QMessageBox::critical(0,"Erreur",s);
}


void UV::getBranche() {
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    branche[0] = sql->tupleExiste(QString::fromStdString("SELECT * FROM AssociationUVBranche WHERE uv = '"+code.toStdString()+"' AND branche = 'TC';"));
    branche[1] = sql->tupleExiste(QString::fromStdString("SELECT * FROM AssociationUVBranche WHERE uv = '"+code.toStdString()+"' AND branche = 'HUTECH';"));
    branche[2] = sql->tupleExiste(QString::fromStdString("SELECT * FROM AssociationUVBranche WHERE uv = '"+code.toStdString()+"' AND branche = 'GB';"));
    branche[3] = sql->tupleExiste(QString::fromStdString("SELECT * FROM AssociationUVBranche WHERE uv = '"+code.toStdString()+"' AND branche = 'GI';"));
    branche[4] = sql->tupleExiste(QString::fromStdString("SELECT * FROM AssociationUVBranche WHERE uv = '"+code.toStdString()+"' AND branche = 'GM';"));
    branche[5] = sql->tupleExiste(QString::fromStdString("SELECT * FROM AssociationUVBranche WHERE uv = '"+code.toStdString()+"' AND branche = 'GP';"));
    branche[6] = sql->tupleExiste(QString::fromStdString("SELECT * FROM AssociationUVBranche WHERE uv = '"+code.toStdString()+"' AND branche = 'GSM';"));
    branche[7] = sql->tupleExiste(QString::fromStdString("SELECT * FROM AssociationUVBranche WHERE uv = '"+code.toStdString()+"' AND branche = 'GSU';"));
}
