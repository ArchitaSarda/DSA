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

class BT {
    Node* root;

    void inOrderTraversal(Node* ptr) {
        if(ptr == NULL) {
            return;
        }
        inOrderTraversal(ptr->left);
        cout << ptr->data << "\t";
        inOrderTraversal(ptr->right);
    }

    bool checkBST(Node* ptr) {
        Node* left = ptr->left;
        Node* right = ptr->right;

        bool leftCheck = ptr->left == NULL || ptr->data >= left->data;
        bool rightCheck = ptr->right == NULL || ptr->data < right->data;

        return leftCheck && rightCheck;
    }

    bool isBST(Node* ptr) {
        if(ptr == NULL) {
            return 1;
        }
        if(checkBST(ptr) && isBST(ptr->left) && isBST(ptr->right)) {
            return 1;
        }
        return 0;
    }
    

    public: 

    BT() {
        root = NULL;
    }

    void insert(int value) {
        if(root == NULL) {
            Node* temp = new Node(value);
            root = temp;
            return;
        }

        queue<Node*> q;
        Node* traverse = root;
        q.push(traverse);
        while(!q.empty()) {
            if(traverse->left != NULL) {
                q.push(traverse->left);
            } else {
                Node* temp = new Node(value);
                traverse->left = temp;
                break;
            }
            if(traverse->right != NULL) {
                q.push(traverse->right);
            } else {
                Node* temp = new Node(value);
                traverse->right = temp;
                break;
            }
            q.pop();
            traverse = q.front();

        }
        inOrderTraversal();

    }

    void inOrderTraversal() {
        if(root == NULL) {
            cout << "Tree empty" << "\n";
            return;
        } 
        cout << "In order traversal: " << "\n";
        inOrderTraversal(root);
        cout << "\n";
    }

    void isBST() {
        cout << "Is bst? : " << isBST(root) << "\n";
    }

};

int main() {
    BT b;
    b.insert(5);
    b.insert(8);
    b.insert(6);
    b.insert(7);
    b.insert(9);
    b.insert(5);
    b.insert(2);
    b.insert(0);

    BT b2;
    b2.insert(5);
    b2.insert(3);
    b2.insert(8);
    b2.insert(1);
    b2.insert(4);
    b2.insert(6);
    b2.insert(12);

    b.isBST();
    b2.isBST();

}
