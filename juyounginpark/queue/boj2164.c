#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

void push(Node **head, Node **tail, int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if(*head == NULL) {
        *head = new_node;
        *tail = new_node;
        return;
    }

    (*tail)->next = new_node;
    *tail = new_node;
    return;
}

int pop(Node **head, Node **tail) {
    int data;

    if((*head)->next == NULL) {
        data = (*head)->data;
        free(*head);
        *head = NULL;
        *tail = NULL;
        return data;
    }
    
    data = (*head)->data;
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
    return data;
    
}

void printN(Node **head) {
    Node *curr = *head;
    while(curr) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    putchar('\n');
}
int main() {
    Node *head = NULL;
    Node *tail = NULL;
    int N;
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        push(&head, &tail, i);
    }

    while(head != tail) {
        pop(&head, &tail);
        if(head == tail) break;
        push(&head, &tail, pop(&head, &tail));
        
    }
    printN(&head);
}