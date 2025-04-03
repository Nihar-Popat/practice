#include <iostream>

//Time Complexity: O(n^2)
//Space Complexity: O(1)

using namespace std;

void bubbleSort(vector<int> &arr, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) 
            if (arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
    }
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    int n = arr.size();
    bubbleSort(arr, n);
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
//What are other sorting algorithms?
//Insertion Sort
//Merge Sort
//Quick Sort
//Heap Sort
//Counting Sort
//Radix Sort    
