#include "moteur.hh"

float moteur::resultatm(){
    float resultat=0;

    if(_op=='+') {
        resultat=_o1+_o2 ;
    }
    if(_op=='-') {
        resultat=_o1-_o2 ;
    }
    if(_op=='*') {
        resultat=_o1*_o2 ;
    }
    if(_op=='/') {
        resultat=_o1/_o2 ;
    }

    return resultat;
}


void moteur::majm(float o1, float o2, char op){
    _o1=o1;
    _o2=o2;
    _op=op;
}
