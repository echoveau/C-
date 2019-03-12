#include "bibliotheque.hh"
#include <sstream>
#include <string>
#include <iostream>


std::ostream & operator <<(std::ostream & os, document const & d){
    os << d.to_string();
    return os;
}

std::string document::to_string()const{
    std::ostringstream out;
    out<<_titre<<"  "<<std::endl<<_auteur<<std::endl;
    return (out.str());
}

std::string video::to_string()const{
    std::ostringstream out;
    if(_type==type_de_support::Bluray) out<<"       VIDEO"<<std::endl<<document::to_string()<<"Bluray"<<std::endl;
    else if(_type==type_de_support::BluRay3D) out<<"        VIDEO"<<std::endl<<document::to_string()<<"Bluray3D"<<std::endl;
    else out<<"     VIDEO"<<std::endl<<document::to_string()<<"DVD"<<std::endl;
    return (out.str());
}

std::string docecrit::to_string()const{
    std::ostringstream out;
    out<<std::endl<<document::to_string()<<_nbpages<<" pages"<<std::endl;
    return (out.str());

}

std::string livre::to_string()const{
    std::ostringstream out;
    if(_empruntable) out<<"     LIVRE"<<docecrit::to_string()<<"empruntable"<<std::endl;
    else out<<"     LIVRE"<<docecrit::to_string()<<"non empruntable"<<std::endl;
    return (out.str());

}



std::string periodique::to_string()const{
    std::ostringstream out;
    out<<"     PERIODIQUE"<<docecrit::to_string()<<"n°"<<_numero<<std::endl;
    return (out.str());

}



//                                  BIBLI
//#############################################################################
bibliotheque::~bibliotheque() {
    for(auto d : _documents){
        delete d;
    }
}

bibliotheque::bibliotheque(bibliotheque const &b){
    for(auto d : b.get_document()){
        _documents.push_back(d);
    }
}

std::vector<document *> bibliotheque::get_document() const{
    return _documents;
}


void bibliotheque::ajouter_doc(document &d){
    _documents.push_back(d.clone());
}



void bibliotheque::acces_document()const{
    for(auto d : _documents) {
        //Video
        auto v = dynamic_cast<video const*>(d);
        if(v != nullptr)
            std::cout<<v->to_string();
        //Livre
        auto l = dynamic_cast<livre const*>(d);
        if(l != nullptr)
            std::cout<<l->to_string();
        //Periodique
        auto p = dynamic_cast<periodique const*>(d);
        if(p != nullptr)
            std::cout<<p->to_string();
    }
}


int bibliotheque::nb_video(const type_de_support &t) const{
    int compt=0;
    for(auto d : _documents) {
        auto v = dynamic_cast<video const*>(d);
        if(v != nullptr)
            if(v->get_type()==t)
                ++compt;
    }
    return compt;
}









