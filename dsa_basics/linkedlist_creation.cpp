// Online C++ compiler to run C++ program online
#include <iostream>


int main() {
    struct node {
        int data;
        node* next;
    };
    
    node* head;
    head = NULL;
    
    node* A = new node();
    A->data = 700;
    head = A;
    A->next = NULL;
    
    std::cout << A->data << '\n';
    std::cout << A->next << '\n';
    std::cout << head;
    return 0;
}



// output - 
// 700
// 0
// 0x56073706beb0