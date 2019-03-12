#pragma once
#include<iostream>
#include<vector>


class parcours {
public:
    parcours(): _element(0) {
    }
    std::size_t element() const {
        return _element;
    }
    void passersuivant() {
        ++_element;
    }
private:
    std::size_t _element;
};

class ensemble {
public:
    ensemble() =default;                    //pas obligatoire
    ensemble(ensemble const &e) =default;   //pas obligatoire
    ~ensemble() =default;

    virtual bool contient(int x) const =0;
    virtual bool estvide() const =0;
    void ajouter(int x); //permet de factoriser le code (on verifie qu une seule fois si l'entier est deja dans l'ensemble ou non plutot que de verifer dans tout les methodes "ajouter")
    virtual void afficher() =0;
    virtual void supprimer(int x) =0;

    virtual parcours commencer() const;
    virtual bool estfini(parcours const &p) const =0;
    virtual void suivant(parcours &p) const;
    virtual int courant(parcours const &p) const =0;

    void union_ensemble(ensemble &e2);

protected: //car on ne veut pas utiliser ses fonctions dans le main
    virtual void ajoutersansverifier(int x) =0;
};



class ensembletableau:
        public ensemble {
public:
    ensembletableau();
    ensembletableau(ensembletableau const &e);
    ~ensembletableau();

    bool contient(int x) const override;
    bool estvide() const override;
    void afficher() override;
    void supprimer(int x) override;


    bool estfini(parcours const &p) const override;
    int courant(parcours const &p) const override;

protected:
    void ajoutersansverifier(int x) override;

private:
    std::size_t _taille;
    int *_Ens;
};


class ensemblevector:
        public ensemble {
public:
    ensemblevector() =default;
    ensemblevector(ensemblevector const &v) =default;
    ~ensemblevector() =default;                         //pas obligatoire

    bool contient(int x) const override;
    bool estvide() const override;
    void afficher() override;
    void supprimer(int x) override;


    bool estfini(parcours const &p) const override;
    int courant(parcours const &p) const override;

protected:
    void ajoutersansverifier(int x) override;

private:
    std::vector<int> _Ens;
};




