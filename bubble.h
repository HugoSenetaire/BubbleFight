#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


const int SPEED=10;
const float RAYON=15.;

class Bubble
{
public:
    Bubble(sf::Vector2f pos, sf::Color col=sf::Color::Red);
    void actualise(sf::Vector2f dir, sf::Vector2f look, bool dash);
    void affiche(sf::RenderWindow &app) const;
    sf::CircleShape getShape() const;
    sf::Vector2f getPos() const;
    void move(sf::Vector2f vect);
    void setPosition(sf::Vector2f vec);
    int getLife() const;
    void afficheScore(sf::RenderWindow &app, sf::View vue) const;
    void damage(int degats);
    void dashHandler(bool dash);

private:
    sf::CircleShape _shape;
    int dash_cd; //de 350 à 300 dash (vitesse multipliée) et de 300 à 0 cooldown
    sf::Vector2f _look;
    float _speed;
    int _hp;
};

#endif // PERSONNAGE_H
