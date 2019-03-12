#include <iostream>
#include "position.hh"


int main()
{
    echiquier e;

    for(int i=0; i<8; ++i){
        pion pn(couleur::Noir,position(6,i));
        pion pb(couleur::Blanc,position(1,i));
        e.ajout(pn.clone());
        e.ajout(pb.clone());
    }
        //PIECES BLANCHES
    roi rn(couleur::Blanc,position(0,3));
    dame dn(couleur::Blanc,position(0,4));
    cavalier cn1(couleur::Blanc,position(0,1));
    cavalier cn2(couleur::Blanc,position(0,6));
    e.ajout(rn.clone());
    e.ajout(dn.clone());
    e.ajout(cn1.clone());
    e.ajout(cn2.clone());

        //PIECES BLANCHES
    roi rb(couleur::Noir,position(7,3));
    dame db(couleur::Noir,position(7,4));
    cavalier cb1(couleur::Noir,position(7,1));
    cavalier cb2(couleur::Noir,position(7,6));
    e.ajout(rb.clone());
    e.ajout(db.clone());
    e.ajout(cb1.clone());
    e.ajout(cb2.clone());


    while(!e.aperdu(couleur::Blanc) && !e.aperdu(couleur::Noir))
    {
        int xsrc,ysrc,xdst,ydst;

        if(!e.aperdu(couleur::Blanc)){
            do{
                e.affichage(std::cout);
                std::cout<<"\nBlanc :";
                std::cin >> xsrc;
                std::cin>>ysrc;
                std::cin >> xdst;
                std::cin>>ydst;
            }
            while(!e.deplacer(position(xsrc,ysrc),position(xdst,ydst)));
        }

        if(!e.aperdu(couleur::Noir)){
            do{
                e.affichage(std::cout);
                std::cout<<"\nNoir :";
                std::cin >> xsrc;
                std::cin>>ysrc;
                std::cin >> xdst;
                std::cin>>ydst;
            }
            while(!e.deplacer(position(xsrc,ysrc),position(xdst,ydst)));
        }
    }

    e.affichage(std::cout);
    std::cout<<"\n-------------------FIN-----------------\n";



    return 0;
}
