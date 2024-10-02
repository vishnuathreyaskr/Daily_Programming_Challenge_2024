#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> slidingWindowMaximum(const vector<int>& arr, int k) {
    deque<int> dq;
    vector<int> result;

    for (int i = 0; i < arr.size(); ++i) {
        // Remove indices of elements not in the current window
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

        // Remove elements smaller than the current element
        while (!dq.empty() && arr[dq.back()] < arr[i]) {
            dq.pop_back();
        }

        // Add the current element's index to the deque
        dq.push_back(i);

        // The first k-1 windows are not full, so we start adding to result from i >= k-1
        if (i >= k - 1) {
            result.push_back(arr[dq.front()]);
        }
    }

    return result;
}

int main() {
    // Example test cases
    vector<int> arr1 = {1, 3, -1, -3, 5, 3, 6, 7};
    int k1 = 3;
    vector<int> result1 = slidingWindowMaximum(arr1, k1);
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;  // Output: 3 3 5 5 6 7

    vector<int> arr2 = {1, 5, 3, 2, 4, 6};
    int k2 = 3;
    vector<int> result2 = slidingWindowMaximum(arr2, k2);
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;  // Output: 5 5 4 6

    vector<int> arr3 = {1, 2, 3, 4};
    int k3 = 2;
    vector<int> result3 = slidingWindowMaximum(arr3, k3);
    for (int num : result3) {
        cout << num << " ";
    }
    cout << endl;  // Output: 2 3 4

    vector<int> arr4 = {7, 7, 7, 7};
    int k4 = 1;
    vector<int> result4 = slidingWindowMaximum(arr4, k4);
    for (int num : result4) {
        cout << num << " ";
    }
    cout << endl;  // Output: 7 7 7 7

    return 0;
}
