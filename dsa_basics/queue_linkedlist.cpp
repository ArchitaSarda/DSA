#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        next = NULL;
        data = val;
    }
};

class Queue {
    Node* front;
    Node* rear;

    public:

        Queue() {
            front = NULL;
            rear = NULL;
        }
        void traverse() {
            if(isEmpty()) {
                cout << "Queue empty" << "\n";
                return;
            }
            cout << "Queue is: " << "\n";
            Node* temp = front;
            while(temp != NULL) {
                cout << temp->data << "\t";
                temp = temp->next;
            }
            cout << "\n";
        }

        bool isEmpty() {
            return front == NULL && rear == NULL;
        }

        void push(int ele) {
            Node* temp = new Node(ele);
            if(temp == NULL) {
                cout << "Queue full" << "\n";
                return;
            } else if(isEmpty()) {
                front = rear = temp;
            } else {
                rear->next = temp;
                rear = temp;
            }

            traverse();
        }

        void del() {
            if(isEmpty()) {
                cout << "Queue empty" << "\n";
                return;
            } 
            Node* temp = front;
            if(front == rear) {
                cout << "Element deleted: " << front->data << "\n";
                front = rear = NULL;
                delete temp;
            } else {
                cout << "Element deleted: " << front->data << "\n";
                front = front->next;
                delete temp;
            }
            traverse();
        }

        void getFront() {
            if(isEmpty()) {
                cout << "Queue empty" << "\n";
                return;
            }
            cout << "Current front: " << front->data << "\n";
        }
};

int main() {
    Queue q;
    int choice = 1;
    do {
        cout << "Enter 1 for push, 2 for del, 3 for current front value, 4 to check if queue is empty, 5 to see the full queue, any other value to exit" << "\n";
        cin >> choice;
        switch(choice) {
            case 1: {
                int data;
                cout << "Enter data: " << "\n";
                cin >> data;
                q.push(data);
                break;
            }
            case 2: {
                q.del();
                break;
            }
            case 3: {
                q.getFront();
                break;
            }
            case 4: {
                cout << "Is queue empty: " << q.isEmpty() << "\n";
                break;
            }
            case 5: {
                q.traverse();
                break;
            }
            default: {
                cout << "Exiting ...!" << "\n";
                choice = 6;
            }
        }
    } while(choice < 6);


    return 0;
}