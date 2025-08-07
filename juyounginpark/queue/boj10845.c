#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
    int data;
    struct Node *next;
}Node;

void insert(Node **head, Node **tail, int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node -> data = data;
    new_node -> next = NULL;

    if(*head == NULL) {
        *head = new_node;
        *tail = new_node;
        return;
    }

    (*tail) -> next = new_node;
    *tail = new_node;
    return;

}

int pop(Node **head, Node **tail) {
    int data;
    if(*head == NULL) return -1;
    if((*head)->next == NULL) {
        data = (*head)->data;
        free(*head);
        *head = NULL;
        *tail = NULL;
        return data; 
    }

    data = (*head)->data;
    Node *temp = *head;
    *head = (*head) -> next;
    free(temp);
    return data;

}

void printN(Node **head) {
    Node *temp = *head;
    while(temp) {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    putchar('\n');
}

int main() {
    Node *head = NULL;
    Node *tail = NULL;
    
    int n;
    scanf("%d", &n);

    int size = 0;
    char buffer[10];
    while(n--) {
        scanf("%s", buffer);
        if(!strcmp(buffer, "push")) {
            int x;
            scanf("%d", &x);
            insert(&head, &tail, x);
            size++;
        }
        else if (!strcmp(buffer, "pop")) {
            printf("%d\n",pop(&head, &tail));
            if(size)size--;
        }
        else if (!strcmp(buffer, "size")) {
            printf("%d\n", size);
        }
        else if (!strcmp(buffer, "empty")) {
            printf("%d\n", (size?0:1));
        }
        else if (!strcmp(buffer, "front")) {
            printf("%d\n",(head?head->data:-1));
        }
        else if (!strcmp(buffer, "back")) {
            printf("%d\n",(tail?tail->data:-1));
        }
    }
}