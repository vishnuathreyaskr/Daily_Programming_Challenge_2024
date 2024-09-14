#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<pair<int, int>> findZeroSumSubarrays(const vector<int>& arr) {
    vector<pair<int, int>> result;
    unordered_map<int, vector<int>> prefixSumMap;
    int sum = 0;

    // Traverse the array
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        // If sum is zero, we found a subarray from 0 to i
        if (sum == 0) {
            result.push_back({0, i});
        }

        // If sum already exists in the map, it means we found a subarray with zero sum
        if (prefixSumMap.find(sum) != prefixSumMap.end()) {
            for (int startIndex : prefixSumMap[sum]) {
                result.push_back({startIndex + 1, i});
            }
        }

        // Add the current index to the map
        prefixSumMap[sum].push_back(i);
    }

    return result;
}

int main() {
    // Test case 1
    vector<int> arr1 = {1, 2, -3, 3, -1, 2};
    vector<pair<int, int>> result1 = findZeroSumSubarrays(arr1);
    for (const auto& p : result1) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    // Test case 2
    vector<int> arr2 = {4, -1, -3, 1, 2, -1};
    vector<pair<int, int>> result2 = findZeroSumSubarrays(arr2);
    for (const auto& p : result2) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    // Test case 3
    vector<int> arr3 = {1, 2, 3, 4};
    vector<pair<int, int>> result3 = findZeroSumSubarrays(arr3);
    for (const auto& p : result3) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    // Test case 4
    vector<int> arr4 = {0, 0, 0};
    vector<pair<int, int>> result4 = findZeroSumSubarrays(arr4);
    for (const auto& p : result4) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    // Test case 5
    vector<int> arr5 = {-3, 1, 2, -3, 4, 0};
    vector<pair<int, int>> result5 = findZeroSumSubarrays(arr5);
    for (const auto& p : result5) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    return 0;
}
