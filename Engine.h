//
// Created by super on 10/12/2023.
//

#ifndef CALCULATOR_ENGINE_H
#define CALCULATOR_ENGINE_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Engine {
private:
    static sf::Font font;
    static bool loadedFont;
    static void loadFont();

public:
    static sf::Font& getFont();
};


#endif //CALCULATOR_ENGINE_H
