#include "calculator.hh"
#include <iostream>
#include <QtWidgets>



int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    calculator c;

    c.show();
    return app.exec();
}
