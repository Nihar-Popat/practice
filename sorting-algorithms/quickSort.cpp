#include <iostream>

//Time Complexity: O(n log n)
//Space Complexity: O(log n)

using namespace std;

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int count = 0;
    for(int i = low + 1; i <= high; i++) {
        if(arr[i] <= pivot) count++;
    }
    int pivotIndex = low + count;
    swap(arr[pivotIndex], arr[low]);
    int i = low, j = high;
    while(i < pivotIndex && j > pivotIndex) {
        while(arr[i] <= pivot) i++;
        while(arr[j] > pivot) j--;
        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i], arr[j]);
        }
    }
    return pivotIndex;
}

void quickSort(vector<int> &arr, int low, int high) {
    if(low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    return 0;
}