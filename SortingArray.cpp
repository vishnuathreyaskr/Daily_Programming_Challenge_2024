#include <iostream>
#include <vector>

using namespace std;

void sortArray(vector<int>& arr) 
{
    int low = 0, mid = 0, high = arr.size() - 1;
    
    while (mid <= high) 
    {
        switch (arr[mid]) 
        {
           
            case 0:
                swap(arr[low], arr[mid]);
                low++;
                mid++;
                break;
            
            case 1:
                mid++;
                break;
            
            case 2:
                swap(arr[mid], arr[high]);
                high--;
                break;
        }
    }
}

int main() 
{
    vector<int> arr1 = {0, 1, 2, 1, 0, 2, 1, 0};
    sortArray(arr1);
    for (int num : arr1) 
    {
        cout << num << " ";
    }
    cout << endl;
    vector<int> arr2 = {2, 2, 2, 2};
    sortArray(arr2);
    for (int num : arr2) 
    {
        cout << num << " ";
    }
    cout << endl;
    vector<int> arr3 = {0, 0, 0, 0};
    sortArray(arr3);
    for (int num : arr3) 
    {
        cout << num << " ";
    }
    cout << endl;
    vector<int> arr4 = {1, 1, 1, 1};
    sortArray(arr4);
    for (int num : arr4) {
        cout << num << " ";
    }
    cout << endl;
    vector<int> arr5 = {2, 0, 1};
    sortArray(arr5);
    for (int num : arr5) {
        cout << num << " ";
    }
    cout << endl;
    vector<int> arr6 = {};
    sortArray(arr6);
    for (int num : arr6) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
