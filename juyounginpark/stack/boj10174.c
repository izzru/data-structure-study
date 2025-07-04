#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        return;
    }

    new_node->prev = *tail;
    (*tail)->next = new_node;
    *tail = new_node;
}

void pop_tail(Node **head, Node **tail) {
    if (*head == NULL) return;

    if (*head == *tail) {
        free(*head);
        *head = *tail = NULL;
        return;
    }

    Node *temp = *tail;
    *tail = (*tail)->prev;
    (*tail)->next = NULL;
    free(temp);
}

void pop_head(Node **head, Node **tail) {
    if (*head == NULL) return;

    if (*head == *tail) {
        free(*head);
        *head = *tail = NULL;
        return;
    }

    Node *temp = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;
    free(temp);
}

void clear(Node **head, Node **tail) {
    while (*head) {
        pop_tail(head, tail);
    }
}

int is_palindrome(Node **head, Node **tail) {
    Node *front = *head;
    Node *back = *tail;

    while (front && back && front != back && front->prev != back) {
        if (front->d != back->d)
            return 0;
        front = front->next;
        back = back->prev;
    }

    return 1;
}

int main() {
    Node *head = NULL;
    Node *tail = NULL;

    int n;
    scanf("%d", &n);

    char str[51];
    while (n--) {
        scanf("%s", str);

        clear(&head, &tail);

        for (int i = 0; str[i]; i++) {
            push(&head, &tail, str[i]);
        }

        if (is_palindrome(&head, &tail)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    clear(&head, &tail);
    return 0;
}
