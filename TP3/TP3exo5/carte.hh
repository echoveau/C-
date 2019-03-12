#pragma once
#include "tailleposition.hh"

enum class deplacement{
    Nord,
    Sud,
    Ouest,
    Est
};


class carte{
public:
    carte(taille t)
        :_taille(t){}

    void ajouterobstacle(obstacle const & ob);
    void ajouterpersonnage(personnage const & pers);
    void ajouterobjetramassable(objetramassable const & ob);
    void affichercarte();
    bool interelement(element const & e1, element const & e2) const;
    bool deplacementpossible(personnage const & p,deplacement d)const;
    void deplacementperso(personnage p, deplacement d);

private:
    bool interintervalles(coordonnee xa, coordonnee ya,coordonnee xb, coordonnee yb) const;
    taille                      _taille;
    std::list<personnage>       _personnages;
    std::list<obstacle>         _obstacles;
    std::list<objetramassable>  _objetsramassables;
};
