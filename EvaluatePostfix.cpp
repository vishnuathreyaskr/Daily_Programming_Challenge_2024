#include <iostream>
#include <stack>
#include <sstream>
#include <string>

using namespace std;

int evaluatePostfix(const string& expression) {
    stack<int> operands;
    istringstream tokens(expression);
    string token;

    while (tokens >> token) {
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-')) {
            // If it's a number (including negative numbers), push it to the stack
            operands.push(stoi(token));
        } else {
            // Operator case: pop two operands from the stack
            int b = operands.top(); operands.pop();
            int a = operands.top(); operands.pop();

            if (token == "+") {
                operands.push(a + b);
            } else if (token == "-") {
                operands.push(a - b);
            } else if (token == "*") {
                operands.push(a * b);
            } else if (token == "/") {
                operands.push(a / b); // Integer division
            }
        }
    }

    // The result is the only element left in the stack
    return operands.top();
}

int main() {
    // Test cases
    cout << evaluatePostfix("2 1 + 3 *") << endl; // Output: 9
    cout << evaluatePostfix("5 6 +") << endl; // Output: 11
    cout << evaluatePostfix("-5 6 -") << endl; // Output: -11
    cout << evaluatePostfix("15 7 1 1 + - / 3 * 2 1 1 + + -") << endl; // Output: 5
    cout << evaluatePostfix("5") << endl; // Output: 5

    return 0;
}
