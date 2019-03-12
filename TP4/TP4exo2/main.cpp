#include <iostream>
#include "bibliotheque.hh"



int main()
{
    livre l("Ma vie, mon histoire","Kevin Balavoine",1,true);
    periodique p("Mon vrai prénom","Mathsup Destiné",10,5);
    video v("Notre Projet","Emmanuel Macron",type_de_support::BluRay3D);


    bibliotheque b;
    b.ajouter_doc(v);
    b.ajouter_doc(v);

    bibliotheque b2(b);
    b.ajouter_doc(v);

    std::cout<<b.nb_video(type_de_support::BluRay3D);
    std::cout<<b2.nb_video(type_de_support::BluRay3D);

    return 0;
}
