#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int THIS;
    struct Node *next;
}Node;

void push(Node **head, Node **tail, int data,int THIS) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->THIS = THIS;
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

void pop_butnotrealpop(Node **head, Node **tail) {
    if(*head == *tail) return;
    Node *temp = *head;
    (*head) = (*head) -> next;
    temp -> next = NULL;
    (*tail)->next = temp;
    *tail = temp;
}

int max(Node *curr) {
    int M = 0;
    while(curr) {
        if(curr->data > M) M = curr->data;
        curr = curr->next;
    }
    return M;
}

void clear(Node **head, Node **tail) {
    while(*head) {
        Node *temp = *head;
        (*head) = (*head) -> next;
        free(temp);
    }
    *head = NULL;
    *tail = NULL;
    return;
}

int main() {
    Node *head = NULL;
    Node *tail = NULL;
    int N;
    scanf("%d", &N);


    while(N--) {
        

        int k, m;
        scanf("%d %d", &k, &m);

        int buffer;
        for(int i = 0; i < k; i++) {
            scanf("%d", &buffer);
            push(&head, &tail, buffer, (i==m ? 1 : 0));
        }


        int res = 0;
        while(1) {
            if(head->data == max(head)) {
                res++;
                if(head->THIS) break;
                Node *temp = head;
                head = head->next;
                free(temp);
                
            }
            else {
                pop_butnotrealpop(&head, &tail);
            }
        }
        printf("%d\n", res);
        clear(&head, &tail);
    }
    

}