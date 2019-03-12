#include <iostream>
#include "figuregeo.hh"

using namespace std;

int main()
{
    point p1(4,3);
    point p2(6,9);
    point p3(10,2);

    triangle f(p1,{100,250,30},p2,p3);

    rectangle r(p1,{10,20,0},p2);
    texte t(p1,{10,20,0},"JE SUIS TROP FORT PUTIN");
    std::cout<<f.ToString()<<std::endl;
    std::cout<<r.ToString()<<std::endl;
    std::cout<<t.ToString()<<std::endl;

    return 0;
}
