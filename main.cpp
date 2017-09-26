#include <QCoreApplication>
#include "bubble.h"
#include <iostream>
using namespace sf;
using namespace std;

const int windowWidth=1080;
const int windowHeight=768;


float reduireBruit(float x,float bruit) {
    if(x>0)
        return(max(0.f,x-bruit)/(100-bruit));
    else
        return(min(0.f,x+bruit)/(100-bruit));
}

int main()
{
    RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Bubble fight");
    window.setFramerateLimit(60);
    View vue(Vector2f(windowWidth/2,windowHeight/2),Vector2f(windowWidth,windowHeight));
    window.setView(vue);
    Bubble perso(Vector2f(50,50));
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type) {
            case Event::Closed:
                window.close();
                break;
            default:
                break;
            }
        }
        window.clear(Color::White);
        float dx=reduireBruit(Joystick::getAxisPosition(1,Joystick::Axis::X),15);
        float dy=reduireBruit(Joystick::getAxisPosition(1,Joystick::Axis::Y),15);
        float dx2=Joystick::getAxisPosition(1,Joystick::Axis::U);
        float dy2=Joystick::getAxisPosition(1,Joystick::Axis::R);
        perso.actualise(Vector2f(dx,dy),Vector2f(dx2,dy2),Joystick::isButtonPressed(1,0));
        perso.affiche(window);
        window.setView(vue);
        window.display();
    }
}


