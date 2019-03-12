#include "graphe.hh"
#include <fstream>
#include <iostream>


int main() {

    sommet p("Paris");
    sommet n("Nantes");
    sommet a("Angers");

    std::cout<<n.id()<<"\n";

    graphe g;

    g.ajoutersommet("Paris");   //0
    g.ajoutersommet("Nantes");  //1
    g.ajoutersommet("Angers");  //2

    std::cout<<g.ajouterarc(2, 1, "Bus")<<"\n";
    std::cout<<g.ajouterarc(1, 2, "Bus")<<"\n";
    std::cout<<g.ajouterarc(2, 0, "Train")<<"\n";
    std::cout<<g.ajouterarc(0, 1, "Avion")<<"\n";

    g.dot_sortie(std::cout);

    return 0;
}
