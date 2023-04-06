// Online C++ compiler to run C++ program online
#include <iostream>

struct node {
    int data;
    node* next;
};

void traverseArray(node* head) {
    std::cout << "Final elements entered: " << "\n";
    node* traverse = head;
    while(traverse != NULL) {
        std::cout << traverse->data << "\t";
        traverse = traverse->next;
    }
    std::cout << "\n";
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

void insertElement(node** head, int position) {

    //read
    node* tempNode = new node();
    std::cout << "Enter the element: " << "\n";
    std::cin >> tempNode->data;

    
    if(position == 1) {
        
        //insert
        tempNode->next = *head;
        *head = tempNode;
        return;
    }

    //traverse
    node* placeOfInsertion = *head;
    for(int i=0; i<position-2; i++) {
        placeOfInsertion = placeOfInsertion->next;   
    }
    
    //insert
    tempNode->next = placeOfInsertion->next;
    placeOfInsertion->next = tempNode;
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

        int position = 1;
        std::cout << "Enter position of element: " << "\n";
        std::cin >> position;
        insertElement(&head, position);
        choice = getChoice();
    }
    
    traverseArray(head);
    
    return 0;
}

// Enter first element: 
// 5
// Do you want to enter another element?
// Enter 'Y' for yes and 'N' for no: 
// Y
// Enter position of element: 
// 1
// Enter the element: 
// 3
// Do you want to enter another element?
// Enter 'Y' for yes and 'N' for no: 
// Y
// Enter position of element: 
// 1
// Enter the element: 
// 2
// Do you want to enter another element?
// Enter 'Y' for yes and 'N' for no: 
// Y
// Enter position of element: 
// 2
// Enter the element: 
// 4
// Do you want to enter another element?
// Enter 'Y' for yes and 'N' for no: 
// Y
// Enter position of element: 
// 5
// Enter the element: 
// 7
// Do you want to enter another element?
// Enter 'Y' for yes and 'N' for no: 
// N
// Final elements entered: 
// 2       4       3       5       7
