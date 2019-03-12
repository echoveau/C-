#pragma once
#include <QtWidgets>
#include "traducteur.hh"

class vue:public QWidget{
public:
    vue();

    float get_o1();
    float get_o2();
    char get_op();

public slots:
    void set_res();


private:
    QSpinBox *      _operande1;
    QSpinBox *      _operande2;
    QComboBox *     _operateur;
    QPushButton *   _egal;
    QLabel *        _res;
    QHBoxLayout *   _hbox;
    traducteur      _t;
};
