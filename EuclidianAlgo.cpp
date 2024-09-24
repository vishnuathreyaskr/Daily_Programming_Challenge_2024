#include <iostream>
#include <algorithm> // For std::gcd in C++17

using namespace std;

// Function to compute the GCD using the Euclidean algorithm
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute the LCM
long long lcm(long long N, long long M) {
    return (N / gcd(N, M)) * M;
}

int main() {
    // Test case 1
    long long N1 = 4, M1 = 6;
    cout << "Output: " << lcm(N1, M1) << endl;

    // Test case 2
    long long N2 = 5, M2 = 10;
    cout << "Output: " << lcm(N2, M2) << endl;

    // Test case 3
    long long N3 = 7, M3 = 3;
    cout << "Output: " << lcm(N3, M3) << endl;

    // Test case 4
    long long N4 = 1, M4 = 987654321;
    cout << "Output: " << lcm(N4, M4) << endl;

    // Test case 5
    long long N5 = 123456, M5 = 789012;
    cout << "Output: " << lcm(N5, M5) << endl;

    return 0;
}
