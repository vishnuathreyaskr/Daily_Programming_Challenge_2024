#include <iostream>
using namespace std;

// Function to calculate the n-th Fibonacci number using dynamic programming
long long fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    long long prev1 = 1, prev2 = 0; // Initialize first two Fibonacci numbers
    long long current;

    // Calculate Fibonacci numbers iteratively
    for (int i = 2; i <= n; ++i) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }

    return current;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    // Output the n-th Fibonacci number
    cout << "The " << n << "-th Fibonacci number is: " << fibonacci(n) << endl;

    return 0;
}
