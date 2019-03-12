#include "calculator.hh"

calculator::calculator()
    :QWidget(),
    _operande1(new QSpinBox(this)),
    _operande2(new QSpinBox(this)),
    _operateur(new QComboBox(this)),
    _egal(new QPushButton ("=",this)),
    _res(new QLabel("",this)),
    _hbox(new QHBoxLayout(this))
{
    resize(450,50);
    _operateur->addItem("+");
    _operateur->addItem("-");
    _operateur->addItem("*");
    _operateur->addItem("/");


    _hbox->addWidget(_operande1);
    _hbox->addWidget(_operateur);
    _hbox->addWidget(_operande2);
    _hbox->addWidget(_egal);
    _hbox->addWidget(_res);

    setWindowTitle("Calcuatrice");

    connect(_egal, &QPushButton::clicked, this, & calculator::resultat);
}



void calculator::resultat(){
    float o1 = std::stof(_operande1->text().toStdString());
    float o2 = std::stof(_operande2->text().toStdString());

    float resultat;

    if(_operateur->currentText().toStdString()=="+") {
        resultat=o1+o2 ;
    }
    if(_operateur->currentText().toStdString()=="-") {
        resultat=o1-o2 ;
    }
    if(_operateur->currentText().toStdString()=="*") {
        resultat=o1*o2 ;
    }
    if(_operateur->currentText().toStdString()=="/") {
        resultat=o1/o2 ;
    }

    _res->setText(QString::fromStdString(std::to_string(resultat)));
}






























