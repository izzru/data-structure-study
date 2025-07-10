#include <stdio.h>
#include <stdlib.h>

void push(Node **head, Node **tail, char data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->d = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (*head == NULL) {
        *head = new_node;
        *tail = new_node;  
        return;
    }

    new_node->prev = *tail;
    (*tail)->next = new_node;
    *tail = new_node;
}

void pop (Node **head, Node **tail) {
    int data;
    if(*head != NULL && (*head)->next == NULL) {
        data = (*head)->d;
        free(*head);
        *head = NULL;
        return;
    }

    data = (*tail)->d;
    *tail = (*tail)->prev;
    Node *temp = (*tail)->next;
    free(temp);
    (*tail)->next = NULL;
    return;

}

int main() {

}