//
// Created by super on 10/11/2023.
//

#ifndef CALCULATOR_APPLICATION_H
#define CALCULATOR_APPLICATION_H
#include "CalcBody.h"


class Application {
private:
    static CalcBody calcBody;
public:
    Application();
    static void runCalculator();
};


#endif //CALCULATOR_APPLICATION_H
