#include "arrayint.hh"

const char * exceptionarrayint::what() const noexcept {
    return _msg.c_str();
}


int arrayint::at(indice i) const{
    if((i >=min()) && (i<=max()))
        return _tab[i-_min];
    else
        throw exceptionarrayint(i);
}
