#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int firstElementToRepeatKTimes(const vector<int>& arr, int k) {
    unordered_map<int, int> freq;

    // Step 1: Count the frequency of each element
    for (int num : arr) {
        freq[num]++;
    }

    // Step 2: Find the first element with frequency exactly k
    for (int num : arr) {
        if (freq[num] == k) {
            return num;
        }
    }

    // If no element is found with exactly k occurrences, return -1
    return -1;
}

int main() {
    // Example test cases
    vector<int> arr1 = {3, 1, 4, 4, 5, 2, 6, 1, 4};
    int k1 = 2;
    cout << firstElementToRepeatKTimes(arr1, k1) << endl; // Output: 1

    vector<int> arr2 = {2, 3, 4, 2, 2, 5, 5};
    int k2 = 2;
    cout << firstElementToRepeatKTimes(arr2, k2) << endl; // Output: 5

    vector<int> arr3 = {1, 1, 1, 1};
    int k3 = 1;
    cout << firstElementToRepeatKTimes(arr3, k3) << endl; // Output: -1

    vector<int> arr4 = {10};
    int k4 = 1;
    cout << firstElementToRepeatKTimes(arr4, k4) << endl; // Output: 10

    vector<int> arr5 = {6, 6, 6, 6, 7, 7, 8, 8, 8};
    int k5 = 3;
    cout << firstElementToRepeatKTimes(arr5, k5) << endl; // Output: 8

    return 0;
}
