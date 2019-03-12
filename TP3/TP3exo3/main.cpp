#include <iostream>
#include "ensemble.hh"

using namespace std;

void testensemble(ensemble &e1, ensemble &e2)
{
    std::cout<<"----------------------Tableau :----------------------";
    e1.ajouter(1);
    e1.ajouter(2);
    e1.ajouter(3);
    e1.ajouter(4);
    e1.ajouter(5);
    e1.afficher();
    std::cout<<std::endl;

    std::cout<<"----------------------Vecteur :----------------------";
    e2.ajouter(5);
    e2.ajouter(6);
    e2.ajouter(7);
    e2.ajouter(2);
    e2.afficher();
    std::cout<<std::endl;

    std::cout<<"----------------------Union :------------------------";
    ensembletableau e3;
    e3.unionens(e1,e2);
    e3.afficher();
    std::cout<<std::endl;

    std::cout<<"----------------------Inter :------------------------";
    ensembletableau e4;
    e4.interens(e1,e2);
    e4.afficher();
    std::cout<<std::endl;
}


int main()
{
    ensembletableau et;
    ensemblevector ev;

    testensemble(et,ev);

    return 0;
}
