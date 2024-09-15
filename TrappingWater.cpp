#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int trapRainWater(const vector<int>& height) {
    int n = height.size();
    if (n <= 2) return 0;

    int left = 0, right = n - 1;
    int left_max = 0, right_max = 0;
    int water_trapped = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= left_max) {
                left_max = height[left];
            } else {
                water_trapped += left_max - height[left];
            }
            left++;
        } else {
            if (height[right] >= right_max) {
                right_max = height[right];
            } else {
                water_trapped += right_max - height[right];
            }
            right--;
        }
    }

    return water_trapped;
}

int main() {
    // Test case 1
    vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Water trapped: " << trapRainWater(height1) << " units" << endl;

    // Test case 2
    vector<int> height2 = {4, 2, 0, 3, 2, 5};
    cout << "Water trapped: " << trapRainWater(height2) << " units" << endl;

    // Test case 3
    vector<int> height3 = {1, 1, 1};
    cout << "Water trapped: " << trapRainWater(height3) << " units" << endl;

    // Test case 4
    vector<int> height4 = {5};
    cout << "Water trapped: " << trapRainWater(height4) << " units" << endl;

    // Test case 5
    vector<int> height5 = {2, 0, 2};
    cout << "Water trapped: " << trapRainWater(height5) << " units" << endl;

    return 0;
}
