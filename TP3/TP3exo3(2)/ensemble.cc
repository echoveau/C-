#include "ensemble.hh"
#include <algorithm>
//////////////////////ENSEMBLE//////////////////////////

void ensemble::ajouter(int x) {
    if(!contient(x)) {
        ajoutersansverifier(x);
    }
}

parcours ensemble::commencer() const {
    parcours p;
    return p;
}

void ensemble::suivant(parcours &p) const {
    p.passersuivant();
}

/*void ensemble::union_ensemble(ensemble &e2) {
    this->init_indice();
    while(!this->est_fini()) {
        e2.ajouter(this->element_courant());
        this->inc_indice();
    }
}*/

//////////////////////ENSEMBLETABLEAU//////////////////////////


ensembletableau::ensembletableau()
    :_taille(0),_Ens(nullptr) {
}

ensembletableau::ensembletableau(ensembletableau const &e)
    :_taille(e._taille),
    _Ens( (e._taille==0) ? nullptr : new int[e._taille] ){
    for(std::size_t i=0; i<e._taille; ++i)
        _Ens[i]=e._Ens[i];
}

ensembletableau::~ensembletableau() {
    delete[]_Ens;
}

bool ensembletableau::contient(int x) const {
    for(std::size_t i=0; i<_taille; ++i)
            if(_Ens[i]==x) return true;
    return false;

}

bool ensembletableau::estvide() const {
    return _taille!=0;
}

void ensembletableau::ajoutersansverifier(int x) {
    int *Ens_aux= new int[_taille];

    for(std::size_t i=0; i<_taille; ++i)
        Ens_aux[i]=_Ens[i];

    Ens_aux[_taille]=x;
    _taille++;
    if(_Ens!=nullptr)
        delete []_Ens;
    _Ens=Ens_aux;
}

void ensembletableau::afficher() {
    if(_taille!=0) {
        std::cout << "[ ";
        for(std::size_t i=0; i<_taille; ++i) {
            std::cout << _Ens[i] << " ";
        }
        std::cout << "]\n";
    }
    else std::cout << "[Ensemble vide] \n";
}

void ensembletableau::supprimer(int x) {
    for(std::size_t i=0; i<_taille; ++i)
        if(_Ens[i] == x) {
            _Ens[i] = _Ens[_taille-1];
            _taille--;
            return;
        }
}




//////////////////////ENSEMBLEVECTOR//////////////////////////

bool ensemblevector::contient(int x) const {
    /*for(std::size_t i=0; i<_taille; ++i)
            if(_Ens.at(i)==x) return true;
    return false;*/
    return std::find(_Ens.begin(),_Ens.end(), x) != _Ens.end();
}

bool ensemblevector::estvide() const {
    return _Ens.empty();
}

void ensemblevector::ajoutersansverifier(int x) {
    _Ens.push_back(x);
}

void ensemblevector::afficher() {
    if(!_Ens.empty()) {
        std::cout << "[ ";
        for(auto i : _Ens) {
            std::cout << i << " ";
        }
        std::cout << "]\n";
    }
    else std::cout << "[Ensemble vide] \n";
}

void ensemblevector::supprimer(int x) {
    auto i = std::find(_Ens.begin(), _Ens.end(), x);
    if( i != _Ens.end()) {
        _Ens.erase(i);
    }
}


bool ensemblevector::estfini(parcours const &p) const {
    return p.element() >= _Ens.size();
}
int ensemblevector::courant(parcours const &p) const {
    return _Ens[p.element()];
}



