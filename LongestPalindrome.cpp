#include <iostream>
#include <string>

using namespace std;

// Helper function to expand around the center
string expandAroundCenter(const string& s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
    }
    // Return the palindromic substring
    return s.substr(left + 1, right - left - 1);
}

string longestPalindrome(string s) {
    if (s.empty()) return "";
    
    string longest = "";
    
    for (int i = 0; i < s.size(); i++) {
        // Check for odd-length palindromes
        string oddPal = expandAroundCenter(s, i, i);
        if (oddPal.size() > longest.size()) {
            longest = oddPal;
        }
        
        // Check for even-length palindromes
        string evenPal = expandAroundCenter(s, i, i + 1);
        if (evenPal.size() > longest.size()) {
            longest = evenPal;
        }
    }
    
    return longest;
}

int main() {
    // Test case 1
    string s1 = "babad";
    cout << longestPalindrome(s1) << endl; // Output: "bab" (or "aba")

    // Test case 2
    string s2 = "cbbd";
    cout << longestPalindrome(s2) << endl; // Output: "bb"

    // Test case 3
    string s3 = "a";
    cout << longestPalindrome(s3) << endl; // Output: "a"

    // Test case 4
    string s4 = "aaaa";
    cout << longestPalindrome(s4) << endl; // Output: "aaaa"

    // Test case 5
    string s5 = "abc";
    cout << longestPalindrome(s5) << endl; // Output: "a"

    return 0;
}
