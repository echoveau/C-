#include "ensemble.hh"
#include <algorithm>



bool ensembletableau::contient(int x) const{

    if(_indtab==0){
        return false;
    }
    else{
        indicesequence i=0;

        while(i<_indtab)
        {
            if(_tab[i]==x)
            {
                return true;
            }
            ++i;
        }

        return false;
    }
}

bool ensemblevector::contient(int x) const{
    return std::find(_vec.begin(),_vec.end(), x) != _vec.end();
}


//###################################################################"

bool ensembletableau::estvide() const{
    return _indtab==0;
}


bool ensemblevector::estvide() const{
    return _vec.empty();
}


//###################################################################"

void ensemble::ajouter(int x){
    if(!contient(x))
        ajoutersansverifier(x);
}

void ensembletableau::ajoutersansverifier(int x){
    _tab[_indtab]=x;
    ++_indtab;
}


void ensemblevector::ajoutersansverifier(int x){
    _vec.push_back(x);
}

//####################################################################

void ensembletableau::afficher(){
    for(int i=0; i<_indtab;++i)
    {
        std::cout<<" "<<_tab[i];
    }
    std::cout<<std::endl;
}

void ensemblevector::afficher(){
    for(auto i : _vec)
    {
        std::cout<<" "<<i;
    }
    std::cout<<std::endl;
}

//####################################################################

/*  Supprime seulement la première itération
 *
   void ensembletableau::supprimer(int x){

    indicesequence s=_indtab+1;

    for(int i=0; i<_indtab;++i)
    {
        if(_tab[i]==x){
            s=i;
            _tab[i]=_tab[i+1];
        }
        if(i>s){
            _tab[i]=_tab[i+1];
        }
    }
    --_indtab;
}

void ensemblevector::supprimer(int x){

}
*/


//Supprime également les doublons
void ensembletableau::supprimer(int x){
    indicesequence i=0;

    while(i<_indtab)
    {
        if(_tab[i]==x){
            for(int j=i; j<_indtab; ++j){
                _tab[j]=_tab[j+1];
            }
            --_indtab;
        }

        ++i;
    }

}

void ensemblevector::supprimer(int x){
    auto i = std::find(_vec.begin(), _vec.end(), x);
    if( i != _vec.end()) {
        _vec.erase(i);
    }
}

//####################################################################

parcours ensemble::commencer() const{
    parcours p;
    return p;
}

//####################################################################

bool ensembletableau::estfini(parcours const &p) const{
    return p.element() >= _indtab;
}

bool ensemblevector::estfini(parcours const &p) const{
    return p.element() >= _vec.size();
}

//####################################################################

void ensemble::suivant(parcours &p) const{
    p.passerausuivant();
}

//####################################################################

int ensembletableau::courant(parcours const & p) const {
    return _tab[p.element()];
}


int ensemblevector::courant(parcours const & p) const {
    return _vec[p.element()];
}

//####################################################################

void ensemble::unionens(const ensemble &e1, const ensemble &e2){
    vider();
    for(auto p=e1.commencer(); !e1.estfini(p); e1.suivant(p))
        this->ajouter(e1.courant(p));
    for(auto p=e2.commencer(); !e2.estfini(p); e2.suivant(p))
        this->ajouter(e2.courant(p));
}


void ensemble::interens(const ensemble &e1, const ensemble &e2){
    for(auto p1=e1.commencer(); !e1.estfini(p1); e1.suivant(p1))
        for(auto p2=e2.commencer(); !e2.estfini(p2); e2.suivant(p2))
        {
            if(e1.courant(p1)==e2.courant(p2))
                this->ajouter(e1.courant(p1));
        }
}






















