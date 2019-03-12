#include <iostream>
#include "position.hh"

using namespace std;

int main()
{
    position p1(5,4);

    roi pi(couleur::Blanc,p1);

    std::cout<<pi.tostring()<<std::endl;

    std::cout<<true<<std::endl;

    for(int i=0; i<8;++i){
        for(int j=0; j<8;++j)
            std::cout<<pi.accepterposition(position(i,j));
        std::cout<<std::endl;
    }

    pi.deplacer(position(6,4));
    std::cout<<std::endl;
    for(int i=0; i<8;++i){
        for(int j=0; j<8;++j)
            std::cout<<pi.accepterposition(position(i,j));
        std::cout<<std::endl;
    }

    return 0;
}
