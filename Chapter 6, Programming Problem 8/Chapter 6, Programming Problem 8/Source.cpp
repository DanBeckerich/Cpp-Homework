#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

//convert chars 0-9 to an intiger
int char_to_int(char character) {
	stringstream temp;
	temp << character;
	int x;
	temp >> x;
	return x;
}

//parse 2 values and an operator off the stacks.
void exec(stack<int>& valstack, stack<char>& opstack) {
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

	cout << " " << operand1 << " " << operand2 << " " << op << " = " << result << endl;

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

//concatenate two ints
int concatenate(int i, int j) {
	return stoi(to_string(i) + to_string(j));
}

//trim out whitespace from a string
string trim(string full)
{
	char x;
	int counter = 0;
	string processed;
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

//check if a char is a space or other whitespace character.
bool isWhiteSpace(char ch)
{
	return isspace(static_cast<unsigned char>(ch));
}

int parse(string equation) {


	//create the stacks
	stack<char> opStack = stack<char>();
	stack<int> valStack = stack<int>();

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
			//if it isnt empty, make sure the op below it doesnt have a higher precedence.
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

		//if its a closing parenthacy, keep calling exec until we go back to the opening parenthacy.
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
		//store user equations.
		string equation;
		cout << "Enter a mathematical expression, enter \'.\' to exit:  ";
		getline(cin, equation);
		equation = trim(equation);

		//loop until the user enters '.'
		while (equation != ".") {
			cout << parse(equation) << endl;
			
			cout << "Enter a mathematical expression, enter \'.\' to exit:  ";
			getline(cin, equation);
			equation = trim(equation);
		}
		system("pause");
		return 0;


}
