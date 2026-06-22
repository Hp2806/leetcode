#include <stdio.h>
#include <stdlib.h>
struct Employee {
    int empID;
    struct Employee* next;
};
void findME(struct Employee* head) {
    if (head == NULL) {
        printf("The employee list is empty.\n");
        return;
    }

    struct Employee* slow = head; 
    struct Employee* fast = head; 
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;      
        fast = fast->next->next; 
    }
    printf("Middle Employee ID: %d\n", slow->empID);
}
struct Employee* insertEnd(struct Employee* head, int id) {
    struct Employee* newEmp = (struct Employee*)malloc(sizeof(struct Employee));
    newEmp->empID = id;
    newEmp->next = NULL;

    if (head == NULL) {
        return newEmp;
    }
    struct Employee* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newEmp;
    return head;
}
void printList(struct Employee* head) {
    struct Employee* temp = head;
    while (temp != NULL) {
        printf("[ID: %d] -> ", temp->empID);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    struct Employee* hrList = NULL;
    hrList = insertEnd(hrList, 101);
    hrList = insertEnd(hrList, 102);
    hrList = insertEnd(hrList, 103);
    printf("Employee List:\n");
    printList(hrList);
    findME(hrList);

    return 0;
}
