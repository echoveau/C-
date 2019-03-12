#include "vue.hh"
#include <iostream>
#include <QtWidgets>



int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    vue v;

    v.show();
    return app.exec();
}
