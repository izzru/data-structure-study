#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define STACK_MAX_SIZE 10000

typedef struct _Stack{
    int top;
    int number[STACK_MAX_SIZE];
}Stack;

int is_empty(Stack *s){
    if(s->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

bool is_full(Stack *s){
    return s->top == STACK_MAX_SIZE -1;
}

void init(Stack *s){
    s->top = -1;
}

void push(Stack* s, int num){
    if(!is_full(s)){
        s->top += 1;
        s->number[s->top]= num;
    }
    else if(is_full(s)){
        printf("Error: This stack is already full.\n");
    }
}

void pop(Stack* s){
    if(!is_empty(s)){
        printf("%d\n", s->number[s->top]);
        s->top -= 1;
    }
    else {
        printf("-1\n");
    }
}

void top(Stack *s){
    if(!is_empty(s)){
        printf("%d\n", s->number[s->top]);
    }
    else{
        printf("-1\n");
    }
}

void size(const Stack *s) {    
    printf("%d\n", s->top + 1);
}

int main(){
    Stack stackS2;
    int num =0;
    int empty = 0;
    char buffer[6]="";
    int N = 0;
    scanf("%d", &N);
    init(&stackS2);
    for(int i = 0; i < N; i++){
        scanf("%s", buffer);
        if(strcmp(buffer, "push") == 0){
            scanf("%d", &num);
            push(&stackS2, num);
        }
        else if(strcmp(buffer, "pop") == 0){
            pop(&stackS2);
        }
        else if(strcmp(buffer, "top") == 0){
            top(&stackS2);
        }
        else if(strcmp(buffer, "size") == 0){
            size(&stackS2);
        }
         else if(strcmp(buffer, "empty") == 0){
            empty = is_empty(&stackS2);
            printf("%d\n", empty);
        }
        else {
            printf("Invalid input.\n");
        }
    }
    return 0;
}