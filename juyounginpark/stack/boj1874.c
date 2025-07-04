#include <stdio.h>
#include <stdlib.h>

int ind = 0;

typedef struct Node {
    int d;
    struct Node *next;
    struct Node *prev;
} Node;

void push(Node **head, Node **tail, int data, char* res) {
    *(res + ind++) = '+';

    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->d = data;
    new_node->next = NULL;
    new_node->prev = *tail;

    if (*tail != NULL)
        (*tail)->next = new_node;
    else
        *head = new_node;

    *tail = new_node;
}

void pop(Node **head, Node **tail, char* res) {
    *(res + ind++) = '-';

    if (*tail == NULL) return;

    Node *temp = *tail;
    *tail = (*tail)->prev;

    if (*tail != NULL)
        (*tail)->next = NULL;
    else
        *head = NULL;

    free(temp);
}

int main() {
    Node *head = NULL, *tail = NULL;
    int n, current = 1;
    scanf("%d", &n);

    int *arr = (int *)malloc(sizeof(int) * n);
    char res[2 * 100000];  

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < n; i++) {
        int target = arr[i];

        while (current <= target) {
            push(&head, &tail, current, res);
            current++;
        }

        if (tail == NULL || tail->d != target) {
            printf("NO\n");
            free(arr);
            return 0;
        }

        pop(&head, &tail, res);
    }

    for (int i = 0; i < ind; i++)
        printf("%c\n", res[i]);

    free(arr);
    return 0;
}
