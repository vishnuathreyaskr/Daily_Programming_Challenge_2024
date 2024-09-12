#include <iostream>
#include <vector>
#include <cmath> // For ceil function

using namespace std;

// Function to get the next gap
int nextGap(int gap) {
    if (gap <= 1) 
        return 0;
    return (gap / 2) + (gap % 2); // To handle odd values, we add 1 if needed
}

// Function to merge two sorted arrays in place
void mergeArrays(vector<int>& arr1, vector<int>& arr2) {
    int m = arr1.size();
    int n = arr2.size();
    int gap = m + n;
    
    // Start with the largest gap
    gap = nextGap(gap);
    
    while (gap > 0) {
        int i = 0; // index for arr1
        int j = gap; // index for arr2 if gap >= m, else arr1
        
        // First compare within arr1
        for (; j < m && i < m; i++, j++) {
            if (arr1[i] > arr1[j]) {
                swap(arr1[i], arr1[j]);
            }
        }
        
        // Then compare between arr1 and arr2
        j -= m; // Adjust j to compare arr1 and arr2
        for (; j < n && i < m; i++, j++) {
            if (arr1[i] > arr2[j]) {
                swap(arr1[i], arr2[j]);
            }
        }

        // Lastly compare within arr2
        for (i = 0; j < n; i++, j++) {
            if (arr2[i] > arr2[j]) {
                swap(arr2[i], arr2[j]);
            }
        }

        // Update the gap
        gap = nextGap(gap);
    }
}

int main() {
    // Test case 1
    vector<int> arr1 = {1, 3, 5};
    vector<int> arr2 = {2, 4, 6};
    mergeArrays(arr1, arr2);
    for (int x : arr1) cout << x << " ";
    cout << endl;
    for (int x : arr2) cout << x << " ";
    cout << endl;

    // Test case 2
    arr1 = {10, 12, 14};
    arr2 = {1, 3, 5};
    mergeArrays(arr1, arr2);
    for (int x : arr1) cout << x << " ";
    cout << endl;
    for (int x : arr2) cout << x << " ";
    cout << endl;

    // Test case 3
    arr1 = {2, 3, 8};
    arr2 = {4, 6, 10};
    mergeArrays(arr1, arr2);
    for (int x : arr1) cout << x << " ";
    cout << endl;
    for (int x : arr2) cout << x << " ";
    cout << endl;

    return 0;
}

