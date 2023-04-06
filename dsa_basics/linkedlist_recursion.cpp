// Online C++ compiler to run C++ program online
#include <iostream>

struct node {
    int data;
    node* next;
};

void traverseList(node* head) {
    std::cout << "Final elements entered: " << "\n";
    node* traverse = head;
    while(traverse != NULL) {
        std::cout << traverse->data << "\t";
        traverse = traverse->next;
    }
    std::cout << "\n";
}

void traverseListRecursion(node* traverse) {
    if(traverse == NULL) {
        return;
    } else {
        std::cout << traverse->data << "\t"; //sequential
        traverseListRecursion(traverse->next);
        std::cout << traverse->data << "\t"; //reverse
        
    }
}

char getChoice() {
    char choice = 'N';
    std::cout << "Do you want to enter another element?" 
        << "\n"
        << "Enter 'Y' for yes and 'N' for no: " 
        << "\n";
    std::cin >> choice;
    return choice;
}

void insertElement(node** head) {

    //read
    node* tempNode = new node();
    std::cout << "Enter the element: " << "\n";
    std::cin >> tempNode->data;
    
    //insert
    tempNode->next = *head;
    *head = tempNode;
}

int main() {

    node* head = NULL;
    
    std::cout << "Enter first element: " << "\n";
    node* tempNode = new node();
    std::cin >> tempNode->data;
    head = tempNode;
    tempNode->next = NULL;
    
    char choice = 'N';
    choice = getChoice();
    
    
    while(choice == 'Y') {
        
        insertElement(&head);
        choice = getChoice();
    }
    
    traverseList(head);
    traverseListRecursion(head);
    traverseList(head);
    
    return 0;
}


