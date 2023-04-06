#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node() {
        next = NULL;
        data = 0;
    }
};

class LinkedList {
    private:
    
    Node* head;

    public: 
    
    LinkedList() {
        head = NULL;
    };

    void insertAtBeginning(int value) {
        Node* temp = new Node();
        temp->data = value;
        temp->next = head;
        head = temp;
    };

    void traverse() {
        cout << "Final elements entered: " << "\n";
        Node* traverse = head;
        while(traverse != NULL) {
            cout << traverse->data << "\t";
            traverse = traverse->next;
        }
        cout << "\n";
    };

    void reverseRecursion(Node* traverse) {
        if(traverse->next == NULL) {
            head = traverse;
            return;
        } else {
            reverseRecursion(traverse->next);
            traverse->next->next = traverse;
            traverse->next = NULL; 
        }
    }

    Node* getHead() {
        return head;
    }
};

int main() {
    LinkedList ll;
    
    ll.insertAtBeginning(5);
    ll.insertAtBeginning(7);
    ll.insertAtBeginning(8);
    ll.insertAtBeginning(3);
    ll.traverse();
    ll.reverseRecursion(ll.getHead());
    ll.traverse();
    return 0;

}