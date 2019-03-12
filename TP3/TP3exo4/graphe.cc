#include "graphe.hh"
#include <iostream>
#include <algorithm>

identifiant sommet::_compteur(0);

void sommet::ajouterarc(identifiant s, std::string const & e){
    arcsortant as;
    as.etiquette=e;
    as.id=s;
    _arcssortants.push_back(as);
}


void sommet::supprimerarc(identifiant s){

    for(auto i=_arcssortants.begin(); i!=_arcssortants.end();)
    {
        if((*i).id==s)
            _arcssortants.erase(i);
        else
            ++i;
    }

   // _arcssortants.remove_if([extremite](auto const & a){return a.id()==extremite;});
}


void sommet::supprimertousarcs(){
    auto i=_arcssortants.begin();
    while(i!=_arcssortants.end())
        _arcssortants.pop_back();
}


void sommet::dot_etiquette(std::ostream & o) const{
    o << "c"<<_idsommet<<" [label=\""<<_etiquette<<"\"];";
}


void sommet::dot_arcssortants(std::ostream &o) const{
    for(auto i : _arcssortants)
    {
        o << "c"<<_idsommet<<" -> c"<<i.id<<" ; ";
    }
    o<<"\n";
}


//                      GRAPHE
//###############################################################################

identifiant graphe::ajoutersommet(const std::string &e){
    sommet s(e);
    _sommets.push_back(s);
    return s.id();
}


std::list<sommet>::iterator graphe::chercher(identifiant id){
    return std::find_if(_sommets.begin(),_sommets.end(), [id](auto & a){return a.id()==id;});
}

bool graphe::ajouterarc(identifiant s1, identifiant s2,std::string const & ea){
    auto is1(chercher(s1));
    auto is2(chercher(s2));

    if((is1==_sommets.end()) || (is2==_sommets.end()))
        return false;

    is1->ajouterarc(s2,ea);
    return true;

}


void graphe::supprimersommet(identifiant s){


    for(auto i=_sommets.begin(); i!=_sommets.end();)
    {
        if((*i).id()==s)
            _sommets.erase(i);
        else
            ++i;

        (*i).supprimerarc(s);
    }

}



void graphe::dot_sortie(std::ostream &o) const{

    o << "disgraph g {"<<"\n";
    for(auto i : _sommets){
        i.dot_etiquette(o);
                o <<"\n";
        i.dot_arcssortants(o);
                o <<"\n";
    }
    o <<"}"<<"\n";
}











