#include <iostream>
#include <cmath>
using namespace std;

int countDivisors(long long N) {
    int count = 0;
    
    // Loop through numbers from 1 to sqrt(N)
    for (long long i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            // i is a divisor
            count++;
            // N / i is also a divisor, if it's not the same as i
            if (i != N / i) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    // Test case 1
    long long N1 = 12;
    cout << "Number of divisors of " << N1 << ": " << countDivisors(N1) << endl;

    // Test case 2
    long long N2 = 18;
    cout << "Number of divisors of " << N2 << ": " << countDivisors(N2) << endl;

    // Test case 3
    long long N3 = 29;
    cout << "Number of divisors of " << N3 << ": " << countDivisors(N3) << endl;

    // Test case 4
    long long N4 = 100;
    cout << "Number of divisors of " << N4 << ": " << countDivisors(N4) << endl;

    // Test case 5
    long long N5 = 997;
    cout << "Number of divisors of " << N5 << ": " << countDivisors(N5) << endl;

    return 0;
}
