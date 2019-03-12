#pragma once
#include <iostream>
#include <vector>
#include <memory>

using coordonnee = signed short;

enum class couleur{
    Noir,
    Blanc
};



class position {
public:
    position(coordonnee cx, coordonnee cy)
        :_x(cx),_y(cy){}
    position(position const & p)=default;

    coordonnee get_x() const { return _x; }
    coordonnee get_y() const { return _y; }

    void set_x(coordonnee cx){ _x=cx; }
    void set_y(coordonnee cy){ _x=cy; }

    bool operator == (position const & p) const;
    bool operator != (position const & p) const;
    position & operator = (position const & p);

    bool estvalide()const;

private:
    coordonnee _x;
    coordonnee _y;
};

std::ostream & operator << (std::ostream & os, position const & p);


//                                  PIECE
//###########################################################################

class piece {
public:
    piece(couleur const & c, position const & p)
        :_c(c),_p(p){}

    virtual std::unique_ptr<piece> clone() const=0;

    virtual char symbole() const =0;
    virtual int val() const =0;

    std::string tostring()const;
    virtual std::vector<position> deplacementspossibles() const=0;

    bool accepterposition(position const & p) const;
    bool deplacer(position const & p);

    position get_p() const{ return _p;}
    couleur get_c() const{ return _c;}

private:
    couleur _c;
    position _p;
};


//                                  PION
//###########################################################################

class pion : public piece{
public:
    pion(couleur const & c, position const & p)
        :piece(c,p){}

    std::unique_ptr<piece> clone() const override{
        return std::make_unique<pion>(*this);
    }
    char symbole() const override { return 'P';}
    int val() const override      { return 1  ;}
    std::vector<position> deplacementspossibles() const override;

private:
};



//                                  CAVALIER
//###########################################################################

class cavalier : public piece{
public:
    cavalier(couleur const & c, position const & p)
        :piece(c,p){}
    std::unique_ptr<piece> clone() const override{
        return std::make_unique<cavalier>(*this);
    }
    char symbole() const override { return 'C';}
    int val() const override      { return 3  ;}
    std::vector<position> deplacementspossibles() const override;


private:
};



//                                  DAME
//###########################################################################

class dame : public piece{
public:
    dame(couleur const & c, position const & p)
        :piece(c,p){}
    std::unique_ptr<piece> clone() const override{
        return std::make_unique<dame>(*this);
    }
    char symbole() const override { return 'D';}
    int val() const override      { return 9  ;}
    std::vector<position> deplacementspossibles() const override;


private:
};



//                                  ROI
//###########################################################################

class roi : public piece{
public:
    roi(couleur const & c, position const & p)
        :piece(c,p){}
    std::unique_ptr<piece> clone() const override{
        return std::make_unique<roi>(*this);
    }
    char symbole() const override { return 'R';}
    int val() const override      { return 100 ;}
    std::vector<position> deplacementspossibles() const override;


private:
};



//                                  ECHIQUIER
//###########################################################################

class echiquier {
public:
    echiquier() =default;
    echiquier(echiquier const & e);
    echiquier & operator =(echiquier const & e);
    void ajout(std::unique_ptr<piece> p) {
        _pieces.push_back(std::move(p));
    }
    unsigned int valeurdujoueur(couleur c) const;
    bool deplacer(position const & src, position const & dst);
    void affichage(std::ostream & os) const;
    void sauvegarde(std::ofstream & os) const;
    void chargement(std::ifstream & os);
    void depart();
    bool aperdu(couleur c) const;



private:
    std::vector<std::unique_ptr <piece>> _pieces;   //Pas besoin de définir de destructeur
};













