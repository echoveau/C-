#pragma once
#include <string>
#include <vector>

enum class type_de_support{
    DVD,
    Bluray,
    BluRay3D
};


//                                  DOCUMENT
//#############################################################################
class document{
public:
    document(std::string const & t,std::string const & a)
        :_titre(t),_auteur(a){}
    virtual bool est_empruntable()const=0;
    virtual float cout()const=0;
    virtual std::string to_string()const;
    virtual document * clone()const =0;


private:
    std::string _titre;
    std::string _auteur;
};

std::ostream & operator <<(std::ostream & os, document const & d);


//                                  VIDEO
//#############################################################################
class video : public document{
public:
    video(std::string const & t,std::string const & a,type_de_support const & ty)
        :document(t,a),_type(ty){}
    bool est_empruntable()const override{return true;}
    float cout()const override{return 70;}
    std::string to_string()const override;

    type_de_support get_type()const{
        return _type;
    }

    document * clone() const override{
        return new video(*this);
    }

private:
    type_de_support _type;
};


//                                  DOCECRIT
//#############################################################################
class docecrit : public document{
public:
    docecrit(std::string const & t,std::string const & a,unsigned int n)
        :document(t,a),_nbpages(n){}
    float cout()const override{return (0,50*_nbpages);}
    std::string to_string()const override;

private:
    unsigned int _nbpages;
};


//                                  LIVRE
//#############################################################################
class livre : public docecrit{
public:
    livre(std::string const & t,std::string const & a,unsigned int n,bool e)
        :docecrit(t,a,n),_empruntable(e){}
    bool est_empruntable()const override{return _empruntable;}
    std::string to_string()const override;

    document * clone() const override{
        return new livre(*this);
    }


private:
    bool    _empruntable;
};


//                                  PERIODIQUE
//#############################################################################
class periodique : public docecrit{
public:
    periodique(std::string const & t,std::string const & a,unsigned int num,unsigned int n)
        :docecrit(t,a,num),_numero(n){}
    bool est_empruntable()const override{return false;}
    std::string to_string()const override;

    document * clone() const override{
        return new periodique(*this);
    }


private:
    unsigned int _numero;
};


//                                  BIBLIOTHEQUE
//#############################################################################
class bibliotheque{
public:
    bibliotheque()=default;
    bibliotheque(bibliotheque const & b);
    ~bibliotheque();
    std::vector<document *> get_document() const;
    void ajouter_doc(document & d);

    void acces_document() const;

    int nb_video(type_de_support const & t)const;

private:
    std::vector<document *> _documents;
};

















