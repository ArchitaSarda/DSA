#include<iostream>
using namespace std;

class Stack {
    int top;
    int arr[50];
    public:
        Stack() {
            top = -1;
        };

        void push(int data) {
            if(top == 49) {
                cout << "max size reached" << "\n";
                return;
            }
            arr[++top] = data;
            traverse();
        }

        int pop() {
            if(isEmpty()) {
                cout << "stack empty!" << "\n";
                return -1;
            }
            int returnVal = arr[top--];
            cout << "Element popped is: " << returnVal << "\n";
            traverse();
            return returnVal;
        }

        bool isEmpty() {
            return top == -1;
        }

        void topValue() {
            if(isEmpty()) {
                cout << "stack empty!" << "\n";
                return;
            }
            cout << "Top element is: " << arr[top] << "\n";
        }

        void traverse() {
            if(isEmpty()) {
                cout << "stack empty!" << "\n";
                return;
            }
            cout << "Stack is: " << "\n";
            for(int i=top;i>-1;i--) {
                cout << arr[i] << "\t";
            }
            cout << "\n";
        }
};