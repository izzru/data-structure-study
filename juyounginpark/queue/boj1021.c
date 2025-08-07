#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;

}Node;


void insert(Node **head, Node **tail, int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    if(*head == NULL) {
        *head = new_node;
        *tail = new_node; 

        return;
    }

    new_node->prev = *tail;
    (*tail)->next = new_node;
    *tail = new_node;

    return;
    
}

void move_left(Node **head, Node **tail) {
    if(*head == *tail) return;

    Node *temp = *head;

    (*head) = (*head) -> next;
    (*head) -> prev = NULL;

    temp -> next = NULL;
    temp -> prev = *tail;

    (*tail)->next = temp;
    *tail = temp;

    return;
}

void move_right(Node **head, Node **tail) {
    if(*head == *tail) return;

    Node *temp = *tail;

    (*tail) = (*tail) -> prev;
    (*tail) -> next = NULL;

    temp->prev = NULL;
    temp->next = *head;

    (*head) -> prev = temp;
    *head = temp;

    return;
}

int compare(Node *curr, int buffer) {
    int op = 0;
    int node_total;
    int node_location = 0;

    if(curr == NULL) return 0;
    for(node_total = 1; curr; node_total++) {
        if(buffer == curr->data) node_location = node_total;
        curr=curr->next;
    }

    int node_mid = (float)node_total/2;

    op = node_mid - node_location;
    if(op >= 0) {
        return (node_location);
    }
    else {
        return (-1) * (node_total - node_location);
    } 

    return op;
}

int del (int op, Node **head, Node **tail) {
    if(*head == *tail) return 0;
    int total;
    if(op >= 0) {
        for(total = 0; total < (op-1); total++) move_left(head, tail);
    }
    else {
        for(total = 0; total < ((-1) * (op)); total++) move_right(head, tail);
    }

    Node *temp = *head;
    (*head) = (*head)->next;
    (*head) -> prev = NULL;
    free(temp);
    return total;
}

void print(Node *curr) {
    while(curr) {
        printf("%d ",curr->data);
        curr = curr->next;
    } 
    putchar('\n');
    return;
}

int main() {
    Node *head = NULL;
    Node *tail = NULL;

    int N, M;
    scanf("%d %d", &N, &M);

    for(int i=1; i<=N; i++)insert(&head, &tail, i);

    int buffer;
    int res = 0;
    while(M--) {
        scanf("%d", &buffer);
        res +=  del(compare(head, buffer), &head, &tail);
    }
    printf("%d", res);
    
}