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

class Queue {
    Node* frontNode;
    Node* rearNode;

public:
    Queue() {
        frontNode = NULL;
        rearNode = NULL;
    }

    ~Queue() {
        while (frontNode != NULL) {
            Node* temp = frontNode;
            frontNode = frontNode->next;
            delete temp;
        }
    }

    // Enqueue operation
    void enqueue(int data) {
        Node* newNode = new Node(data);

        if (rearNode == NULL) {
            frontNode = rearNode = newNode;
            return;
        }

        rearNode->next = newNode;
        rearNode = newNode;
    }

    // Dequeue operation
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }

        Node* temp = frontNode;
        int result = temp->data;

        frontNode = frontNode->next;

        if (frontNode == NULL) {
            rearNode = NULL;
        }

        delete temp;
        return result;
    }

    // Front operation
    int front() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        return frontNode->data;
    }

    // isEmpty operation
    bool isEmpty() {
        return frontNode == NULL;
    }
};

int main() {
    Queue queue;

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
