#include <iostream>

//Time Complexity: O(n log n)
//Space Complexity: O(n)

using namespace std;

void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp(high - low + 1);    
    int left = low;                      
    int right = mid + 1;                 
    int k = 0;                           

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp[k++] = arr[left++];
        } else {
            temp[k++] = arr[right++];
        }
    }

    while (left <= mid) {
        temp[k++] = arr[left++];
    }

    while (right <= high) {
        temp[k++] = arr[right++];
    }

    for (int i = 0; i < k; i++) {
        arr[low + i] = temp[i];
    }
}


void mergeSort(vector<int> &arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}   

int main() {
    // Test case 1: Random array
    vector<int> arr1 = {64, 34, 25, 12, 22, 11, 90};
    cout << "Test Case 1 - Random Array\n";
    cout << "Before sorting: ";
    for(int num : arr1) cout << num << " ";
    cout << "\n";
    
    mergeSort(arr1, 0, arr1.size()-1);
    
    cout << "After sorting:  ";
    for(int num : arr1) cout << num << " ";
    cout << "\n\n";

    // Test case 2: Already sorted array
    vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7};
    cout << "Test Case 2 - Already Sorted Array\n";
    cout << "Before sorting: ";
    for(int num : arr2) cout << num << " ";
    cout << "\n";
    
    mergeSort(arr2, 0, arr2.size()-1);
    
    cout << "After sorting:  ";
    for(int num : arr2) cout << num << " ";
    cout << "\n\n";

    // Test case 3: Reverse sorted array
    vector<int> arr3 = {9, 8, 7, 6, 5, 4, 3};
    cout << "Test Case 3 - Reverse Sorted Array\n";
    cout << "Before sorting: ";
    for(int num : arr3) cout << num << " ";
    cout << "\n";
    
    mergeSort(arr3, 0, arr3.size()-1);
    
    cout << "After sorting:  ";
    for(int num : arr3) cout << num << " ";
    cout << "\n\n";

    // Test case 4: Array with duplicates
    vector<int> arr4 = {5, 2, 8, 5, 1, 9, 2, 8};
    cout << "Test Case 4 - Array with Duplicates\n";
    cout << "Before sorting: ";
    for(int num : arr4) cout << num << " ";
    cout << "\n";
    
    mergeSort(arr4, 0, arr4.size()-1);
    
    cout << "After sorting:  ";
    for(int num : arr4) cout << num << " ";
    cout << "\n";

    return 0;
}
