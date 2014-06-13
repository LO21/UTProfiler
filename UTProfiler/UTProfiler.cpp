#include "UTProfiler.h"

UTProfilerException::UTProfilerException(const QString& s) {
    QMessageBox::critical(0,"Erreur",s);
}


bool* UV::getBranche() {
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    branche[0] = sql->tupleExiste(QString::fromStdString("SELECT * FROM AssociationFormationUV WHERE uv = '"+getCode().toStdString()+"' AND formation = 'TC';"));
    branche[1] = sql->tupleExiste(QString::fromStdString("SELECT * FROM AssociationFormationUV WHERE uv = '"+getCode().toStdString()+"' AND formation = 'HUTECH';"));
    branche[2] = sql->tupleExiste(QString::fromStdString("SELECT * FROM AssociationFormationUV WHERE uv = '"+getCode().toStdString()+"' AND formation = 'GB';"));
    branche[3] = sql->tupleExiste(QString::fromStdString("SELECT * FROM AssociationFormationUV WHERE uv = '"+getCode().toStdString()+"' AND formation = 'GI';"));
    branche[4] = sql->tupleExiste(QString::fromStdString("SELECT * FROM AssociationFormationUV WHERE uv = '"+getCode().toStdString()+"' AND formation = 'GM';"));
    branche[5] = sql->tupleExiste(QString::fromStdString("SELECT * FROM AssociationFormationUV WHERE uv = '"+getCode().toStdString()+"' AND formation = 'GP';"));
    branche[6] = sql->tupleExiste(QString::fromStdString("SELECT * FROM AssociationFormationUV WHERE uv = '"+getCode().toStdString()+"' AND formation = 'GSM';"));
    branche[7] = sql->tupleExiste(QString::fromStdString("SELECT * FROM AssociationFormationUV WHERE uv = '"+getCode().toStdString()+"' AND formation = 'GSU';"));
    return branche;
}

QString checkSyntax(QString s){
    unsigned int i=0;
    while (s[i]!='\0') {
        if (s[i]=='\'') {s.insert(i,'\'');}
        ++i;
    }
    return s;
}
