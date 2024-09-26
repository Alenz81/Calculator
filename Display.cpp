//
// Created by super on 10/12/2023.
//

#include "Display.h"

Display::Display() {
    box.setFillColor({214, 240, 215});
    box.setOutlineColor(sf::Color::Black);
    box.setOutlineColor(sf::Color::Black);
    box.setOutlineThickness(3);

    text.setFont(Engine::getFont());
    text.setCharacterSize(45);
    text.setFillColor(sf::Color::Black);
    Helper::leftText(box, text);
}

Display::Display(const sf::Vector2f &dimension, const sf::Font &font) {
    box.setSize(dimension);
    box.setFillColor({214, 240, 215});
    box.setOutlineColor(sf::Color::Black);
    box.setOutlineThickness(100);


    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    Helper::leftText(box, text);
}

void Display::setPosition(const sf::Vector2f &position) {
    box.setPosition(position);
    text.setPosition(position);
    Helper::leftText(box, text);
}

void Display::setDimension(const sf::Vector2f &size) {
    box.setSize(size);
    Helper::leftText(box, text);
}

void Display::setText(const std::string &text) {
    this->text.setString(text);
}

void Display::addText(const std::string &text) {
    this->text.setString(this->text.getString() + text);
}

const std::string &Display::getText() {
    return text.getString();
}

void Display::clear() {
    text.setString("");
}

void Display::setTextColor(const sf::Color &color) {
    text.setFillColor(color);
}

void Display::setBackground(const sf::Color &color) {
    box.setFillColor(color);
}

void Display::toggleDisplay() {

}

void Display::evaluateExpression() {
    text.setString(std::to_string(PostFix::evaluate(PostFix::inFixToPostFix(text.getString()))));
}

void Display::deleteOneChar() {
    text.setString(text.getString().substring(0, text.getString().getSize() - 1));
}

void Display::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (event.type == sf::Event::TextEntered){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)){
            deleteOneChar();
        } else if (std::isdigit(event.text.unicode) || event.text.unicode == '+' || event.text.unicode == '-' || event.text.unicode == '*' || event.text.unicode == '/' || event.text.unicode == '.' || event.text.unicode == '(' || event.text.unicode == ')'){
            text.setString(text.getString() + event.text.unicode);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
            evaluateExpression();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            clear();
        }
    }
}

void Display::update() {
    Helper::leftText(box, text);
}

void Display::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    //states.transform = box.getTransform();
    target.draw(box);
    target.draw(text);
    //target.draw(text, states);
}


