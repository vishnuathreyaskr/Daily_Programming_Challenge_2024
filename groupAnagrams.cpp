#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagramMap;

    // Iterate through each string in the input array
    for (string s : strs) {
        string sortedStr = s;
        sort(sortedStr.begin(), sortedStr.end()); // Sort the string
        anagramMap[sortedStr].push_back(s); // Use the sorted string as the key
    }

    // Collect the grouped anagrams from the map
    vector<vector<string>> result;
    for (auto& entry : anagramMap) {
        result.push_back(entry.second);
    }

    return result;
}

int main() {
    // Test case 1
    vector<string> strs1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result1 = groupAnagrams(strs1);
    for (const auto& group : result1) {
        cout << "[ ";
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << "] ";
    }
    cout << endl;

    // Test case 2
    vector<string> strs2 = {""};
    vector<vector<string>> result2 = groupAnagrams(strs2);
    for (const auto& group : result2) {
        cout << "[ ";
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << "] ";
    }
    cout << endl;

    // Test case 3
    vector<string> strs3 = {"a"};
    vector<vector<string>> result3 = groupAnagrams(strs3);
    for (const auto& group : result3) {
        cout << "[ ";
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << "] ";
    }
    cout << endl;

    // Test case 4
    vector<string> strs4 = {"abc", "bca", "cab", "xyz", "zyx", "yxz"};
    vector<vector<string>> result4 = groupAnagrams(strs4);
    for (const auto& group : result4) {
        cout << "[ ";
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << "] ";
    }
    cout << endl;

    // Test case 5
    vector<string> strs5 = {"abc", "def", "ghi"};
    vector<vector<string>> result5 = groupAnagrams(strs5);
    for (const auto& group : result5) {
        cout << "[ ";
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << "] ";
    }
    cout << endl;

    return 0;
}
