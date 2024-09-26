//
// Created by super on 10/10/2023.
//

#ifndef CALCULATOR_POSTFIX_H
#define CALCULATOR_POSTFIX_H
#include <string>
#include <stack>
#include <queue>

class PostFix {
private:
    static std::string getNextValue(std::string string);
    static void removeExtraneousSpaces(std::string &string);
    static bool isNumber(const std::string& string);

    static bool canGoInStack(std::string inStack, std::string next);
public:
    static std::queue<std::string> inFixToPostFix(std::string inFix);
    static double evaluate(std::queue<std::string> inFix);


};


#endif //CALCULATOR_POSTFIX_H
