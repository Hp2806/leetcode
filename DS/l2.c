#include <stdio.h>
#include <stdlib.h>


struct Coach {
    int coachNumber;
    struct Coach* next;
};


void printTrain(struct Coach* head) {
    struct Coach* temp = head;
    while (temp != NULL) {
        printf("[Coach %d] -> ", temp->coachNumber);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Coach* addCoach(struct Coach* head, int num) {
    struct Coach* newCoach = (struct Coach*)malloc(sizeof(struct Coach));
    newCoach->coachNumber = num;
    newCoach->next = head;
    return newCoach;
}

 struct Coach* reverseTrain(struct Coach* head) {
         struct Coach* prev = NULL;    
           struct Coach* current = head; 
           struct Coach* next = NULL;
             
	     while (current != NULL) {
	         next = current->next;
	         current->next = prev;
	         prev = current;      
	         current = next;
	     }
	      return prev;
	   }
int main() {
    struct Coach* train = NULL;
    train = addCoach(train, 104);
    train = addCoach(train, 103);

    printf("Original Train Coach Sequence:\n");
    printTrain(train);
    train = reverse(train);

    printf("\nReversed Train Coach Sequence:\n");
    printTrain(train);

    return 0;
}

