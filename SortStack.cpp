#include <iostream>
#include <stack>
using namespace std;

// Function to insert an element into a sorted stack
void sortedInsert(stack<int> &stk, int element) {
    // Base case: If stack is empty or element is greater than top element, push it
    if (stk.empty() || stk.top() <= element) {
        stk.push(element);
        return;
    }

    // Pop the top element and hold it until we find the correct position
    int topElement = stk.top();
    stk.pop();

    // Recursive call to insert element in the correct position
    sortedInsert(stk, element);

    // Push the top element back after inserting the element in sorted order
    stk.push(topElement);
}

// Function to sort the stack using recursion
void sortStack(stack<int> &stk) {
    // Base case: If stack is empty, return
    if (stk.empty()) {
        return;
    }

    // Pop the top element and sort the remaining stack recursively
    int topElement = stk.top();
    stk.pop();

    // Recursive call to sort the rest of the stack
    sortStack(stk);

    // Insert the popped element into the sorted stack
    sortedInsert(stk, topElement);
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
    stk1.push(3);
    stk1.push(1);
    stk1.push(4);
    stk1.push(2);
    sortStack(stk1);
    printStack(stk1);  // Output: 1 2 3 4

    // Test case 2
    stack<int> stk2;
    stk2.push(7);
    stk2.push(1);
    stk2.push(5);
    sortStack(stk2);
    printStack(stk2);  // Output: 1 5 7

    // Test case 3
    stack<int> stk3;
    stk3.push(-3);
    stk3.push(14);
    stk3.push(8);
    stk3.push(2);
    sortStack(stk3);
    printStack(stk3);  // Output: -3 2 8 14

    // Test case 4 (Empty stack)
    stack<int> stk4;
    sortStack(stk4);
    printStack(stk4);  // Output: (empty)

    // Test case 5 (All elements the same)
    stack<int> stk5;
    stk5.push(3);
    stk5.push(3);
    stk5.push(3);
    sortStack(stk5);
    printStack(stk5);  // Output: 3 3 3

    return 0;
}
