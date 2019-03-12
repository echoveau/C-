#pragma once
#include <iostream>

enum class couleur
{
    rouge,
    bleu,
    jaune,
    vert
};

using indicesequence = std::size_t;

struct sequence {
    couleur * couleurs;
    indicesequence taille;
    indicesequence zone_alloue;
};

void sc_initialiservide(sequence &a);

void sc_ajouter(sequence &a, couleur c);

void sc_copier(sequence &b,sequence const &a);

couleur sc_acces(sequence const &a, indicesequence n);

void sc_afficher(couleur const &c);

void sc_vider(sequence &a);

void sc_detruire(sequence &s);

void sc_afficher(sequence const &a);

bool sc_comparer(sequence const &a,sequence const &b);
