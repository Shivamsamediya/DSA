#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Stack {
    Node* topNode;

public:
    Stack() {
        topNode = NULL;
    }

    ~Stack() {
        while (topNode != NULL) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }

    // Push operation
    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = topNode;
        topNode = newNode;
    }

    // Pop operation
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        Node* temp = topNode;
        int poppedElement = temp->data;
        topNode = topNode->next;
        delete temp;
        return poppedElement;
    }

    // Top operation
    int top() {
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        return topNode->data;
    }

    // isEmpty operation
    bool isEmpty() {
        return topNode == NULL;
    }
};

int main() {
    Stack stack;

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
