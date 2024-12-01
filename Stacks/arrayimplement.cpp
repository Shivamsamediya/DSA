#include<iostream>
using namespace std;

class Stack {
    int* arr;
    int topIndex;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        topIndex = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    // Push operation
    void push(int data) {
        if (topIndex == capacity - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        topIndex++;
        arr[topIndex] = data;
    }

    // Pop operation
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        int poppedElement = arr[topIndex];
        topIndex--;
        return poppedElement;
    }

    // Top operation
    int top() {
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        return arr[topIndex];
    }

    // isEmpty operation
    bool isEmpty() {
        return topIndex == -1;
    }
};

int main() {
    Stack stack(5);

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    cout << "Top element is: " << stack.top() << endl;

    cout << "Popped element is: " << stack.pop() << endl;

    cout << "Top element after pop is: " << stack.top() << endl;

    while (!stack.isEmpty()) {
        cout << "Popped element is: " << stack.pop() << endl;
    }

    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}

/*  Operation      Complexity
    Push:           O(1)
    Pop:            O(1)
    Top:            O(1)
    isEmpty:        O(1)
*/