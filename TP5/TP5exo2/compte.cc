#include "compte.hh"
#include <sstream>
#include <string>
#include <iostream>


int compte::_compteur(1);

std::ostream & operator <<(std::ostream & os, proprietaire const & p){
    p.sortie(os);
    return os;
}

std::ostream & operator <<(std::ostream & os, compte const & c){
    c.sortie(os);
    return os;
}

void compte::verser(int espece){
    _montant += espece;
}

void compte::retirer(int espece){
    _montant -= espece;
}


void compte::virer(compte debite, int montant){
    if(_pp==debite.get_pp()){
        debite.retirer(montant);
        this->verser(montant);
    }
    else{
        debite.retirer(montant+1);
        this->verser(montant);
    }
}
