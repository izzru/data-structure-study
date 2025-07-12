#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int THIS;
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

int MAX(Node **head) {
    Node *curr = *head;
    int M = 0;
    while(curr) {
        if(M < curr->data ) M = curr->data;
        curr = curr->next;
    }
    return M;
}

void clear(Node **head, Node **tail) {
    while(*head) {
        pop(head, tail);
    }
    head = NULL;
    tail = NULL;
}
int main() {
    Node *head = NULL;
    Node *tail = NULL;
    int N;
    scanf("%d", &N);

    while(N--) {
    int M, K;
        int sign = 0;
        scanf("%d %d", &M, &K);
        for(int i=0; i<M; i++) {
            int buffer;
            scanf("%d", &buffer);
            push(&head, &tail, buffer);
            if(i==K) {
                tail->THIS = 1;
            }
            else {
                tail->THIS = 0;
            }
        }
        int num = 0;
        while(1) {
            int max = MAX(&head);
            if(max == head->data) {
                num++;
                if(head->THIS) {
                    break;
                }
                else {
                    Node *temp = head;
                    tail->next = temp;
                    pop(&head, &tail);
                }
            }
            else {
                push(&head, &tail, pop(&head, &tail));
            }

            
        }
        clear(&head, &tail);
        printf("%d\n", num);
    }
    
}