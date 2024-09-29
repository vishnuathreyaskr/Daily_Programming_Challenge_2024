#include <iostream>
#include <stack>
using namespace std;

// Function to insert an element at the bottom of the stack
void insertAtBottom(stack<int> &stk, int element) {
    // Base case: If stack is empty, push the element
    if (stk.empty()) {
        stk.push(element);
        return;
    }

    // Hold all items in the stack until we reach the bottom
    int topElement = stk.top();
    stk.pop();

    // Recursive call to reach the bottom
    insertAtBottom(stk, element);

    // Push the held elements back into the stack
    stk.push(topElement);
}

// Function to reverse the stack using recursion
void reverseStack(stack<int> &stk) {
    // Base case: If stack is empty, return
    if (stk.empty()) {
        return;
    }

    // Pop the top element and reverse the remaining stack recursively
    int topElement = stk.top();
    stk.pop();

    // Recursive call to reverse the rest of the stack
    reverseStack(stk);

    // Insert the popped element at the bottom of the reversed stack
    insertAtBottom(stk, topElement);
}

// Helper function to print the stack
void printStack(stack<int> stk) {
    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}

int main() {
    // Test case 1
    stack<int> stk1;
    stk1.push(1);
    stk1.push(2);
    stk1.push(3);
    stk1.push(4);
    reverseStack(stk1);
    printStack(stk1);  // Output: 4 3 2 1

    // Test case 2
    stack<int> stk2;
    stk2.push(3);
    stk2.push(2);
    stk2.push(1);
    reverseStack(stk2);
    printStack(stk2);  // Output: 1 2 3

    // Test case 3 (Single element)
    stack<int> stk3;
    stk3.push(5);
    reverseStack(stk3);
    printStack(stk3);  // Output: 5

    // Test case 4 (Negative numbers)
    stack<int> stk4;
    stk4.push(-5);
    stk4.push(-10);
    stk4.push(-15);
    reverseStack(stk4);
    printStack(stk4);  // Output: -15 -10 -5

    // Test case 5 (Empty stack)
    stack<int> stk5;
    reverseStack(stk5);
    printStack(stk5);  // Output: (empty)

    // Test case 6 (All elements are the same)
    stack<int> stk6;
    stk6.push(3);
    stk6.push(3);
    stk6.push(3);
    reverseStack(stk6);
    printStack(stk6);  // Output: 3 3 3

    return 0;
}
