#include <iostream>
#include "sequence.hh"

using namespace std;

int main()
{
    sequence a, b;
    sc_initialiservide(a); // 3
    sc_initialiservide(b);


    sc_ajouter(a, couleur::rouge); // 4

    sc_ajouter(a, couleur::bleu);
    sc_ajouter(a, couleur::rouge);
    sc_ajouter(a, couleur::vert);

    sc_copier(a, b); // Copie a dans b // 5
    std::cout << "b :   ";sc_afficher(b); std::cout << "\n";
    std::cout << "a :   ";sc_afficher(a); std::cout << "\n";


    std::cout << std::endl;
    sc_vider(a); // 8
    std::cout << "b :   ";sc_afficher(b); std::cout << "\n";
    std::cout << "a :   ";sc_afficher(a); std::cout << "\n";
    std::cout << std::endl;


    std::cout << sc_comparer(a,b) << "\n"; // 10


    sc_ajouter(a, couleur::bleu);
    sc_ajouter(a, couleur::bleu);
    sc_ajouter(a, couleur::bleu);
/*
    std::cout << sc_comparer(a,b) << "\n"; // 10
*/
    std::cout << std::endl;
    std::cout << "b :   ";sc_afficher(b); std::cout << "\n";
    std::cout << "a :   ";sc_afficher(a); std::cout << "\n";


    sc_detruire(a);

    std::cout << "b :   ";sc_afficher(b); std::cout << "\n";

    return 0;
}
