#include <iostream>
#include "arrayint.hh"

using namespace std;

int main()
{
    arrayint tab(-10,10);

    int b = tab.at(9);

    std::cout<<b<<"\n";
    return 0;
}
