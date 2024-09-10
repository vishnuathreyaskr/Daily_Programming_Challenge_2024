#include <iostream>
#include <vector>

int findMissingNumber(const std::vector<int>& arr, int n) {
    // Calculate the expected sum of numbers from 1 to n
    int expectedSum = n * (n + 1) / 2;
    
    // Calculate the actual sum of the elements in the array
    int actualSum = 0;
    for (int num : arr) {
        actualSum += num;
    }
    
    // The missing number is the difference between the expected sum and the actual sum
    return expectedSum - actualSum;
}

int main() {
    // Test cases
    std::vector<int> arr1 = {1, 2, 4, 5};
    std::vector<int> arr2 = {2, 3, 4, 5};
    std::vector<int> arr3 = {1, 2, 3, 4};
    std::vector<int> arr4 = {1};
    std::vector<int> arr5(999999);
    for (int i = 0; i < 999999; ++i) {
        arr5[i] = i + 1;
    }
    
    std::cout << "Missing number in arr1: " << findMissingNumber(arr1, 5) << std::endl;
    std::cout << "Missing number in arr2: " << findMissingNumber(arr2, 5) << std::endl;
    std::cout << "Missing number in arr3: " << findMissingNumber(arr3, 5) << std::endl;
    std::cout << "Missing number in arr4: " << findMissingNumber(arr4, 2) << std::endl;
    std::cout << "Missing number in arr5: " << findMissingNumber(arr5, 1000000) << std::endl;

    return 0;
}
