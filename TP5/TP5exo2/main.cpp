#include <iostream>
#include "compte.hh"

int main()
{
    std::shared_ptr<personne_physique> pp = personne_physique::fabrique("Etienne","3 rue","01/05/1997");
    pp->sortie(std::cout);

    compte c(1000,pp);
    std::cout<<c;
    return 0;
}
