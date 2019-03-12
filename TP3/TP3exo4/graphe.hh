#pragma once
#include <string>
#include <list>

using identifiant = unsigned int;

struct arcsortant
{
    std::string etiquette;
    identifiant id;
};


class sommet{
public:
    sommet(std::string const & e)
        :_idsommet(_compteur++),_etiquette(e),_arcssortants(){}

    identifiant id() const{
        return _idsommet;
    }
    std::string etiquette() const{
        return _etiquette;
    }
    void ajouterarc(identifiant s, std::string const & e);
    void supprimerarc(identifiant s);
    void supprimertousarcs();
    void dot_etiquette(std::ostream & o) const;
    void dot_arcssortants(std::ostream & o) const;


private:
    identifiant _idsommet;
    std::string _etiquette;
    std::list<arcsortant> _arcssortants;
    static identifiant _compteur;
};


class graphe{
public:


    identifiant ajoutersommet(std::string const & e);
    bool ajouterarc(identifiant s1, identifiant s2,std::string const & ea);
    void supprimersommet(identifiant extremite);
    void dot_sortie(std::ostream & o)const;

private:
    std::list<sommet>::iterator chercher(identifiant id);
private:
    std::list<sommet> _sommets;
};
