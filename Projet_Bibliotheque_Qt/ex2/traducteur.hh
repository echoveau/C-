#pragma once
#include "moteur.hh"
#include <QtWidgets>


class traducteur{
public:
    traducteur(float o1,float o2,char op)
        :_m(o1,o2,op){}

    void maj(float o1,float o2,char op);
    QString resultat();

private:
    moteur  _m;
};
