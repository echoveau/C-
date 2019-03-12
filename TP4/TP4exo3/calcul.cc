#include "calcul.hh"
#include <iostream>


calcul::calcul()
    :QWidget(),
    _operande1(new QLineEdit("",this)),
    _operande2(new QLineEdit("",this)),
    _operateur(new QComboBox(this)),
    _resultat(new QLabel("", this)),
    _calculer(new QPushButton("=", this)),
    _quitter(new QPushButton("Quitter", this)) {

    resize(450,50);
    _operateur->addItem(("+"));
    _operateur->addItem(("-"));
    _operateur->addItem(("*"));
    _operateur->addItem(("/"));

    _operande1->setGeometry(10,10,70,30);
    _operateur->setGeometry(90,10,50,30);
    _operande2->setGeometry(150,10,70,30);
    _calculer->setGeometry(230,10,50,30);
    _resultat->setGeometry(290,10,70,30);
    _quitter->setGeometry(370,10,70,30);
    setWindowTitle("calculatrice");

    connect(_quitter,&QPushButton::clicked, this, & calcul::close);
    connect(_calculer,&QPushButton::clicked, this, & calcul::oncliccalculer);
    connect(_operande1,&QLineEdit::textChanged, this,& calcul::oncliccalculer);
    connect(_operande2,&QLineEdit::textChanged, this,& calcul::oncliccalculer);
    connect(_operateur,&QComboBox::currentTextChanged, this,& calcul::oncliccalculer);
}


void calcul::oncliccalculer(){
    float o1=0;
    float o2=0;

    try{
        o1 = std::stof(_operande1->text().toStdString());
    }
    catch (const std::exception& e){}

    try{
        o2 = std::stof(_operande2->text().toStdString());
    }
    catch (const std::exception& e){}




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

    _resultat->setText(QString::fromStdString(std::to_string(resultat)));
}












