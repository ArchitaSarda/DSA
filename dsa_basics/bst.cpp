#include<iostream>
#include<queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST {
    Node* root;

    Node* insert(Node* ptr, int value) {
        if(ptr == NULL) {
            Node* temp = new Node(value);
            ptr = temp;
        } else if(value <= ptr->data) {
            ptr->left = insert(ptr->left, value);
        } else {
            ptr->right = insert(ptr->right, value);
        }
        return ptr;
    }

    bool search(Node* ptr, int value) {
        if(ptr == NULL) {
            return 0;
        } else if(ptr->data == value) {
            return 1;
        } else if(value <= ptr->data) {
            return search(ptr->left, value);
        } else {
            return search(ptr->right, value);
        }
    }

    int getHeight(Node* ptr) { 
        if(ptr == NULL) {
            return -1;
        }
        int leftHeight = getHeight(ptr->left);
        int rightHeight = getHeight(ptr->right);
        
        int height = max(leftHeight, rightHeight) + 1;
        return height;
    }

    int isBalanced(Node* ptr) {
        if (ptr == NULL)
            return 0;
        int lh = isBalanced(ptr->left);
        if (lh == -1)
            return -1;
        int rh = isBalanced(ptr->right);
        if (rh == -1)
            return -1;
    
        if (abs(lh - rh) > 1)
            return -1;
        else
            return max(lh, rh) + 1;
    }

    void preOrderTraversal(Node* ptr) {
        if(ptr == NULL) {
            return;
        }
        cout << ptr->data << "\t";
        preOrderTraversal(ptr->left);
        preOrderTraversal(ptr->right);
    }

    void inOrderTraversal(Node* ptr) {
        if(ptr == NULL) {
            return;
        }
        inOrderTraversal(ptr->left);
        cout << ptr->data << "\t";
        inOrderTraversal(ptr->right);
    }

    void postOrderTraversal(Node* ptr) {
        if(ptr == NULL) {
            return;
        }
        postOrderTraversal(ptr->left);
        postOrderTraversal(ptr->right);
        cout << ptr->data << "\t";
    }
    
    public:

    BST() {
        root = NULL;
    }

    bool isEmpty() {
        return root == NULL;
    }

    void insert(int value) {
        root = insert(root, value);
        cout << "Value inserted: " << value << "\n";
        levelOrderTraversal();
    }

    string search(int value) {
        cout << "Searched value: " << value << "\n";
        if(isEmpty()) {
            return "Tree empty";
        } 
        return search(root, value) ? "Value found" : "Not found";
    }

    void getMin() {
        if(isEmpty()) {
            cout << "Tree empty" << "\n";
            return;
        } 
        Node* traverse = root;

        while(traverse->left != NULL) {
            traverse = traverse->left;
        }
        cout << "Min value: " << traverse->data << "\n";
    }

    void getMax() {
        if(isEmpty()) {
            cout << "Tree empty" << "\n";
            return;
        } 
        Node* traverse = root;

        while(traverse->right != NULL) {
            traverse = traverse->right;
        }
        cout << "Max value: " << traverse->data << "\n";
    }

    void getHeight() {
        int height = 0;
        if(isEmpty()) {
            height = 0;
        } else {
            height = getHeight(root);
        } 
        cout << "Height of the tree is: " << height << "\n";
    }

    void isBalanced() {
        if(isEmpty()) {
            cout << "Tree empty" << "\n";
        } else {
            cout << "Is balanced? ";
            if(isBalanced(root) > 0) {
                cout << "yes" <<"\n";
            } else {
                cout << "no" << "\n";
            }
        }
    }

    void levelOrderTraversal() {
        if(isEmpty()) {
            cout << "Tree empty" << "\n";
            return;
        } 
        cout << "Breadth first or level order traversal: " << "\n";
        queue<Node*> q;
        Node* traverse = root;

        q.push(traverse);

        while(!q.empty()) {
            cout << traverse->data << "\t";
            if(traverse->left != NULL) 
                q.push(traverse->left);
            if(traverse->right != NULL) 
                q.push(traverse->right);

            q.pop();
            traverse = q.front();
        }
        cout << "\n";
    }

    void preOrderTraversal() {
        if(isEmpty()) {
            cout << "Tree empty" << "\n";
            return;
        } 
        cout << "Pre order traversal: " << "\n";
        preOrderTraversal(root);
        cout << "\n";
    }

    void inOrderTraversal() {
        if(isEmpty()) {
            cout << "Tree empty" << "\n";
            return;
        } 
        cout << "In order traversal: " << "\n";
        inOrderTraversal(root);
        cout << "\n";
    }

    void postOrderTraversal() {
        if(isEmpty()) {
            cout << "Tree empty" << "\n";
            return;
        } 
        cout << "Post order traversal: " << "\n";
        postOrderTraversal(root);
        cout << "\n";
    }
};

int main() {
    BST t;
    cout << t.search(5) << "\n";
    cout << t.isEmpty() << "\n";
    t.insert(5);
    t.insert(12);
    t.insert(24);
    t.insert(2);
    t.insert(4);
    t.insert(7);
    t.insert(28);
    t.insert(25);
    t.insert(27);
    t.insert(3);
    cout << t.isEmpty() << "\n";
    cout << t.search(5) << "\n";
    cout << t.search(10) << "\n";
    cout << t.search(12) << "\n";
    t.getMax();
    t.getMin();
    t.getHeight();
    t.preOrderTraversal();
    t.inOrderTraversal();
    t.postOrderTraversal();
    t.isBalanced();
}