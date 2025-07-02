#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define STACK_MAX_SIZE 50

typedef struct {
    int top;
    char parentheses[51];
}Stack;

bool is_empty(int top){
    return top == -1;
}

void init(Stack *s){
    s->top = -1;
}

void push(Stack* s){
    s->top += 1;
}

void pop(Stack* s){
     s->top -= 1;
}

void solution(Stack *s){
    int cnt = 0;
    scanf("%s", s->parentheses);
    int len = strlen(s->parentheses);
    while(s->parentheses[cnt] != '\0'){ 
        if(s->parentheses[cnt] == '('){
            push(s);
        }
        else if(s->parentheses[cnt] == ')'){
            pop(s);
        }
        cnt++;

        if(cnt < 50){ 
            if(s->top < -1){
                printf("No\n");
                break;
            }
        }
        if(cnt == len){
            if(is_empty(s->top)){ 
                printf("YES\n");
            }
            else printf("No\n"); 
            }
	  }
}

int main(){
    int T;
    Stack stack;
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
		    init(&stack);
        solution(&stack);
    }
    return 0;
}