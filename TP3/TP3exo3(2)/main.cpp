#include <iostream>
#include "ensemble.hh"


void testens(ensemble &e1,ensemble &e2) {
    e1.ajouter(1);
    e1.ajouter(2);
    e1.ajouter(3);
    e1.ajouter(4);
    e1.ajouter(5);

    e2.ajouter(6);
    e2.ajouter(7);
    e2.ajouter(8);
    std::cout << "e1 : ";
    e1.afficher();
    std::cout << "e2 : ";
    e2.afficher();

    for(auto p=e1.commencer(); !e1.estfini(p); e1.suivant(p)) {
        std::cout << e1.courant(p) << " ";
    }
    std::cout << "\n";

    std::cout << "e1 U e2 : ";
    //e1.union_ensemble(e2);
    e2.afficher();

}

int main()
{
    {
        ensembletableau e1,e2;
        std::cout << "Ensemble tableau : \n";
        testens(e1,e2);
    }
    {
        ensemblevector e1,e2;
        std::cout << "Ensemble vector : \n";
        testens(e1,e2);
    }

    return 0;
}
