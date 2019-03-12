#include <iostream>
#include "calcul.hh"
#include <QtWidgets>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    calcul c;

    c.show();
    return app.exec();
}
