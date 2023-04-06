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

char getDeleteChoice() {
    char choice = 'N';
    std::cout << "Do you want to delete element? "
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

void deleteElement(node** head, int position) {

    node* placeOfDeletion = *head;
    if(position == 1) {
        *head = placeOfDeletion->next;
        delete placeOfDeletion;
        return;
    }

    //traversal
    for(int i=0; i<position-2; i++) {
        placeOfDeletion = placeOfDeletion->next;   
    }

    //deletion
    node* temp = placeOfDeletion->next;
    placeOfDeletion->next = temp->next;
    delete temp;

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
        traverseArray(head);
        choice = getChoice();
    }
    

    choice = getDeleteChoice();

    while(choice == 'Y') {

        int position = 1;
        std::cout << "Enter the position where you wish to delete the element: " << "\n";
        std::cin >> position;
        deleteElement(&head, position);
        traverseArray(head);
        choice = getDeleteChoice();

    }
    
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
// 2
// Final elements entered: 
// 2       5
// Do you want to enter another element?
// Enter 'Y' for yes and 'N' for no: 
// Y
// Enter position of element: 
// 1
// Enter the element: 
// 8
// Final elements entered: 
// 8       2       5
// Do you want to enter another element?
// Enter 'Y' for yes and 'N' for no: 
// Y
// Enter position of element: 
// 4
// Enter the element: 
// 3
// Final elements entered: 
// 8       2       5       3
// Do you want to enter another element?
// Enter 'Y' for yes and 'N' for no: 
// Y
// Enter position of element: 
// 2
// Enter the element: 
// 9
// Final elements entered: 
// 8       9       2       5       3
// Do you want to enter another element?
// Enter 'Y' for yes and 'N' for no: 
// N
// Do you want to delete element? 
// Enter 'Y' for yes and 'N' for no: 
// Y
// Enter the position where you wish to delete the element: 
// 3
// Final elements entered: 
// 8       9       5       3
// Do you want to delete element? 
// Enter 'Y' for yes and 'N' for no: 
// Y
// Enter the position where you wish to delete the element: 
// 4
// Final elements entered: 
// 8       9       5
// Do you want to delete element? 
// Enter 'Y' for yes and 'N' for no: 
// Y
// Enter the position where you wish to delete the element: 
// 1
// Final elements entered: 
// 9       5
// Do you want to delete element? 
// Enter 'Y' for yes and 'N' for no: 
// N
