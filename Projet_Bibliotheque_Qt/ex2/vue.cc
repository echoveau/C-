#include "vue.hh"

vue::vue()
    :QWidget(),
    _operande1(new QSpinBox(this)),
    _operande2(new QSpinBox(this)),
    _operateur(new QComboBox(this)),
    _egal(new QPushButton ("=",this)),
    _res(new QLabel("",this)),
    _hbox(new QHBoxLayout(this)),
    _t(0,0,'+')
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

    connect(_egal, &QPushButton::clicked, this, & vue::set_res);
}


float vue::get_o1(){
    return std::stof(_operande1->text().toStdString());
}

float vue::get_o2(){
    return std::stof(_operande2->text().toStdString());
}

char vue::get_op(){
    return (_operateur->currentText().toStdString())[0];
}

void vue::set_res(){
    _t.maj(this->get_o1(),this->get_o2(),this->get_op());
    _res->setText(_t.resultat());
}



























