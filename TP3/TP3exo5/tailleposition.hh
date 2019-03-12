#pragma once
#include <iostream>
#include <list>

using coordonnee = int;
using nbpoints = int;


//                      POSITION
//#################################################################################################################
class position
{
public:
    position(coordonnee x, coordonnee y);
    position(position const & c) =default;

    coordonnee const & get_x() const
    {
        return _x;
    }
    coordonnee const & get_y() const
    {
        return _y;
    }

    void mutateur_x(coordonnee new_x)
    {
        _x=new_x;
    }
    void mutateur_y(coordonnee new_y)
    {
        _y=new_y;
    }

    bool comparaison(position const & c);

    std::string tostring() const;

private:
    coordonnee _x;
    coordonnee _y;
};



//                              TAILLE
//#################################################################################################################
class taille
{
public:
    taille(coordonnee l,coordonnee h)
        :_largeur(l),_hauteur(h){}

    coordonnee const & get_largeur() const
    {
        return _largeur;
    }
    coordonnee const & get_hauteur() const
    {
        return _hauteur;
    }

    void mutateur_largeur(coordonnee new_largeur)
    {
        _largeur=new_largeur;
    }
    void mutateur_hauteur(coordonnee new_hauteur)
    {
        _hauteur=new_hauteur;
    }

    std::string tostring() const;

private:
    coordonnee _largeur;
    coordonnee _hauteur;
};


//                      ELEMENT
//#################################################################################################################
class element
{
public:
    element(position const & p, taille const & t)
        :_p(p),_t(t){}

    position const & get_p() const
    {
        return _p;
    }
    taille const & get_t() const
    {
        return _t;
    }
    void mut_p(position const & p2){
        _p=p2;
    }

    std::string tostring() const;

    bool contientposition(position const & p) const;

private:
    position _p;
    taille _t;
};



//                      OBSTACLE
//#################################################################################################################
class obstacle:public element {
public:
    obstacle(position const & p, taille const & t)
        :element(p,t){}
};



class objetramassable:public element {

public:
    objetramassable (position const & p, taille const & t, nbpoints nb)
        :element(p,t),_nbpointsobjet(nb){}

    std::string tostring() const;

    nbpoints const & get_nbpointsobjet() const
    {
        return _nbpointsobjet;
    }

private:
    nbpoints _nbpointsobjet;
};



//                          PERSONNAGE
//#################################################################################################################
class personnage:public element {


public:
    personnage (position const & p, taille const & t,std::string const & n)
        :element(p,t),_acquis(0),_nom(n){}

    nbpoints const & get_acquis() const
    {
        return _acquis;
    }
    std::string const & get_nom() const
    {
        return _nom;
    }
    std::string tostring() const;
    void ramasser(objetramassable const & o);


private:
    nbpoints _acquis;
    std::string _nom;

};



