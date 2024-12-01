#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
public:
    vector<int> heap;

    // Function to heapify up
    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] >= heap[parentIndex]) break;
            swap(heap[index], heap[parentIndex]);
            index = parentIndex;
        }
    }

    // Function to heapify down
    void heapifyDown(int index) {
        int size = heap.size();
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;

        if (leftChild < size && heap[leftChild] < heap[smallest]) {
            smallest = leftChild;
        }
        if (rightChild < size && heap[rightChild] < heap[smallest]) {
            smallest = rightChild;
        }
        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    // Function to insert a value into the heap
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // Function to extract the minimum value from the heap
    int extractMin() {
        if (heap.empty()) throw runtime_error("Heap is empty");
        int minValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return minValue;
    }

    // Function to get the minimum value from the heap
    int getMin() {
        if (heap.empty()) throw runtime_error("Heap is empty");
        return heap[0];
    }

    // Function to check if the heap is empty
    bool isEmpty() {
        return heap.empty();
    }
};

class MaxHeap {
public:
    vector<int> heap;

    // Function to heapify up
    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] <= heap[parentIndex]) break;
            swap(heap[index], heap[parentIndex]);
            index = parentIndex;
        }
    }

    // Function to heapify down
    void heapifyDown(int index) {
        int size = heap.size();
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < size && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }
        if (rightChild < size && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

    // Function to insert a value into the heap
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // Function to extract the maximum value from the heap
    int extractMax() {
        if (heap.empty()) throw runtime_error("Heap is empty");
        int maxValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return maxValue;
    }

    // Function to get the maximum value from the heap
    int getMax() {
        if (heap.empty()) throw runtime_error("Heap is empty");
        return heap[0];
    }

    // Function to check if the heap is empty
    bool isEmpty() {
        return heap.empty();
    }
};

int main() {
    // MinHeap Example
    MinHeap minHeap;
    minHeap.insert(10);
    minHeap.insert(20);
    minHeap.insert(5);
    minHeap.insert(6);
    minHeap.insert(1);

    cout << "Min-Heap:" << endl;
    while (!minHeap.isEmpty()) {
        cout << minHeap.extractMin() << " ";
    }
    cout << endl;

    // MaxHeap Example
    MaxHeap maxHeap;
    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(5);
    maxHeap.insert(6);
    maxHeap.insert(1);

    cout << "Max-Heap:" << endl;
    while (!maxHeap.isEmpty()) {
        cout << maxHeap.extractMax() << " ";
    }
    cout << endl;

    return 0;
}

/*
    1.Insert Operation:
        Time Complexity: O(log n)
        Space Complexity: O(1)

    2.Extract Min/Max Operation:
        Time Complexity: O(log n)
        Space Complexity: O(1)

    3. Min/Max Operation:
        Time Complexity: O(1)
        Space Complexity: O(1)

    4.Heapify Up/Down Operations:
        Time Complexity: O(log n)
        Overall Space Complexity:

    O(n) for storing the heap elements.
*/