#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node() {
        data = 0;
        next = NULL;
        prev = NULL;
    };
};

class LinkedList {
    Node* head;

    public:

        LinkedList() {
            head = NULL;
        }

        void insertAtBegin(int data) {
            Node* temp = new Node();
            temp->data = data;
            temp->next = head;
            if(head != NULL) {
                temp->next->prev = temp;
            }
            temp->prev = NULL;
            head = temp;
        }

        void insertAtEnd(int data) {
            Node* temp = new Node();
            temp->data = data;
             if(head == NULL) {
                head = temp;
                return;
            }
            Node* traverse = head;
            while(traverse->next != NULL) {
                traverse = traverse->next;
            }
            temp->prev = traverse;
            traverse->next = temp;
        }

        void traverse() {
            cout << "Final elements entered: " << "\n";
            if(head == NULL) {
                return;
            }
            Node* traverse = head;
            while(traverse != NULL) {
                cout << traverse->data << "\t";
                traverse = traverse->next;
            }
            cout << "\n";
        }

        void reverseTraverse() {
            cout << "Final elements entered: " << "\n";
            if(head == NULL) {
                return;
            }
            Node* traverse = head;
            while(traverse->next != NULL) {
                traverse = traverse->next;
            }
            while(traverse != NULL) {
                cout << traverse->data << "\t";
                traverse = traverse->prev;
            }
            cout << "\n";
        }
};

int main() {
    LinkedList ll;
    // ll.insertAtBegin(5);
    // ll.insertAtBegin(6);
    ll.insertAtBegin(9);
    ll.traverse();
    ll.reverseTraverse();

    LinkedList ll2;
    // ll2.insertAtEnd(5);
    // ll2.insertAtEnd(6);
    ll2.insertAtEnd(9);
    ll2.traverse();
    ll2.reverseTraverse();
    return 0;
}

// Final elements entered: 
// 9       6       5
// Final elements entered: 
// 5       6       9
// Final elements entered: 
// 5       6       9
// Final elements entered: 
// 9       6       5