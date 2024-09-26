//
// Created by super on 10/12/2023.
//

#ifndef CALCULATOR_HELPER_H
#define CALCULATOR_HELPER_H
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

class Helper : sf::Drawable {
public:
    template<typename T>
    static void centerText(const T &obj, sf::Text &text);
    template<typename T>
    static void leftText(const T &obj, sf::Text &text);
};

#include "Helper.cpp"

#endif //CALCULATOR_HELPER_H
