#include "bubble.h"
#include <iostream>

Bubble::Bubble(sf::Vector2f pos, sf::Color col):_shape(RAYON),_speed(SPEED),dash_cd(0),_hp(100) {
    _shape.setPosition(pos.x,pos.y);
    _shape.setFillColor(col);
}

sf::CircleShape Bubble::getShape() const {
    return _shape;
}

void Bubble::setPosition(sf::Vector2f vec) {
    _shape.move(vec-_shape.getPosition());
}


int Bubble::getLife() const {
    return _hp;
}



void Bubble::damage(int degats) {
    _hp=std::min(std::max(0,_hp-degats),100);
}

sf::Vector2f Bubble::getPos() const {
    return _shape.getPosition();
}

void Bubble::dashHandler(bool dash) {
    std::cout<<dash_cd<<std::endl;
    if(dash && dash_cd==0) {
        _speed*=4;
        dash_cd=310;
    }
    if(dash_cd==300)
        _speed=SPEED;
    if(dash_cd>0)
        dash_cd--;
}


//version1 : on empeche le personnage de rentrer dans le mur
void Bubble::actualise(sf::Vector2f dir,sf::Vector2f look,bool dash) {
    dashHandler(dash);
    _shape.move(_speed*dir);
    if(abs(look.x)<50)
        look.x=0;
    if(abs(look.y)<50)
        look.y=0;
    float norm = sqrt(look.x*look.x+look.y*look.y);
    if(norm<1) //si la norme est trop petite on fait rien
        return;
    else {
        _look=look/norm;
    }
}



void Bubble::affiche(sf::RenderWindow &app) const{
    app.draw(_shape);
    sf::CircleShape eye(7);
    eye.setFillColor(sf::Color::Black);
    eye.setPosition(sf::Vector2f(RAYON-7,RAYON-7)+_shape.getPosition()+RAYON*_look);
    app.draw(eye);
}



