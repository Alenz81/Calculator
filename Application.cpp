//
// Created by super on 10/11/2023.
//

#include "Application.h"

CalcBody Application::calcBody;

Application::Application() {

}

void Application::runCalculator() {
    sf::VideoMode videoMode(630 + (25 * 2), 660 + (25 * 2) - 10 , 32);
    sf::RenderWindow window(videoMode, "Calculator");
    window.setFramerateLimit(30);


    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            } else {
                calcBody.addEventHandler(window, event);
            }
        }

        calcBody.update();

        window.clear();
        window.draw(calcBody);
        window.display();
    }
}
