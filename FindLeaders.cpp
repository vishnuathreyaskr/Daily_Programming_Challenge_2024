#include <iostream>
#include <vector>
#include <algorithm> // For reverse function

using namespace std;

vector<int> findLeaders(const vector<int>& arr) {
    vector<int> leaders;
    int n = arr.size();
    
    if (n == 0) return leaders; // In case of an empty array

    // The last element is always a leader
    int max_from_right = arr[n - 1];
    leaders.push_back(max_from_right);

    // Traverse the array from right to left
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > max_from_right) {
            leaders.push_back(arr[i]);
            max_from_right = arr[i];
        }
    }

    // Reverse the result as we need to maintain the order
    reverse(leaders.begin(), leaders.end());
    return leaders;
}

int main() {
    // Test Case 1
    vector<int> arr1 = {16, 17, 4, 3, 5, 2};
    vector<int> result1 = findLeaders(arr1);
    for (int leader : result1) cout << leader << " ";
    cout << endl;

    // Test Case 2
    vector<int> arr2 = {1, 2, 3, 4, 0};
    vector<int> result2 = findLeaders(arr2);
    for (int leader : result2) cout << leader << " ";
    cout << endl;

    // Test Case 3
    vector<int> arr3 = {7, 10, 4, 10, 6, 5, 2};
    vector<int> result3 = findLeaders(arr3);
    for (int leader : result3) cout << leader << " ";
    cout << endl;

    // Test Case 4
    vector<int> arr4 = {5};
    vector<int> result4 = findLeaders(arr4);
    for (int leader : result4) cout << leader << " ";
    cout << endl;

    // Test Case 5
    vector<int> arr5 = {100, 50, 20, 10};
    vector<int> result5 = findLeaders(arr5);
    for (int leader : result5) cout << leader << " ";
    cout << endl;

    return 0;
}
