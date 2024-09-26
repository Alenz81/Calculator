//
// Created by super on 10/12/2023.
//

#include "Engine.h"

sf::Font Engine::font;
bool Engine::loadedFont = false;

void Engine::loadFont() {
    if (!loadedFont) {
        loadedFont = font.loadFromFile("Digital7-rg1mL.ttf");
    }
}

sf::Font &Engine::getFont() {
    loadFont();
    return font;
}
