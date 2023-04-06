#include<iostream>
#include"stack_array.h"
using namespace std;

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