#pragma once
#include <QtWidgets>

class calculator:public QWidget{
public:
    calculator();
public slots:
    void resultat();

private:
    QSpinBox *     _operande1;
    QSpinBox *     _operande2;
    QComboBox *     _operateur;
    QPushButton *   _egal;
    QLabel *     	_res;
    QHBoxLayout *   _hbox;
};


