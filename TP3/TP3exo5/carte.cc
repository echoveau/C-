#include "carte.hh"

void carte::ajouterobstacle(const obstacle &ob){
    _obstacles.push_back(ob);
}

void carte::ajouterobjetramassable(const objetramassable &ob){
    _objetsramassables.push_back(ob);
}

void carte::ajouterpersonnage(const personnage &pers){
    _personnages.push_back(pers);
}


void carte::affichercarte(){
    std::cout<<"TAILLE :"<<_taille.tostring()<<"\n";
    std::cout<<"\n";

    std::cout<<"PERSONNAGES : "<<"\n";
    for(auto i : _personnages)
    {
        std::cout<<i.tostring()<<"\n";
    }
    std::cout<<"\n";

    std::cout<<"OBSTACLES : "<<"\n";
    for(auto i : _obstacles)
    {
        std::cout<<i.tostring()<<"\n";
    }
    std::cout<<"\n";

    std::cout<<"OBJETS RAMASSABLES : "<<"\n";
    for(auto i : _objetsramassables)
    {
        std::cout<<i.tostring()<<"\n";
    }
    std::cout<<"\n";
}


bool carte::interelement(const element &e1, const element &e2) const{
    return (interintervalles(e1.get_p().get_x(),(e1.get_p().get_x()+e1.get_t().get_largeur()),e2.get_p().get_x(),(e2.get_p().get_x()+e2.get_t().get_largeur())) && interintervalles(e1.get_p().get_y(),e1.get_p().get_y()+e1.get_t().get_hauteur(),e2.get_p().get_y(),e2.get_p().get_y()+e2.get_t().get_hauteur()));
}


bool carte::interintervalles(coordonnee xa, coordonnee ya,coordonnee xb, coordonnee yb) const{
    return(ya>xb && yb>xa);
}


bool carte::deplacementpossible(const personnage &p, deplacement d) const{

    int y = p.get_p().get_y();
    int x = p.get_p().get_x();
    int xl = p.get_p().get_x()+p.get_t().get_largeur();
    int yh = p.get_p().get_y()+p.get_t().get_hauteur();

    position pos(x,y);
    taille t(xl-x,yh-y);

    if(d==deplacement::Nord){
        if(y-1<0){
            return false;
        }
        pos.mutateur_y(y-1);
    }

    else if(d==deplacement::Sud){
        if(yh+1>_taille.get_hauteur()){
            return false;
        }
        pos.mutateur_y(y+1);
    }

    else if(d==deplacement::Ouest){
        if(x-1<0){
            return false;
        }
        pos.mutateur_x(x-1);
    }

    else if(d==deplacement::Est){
        if(xl+1>_taille.get_largeur()){
            return false;
        }
        pos.mutateur_x(x+1);
    }


    element e(pos,t);

    for(auto i : _objetsramassables){
        if(interelement(i,e)){
            return false;
            break;
        }
    }

    for(auto i : _personnages){
        if(interelement(i,e) && p.get_nom()!=i.get_nom()){
            return false;
            break;
        }
    }

    for(auto i : _obstacles){
        if(interelement(i,e)){
            return false;
            break;
        }
    }

    return true;
}


void carte::deplacementperso(personnage p, deplacement d){
    if(deplacementpossible(p,d)){
        int y = p.get_p().get_y();
        int x = p.get_p().get_x();
        int xl = p.get_p().get_x()+p.get_t().get_largeur();
        int yh = p.get_p().get_y()+p.get_t().get_hauteur();

        if(d==deplacement::Nord){
            position pos(x,y-1);
            p.mut_p(pos);
        }

        else if(d==deplacement::Sud){
            position pos(x,y+1);
            p.mut_p(pos);
        }

        else if(d==deplacement::Ouest){
            position pos(x-1,y);
            p.mut_p(pos);
        }

        else if(d==deplacement::Est){
            position pos(x+1,y);
            p.mut_p(pos);
        }
    }
}










