#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cmath>
#include "include/infix.hpp"
#include "include/util.hpp"

//parse 2 values and an operator off the stacks.
void exec(std::stack<int>& valstack, std::stack<char>& opstack) {
    //take the 2 numbers off the valstack
    int operand2 = valstack.top();
    valstack.pop();
    int operand1 = valstack.top();
    valstack.pop();
    //get the operator
    char op = opstack.top();
    opstack.pop();

    int result = 0;

    //perform the operation
    switch (op)
    {
        case '+':
            result = operand1 + operand2;
            break;
        case '-':
            result = operand1 - operand2;
            break;
        case '*':
            result = operand1 * operand2;
            break;
        case '/':
            result = round((double)operand1 / (double)operand2);
            break;
        case '^':
            result = (int)pow(operand1, operand1);
            break;
    }

    std::cout << " " << operand1 << " " << operand2 << " " << op << " = " << result << std::endl;

    //put the resulting value back on the stack
    valstack.push(result);
}

//get the precedence of an operator
int precedence(char op) {

    switch (op) {
        case '(':
        case ')':
            return 0;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        case '^':
            return 3;
    }

    return 0;
}

//trim out whitespace from a string
std::string trim(std::string full)
{
    char x;
    int counter = 0;
    std::string processed;
    for (int t = full.size(); t > 0; t--)
    {
        x = full.at(counter);
        if (x != ' ')
        {
            processed.push_back(full.at(counter));
        }
        counter++;
    }
    return processed;
}

int parse(std::string equation) {


    //create the stacks
    std::stack<char> opStack = std::stack<char>();
    std::stack<int> valStack = std::stack<int>();

    //iterate through each character in the string
    for (int i = 0; i < equation.length(); i++) {

        //save some time, get the char from the specific location in the string
        char current = equation.at(i);

        //if the char is a digit
        if (isdigit(current)) {

            //and if the last char was a digit.
            if (i - 1 >= 0 && isdigit(equation.at(i - 1))) {
                //concatenate it on the last number
                int temp = valStack.top();
                valStack.pop();
                valStack.push(concatenate(temp, char_to_int(current)));
            }
            else {
                //if the last char was not a digit, just put it on the stack
                valStack.push(char_to_int(current));
            }
        }

        else if (current == '(') {
            opStack.push(current);
        }

            //if the char is an operator
        else if (current == '+' || current == '-' || current == '*' || current == '/' || current == '^') {
            //add it to an empty stack.
            if (opStack.empty()) {
                opStack.push(current);
            }
                //if it isn't empty, make sure the op below it doesnt have a higher precedence.
            else if (precedence(current) > precedence(opStack.top())) {
                opStack.push(current);
            }
            else {
                //if it does, execute the stacks until the stack is either empty, or the op on top of the stack has an equal or lower precedence.
                while (opStack.empty() == false && (precedence(current) <= precedence(opStack.top()))) {
                    exec(valStack, opStack);
                }
                opStack.push(current);
            }
        }

            //if its a closing parentheses, keep calling exec until we go back to the opening parenthacy.
        else if (current == ')') {
            while (opStack.top() != '(') {
                exec(valStack, opStack);
            }
            opStack.pop();
        }
    }

    //if there are any ops left on the stack, execute them
    while (opStack.empty() == false) {
        exec(valStack, opStack);
    }
    int result = valStack.top();

    return result;
}

int main() {
    start:
    //store user equations.
    std::string equation;

    std::cout << "shunting yard equation parser. enter your equation in ether infix or prefix notation." << std::endl;
    std::cout << "supported operators: +, -, *, /, ^, and parentheses" << std::endl;
    std::cout << "type in your equation, enter \'.\' to exit:  ";

    //get the user input and strip all white space.
    getline(std::cin, equation);
    //equation = trim(preToInfix(equation));

    if(isPreFix(equation)){
        equation = trim(preToInfix(equation));
    }
    else if(isInfix(equation)){
        equation = trim(equation);
    }

    else {

        std::cout << "please enter a valid expression." << std::endl;
        goto start;
    }

    std::cout << std::endl;

    //loop until the user enters '.'
    while (equation != ".") {
        std::cout << parse(equation) << std::endl;

        std::cout << "type in your infix equation, enter \'.\' to exit:  ";
        getline(std::cin, equation);

        //I wrote this to parse standard equations (infix) because i didnt read all the instructions before i wrote it.
        //rather than going through and re-writing the damn thing, I just put in the little function to convert one to the other
        //if you want to be able to enter regular equations, get rid of the getInfix() call.
        equation = trim(preToInfix(equation));
    }

    return 0;
}
