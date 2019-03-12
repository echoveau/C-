#include "position.hh"
#include <sstream>
#include <string>
#include <algorithm>
#include <fstream>


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
    int x =get_p().get_x()+1;
    int y = get_p().get_y();
    position pos(x,y);

    if(get_c()==couleur::Noir){
        pos.set_x(x-2);
    }

    std::cout<<pos.get_x()<<";"<<pos.get_y()<<"\n";

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




std::vector<position> roi::deplacementspossibles() const {
    std::vector<position> v;
    auto const & actuel = get_p();

    for(coordonnee a : {-1,0,1}) {
        for(coordonnee b : {-1,0,1}){
            if(a!=0 && b!=0){
                position pos(actuel.get_x()+a,actuel.get_y()+b);
                if(pos.estvalide()) v.push_back(pos);
            }
        }
    }
    return v;
}


bool piece::accepterposition(position const &p) const{
    for(auto const & it : deplacementspossibles()){
        if(it==p) return true;
    }
    return false;
}

bool piece::deplacer(position const &p){
    if(accepterposition(p)){
        _p=p;
        return true;
    }
    else return false;
}


unsigned int echiquier::valeurdujoueur(couleur c) const {
    unsigned int result(0);
    for(auto const & p : _pieces) {
        if(p->get_c()==c)
            result += p->val();
    }
    return result;
}


bool echiquier::deplacer(const position &src, const position &dst){

    auto fsrc(std::find_if(_pieces.begin(), _pieces.end(), [&src](auto const & p){return p->get_p() == src;}));

    // fsrc     est un itérateur
    // *fsrc    est un objet pointé
    // **fsrc   est la piece

    if (fsrc == _pieces.end())
        return false;
    auto fdst(std::find_if(_pieces.begin(), _pieces.end(), [&dst](auto const & p){return p->get_p() == dst;}));

    if (fdst == _pieces.end())
        return (**fsrc).deplacer(dst);
    else {
        if((**fsrc).get_c() != (**fdst).get_c())
            if((**fsrc).deplacer(dst)){
                _pieces.erase(fdst);
                return true;
            }
        return false;
    }

}


echiquier::echiquier(echiquier const & e) {
    for(auto const & p : e._pieces)
        _pieces.push_back(p->clone());
}


echiquier & echiquier::operator =(echiquier const & e ){
    if(this !=&e){                                  //e.operator=(e) Si on ne vérifie pas, le clear va effacer e alors e=e va effacer e
        _pieces.clear();
        for(auto const & p : e._pieces){
            _pieces.push_back(p->clone());
        }
    }
    return *this;
}


void echiquier::affichage(std::ostream &os) const{
    for(int x=0; x<8; ++x){
        for(int y = 0; y<8; ++y){
            auto f(std::find_if(_pieces.begin(), _pieces.end(), [x,y](auto const & p){return ((p->get_p().get_x() == x) && (p->get_p().get_y() == y));}));
            if(f == _pieces.end())
                os << " ||";
            else
                os <<" " <<std::string() + (*f)->symbole() + (((*f)->get_c()== couleur::Noir) ? "N" : "B");
        }
        os << "\n";
    }


}


void echiquier::sauvegarde(std::ofstream &os) const{
    for(auto const & p : _pieces)
        os << p->tostring() << "\n";
}



void echiquier::chargement(std::ifstream &os){
    while (!os.eof()) {
        std::string line;
        os >> line;
        if(line.empty())
            break;
        position p(line[2]-'0', line[3]-'0');
        couleur c(line[1]=='N' ? couleur::Noir : couleur::Blanc);
        std::unique_ptr<piece> np;

        switch (line[0]) {
            case 'P':
                np = std::make_unique<pion>(c,p);
                break;
            case 'C':
                np = std::make_unique<cavalier>(c,p);
                break;
            case 'D':
                np = std::make_unique<dame>(c,p);
                break;
            case 'R':
                np = std::make_unique<roi>(c,p);
                break;
        }
        _pieces.push_back(std::move(np));
    }
}




bool echiquier::aperdu(couleur c) const{
    return (valeurdujoueur(c)<100);
}






