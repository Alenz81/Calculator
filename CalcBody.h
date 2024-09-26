//
// Created by super on 10/12/2023.
//

#ifndef CALCULATOR_CALCBODY_H
#define CALCULATOR_CALCBODY_H
#include <SFML/Graphics.hpp>
#include "Display.h"
#include "ButtonBoard.h"
#include "Engine.h"

class CalcBody : public sf::Drawable {
private:
    sf::RectangleShape body;
    Display display;
    ButtonBoard board;
public:
    CalcBody();
    void addEventHandler(sf::RenderWindow & window, sf::Event event);
    void update();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //CALCULATOR_CALCBODY_H
