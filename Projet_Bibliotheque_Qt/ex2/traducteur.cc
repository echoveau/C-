#include "traducteur.hh"

QString traducteur::resultat(){
    return QString::fromStdString(std::to_string(_m.resultatm()));
}


void traducteur::maj(float o1, float o2, char op){
    _m.majm(o1,o2,op);
}

