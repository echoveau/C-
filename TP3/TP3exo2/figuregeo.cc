#include "figuregeo.hh"
#include <sstream>
#include <string>

std::string point::ToString()
{
    std::ostringstream out;
    out<<"("<<_x<<";"<<_y<<")"<<std::endl;
    std::string s(out.str());
    return  s;
}


std::string figuregeometrique::ToString()
{
     std::ostringstream out;
     out<<std::endl<<"Couleur   :      "<<_c.rouge<<","<<_c.bleu<<","<<_c.vert<<std::endl<<"point_o   :      "<<_p_origine.ToString();
     return out.str();
}


std::string texte::ToString()
{
    std::ostringstream out;
    out<<std::endl<<"-----------------------TEXTE-----------------------"<<std::endl<<"Texte     :      "<<_txt<<figuregeometrique::ToString();
    std::string s(out.str());
    return s;
}

std::string triangle::ToString()
{
    std::ostringstream out;
    out<<std::endl<<"-----------------------TRIANGLE-----------------------"<<figuregeometrique::ToString()<<"point_1   :      "<<_p1.ToString()<<"point_2   :      "<<_p2.ToString();
    std::string s(out.str());
    return s;
}


std::string segment::ToString()
{
    std::ostringstream out;
    out<<std::endl<<"-----------------------SEGMENT-----------------------"<<figuregeometrique::ToString()<<"point_1   :      "<<_p1.ToString();
    std::string s(out.str());
    return s;
}

std::string rectangle::ToString()
{
    std::ostringstream out;
    out<<std::endl<<"-----------------------RECTANGLE-----------------------"<<figuregeometrique::ToString()<<"point_1   :      "<<_p1.ToString();
    std::string s(out.str());
    return s;
}
