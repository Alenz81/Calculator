//
// Created by super on 10/12/2023.
//

#ifndef CALCULATOR_DISPLAY_H
#define CALCULATOR_DISPLAY_H
#include <SFML/Graphics.hpp>
#include "Engine.h"
#include "Helper.h"
#include "PostFix.h"

class Display : public sf::Drawable{
private:
    sf::RectangleShape box;
    sf::Text text;
public:
    Display();
    Display(const sf::Vector2f& dimension, const sf::Font &font);
    void setPosition(const sf::Vector2f &position);
    void setDimension(const sf::Vector2f &size);
    void setText(const std::string& text);
    void addText(const std::string& text);
    const std::string& getText();
    void clear();
    void setTextColor(const sf::Color & color);
    void setBackground(const sf::Color & color);
    void toggleDisplay();
    void evaluateExpression();
    void deleteOneChar();


    void addEventHandler(sf::RenderWindow & window, sf::Event event);
    void update();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;


};


#endif //CALCULATOR_DISPLAY_H
