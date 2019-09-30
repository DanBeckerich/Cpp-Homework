#include <bits/stdc++.h>
#include <string>
#include "../include/infix.hpp"
#include "../include/util.hpp"
#include <regex>

bool isOperator(char x) {
    switch (x) {
        case '+':
        case '-':
        case '/':
        case '*':
            return true;
    }
    return false;
}

bool isParen(char x){
    switch (x) {
        case '(':
        case ')':
            return true;

    }
    return false;
}

// Convert prefix to Infix expression
std::string preToInfix(std::string pre_exp) {
    std::stack<std::string> s;

    // length of expression
    int length = pre_exp.size();

    // reading from right to left
    for (int i = length - 1; i >= 0; i--) {

        // check if symbol is operator
        if (isOperator(pre_exp[i])) {

            // pop two operands from stack
            std::string op1 = s.top();   s.pop();
            std::string op2 = s.top();   s.pop();

            // concat the operands and operator
            std::string temp = "(" + op1 + pre_exp[i] + op2 + ")";

            // Push string temp back to stack
            s.push(temp);
        }

            // if symbol is an operand
        else {
            char current = pre_exp[i];

            //if it isnt, make some checks.
            //if there is one more space after the current one,
            //check if we need to concatenate them,
            if(i + 1 <= length && isdigit(pre_exp[i + 1])) {
                std::string newNum = pre_exp[i] + s.top();  s.pop();
                s.push(newNum);
            }

            else if ( current != ' ') {
                s.push(std::string(1,pre_exp[i]));
            }

        }
    }

    // Stack now contains the Infix expression
    return s.top();
}

//---------------------------------------------------C5E6---------------------------------------------------------------
bool isPreFix(std::string exp){
    for(int i = 0; i < exp.size(); i++){
        if(isParen(exp[i]) || isspace(exp[i])){
            continue;
        }
        else if(isOperator(exp[i])){
            return true;
        }
        else if(isdigit(exp[i])){
            return false;
        }
    }
    return false;
}
//---------------------------------------------------C5E6---------------------------------------------------------------

//---------------------------------------------------C5E8---------------------------------------------------------------
//i realize this isn't really covered in this course, let alone in this chapter, but i feel the easiest way of completing
// this section is to use Regex. my regex string i am using for pattern matching is "\(?\d+\s?[\+\-\*\\\^]\s?\d+\)?"
//to get a better idea of whats actually happening here, take a look at this web page https://regex101.com/r/JaU1Qu/2
//but the tl;dr for it is as fallows:
// \(? and \)? optionally checks for open and closing parens
// \d+ non-optionally looks for any number of digits.
// \s? optionally checks for whitespace characters.
// [\+\-\*\\\^] non-optionally looks for an operator character.
// the only time this will break (that i know of) is when a user puts two or more whitespaces in like so: 2  +    8.
bool isInfix(std::string exp){

    std::regex pattern(R"(\(?\d+\s?[\+\-\*\\^]\s?\d+\)?)");
    return regex_match(exp, pattern);
    //ez pz lol.
}
//---------------------------------------------------C5E8---------------------------------------------------------------