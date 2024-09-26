//
// Created by super on 10/11/2023.
//

#ifndef CALCULATOR_BUTTONBOARD_H
#define CALCULATOR_BUTTONBOARD_H
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Display.h"

class ButtonBoard : public sf::Drawable {
private:
    Button buttonArray[4][5];
    sf::Vector2f pos, size;

    void initializeBoard(sf::Color color);
    int spacing;
public:
    ButtonBoard();
    ButtonBoard(sf::Color color, sf::Vector2f size);
    void setPosition(sf::Vector2f pos);
    void setSize(float size);

    void addEventHandler(sf::RenderWindow & window, sf::Event event, Display &display);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

};


#endif //CALCULATOR_BUTTONBOARD_H
