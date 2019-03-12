#pragma once
#include <iostream>

struct couleur{
    unsigned short int rouge, vert, bleu;
};


class point {
public:
    point(int x, int y)
        :_x(x),_y(y){
        std::cout << "POINT constructeur par défaut" << std::endl;
    }

    point():_x(0),_y(0){
         std::cout << "POINT constructeur init par défaut" << std::endl;
    }

    point(point const & p)
        :_x(p._x),_y(p._y){
         std::cout << "POINT constructeur par recopie" << std::endl;
    }

    ~point(){
        std::cout << "POINT Destructeur" << std::endl;
    }


    int const & get_x() const
    {
        return _x;
    }

    int const & get_y() const
    {
        return _y;
    }

    std::string ToString();

private:
    int _x;
    int _y;
};


class figuregeometrique {
public:
    figuregeometrique(point const & p,couleur c)
        :_p_origine(p),_c(c){
        std::cout << "FIGUREGEO constructeur par défaut" << std::endl;
    }

    figuregeometrique()
        :_p_origine(point()),_c(){
        std::cout << "FIGUREGEO constructeur init par défaut" << std::endl;
    }

    figuregeometrique(figuregeometrique const & fg)
        :_p_origine(fg._p_origine),_c(fg._c){
        std::cout << "FIGUREGEO constructeur par recopie" << std::endl;
    }

    ~figuregeometrique(){
        std::cout << "FIGUREGEO Destructeur" << std::endl;
    }

    point get_p_origine() const
    {
        return _p_origine;
    }

    couleur get_c() const
    {
        return _c;
    }

    std::string ToString();

private:
    point _p_origine;
    couleur _c;
};


class texte:public figuregeometrique {
public:
    texte(point const & p,couleur c,std::string const & s)
        :figuregeometrique(p,c),_txt(s){
        std::cout << "TEXTE constructeur par défaut" << std::endl;
    }
    texte()
        :figuregeometrique(),_txt(){
        std::cout << "TEXTE constructeur init par défaut" << std::endl;
    }
    texte(texte const & t)
        :figuregeometrique(t.get_p_origine(),t.get_c()),_txt(t._txt){
        std::cout << "TEXTE constructeur par recopie" << std::endl;
    }
    ~texte(){
        std::cout << "TEXTE Destructeur" << std::endl;
    }

    std::string ToString();

private:
    std::string _txt;
};

class triangle:public figuregeometrique {
public:
    triangle(point const & p,couleur c, point const & p1,point const & p2)
        :figuregeometrique(p,c),_p1(p1),_p2(p2){
        std::cout << "TRIANGLE constructeur par défaut" << std::endl;
    }
    triangle()
        :figuregeometrique(),_p1(),_p2(){
        std::cout << "TRIANGLE constructeur init par défaut" << std::endl;
    }
    triangle(triangle const & t)
        :figuregeometrique(t.get_p_origine(),t.get_c()),_p1(t._p1),_p2(t._p2){
        std::cout << "TRIANGLE constructeur par recopie" << std::endl;
    }
    ~triangle(){
        std::cout << "TRIANGLE Destructeur" << std::endl;
    }

    std::string ToString();
private:
    point _p1;
    point _p2;
};

class segment:figuregeometrique {
public:
    segment(point const & p,couleur c, point const & p1)
        :figuregeometrique(p,c),_p1(p1){
        std::cout << "SEGMENT constructeur par défaut" << std::endl;
    }
    segment()
        :figuregeometrique(),_p1(){
        std::cout << "SEGMENT constructeur init par défaut" << std::endl;
    }
    segment(segment const & s)
        :figuregeometrique(s.get_p_origine(),s.get_c()),_p1(s._p1){
        std::cout << "SEGMENT constructeur par recopie" << std::endl;
    }
    ~segment(){
        std::cout << "SEGMENT Destructeur" << std::endl;
    }

    std::string ToString();
private:
    point _p1;
};



class rectangle:public figuregeometrique {
public:
    rectangle(point const & p,couleur c, point const & p1)
        :figuregeometrique(p,c),_p1(p1){
        std::cout << "RECTANGLE constructeur par défaut" << std::endl;
    }
    rectangle()
        :figuregeometrique(),_p1(){
        std::cout << "RECTANGLE constructeur init par défaut" << std::endl;
    }
    rectangle(rectangle const & r)
        :figuregeometrique(r.get_p_origine(),r.get_c()),_p1(r._p1){
        std::cout << "RECTANGLE constructeur par recopie" << std::endl;
    }
    ~rectangle(){
        std::cout << "RECTANGLE Destructeur" << std::endl;
    }

    std::string ToString();
private:
    point _p1;
};
