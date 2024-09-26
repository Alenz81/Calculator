//
// Created by super on 10/11/2023.
//

#include "ButtonBoard.h"

ButtonBoard::ButtonBoard() : spacing(10), pos({0, 0}), size({3 * 50, 2 * 50}) {
    initializeBoard({213, 213, 211});
}

ButtonBoard::ButtonBoard(sf::Color color, sf::Vector2f size) : spacing(10), pos({0, 0}), size(size) {
    initializeBoard(color);
}

void ButtonBoard::initializeBoard(sf::Color color) {
    int txtSize(40);
    buttonArray[0][0] = Button(color, "AC", {0 * (size.x + spacing), 0 * (size.y + spacing)}, size, txtSize);
    buttonArray[1][0] = Button(color, "(", {1 * (size.x + spacing), 0 * (size.y + spacing)}, size, txtSize);
    buttonArray[2][0] = Button(color, ")", {2 * (size.x + spacing), 0 * (size.y + spacing)}, size, txtSize);


    for (int i = 0; i < 3; i++){
        for (int j = 1; j < 4; j++){
            buttonArray[i][j] = Button(color, (3 * (2 - (j - 1)) + 1 + i) + 48, {(i) * (size.x + spacing), (j) * (size.y + spacing)}, size, txtSize);
        }
    }
    buttonArray[0][4] = Button(color, "del", {0 * (size.x + spacing), (4) * (size.y + spacing)}, size, txtSize);
    buttonArray[1][4] = Button(color, '0', {1 * (size.x + spacing), (4) * (size.y + spacing)}, size, txtSize);
    buttonArray[2][4] = Button(color, '.', {2 * (size.x + spacing), (4) * (size.y + spacing)}, size, txtSize);
    buttonArray[3][4] = Button(color, '=', {3 * (size.x + spacing), (4) * (size.y + spacing)}, size, txtSize);

    buttonArray[3][0] = Button(color, '+', {3 * (size.x + spacing), (0) * (size.y + spacing)}, size, txtSize);
    buttonArray[3][1] = Button(color, '-', {3 * (size.x + spacing), (1) * (size.y + spacing)}, size, txtSize);
    buttonArray[3][2] = Button(color, '*', {3 * (size.x + spacing), (2) * (size.y + spacing)}, size, txtSize);
    buttonArray[3][3] = Button(color, '/', {3 * (size.x + spacing), (3) * (size.y + spacing)}, size, txtSize);


}

void ButtonBoard::setPosition(sf::Vector2f pos) {
    this->pos = pos;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 5; j++){
            buttonArray[i][j].move(pos);
        }
    }
}

void ButtonBoard::setSize(float size) {

}

void ButtonBoard::addEventHandler(sf::RenderWindow &window, sf::Event event, Display &display) {
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 5; j++){
            buttonArray[i][j].addEventHandler(window, event, display);
        }
    }
}

void ButtonBoard::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 5; j++){
            target.draw(buttonArray[i][j]);
        }
    }
}
