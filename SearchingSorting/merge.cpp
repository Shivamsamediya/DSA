//T= O(nlogn)  S = O(n)
#include <iostream>
#include <vector>
using namespace std;

// Function to merge two sorted subarrays
void merge(vector<int>& arr, int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    vector<int> leftArr(leftSize);
    vector<int> rightArr(rightSize);

    for (int i = 0; i < leftSize; ++i)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < rightSize; ++j)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Function to perform Merge Sort
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int size = arr.size();

    mergeSort(arr, 0, size - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    return 0;
}
