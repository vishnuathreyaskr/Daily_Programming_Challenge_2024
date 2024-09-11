#include <iostream>
#include <vector>

int findDuplicate(const std::vector<int>& nums) {
    // Phase 1: Finding the intersection point of the two runners.
    int tortoise = nums[0];
    int hare = nums[0];
    do {
        tortoise = nums[tortoise];
        hare = nums[nums[hare]];
    } while (tortoise != hare);

    // Phase 2: Finding the entrance to the cycle.
    tortoise = nums[0];
    while (tortoise != hare) {
        tortoise = nums[tortoise];
        hare = nums[hare];
    }

    return hare;
}

int main() {
    // Test cases
    std::vector<int> arr1 = {1, 3, 4, 2, 2};
    std::vector<int> arr2 = {3, 1, 3, 4, 2};
    std::vector<int> arr3 = {1, 1};
    std::vector<int> arr4 = {1, 4, 4, 2, 3};
    std::vector<int> arr5(100000);
    for (int i = 0; i < 99999; ++i) {
        arr5[i] = i + 1;
    }
    arr5[99999] = 50000;

    std::cout << "Duplicate number in arr1: " << findDuplicate(arr1) << std::endl;
    std::cout << "Duplicate number in arr2: " << findDuplicate(arr2) << std::endl;
    std::cout << "Duplicate number in arr3: " << findDuplicate(arr3) << std::endl;
    std::cout << "Duplicate number in arr4: " << findDuplicate(arr4) << std::endl;
    std::cout << "Duplicate number in arr5: " << findDuplicate(arr5) << std::endl;

    return 0;
}
