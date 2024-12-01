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

// Function to build the tree
Node* buildTree() {
    int data;
    cout << "Enter node data (or -1 for no node): ";
    cin >> data;

    if (data == -1) return NULL;

    Node* node = new Node(data);
    cout << "Enter left child of " << data << endl;
    node->left = buildTree();
    cout << "Enter right child of " << data << endl;
    node->right = buildTree();

    return node;
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
        Building the Tree:              O(n) time and O(n) space.
        Level Order Traversal:          O(n) time and O(w) space, where w is the maximum width of the tree (can be O(n) in the worst case).
        In-Order Traversal:             O(n) time and O(h) space, where h is the height of the tree.
        Pre-Order Traversal:            O(n) time and O(h) space, where h is the height of the tree.
        Post-Order Traversal:           O(n) time and O(h) space, where h is the height of the tree.
*/