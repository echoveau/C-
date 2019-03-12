#pragma once

class moteur{
public:
    moteur(float o1, float o2, char op)
        :_o1(o1),_o2(o2),_op(op){}

    float resultatm();
    void majm(float o1, float o2, char op);

private:
    float _o1;
    float _o2;
    char  _op;
};
