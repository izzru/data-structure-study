#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size = 0;

typedef struct Node { 
    char d;
    struct Node *next;
    struct Node *prev;
}Node;

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

void clear (Node **head, Node **tail) {

    while (*head) {
        pop(head, tail);
    }
}

int main() {

    
    Node *head = NULL;
    Node *tail = NULL;
    int n;
    scanf("%d", &n);

    char str[51];
    int flag = 0;
    while (n--) {
        if(head) clear(&head, &tail);
        flag = 0;
        scanf("%s", str);
        for(int i=0 ;str[i]!='\0'; i++) {
            if(str[i]=='(') { push(&head, &tail, str[i]); }
            else {
                if(!head) {
                    flag = 1;
                    break;
                }
                pop(&head, &tail); 
            }

        }
        if(flag) {
            printf("NO\n");
            continue;
        }
        printf("%s\n", (head?"NO":"YES"));

       


    }   

}