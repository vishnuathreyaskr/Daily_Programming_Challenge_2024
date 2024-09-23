#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> charIndexMap;
    int maxLength = 0;
    int left = 0;

    // Traverse the string with the right pointer
    for (int right = 0; right < s.length(); right++) {
        // If the character already exists in the map and is within the current window
        if (charIndexMap.find(s[right]) != charIndexMap.end() && charIndexMap[s[right]] >= left) {
            // Move the left pointer to the next position after the last occurrence of the current character
            left = charIndexMap[s[right]] + 1;
        }
        // Update the current character's index in the map
        charIndexMap[s[right]] = right;
        // Calculate the maximum length of the substring
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main() {
    // Test case 1
    string s1 = "abcabcbb";
    cout << "Output: " << lengthOfLongestSubstring(s1) << endl; // Output: 3

    // Test case 2
    string s2 = "bbbbb";
    cout << "Output: " << lengthOfLongestSubstring(s2) << endl; // Output: 1

    // Test case 3
    string s3 = "pwwkew";
    cout << "Output: " << lengthOfLongestSubstring(s3) << endl; // Output: 3

    // Test case 4
    string s4 = "abcdefgh";
    cout << "Output: " << lengthOfLongestSubstring(s4) << endl; // Output: 8

    // Test case 5
    string s5 = "a";
    cout << "Output: " << lengthOfLongestSubstring(s5) << endl; // Output: 1

    return 0;
}
