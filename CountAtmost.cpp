#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// Helper function to count substrings with at most k distinct characters
int countAtMostKDistinct(const string& s, int k) {
    unordered_map<char, int> charCount;
    int left = 0, right = 0, distinctCount = 0, result = 0;
    int n = s.length();

    while (right < n) {
        charCount[s[right]]++;
        if (charCount[s[right]] == 1) {
            distinctCount++;
        }
        right++;

        while (distinctCount > k) {
            charCount[s[left]]--;
            if (charCount[s[left]] == 0) {
                distinctCount--;
            }
            left++;
        }

        // Count substrings from the current window
        result += right - left;
    }

    return result;
}

// Function to count substrings with exactly k distinct characters
int countSubstringsWithKDistinct(const string& s, int k) {
    return countAtMostKDistinct(s, k) - countAtMostKDistinct(s, k - 1);
}

int main() {
    // Test case 1
    string s1 = "pqpqs";
    int k1 = 2;
    cout << "Output: " << countSubstringsWithKDistinct(s1, k1) << endl; // Output: 7

    // Test case 2
    string s2 = "aabacbebebe";
    int k2 = 3;
    cout << "Output: " << countSubstringsWithKDistinct(s2, k2) << endl; // Output: 12

    // Test case 3
    string s3 = "a";
    int k3 = 1;
    cout << "Output: " << countSubstringsWithKDistinct(s3, k3) << endl; // Output: 1

    // Test case 4
    string s4 = "abc";
    int k4 = 3;
    cout << "Output: " << countSubstringsWithKDistinct(s4, k4) << endl; // Output: 1

    // Test case 5
    string s5 = "abc";
    int k5 = 2;
    cout << "Output: " << countSubstringsWithKDistinct(s5, k5) << endl; // Output: 2

    return 0;
}
