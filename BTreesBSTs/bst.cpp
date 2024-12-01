#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    //constructor bhai saab
    Node(int value){
        this->data=value;
        this->left=NULL;
        this->right=NULL;
    }
};

// Function to insert a node into the BST
Node* insertNode(Node* root, int data) {
    if (root == NULL) return new Node(data);

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    
    return root;
}

// Function to build the BST
Node* buildTree() {
    int data;
    cout << "Enter node data (or -1 to finish): ";
    cin >> data;

    Node* root = NULL;
    while (data != -1) {
        root = insertNode(root, data);
        cout << "Enter next node data (or -1 to finish): ";
        cin >> data;
    }

    return root;
}

// Function for level order traversal
void levelOrderTraversal(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";

        if (current->left != NULL) q.push(current->left);
        if (current->right != NULL) q.push(current->right);
    }
    cout << endl;
}

// Function for in-order traversal
void inOrderTraversal(Node* node) {
    if (node == NULL) return;

    inOrderTraversal(node->left);
    cout << node->data << " ";
    inOrderTraversal(node->right);
}

// Function for pre-order traversal
void preOrderTraversal(Node* node) {
    if (node == NULL) return;

    cout << node->data << " ";
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

// Function for post-order traversal
void postOrderTraversal(Node* node) {
    if (node == NULL) return;

    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    cout << node->data << " ";
}

// Function to delete the entire tree
void deleteTree(Node* node) {
    if (node == NULL) return;

    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

int main() {
    Node* root = buildTree();

    cout << "Level Order Traversal: ";
    levelOrderTraversal(root);

    cout << "In-Order Traversal: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Pre-Order Traversal: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "Post-Order Traversal: ";
    postOrderTraversal(root);
    cout << endl;

    // Clean up the tree
    deleteTree(root);

    return 0;
}

/*      Operations                      Complexity
        Building the Tree:              O(nlogn) time and O(n) space.
        Level Order Traversal:          O(n) time and O(w) space, where w is the maximum width of the tree.
        In-Order Traversal:             O(n) time and O(h) space, where h is the height of the tree.
        Pre-Order Traversal:            O(n) time and O(h) space, where h is the height of the tree.
        Post-Order Traversal:           O(n) time and O(h) space, where h is the height of the tree.
*/