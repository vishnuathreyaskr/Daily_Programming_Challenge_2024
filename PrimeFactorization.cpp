#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> primeFactorization(int N) {
    vector<int> factors;
    // Check for number of 2s that divide N
    while (N % 2 == 0) {
        factors.push_back(2);
        N /= 2;
    }
    // N must be odd at this point, so we can skip even numbers
    for (int i = 3; i <= sqrt(N); i += 2) {
        // While i divides N, add i and divide N
        while (N % i == 0) {
            factors.push_back(i);
            N /= i;
        }
    }
    // This condition is to check if N is a prime number greater than 2
    if (N > 2) {
        factors.push_back(N);
    }
    return factors;
}

int main() {
    // Test case 1
    int N1 = 18;
    vector<int> result1 = primeFactorization(N1);
    cout << "Output: ";
    for (int factor : result1) {
        cout << factor << " ";
    }
    cout << endl;

    // Test case 2
    int N2 = 30;
    vector<int> result2 = primeFactorization(N2);
    cout << "Output: ";
    for (int factor : result2) {
        cout << factor << " ";
    }
    cout << endl;

    // Test case 3
    int N3 = 49;
    vector<int> result3 = primeFactorization(N3);
    cout << "Output: ";
    for (int factor : result3) {
        cout << factor << " ";
    }
    cout << endl;

    // Test case 4
    int N4 = 19;
    vector<int> result4 = primeFactorization(N4);
    cout << "Output: ";
    for (int factor : result4) {
        cout << factor << " ";
    }
    cout << endl;

    // Test case 5
    int N5 = 64;
    vector<int> result5 = primeFactorization(N5);
    cout << "Output: ";
    for (int factor : result5) {
        cout << factor << " ";
    }
    cout << endl;

    // Test case 6
    int N6 = 123456;
    vector<int> result6 = primeFactorization(N6);
    cout << "Output: ";
    for (int factor : result6) {
        cout << factor << " ";
    }
    cout << endl;

    return 0;
}
