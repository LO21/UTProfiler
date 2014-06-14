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

bool UV::operator!=(UV& other) {
    if (getCode()==other.getCode()) {
        if (getTitre()==other.getTitre()) {
            if (getResponsable()==other.getResponsable()) {
                if (getCreditsCS()==other.getCreditsCS()) {
                    if (getCreditsTM()==other.getCreditsTM()) {
                        if (getCreditsTSH()==other.getCreditsTSH()) {
                            if (getCreditsSP()==other.getCreditsSP()) {
                                if (getAutomne()==other.getAutomne()) {
                                    if (getPrintemps()==other.getPrintemps()) {
                                        return true;}}}}}}}}}
    return false;
}

QString checkSyntax(QString s){
    unsigned int i=0;
    QString res("");
    while (s[i]!='\0') {
        if (s[i]=='\'') {res.append(QString::fromStdString("''"));}
        else {res.append(s[i]);}
        ++i;
    }
    return res;
}
