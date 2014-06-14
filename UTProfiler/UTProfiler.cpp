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

bool Dossier::checkMineurCCT() const{
    unsigned int countObligatoire = 0, countTheorique = 0, countCommunication = 0;

    QString qu="SELECT uv, resultat FROM Inscription WHERE login ='";
    qu.append(getLogin());
    qu.append("';");
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    QSqlQuery query = sql->execQuery(qu);


    while(query.next()){
        QString uv = query.value(0).toString();
        QString resultat = query.value(1).toString();

        if (resultat != "FX" && resultat != "F" && resultat != "FX" && resultat != "EC" && resultat != "RES"){ // L'UV a été obtenue
            if (uv == "SI01" || uv == "SI90"){
                countObligatoire++;}
            if (uv == "HE01" || uv == "PH02" || uv == "TN18" || uv == "EI05" || uv == "GE21" || uv == "GE23" || uv == "IR" || uv == "EI03" || uv == "AS01"){
                countTheorique++;}
            if (uv == "SI20" || uv == "SI14" || uv == "SI05" || uv == "SI11" || uv == "DI02" || uv == "AV01" || uv == "PR"){
                countCommunication++;}
        }
    }
    if ((countObligatoire >= 2) && (countTheorique >= 1) && (countCommunication >= 2))
        return true;
    else return false;
}
bool Dossier::checkMineurDDRESET() const{
    unsigned int countIngenieur = 0, countEco = 0, countProjet = 0, countCitoyen = 0, countEthique = 0, countDD01 = 0;

    QString qu="SELECT uv, resultat FROM Inscription WHERE login ='";
    qu.append(getLogin());
    qu.append("';");
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    QSqlQuery query = sql->execQuery(qu);


    while(query.next()){
        QString uv = query.value(0).toString();
        QString resultat = query.value(1).toString();

        if (resultat != "FX" && resultat != "F" && resultat != "FX" && resultat != "EC" && resultat != "RES"){ // L'UV a été obtenue
            if (uv == "DI05" || uv == "DI06"|| uv == "EV01"|| uv == "EV02"|| uv == "EV03" || uv == "BT10" || uv == "BL17" || uv == "TS01" || uv == "TS02" || uv == "FQ01" || uv == "FQ05" || uv == "FQ07" || uv == "HE05" || uv == "EG01" || uv == "MQ07" || uv == "TX" || uv == "BT22" || uv == "UB01" || uv == "UB08"){
                countIngenieur++;}
            if (uv == "GE10" || uv == "GE12" || uv == "GE20" || uv == "GE21" || uv == "GE22" || uv == "GE23" || uv == "GE90"){
                countEco++;}
            if (uv == "GE40" || uv == "PR" || uv == "TN09" || uv == "AP" || uv == "AS01" || uv == "AS02"){
                countProjet++;}
            if (uv == "PH05" || uv == "SO04" || uv == "SO05" || uv == "EI05" || uv == "IR" || uv == "AV" || uv == "SI01"){
                countCitoyen++;}
            if (uv == "PH09" || uv == "SI20" || uv == "EI03" || uv == "IR"){
                countEthique++;}
            if (uv == "DD01"){
                countDD01++;}
        }
    }
    if ((countIngenieur >= 1) && (countEco >= 1) && (countProjet >= 1) && (countCitoyen >= 1) && (countEthique >= 1) && (countDD01 == 1))
        return true;
    else return false;
}
bool Dossier::checkMineurFIRME() const{
    unsigned int countEssentielles = 0, countLangue = 0, countComplementaires = 0;

    QString qu="SELECT uv, resultat FROM Inscription WHERE login ='";
    qu.append(getLogin());
    qu.append("';");
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    QSqlQuery query = sql->execQuery(qu);


    while(query.next()){
        QString uv = query.value(0).toString();
        QString resultat = query.value(1).toString();

        if (resultat != "FX" && resultat != "F" && resultat != "FX" && resultat != "EC" && resultat != "RES"){ // L'UV a été obtenue
            if (uv == "GE21" || uv == "GE90"|| uv == "GE39"|| uv == "GE23"|| uv == "GE35" || uv == "GE22" || uv == "GE29"){
                countEssentielles++;}
            if (uv == "LA06"){
                countLangue++;}
            if (uv == "GE12" || uv == "GE24" || uv == "GE20" || uv == "GE37" || uv == "GE28" || uv == "SO04" || uv == "GE25" || uv == "GE27" || uv == "GE36" || uv == "GE26" || uv == "GE38" || uv == "EE01" || uv == "EE02" || uv == "LA05" || uv == "LA15" || uv == "LA25"){
                countComplementaires++;}
        }
    }
    unsigned int somme = countEssentielles + countLangue + countComplementaires;
    if ((countEssentielles >= 2) && (countLangue == 1) && (somme >= 4))
        return true;
    else return false;
}
bool Dossier::checkMineurINTENT() const{
    unsigned int count1 = 0, count2 = 0;

    QString qu="SELECT uv, resultat FROM Inscription WHERE login ='";
    qu.append(getLogin());
    qu.append("';");
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    QSqlQuery query = sql->execQuery(qu);


    while(query.next()){
        QString uv = query.value(0).toString();
        QString resultat = query.value(1).toString();

        if (resultat != "FX" && resultat != "F" && resultat != "FX" && resultat != "EC" && resultat != "RES"){ // L'UV a été obtenue
            if (uv == "SP22" || uv == "TN15" || uv == "GE39" || uv == "GE15" || uv == "SI02"){
                count1++;}
            if (uv == "GE25" || uv == "GE26" || uv == "GE27" || uv == "GE28" || uv == "GE40" || uv == "DI05"){
                count2++;}
        }
    }
    unsigned int somme = count1 + count2;
    if ((count1 >= 2) && (count2 >= 2) && (somme >= 5))
        return true;
    else return false;
}
bool Dossier::checkMineurPHITECO() const{
    unsigned int count1 = 0, count2 = 0, count3 = 0, count4 = 0;

    QString qu="SELECT uv, resultat FROM Inscription WHERE login ='";
    qu.append(getLogin());
    qu.append("';");
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    QSqlQuery query = sql->execQuery(qu);


    while(query.next()){
        QString uv = query.value(0).toString();
        QString resultat = query.value(1).toString();

        if (resultat != "FX" && resultat != "F" && resultat != "FX" && resultat != "EC" && resultat != "RES"){ // L'UV a été obtenue
            if (uv == "SC11" || uv == "SC12" || uv == "PH03" || uv == "HE02"){
                count1++;}
            if (uv == "SC01" || uv == "AS01"){
                count2++;}
            if (uv == "SC21" || uv == "SC22" || uv == "SC24" || uv == "HE03" || uv == "HE05" || uv == "PH02"){
                count3++;}
            if (uv == "IC05" || uv == "IC07" || uv == "DI01" || uv == "PH09" || uv == "AS02" || uv == "PH02"){
                count4++;}
        }
    }
    unsigned int somme = count1 + count2;
    if ((count1 >= 2) && (count2 >= 1) && (count3 >= 1) && (count4 >= 1))
        return true;
    else return false;
}
bool Dossier::checkMineurST() const{
    unsigned int count1 = 0, count2 = 0, count3 = 0;

    QString qu="SELECT uv, resultat FROM Inscription WHERE login ='";
    qu.append(getLogin());
    qu.append("';");
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    QSqlQuery query = sql->execQuery(qu);


    while(query.next()){
        QString uv = query.value(0).toString();
        QString resultat = query.value(1).toString();

        if (resultat != "FX" && resultat != "F" && resultat != "FX" && resultat != "EC" && resultat != "RES"){ // L'UV a été obtenue
            if (uv == "SP01"){
                count1++;}
            if (uv == "SP02" || uv == "SP22"){
                count2++;}
            if (uv == "GE15"){
                count3++;}

        }
    }
    if ((count1 == 1) && (count2 >= 1) && (count3 == 1))
        return true;
    else return false;
}
bool Dossier::checkMineurTCN() const{

    unsigned int countEssentielles1 = 0, countEssentielles2 = 0, countComplementaires = 0;

    QString qu="SELECT uv, resultat FROM Inscription WHERE login ='";
    qu.append(getLogin());
    qu.append("';");
    InterfaceSQL *sql = InterfaceSQL::getInstance();
    QSqlQuery query = sql->execQuery(qu);


    while(query.next()){
        QString uv = query.value(0).toString();
        QString resultat = query.value(1).toString();

        if (resultat != "FX" && resultat != "F" && resultat != "FX" && resultat != "EC" && resultat != "RES"){ // L'UV a été obtenue
            if (uv == "IC01" || uv == "SI22" || uv == "SI07"){
                countEssentielles1++;}
            if (uv == "IC03" || uv == "IC06" || uv == "IC07" || uv == "AV01" || uv == "SI28"){
                countEssentielles2++;}
            if (uv == "IC05" || uv == "PH10" || uv == "AR03" || uv == "GE21" || uv == "GE28" || uv == "SC22" || uv == "SC23" || uv == "IA03"){
                countComplementaires++;}
        }
    }
    unsigned int somme = countEssentielles1 + countEssentielles2 + countComplementaires;
    if ((countEssentielles1 >= 1) && (countEssentielles2 >= 2) && (somme >= 5))
        return true;
    else return false;
}
