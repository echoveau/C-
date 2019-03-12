#include <iostream>
#include "tailleposition.hh"
#include "carte.hh"

using namespace std;

int main()
{
    taille t(2,2);
    position p(5,3);
    objetramassable o(p,t,100);


    taille t2(2,2);
    position p2(8,3);
    personnage perso(p2,t2,"Etienne");

    taille t3(10,10);
    carte c(t3);
    c.ajouterobjetramassable(o);
    c.ajouterpersonnage(perso);

    c.affichercarte();
    std::cout<<"#################################################################################"<<std::endl;

    c.deplacementperso(perso,deplacement::Ouest);
    c.affichercarte();
    std::cout<<std::endl;

    return 0;
}
