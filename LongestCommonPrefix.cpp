#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    // Step 1: Handle edge cases
    if (strs.empty()) return "";
    if (strs.size() == 1) return strs[0];

    // Step 2: Find the shortest string length in the array
    int minLength = strs[0].length();
    for (int i = 1; i < strs.size(); i++) {
        minLength = min(minLength, (int)strs[i].length());
    }

    // Step 3: Compare characters for common prefix
    string commonPrefix = "";
    for (int i = 0; i < minLength; i++) {
        char currentChar = strs[0][i]; // character from the first string
        for (int j = 1; j < strs.size(); j++) {
            if (strs[j][i] != currentChar) {
                return commonPrefix;
            }
        }
        // If all strings match the character, add it to the prefix
        commonPrefix += currentChar;
    }
    
    return commonPrefix;
}

int main() {
    // Test case 1
    vector<string> strs1 = {"flower", "flow", "flight"};
    cout << "Longest Common Prefix: '" << longestCommonPrefix(strs1) << "'" << endl;

    // Test case 2
    vector<string> strs2 = {"dog", "racecar", "car"};
    cout << "Longest Common Prefix: '" << longestCommonPrefix(strs2) << "'" << endl;

    // Test case 3
    vector<string> strs3 = {"apple", "ape", "april"};
    cout << "Longest Common Prefix: '" << longestCommonPrefix(strs3) << "'" << endl;

    // Test case 4 (edge case: empty string in array)
    vector<string> strs4 = {""};
    cout << "Longest Common Prefix: '" << longestCommonPrefix(strs4) << "'" << endl;

    // Test case 5 (single string in array)
    vector<string> strs5 = {"alone"};
    cout << "Longest Common Prefix: '" << longestCommonPrefix(strs5) << "'" << endl;

    return 0;
}
