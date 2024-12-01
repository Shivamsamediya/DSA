#include<iostream>
using namespace std;

class Queue {
    int* arr;
    int frontIndex;
    int rearIndex;
    int capacity;

public:
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        frontIndex = -1;
        rearIndex = -1;
    }

    ~Queue() {
        delete[] arr;
    }

    // Enqueue operation
    void enqueue(int data) {
        if ((rearIndex + 1) % capacity == frontIndex) {
            cout << "Queue Overflow!" << endl;
            return;
        }

        if (frontIndex == -1) { // first element to insert
            frontIndex = 0;
        }

        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = data;
    }

    // Dequeue operation
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }

        int result = arr[frontIndex];

        if (frontIndex == rearIndex) { // only one element
            frontIndex = rearIndex = -1;
        } else {
            frontIndex = (frontIndex + 1) % capacity;
        }

        return result;
    }

    // Front operation
    int front() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        return arr[frontIndex];
    }

    // isEmpty operation
    bool isEmpty() {
        return frontIndex == -1;
    }
};

int main() {
    Queue queue(5);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);

    cout << "Front element is: " << queue.front() << endl;

    cout << "Dequeued element is: " << queue.dequeue() << endl;

    cout << "Front element after dequeue is: " << queue.front() << endl;

    while (!queue.isEmpty()) {
        cout << "Dequeued element is: " << queue.dequeue() << endl;
    }

    cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}

/*  Operation      Complexity
    Enqueue:        O(1)
    Dequeue:        O(1)
    Front:          O(1)
    isEmpty:        O(1)
*/
