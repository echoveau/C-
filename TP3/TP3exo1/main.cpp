#include <iostream>
#include "tailleposition.hh"

using namespace std;

int main()
{
    taille t(2,2);
    position p(5,3);

    objetramassable o(p,t,100);

    std::cout << o.tostring() << std::endl;

    personnage perso(p,t,"Etienne");

    std::cout << perso.tostring() << std::endl;

    perso.ramasser(o);
    std::cout << perso.tostring() << std::endl;

    return 0;
}
