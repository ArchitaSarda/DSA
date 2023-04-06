#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class Stack {
    Node *top;
    
    public:
        Stack() {
           top = NULL;
        };

        void push(int data) {
            Node* temp = new Node(data);
            if(temp == NULL) {
                cout << "heap memory full!" << "\n";
                return;
            }
            temp->next = top;
            top = temp;
            traverse();
        }

        void pop() {
            if(isEmpty()) {
                cout << "stack empty!" << "\n";
                return;
            }
            Node* returnNode = top;
            top = top->next;
            returnNode->next = NULL;
            cout << "Element popped is: " << returnNode->data << "\n";
            delete returnNode;
            traverse();
        }

        bool isEmpty() {
           return top == NULL;
        }

        void topValue() {
            if(isEmpty()) {
                cout << "stack empty!" << "\n";
                return;
            }
            cout << "Top element is: " << top->data << "\n";
        }

        void traverse() {
            if(isEmpty()) {
                cout << "stack empty!" << "\n";
                return;
            }
            cout << "Stack is: " << "\n";
            Node* traverse = top;
            while(traverse != NULL) {
                cout << traverse->data << "\t";
                traverse = traverse->next;
            }

            cout << "\n";
        }
};

int main() {
    Stack s;
    int choice = 1;
    do {
        cout << "Enter 1 for push, 2 for pop, 3 for current top value, 4 to check if stack is empty, 5 to see the full stack, any other value to exit" << "\n";
        cin >> choice;
        switch(choice) {
            case 1: {
                int data;
                cout << "Enter data: " << "\n";
                cin >> data;
                s.push(data);
                break;
            }
            case 2: {
                s.pop();
                break;
            }
            case 3: {
                s.topValue();
                break;
            }
            case 4: {
                cout << "Is stack empty: " << s.isEmpty() << "\n";
                break;
            }
            case 5: {
                s.traverse();
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