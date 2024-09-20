#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

bool isValid(string s) {
    // Map for matching closing brackets with corresponding opening brackets
    unordered_map<char, char> bracketMap = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    stack<char> stk;

    for (char c : s) {
        // If the character is a closing bracket
        if (bracketMap.find(c) != bracketMap.end()) {
            // Check if the stack is empty or the top of the stack doesn't match the opening bracket
            if (stk.empty() || stk.top() != bracketMap[c]) {
                return false; // Invalid case
            }
            stk.pop(); // Pop the matching opening bracket from the stack
        }
        // If it's an opening bracket, push it onto the stack
        else {
            stk.push(c);
        }
    }

    // If the stack is empty, all brackets were matched correctly
    return stk.empty();
}

int main() {
    // Test case 1
    string s1 = "()";
    cout << (isValid(s1) ? "true" : "false") << endl; // Output: true

    // Test case 2
    string s2 = "([)]";
    cout << (isValid(s2) ? "true" : "false") << endl; // Output: false

    // Test case 3
    string s3 = "[{()}]";
    cout << (isValid(s3) ? "true" : "false") << endl; // Output: true

    // Test case 4
    string s4 = "";
    cout << (isValid(s4) ? "true" : "false") << endl; // Output: true

    // Test case 5
    string s5 = "{[}";
    cout << (isValid(s5) ? "true" : "false") << endl; // Output: false

    return 0;
}
