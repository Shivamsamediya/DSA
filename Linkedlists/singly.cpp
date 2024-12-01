#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }

    ~Node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
    }
};


void printList(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}

// Insertion

//1.At Head

void insertAtHead(Node* &head,int d){
    Node* newNode= new Node(d);
    newNode->next=head;
    head=newNode;
}

//2. At Tail

void insertAtTail(Node* &tail,int d){
    Node* newNode= new Node(d);
    tail->next=newNode;
    tail=newNode;
}

//3. At Position

void insertAtPosition(Node* &head,int d,Node* &tail,int position){
    if(position==1){
        insertAtHead(head,d);
        return;
    }

    Node* temp= head;
    int cnt=1;

    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }

    if(temp->next==NULL){
        insertAtTail(tail,d);
        return;
    }

    Node* newNode= new Node(d);
    newNode->next=temp->next;
    temp->next=newNode;
}
// --------- xx ---------- //

//Deletion
void deleteNode(int position,Node* head){
    if(position==1){
       Node* temp=head;
       head=head->next;
       temp->next=NULL;
       delete temp;
    }
    else{
        Node* curr= head;
        Node* prev=NULL;
        int cnt=1;

        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }


        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
        }
}

int main(){
    Node* first= new Node(10);
    Node* second= new Node(20);
    Node* third= new Node(30);
    Node* fourth= new Node(40);

    first->next=second;
    second->next=third;
    third->next=fourth;

    Node* head= first;

    /*
    Traversing
    printList(head);
    */

    /*
    insertAtHead(head,0);
    printList(head);
    */
    
    
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* tail= temp;

    /*
    insertAtTail(tail,50);
    printList(head);
    */
    
    /*
    insertAtPosition(head,15,tail,2);
    printList(head);
    */
    printList(head);

    return 0;
}

/*
Operation      Complexity
--Insertion--
1.Begin             O(1)
2.End               O(n)
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