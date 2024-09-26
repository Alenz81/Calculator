//
// Created by super on 10/10/2023.
//

#include "PostFix.h"

std::queue<std::string> PostFix::inFixToPostFix(std::string inFix) {
    std::stack<std::string> operators;
    std::queue<std::string> calculate;
    std::string next;

    removeExtraneousSpaces(inFix);

    while (inFix.size() != 0) {
        next = getNextValue(inFix);

        inFix = inFix.substr(next.size());
        removeExtraneousSpaces(next);
        removeExtraneousSpaces(inFix);



        if (isNumber(next)) {
            calculate.push(next);
        } else {
            if (operators.empty()){
                operators.push(next);
            } else if (canGoInStack(operators.top(), next)) {
                operators.push(next);
            } else {
                if (next.at(0) == ')'){
                    while (operators.top() != "("){
                        calculate.push(operators.top());
                        operators.pop();
                    }
                    operators.pop();
                } else {
                    while (!operators.empty() && !canGoInStack(operators.top(), next)) {
                        calculate.push(operators.top());
                        operators.pop();
                    }
                    operators.push(next);
                }
            }
        }
    }
    while(!operators.empty()){
        calculate.push(operators.top());
        operators.pop();
    }
    return calculate;
}


void PostFix::removeExtraneousSpaces(std::string &string) {
    if (!string.empty()) {
        int beginPos(0), length(string.size());
        while (string.at(beginPos) == ' ') {
            beginPos++;
        }
        while (string.at(length - 1) == ' ') {
            length--;
        }
        string = string.substr(beginPos, length);
    }
}

double PostFix::evaluate(std::queue<std::string> inFix) {
    std::stack<double> calculate;
    double left, right;

    while(!inFix.empty()){
        if (std::isdigit(inFix.front().at(0))){
            calculate.push(std::stod(inFix.front()));
            inFix.pop();
        } else {
            right = calculate.top();
            calculate.pop();
            left = calculate.top();
            calculate.pop();

            switch (inFix.front().at(0)) {
                case '/':
                    calculate.push(left / right);
                    break;
                case '*':
                    calculate.push(left * right);
                    break;
                case '+':
                    calculate.push(left + right);
                    break;
                case '-':
                    calculate.push(left - right);
                    break;
            }
            inFix.pop();
        }
    }
    return calculate.top();

}

std::string PostFix::getNextValue(std::string string) {
    int lengthOfNewString(0);

    if (std::isdigit(string.at(lengthOfNewString)) || string.at(lengthOfNewString) == '.') {
        while ((lengthOfNewString) < string.size() && (std::isdigit(string.at(lengthOfNewString)) || string.at(lengthOfNewString) == '.')) {
            lengthOfNewString++;
        }
    } else {
        while (!(string.at(lengthOfNewString) >= 40 && string.at(lengthOfNewString) <= 43) && string.at(lengthOfNewString) != '-' && string.at(lengthOfNewString) != '/') {
            lengthOfNewString++;
        }
        lengthOfNewString++;
    }
    return string.substr(0, lengthOfNewString);
}

bool PostFix::isNumber(const std::string& string) {
    for (char c : string){
        if (!std::isdigit(c) && c != ' ' && c != '.'){
            return false;
        }
    }
    return true;
}

bool PostFix::canGoInStack(std::string inStack, std::string next) {
    if (next != ")") {
        if (next == "(" || inStack == "(") {
            return true;
        } else if (next == "+" || next == "-") {
            return false;
        } else if (inStack == "+" || inStack == "-") {
            return true;
        }
    }
    return false;
}
