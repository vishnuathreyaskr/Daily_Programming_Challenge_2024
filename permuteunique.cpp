#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

void backtrack(string& s, int start, vector<string>& result, unordered_set<string>& seen) {
    if (start == s.size()) {
        if (seen.find(s) == seen.end()) {
            result.push_back(s);
            seen.insert(s);
        }
        return;
    }
    for (int i = start; i < s.size(); i++) {
        swap(s[start], s[i]);
        backtrack(s, start + 1, result, seen);
        swap(s[start], s[i]); // backtrack
    }
}

vector<string> permuteUnique(string s) {
    vector<string> result;
    unordered_set<string> seen;
    backtrack(s, 0, result, seen);
    return result;
}

int main() {
    // Test case 1
    string s1 = "abc";
    vector<string> result1 = permuteUnique(s1);
    for (const auto& perm : result1) {
        cout << perm << " ";
    }
    cout << endl;

    // Test case 2
    string s2 = "aab";
    vector<string> result2 = permuteUnique(s2);
    for (const auto& perm : result2) {
        cout << perm << " ";
    }
    cout << endl;

    // Test case 3
    string s3 = "aaa";
    vector<string> result3 = permuteUnique(s3);
    for (const auto& perm : result3) {
        cout << perm << " ";
    }
    cout << endl;

    // Test case 4
    string s4 = "a";
    vector<string> result4 = permuteUnique(s4);
    for (const auto& perm : result4) {
        cout << perm << " ";
    }
    cout << endl;

    // Test case 5
    string s5 = "abcd";
    vector<string> result5 = permuteUnique(s5);
    for (const auto& perm : result5) {
        cout << perm << " ";
    }
    cout << endl;

    return 0;
}
