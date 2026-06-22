#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


struct Node* insert(struct Node* head, int newValue) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newValue;
    newNode->next = head;
    return newNode; 
}


struct Node* delete(struct Node* head, int valueToDelete) {
    struct Node* temp = head;
    struct Node* prev = NULL;
    if (temp != NULL && temp->data == valueToDelete) {
        head = temp->next; 
        free(temp);        
        printf("Element %d deleted successfully.\n", valueToDelete);
        return head;
    }
    while (temp != NULL && temp->data != valueToDelete) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element %d not found in the list.\n", valueToDelete);
        return head;
    }
    prev->next = temp->next;
    free(temp); 
    printf("Element %d deleted successfully.\n", valueToDelete);   
    return head;
}
int main() {
    struct Node* head = NULL;
    head = insertAtBeginning(head, 30);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 10);

    printf("Initial Linked List:\n");
    displayList(head);

    printf("\nAdding 5 to the beginning...\n");
    head = insertAtBeginning(head, 5);
    displayList(head);

    printf("\nRemoving element 20...\n");
    head = deleteByValue(head, 20);
    displayList(head);

    return 0;
}
