//
// Created by super on 10/11/2023.
//

#include "Button.h"

Button::Button() {

}

Button::Button(sf::Color color, char letter, sf::Vector2f pos, sf::Vector2f size, int txtSize) {
    std::string temp;
    temp += letter;
    initializeButton(color, temp, pos, size, txtSize);
}

Button::Button(sf::Color color, std::string letter, sf::Vector2f pos, sf::Vector2f size, int txtSize) {
    initializeButton(color, letter, pos, size, txtSize);

}

void Button::initializeButton(sf::Color color, std::string letter, sf::Vector2f pos, sf::Vector2f size, int txtSize) {
    rect.setPosition(pos);
    rect.setSize(size);
    rect.setFillColor(color);
    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(3);

    text.setFont(Engine::getFont());

    text.setCharacterSize(txtSize);
    text.setPosition(pos);
    text.setString(letter);
    text.setFillColor(sf::Color::Black);

    Helper::centerText(rect, text);

}

void Button::move(sf::Vector2f pos) {
    rect.move(pos);
    text.move(pos);
}

bool Button::withinBounds(sf::Vector2i pos) {
    return (pos.x > rect.getPosition().x && pos.x < (rect.getPosition().x + rect.getSize().x) && pos.y > rect.getPosition().y && pos.y < (rect.getPosition().y + rect.getSize().y));
}

void Button::addEventHandler(sf::RenderWindow &window, sf::Event event, Display &display) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (withinBounds(sf::Mouse::getPosition(window))) {
            std::string temp = text.getString();
            if (temp == "=") {
                display.evaluateExpression();
            } else if (temp == "del") {
                display.deleteOneChar();
            } else if (temp == "AC") {
                display.clear();
            } else {
                display.addText(temp);
            }
        }
    }
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(rect);
    target.draw(text);
}
