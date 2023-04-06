#include<iostream>
using namespace std;

class Queue {
    int arr[50];
    int front;
    int rear;

    public:

        Queue() {
            front = -1;
            rear = -1;
        }
        void traverse() {
            if(isEmpty()) {
                cout << "Queue empty" << "\n";
                return;
            }
            cout << "Queue is: " << "\n";
            for(int i=front; i<=rear; i++) {
                cout << arr[i] << "\t";
            }
            cout << "\n";
        }

        bool isEmpty() {
            return front == -1 && rear == -1;
        }

        bool isFull() {
            return rear == 49;
        }

        void push(int ele) {
            if(isFull()) {
                cout << "Queue full" << "\n";
                return;
            } else if(isEmpty()) {
                front = rear = 0;
                arr[rear] = ele;
            } else {
                rear++;
                arr[rear] = ele;
            }

            traverse();
        }

        void del() {
            if(isEmpty()) {
                cout << "Queue empty" << "\n";
                return;
            } else if(front == rear) {
                cout << "Element deleted: " << arr[front] << "\n";
                front = rear = -1;
            } else {
                cout << "Element deleted: " << arr[front] << "\n";
                front++;
            }
            traverse();
        }

        void getFront() {
            if(isEmpty()) {
                cout << "Queue empty" << "\n";
                return;
            }
            cout << "Current front: " << arr[front] << "\n";
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