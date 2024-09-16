#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

string reverseWords(string s) {
    // Step 1: Use a stringstream to split the string into words
    stringstream ss(s);
    string word;
    vector<string> words;
    
    // Step 2: Extract words while ignoring multiple spaces
    while (ss >> word) {
        words.push_back(word);
    }
    
    // Step 3: Reverse the order of words
    reverse(words.begin(), words.end());
    
    // Step 4: Join the reversed words into a single string with a space in between
    string result;
    for (int i = 0; i < words.size(); i++) {
        result += words[i];
        if (i != words.size() - 1) {
            result += " ";
        }
    }
    
    return result;
}

int main() {
    // Test case 1
    string s1 = "the sky is blue";
    cout << "Reversed: '" << reverseWords(s1) << "'" << endl;

    // Test case 2
    string s2 = "  hello world  ";
    cout << "Reversed: '" << reverseWords(s2) << "'" << endl;

    // Test case 3
    string s3 = "a good   example";
    cout << "Reversed: '" << reverseWords(s3) << "'" << endl;

    // Test case 4 (edge case: all spaces)
    string s4 = "    ";
    cout << "Reversed: '" << reverseWords(s4) << "'" << endl;

    // Test case 5 (edge case: single word)
    string s5 = "word";
    cout << "Reversed: '" << reverseWords(s5) << "'" << endl;

    return 0;
}
