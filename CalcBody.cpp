//
// Created by super on 10/12/2023.
//

#include "CalcBody.h"

CalcBody::CalcBody() {
    float buffer(25), displayW(630), displayH(100);
    body.setSize({displayW + buffer * 2, (displayH + 10) * 6 + buffer * 2 - 10});
    body.setFillColor(sf::Color::White);
    body.setOutlineColor(sf::Color::Black);
    body.setOutlineThickness(3);

    display.setPosition({buffer, buffer});
    display.setDimension({displayW, displayH});
    board.setPosition({buffer, displayH + buffer + 10});
}

void CalcBody::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (event.type == sf::Event::TextEntered){
        display.addEventHandler(window, event);
    } else if(event.type == sf::Event::MouseButtonPressed){
        board.addEventHandler(window, event, display);
    }
}

void CalcBody::update() {
    display.update();
}

void CalcBody::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(body);
    target.draw(display);
    target.draw(board);
}

