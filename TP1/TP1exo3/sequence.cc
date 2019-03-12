#include "sequence.hh"
#include <iostream>

void sc_initialiservide(sequence &a)
{
    a.couleurs=nullptr;
    a.taille=0;
    a.zone_alloue=0;
}

/*void sc_ajouter(sequence &a, couleur c)
{
   couleur * cou = new couleur[a.taille+1];

   for(indicesequence i=0; i<a.taille;++i)
        cou[i]=a.couleurs[i];


   cou[a.taille]=c;
   ++a.taille;

   if(a.couleurs != nullptr)
        delete []a.couleurs;
   a.couleurs=cou;
}
*/

void sc_ajouter(sequence &a, couleur c)
{
   if(a.taille == a.zone_alloue)
   {
      a.zone_alloue += 5;

      couleur * cou = new couleur[a.zone_alloue];

      for(indicesequence i=0; i<a.taille;++i)
           cou[i]=a.couleurs[i];


      cou[a.taille]=c;
      ++a.taille;

      if(a.couleurs != nullptr)
           delete []a.couleurs;
      a.couleurs=cou;
   }
   else
   {
       a.couleurs[a.taille]=c;
       ++a.taille;
   }
}


couleur sc_acces(sequence const &a, indicesequence n)
{
    return a.couleurs[n];
}

void sc_afficher(couleur const &c)
{
    switch (c) {
        case couleur::rouge : std::cout<<"Rouge ";
        break;
        case couleur::vert : std::cout<<"Vert ";
        break;
        case couleur::bleu : std::cout<<"Bleu ";
        break;
        case couleur::jaune :  std::cout<<"Jaune ";
        break;
    }
}

void sc_afficher(sequence const &a)
{
    for (indicesequence i=0; i<a.taille; ++i)
        sc_afficher(a.couleurs[i]);
}

void sc_copier(sequence &b,sequence const &a)
{
    /*if(b.couleurs != nullptr)
        sc_vider(b);

    for(indicesequence i=0; i<a.taille;++i)
    {
        sc_ajouter(b,a.couleurs[i]);
    }*/

    if(a.taille != b.taille)
    {
        if(b.couleurs != nullptr)
            delete [] b.couleurs;

        if(a.taille==0)
            b.couleurs = nullptr;
        else
            b.couleurs = new couleur[a.taille];

        b.taille = a.taille;
    }
    for(indicesequence i(0); i<a.taille; ++i)
        b.couleurs[i] = a.couleurs[i];
}

void sc_vider(sequence &a)
{
    if(a.taille != 0)
    {
        delete []a.couleurs;
        sc_initialiservide(a);
    }
}

void sc_detruire(sequence &s)
{
    delete []s.couleurs;
}

bool sc_comparer(sequence const &a,sequence const &b)
{
    if(a.taille!=b.taille)
        return false;
    else
    {
        indicesequence i=0;
        while (i<a.taille)
        {
            if(a.couleurs[i]!=b.couleurs[i])
                return false;

            ++i;
        }

        return true;
    }
}






