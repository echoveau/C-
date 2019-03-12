#include "position.hh"
#include <sstream>
#include <string>


bool position::operator == (position const & p) const {
    return(_x == p.get_x() && _y == p.get_y());
}


bool position::operator != (position const & p) const{
    /*
    if(_x != p.get_x() || _y != p.get_y()) return true;
    else return false;
    */
    return !operator==(p);
}

position & position::operator = (position const & p){
    _x=p.get_x();
    _y=p.get_y();
    return *this;
}


std::ostream & operator << (std::ostream & os, position const & p){
    os << p.get_x()<<p.get_y()<<std::endl;
    return os;
}


bool position::estvalide() const{
    return(_x<8 && _x>=0 && _y<8 && _y>=0);
}


std::string piece::tostring() const{
    std::ostringstream out;
    char coul = (_c==couleur::Noir) ? 'N' : 'B' ;
    out<<symbole()<<coul<<_p;
    return (out.str());
}



std::vector<position> pion::deplacementspossibles() const{
    std::vector<position> v;
    position pos(get_p().get_x(),get_p().get_y()+1);

    if(get_c()==couleur::Noir){
        pos.set_y(get_p().get_y()-2);
    }

    if(pos.estvalide())
        v.push_back(pos);

    return v;
}

/*
std::vector<position> cavalier::deplacementspossibles() const{
    std::vector<position> v;

    coordonnee x = get_p().get_x();
    coordonnee y = get_p().get_y();

        position pos(x+1,y+2);
        position pos1(x+2,y+1);

        position pos2(x-1,y+2);
        position pos3(x-2,y+1);

        position pos4(x-1,y-2);
        position pos5(x-2,y-1);

        position pos6(x+1,y-2);
        position pos7(x+2,y-1);

    v.push_back(pos);
    v.push_back(pos1);
    v.push_back(pos2);
    v.push_back(pos3);
    v.push_back(pos4);
    v.push_back(pos5);
    v.push_back(pos6);
    v.push_back(pos7);
    return v;
}
*/

std::vector<position> cavalier::deplacementspossibles() const{
    std::vector<position> res;
    auto const & actuel = get_p();
    for(coordonnee a : {-2,2})              //Parcours seulement les valeurs -2 et 2
        for(coordonnee b : {-1,1}){
            position p1(actuel.get_x() + a, actuel.get_y() +b);
            if(p1.estvalide())
                res.push_back(p1);

            position p2(actuel.get_x() +b, actuel.get_y() +a);
            if(p2.estvalide())
                res.push_back(p2);
        }
    return res;
}




std::vector<position> dame::deplacementspossibles() const{
    std::vector<position> v;
    coordonnee x = get_p().get_x();
    coordonnee y = get_p().get_y();


    for(int i=0;i<8; ++i){
            if(i!=x){
                position p1(i,y);
                    if(p1.estvalide())
                        v.push_back(p1);
            }
            if(i!=y){
                position p2(x,i);
                    if(p2.estvalide())
                        v.push_back(p2);
            }

            if(i!=0){
                position p3(x+i,y+i);
                position p4(x-i,y-i);
                position p5(x-i,y+i);
                position p6(x+i,y-i);

                if(p3.estvalide())
                    v.push_back(p3);
                if(p4.estvalide())
                    v.push_back(p4);
                if(p5.estvalide())
                    v.push_back(p5);
                if(p6.estvalide())
                    v.push_back(p6);
            }


    }

    /*
    for (int i=x;i<8;++i){
        v.push_back(position(i,i));
        v.push_back(position(i,-i));
    }
    for (int i=0;i<x;++i){
        v.push_back(position(i,i));
        v.push_back(position(i,-i));
    }
    */
    return v;
}


std::vector<position> roi::deplacementspossibles() const{
    std::vector<position> res;
    auto const & actuel = get_p();
    for(coordonnee a : {-1,0,1})              //Parcours seulement les valeurs -2 et 2
        for(coordonnee b : {-1,0,1}){
            position p1(actuel.get_x() + a, actuel.get_y() +b);
            if(p1.estvalide() && (a!=0 || b!=0))
                res.push_back(p1);
        }
    return res;
}


bool piece::accepterposition(position const &p)const {
    std::vector<position> v;
    v=this->deplacementspossibles();

    bool test =false;
    for(auto i : v){
        if(i==p)
            test=true;
    }
    return test;
}


bool piece::deplacer(const position &destination){
    if(this->accepterposition(destination)){
        _p=destination;
        return true;
    }
    else return false;
}











