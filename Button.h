//
// Created by super on 10/11/2023.
//

#ifndef CALCULATOR_BUTTON_H
#define CALCULATOR_BUTTON_H
#include <SFML/Graphics.hpp>
#include "Engine.h"
#include "Helper.h"
#include "Display.h"

class Button : public sf::Drawable {
private:
    sf::RectangleShape rect;
    sf::Text text;

    void initializeButton(sf::Color color, std::string letter, sf::Vector2f pos, sf::Vector2f size, int txtSize);
public:
    Button();
    Button(sf::Color color, char letter, sf::Vector2f pos, sf::Vector2f size, int txtSize);
    Button(sf::Color color, std::string letter, sf::Vector2f pos, sf::Vector2f size, int txtSize);
    void move(sf::Vector2f pos);
    bool withinBounds(sf::Vector2i pos);

    void addEventHandler(sf::RenderWindow & window, sf::Event event, Display &display);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //CALCULATOR_BUTTON_H
