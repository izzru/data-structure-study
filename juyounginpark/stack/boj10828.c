#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size = 0;

typedef struct Node { 
    int d;
    struct Node *next;
    struct Node *prev;
}Node;

void push(Node **head, Node **tail, int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->d = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    if(*head == NULL) {
        *head = new_node;
        return;
    }

    if(*tail == NULL) {
        (*head)->next = new_node;
        new_node->prev = *head;
        *tail = new_node;
        return;
    }

    new_node->prev = *tail;
    (*tail)->next = new_node;
    *tail = new_node;
    return;

}

int pop (Node **head, Node **tail) {
    int data;
    if(size==1) {
        data = (*head)->d;
        free(*head);
        *head = NULL;
        return data;
    }

    data = (*tail)->d;
    *tail = (*tail)->prev;
    free((*tail)->next);
    (*tail)->next = NULL;
    return data;

}
void print(Node **head) {
    Node* temp = *head;
    while(temp!=NULL) {
        printf("%d ", temp->d);
        temp = temp->next;
    }
}

int main() {

    
    Node *head = NULL;
    Node *tail = NULL;
    int n;
    scanf("%d", &n);

    char str[50];
    int buffer;
    while(n--) {
    
       scanf("%s", str);
       if(!strcmp(str,"push")) {
            scanf("%d", &buffer);
            push(&head, &tail, buffer);
            size++;
       }

       if(!strcmp(str, "pop")) {
            if(size==0) {
                printf("-1\n");
            }
            else {{
                printf("%d\n", pop(&head, &tail));
                size--;
            }}
       }

       if(!strcmp(str, "size")) {
            printf("%d\n", size);
       }

       if(!strcmp(str, "empty")) {
            printf("%d\n",(!size?1:0));
       }

       if(!strcmp(str, "top")) {
            if(size==0) {
                printf("-1\n");
            }
            else if(size==1){
                printf("%d\n", head->d);
            }
            else {
                printf("%d\n", tail->d);
            }
       }

       


    }

}