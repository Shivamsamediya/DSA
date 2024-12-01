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

    ~Node() {
        int value = this->data;
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
    }
};

// Traversal
void printList(Node* head) {
    if (head == NULL) {
        cout << "NULL" << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);
    cout << "HEAD" << endl;
}

// Insertion

// 1. At Head
void insertAtHead(Node* &head, Node* &tail, int d) {
    Node* newNode = new Node(d);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        newNode->next = head;
    } else {
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
}

// 2. At Tail
void insertAtTail(Node* &tail, Node* &head, int d) {
    Node* newNode = new Node(d);
    if (tail == NULL) {
        head = newNode;
        tail = newNode;
        newNode->next = head;
    } else {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
}

// 3. At Position
void insertAtPosition(Node* &head, Node* &tail, int d, int position) {
    if (position == 1) {
        insertAtHead(head, tail, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while (cnt < position - 1 && temp->next != head) {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == head) {
        insertAtTail(tail, head, d);
        return;
    }

    Node* newNode = new Node(d);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Deletion
void deleteNode(Node* &head, Node* &tail, int position) {
    if (head == NULL) {
        return;
    }

    if (position == 1) {
        Node* temp = head;
        if (head->next == head) {
            head = NULL;
            tail = NULL;
        } else {
            head = head->next;
            tail->next = head;
        }
        temp->next = NULL;
        delete temp;
    } else {
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;

        while (cnt < position && curr->next != head) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        if (curr->next == head) {
            tail = prev;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main() {
    Node* first = new Node(10);
    Node* head = first;
    Node* tail = first;

    // Creating initial circular link
    tail->next = head;

    /*
    Traversing
    printList(head);
    */

    /*
    insertAtHead(head, tail, 0);
    printList(head);
    */

    /*
    insertAtTail(tail, head, 50);
    printList(head);
    */
    
    /*
    insertAtPosition(head, tail, 15, 2);
    printList(head);
    */

    printList(head);

    return 0;
}

/*
Operation      Complexity
--Insertion--
1.Begin             O(1)
2.End               O(1)
3.Position          O(n)

--Deletion
1.Begin             O(1)
2.End               O(n)
3.Position          O(n)

--Traversal         O(n)

--Searching         O(n)

--Accessing         O(n)
(by index)

--Updating          O(n)     
(by index)
*/
