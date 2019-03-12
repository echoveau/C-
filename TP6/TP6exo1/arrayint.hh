#pragma once
#include <vector>
#include <string>


//                  ARRAYINT
//##############################################################################
class arrayint
{
public:
    using indice = signed int;
    arrayint(indice min, indice max)
        :_min(min),_tab(max-min+1, 0){}
    arrayint(arrayint const & a)=default;

    indice min() const{ return _min; }
    indice max() const{ return (_min + _tab.size() -1); }
    int at(indice i) const;

private:
    indice _min;
    std::vector<int> _tab;
};



//                  EXCEPTIONARRAYINT
//##############################################################################
class exceptionarrayint : public std::exception{
public:
    exceptionarrayint(arrayint::indice ind)
        :std::exception(), _msg("Accès invalide à " + std::to_string(ind)), _ind(ind){}
    const char * what() const noexcept override;        //noexcept = On ne veut pas que la methode what lève une exception


private:
    std::string _msg;
    arrayint::indice _ind;

};
































