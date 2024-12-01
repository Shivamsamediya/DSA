#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
    }
};

// Traversal
void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Insertion

// 1. At Head
void insertAtHead(Node* &head, int d){
    Node* newNode = new Node(d);
    newNode->next = head;
    if(head != NULL){
        head->prev = newNode;
    }
    head = newNode;
}

// 2. At Tail
void insertAtTail(Node* &tail, int d){
    Node* newNode = new Node(d);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

// 3. At Position
void insertAtPosition(Node* &head, int d, Node* &tail, int position){
    if(position == 1){
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while(cnt < position - 1){
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL){
        insertAtTail(tail, d);
        return;
    }

    Node* newNode = new Node(d);
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

// Deletion
void deleteNode(int position, Node* &head){
    if(position == 1){
        Node* temp = head;
        head = head->next;
        if(head != NULL){
            head->prev = NULL;
        }
        temp->next = NULL;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;

        while(cnt < position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        curr->prev->next = curr->next;
        if(curr->next != NULL){
            curr->next->prev = curr->prev;
        }
        curr->next = NULL;
        curr->prev = NULL;
        delete curr;
    }
}

int main(){
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);

    first->next = second;
    second->prev = first;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;

    Node* head = first;

    /*
    Traversing
    printList(head);
    */

    /*
    insertAtHead(head, 0);
    printList(head);
    */

    Node* tail = fourth;

    /*
    insertAtTail(tail, 50);
    printList(head);
    */
    
    /*
    insertAtPosition(head, 15, tail, 2);
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
2.End               O(1)
3.Position          O(n)

--Traversal         O(n)

--Searching         O(n)

--Accessing         O(n)
(by index)

--Updating          O(n)     
(by index)
*/
