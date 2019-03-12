#pragma once
#include <iostream>
#include <array>
#include <vector>

using indicesequence = int;

class parcours {
public:
    parcours():_element(0){}
    indicesequence element() const {return _element;}
    void passerausuivant() {_element++;}
private:
    indicesequence _element;
};



class ensemble
{
public:
    virtual bool contient(int x) const =0;
    virtual bool estvide() const =0;
    void ajouter (int x);
    virtual void afficher() =0;
    virtual void supprimer(int x) =0;

    virtual parcours commencer() const;
    virtual bool estfini(parcours const & p) const =0;
    virtual void suivant(parcours & p) const;
    virtual int courant(parcours const & p) const =0;
    void unionens(ensemble const & e1, ensemble const & e2);
    void interens(const ensemble &e1, const ensemble &e2);
    virtual void vider() =0;

protected:
    virtual void ajoutersansverifier(int a)=0;
};


class ensembletableau: public ensemble
{
public:
    ensembletableau()
        :_indtab(0){}
    ensembletableau(ensembletableau const &t)
        :_indtab(t._indtab), _tab(t._tab){}
    ~ensembletableau() =default;


    bool contient(int x) const override;
    bool estvide() const override;
    void afficher() override;
    void supprimer(int x) override;
    bool estfini(parcours const & p) const override;
    int courant(parcours const & p) const override;

    void vider()override{_indtab=0;}

protected:
    void ajoutersansverifier(int x) override;

private:
    indicesequence _indtab;
    std::array<int,100> _tab;
};




class ensemblevector: public ensemble
{
public:
    ensemblevector() = default;
    ensemblevector(ensemblevector const &t)=default;
    ~ensemblevector() =default;

    bool contient(int x) const override;
    bool estvide() const override;
    void afficher() override;
    void supprimer(int x) override;

    bool estfini(parcours const & p) const override;
    int courant(parcours const & p) const override;

    void vider() override{_vec.clear();}

protected:
    void ajoutersansverifier(int x) override;

private:
    std::vector<int> _vec;
};

