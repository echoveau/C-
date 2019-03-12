#pragma once
#include <string>
#include <memory>
#include <iostream>

class personne_physique;
class societe;
class couple;

//                  COMPTE
//#########################################################################

class compte
{
public:
    compte(int m,std::shared_ptr<personne_physique> pp)
        :_id(_compteur++),_montant(m),_pp(pp){}
    void verser(int espece);
    void retirer(int espece);
    void virer(compte debite, int montant);
    std::shared_ptr<personne_physique> get_pp() const{
        return _pp;
    }
    void sortie(std::ostream & os) const{
        os << "COMPTE N°"<<_id<<"\n"<<&*_pp<<"\n montant:"<<_montant<<"\n";
    }

private:
    int _id;
    int _montant;
    std::shared_ptr<personne_physique> _pp;
    static int _compteur;
};

std::ostream & operator <<(std::ostream & os, compte const & c);


//                  PROPRIETAIRE
//#########################################################################
class proprietaire
{
public:
    virtual std::string nom()const=0;
    virtual std::string type()const=0;
    virtual std::string adresse()const=0;
    virtual std::string etiquetteexpedition()const=0;
    virtual void sortie(std::ostream & os) const{
        os <<  "\nType:     " << type() << "\nAdresse:   " << adresse() << "\nNom:       " << nom() << "\n";
    }
/*    static std::shared_ptr<personne_physique> fabrique(std::string const & n, std::string const & a,std::string const & dn){
        return (personne_physique::fabrique(n,a,dn));
    }
*/
};

std::ostream & operator <<(std::ostream & os, proprietaire const & d);


//                  PERSONNE PHYSIQUE
//#########################################################################

class personne_physique : public proprietaire
{
private:
    personne_physique(std::string const & n, std::string const & a,std::string const & dn)
        :_nom(n),_adresse(a),_datenaissance(dn){}

public:
    static std::shared_ptr<personne_physique> fabrique(std::string const & n, std::string const & a,std::string const & dn){
        return std::shared_ptr<personne_physique>(new personne_physique(n,a,dn));
    }
    std::string nom()const override{
        return _nom;
    }
    std::string type()const override{
        return " Personne Physique";
    }
    std::string adresse()const override{
        return _adresse;
    }
    std::string etiquetteexpedition()const override{
        return _nom+_adresse;
    }
    void sortie(std::ostream & os) const override {proprietaire::sortie(os); os << "Date de Naissance: "<<_datenaissance << "\n";}

private:
    std::string _nom;
    std::string _adresse;
    std::string _datenaissance;
};


//                  SOCIETE
//#########################################################################

class societe : public proprietaire
{
private:
    societe(std::string const & n, std::string const & a,std::shared_ptr<personne_physique> const &g)
            :_nom(n),_adresse(a),_gerant(g){}

public:
    static std::shared_ptr<societe> fabrique(std::string const & n, std::string const & a,std::shared_ptr<personne_physique> const &g){
        return std::shared_ptr<societe>(new societe(n,a,g));
    }
    std::string nom()const override{ return _nom; }
    std::string type()const override{ return " Société"; }
    std::string adresse()const override{ return _adresse; }
    std::string etiquetteexpedition()const override{ return _nom+_adresse; }
    void sortie(std::ostream & os) const override {proprietaire::sortie(os); os << "Gérant :";_gerant->sortie(os);}

private:
    std::string _nom;
    std::string _adresse;
    std::shared_ptr<personne_physique> _gerant;
};


//                  COUPLE
//#########################################################################

class couple : public proprietaire
{
private:
    couple(std::shared_ptr<personne_physique> const & p1,std::shared_ptr<personne_physique> const & p2)
        :_p1(p1),_p2(p2){}

public:
    static std::shared_ptr<couple> fabreique(std::shared_ptr<personne_physique> p1,std::shared_ptr<personne_physique> p2){
        if(p1->adresse() == p2->adresse()){
            return std::shared_ptr<couple>(new couple(p1,p2));
        }
        else
            return nullptr;
    }
    std::string nom()const override{ return (_p1->nom())+" et "+(_p2->nom()); }
    std::string type()const override{ return " Couple"; }
    std::string adresse()const override{ return _p1->adresse(); }
    std::string etiquetteexpedition()const override{ return this->nom()+this->adresse(); }
    void sortie(std::ostream & os) const override {os << "          P1 : "; _p1->sortie(os);os << "\n          P2 : "; _p2->sortie(os);}

private:
    std::shared_ptr<personne_physique> _p2;
    std::shared_ptr<personne_physique> _p1;
};
































