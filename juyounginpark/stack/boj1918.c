#include <stdio.h>
#include <stdlib.h>

typedef struct Node { 
    char d;
    struct Node *next;
    struct Node *prev;
} Node;

void push(Node **head, Node **tail, char data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->d = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (*head == NULL) {
        *head = new_node;
        *tail = new_node;  
    } else {
        new_node->prev = *tail;
        (*tail)->next = new_node;
        *tail = new_node;
    }
}

char pop(Node **head, Node **tail) {
    if (*tail == NULL) return 0; 

    char data;
    if (*head == *tail) {
        data = (*head)->d;
        if (data != '(') putchar(data);
        free(*head);
        *head = *tail = NULL;
    } else {
        data = (*tail)->d;
        *tail = (*tail)->prev;
        free((*tail)->next);
        (*tail)->next = NULL;
        if (data != '(') putchar(data);
    }
    return data;
}

int cmp(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

int main() {
    Node *head = NULL;
    Node *tail = NULL;
    char str[101];
    scanf("%s", str);

    for (int i = 0; str[i]; i++) {
        char ch = str[i];

        if (ch >= 'A' && ch <= 'Z') {
            putchar(ch);  
        } 
        else if (ch == '(') {
            push(&head, &tail, ch);
        } 
        else if (ch == ')') {
            while (tail && tail->d != '(') pop(&head, &tail);
            pop(&head, &tail);  
        } 
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (tail && cmp(tail->d) >= cmp(ch)) {
                pop(&head, &tail);
            }
            push(&head, &tail, ch);
        }
    }

    while (tail) {
        pop(&head, &tail);
    }

    return 0;
}
