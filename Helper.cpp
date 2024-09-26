//
// Created by super on 10/12/2023.
//
#ifndef CALCULATOR_HELPER_CPP
#define CALCULATOR_HELPER_CPP

#include "Helper.h"

template<typename T>
void Helper::centerText(const T &obj, sf::Text &text)
{
    sf::FloatRect textRect = text.getGlobalBounds();
    sf::FloatRect tRect = obj.getGlobalBounds();
    sf::Vector2f center = {textRect.width/2.0f, textRect.height/2.f};
    sf::Vector2f localBounds = {center.x + text.getLocalBounds().left, center.y + text.getLocalBounds().top};
    sf::Vector2f rounded = {std::round(localBounds.x), std::round(localBounds.y)};
    text.setOrigin(rounded);
    text.setPosition({tRect.left + tRect.width/2, tRect.top + tRect.height/2});

}

template<typename T>
void Helper::leftText(const T &obj, sf::Text &text) {
    text.setPosition({obj.getGlobalBounds().left + 10, obj.getGlobalBounds().top + obj.getGlobalBounds().height/2.f - text.getCharacterSize()/1.6f});
}

#endif