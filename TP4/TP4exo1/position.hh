#pragma once
#include <iostream>
#include <vector>

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

    virtual char symbole() const =0;
    virtual int val() const =0;

    std::string tostring()const;
    virtual std::vector<position> deplacementspossibles() const=0;
    bool accepterposition(position const & p)const;
    bool deplacer(position const & destination);

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

    char symbole() const override { return 'R';}
    int val() const override      { return 20 ;}
    std::vector<position> deplacementspossibles() const override;

private:
};
















