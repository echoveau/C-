#include "tailleposition.hh"
#include <sstream>
#include <string>
#include <iostream>

position::position(coordonnee x, coordonnee y)
    :_x(x),_y(y){

}

/*position::position(position const & c)
    :_x(c._x),_y(c._y){

}*/

bool position::comparaison(position const & c){

    return((c._x==_x) && (c._y==_y));
}


std::string position::tostring() const
{
    std::ostringstream out;
    out << _x <<" "<< _y;
    std::string s(out.str());
    return  s;
}

std::string taille::tostring() const
{
    std::ostringstream out;
    out << _largeur <<" "<< _hauteur;
    std::string s(out.str());
    return  s;
}

std::string element::tostring() const
{
    return ("Taille : " + _p.tostring() + "       Position : "  + _t.tostring());
}


bool element::contientposition(position const & p) const
{
    return ((p.get_x()<=(_p.get_x()+_t.get_largeur())
             && p.get_x()>=_p.get_x())
             && (p.get_y()<=(_p.get_y()+_t.get_hauteur())
             && p.get_y()>=_p.get_y()));
}


std::string objetramassable::tostring() const
{
    return (element::tostring() + "       NbPoints : " + std::to_string(_nbpointsobjet));
}

std::string personnage::tostring() const
{
    return (element::tostring() + "       NbPoints Acquis : " + std::to_string(_acquis) +"         Nom : " + _nom);
}




void personnage::ramasser(objetramassable const & o)
{
    _acquis += o.get_nbpointsobjet();
}
