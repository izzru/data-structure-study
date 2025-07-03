#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define SIZE 50
typedef struct stacktype {
	char ps[SIZE];
	int top;
	
}st;


void init(st* s) {//초기화함수
	s->top = -1;
}

void push(st*s,char S){
	s->ps[++(s->top)] = S;

}
char pop(st* s) {
	if (s->top == -1)return 0;
	return s->ps[(s->top)--];
}

int check(char* str) {
    st s;
    init(&s);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            push(&s, '(');
        }
        else if (str[i] == ')' && s.top == -1) {
            return 0;
        }
        else if (str[i] == ')') {
            pop(&s);
        }
    }
    return s.top == -1;
}



int main() {
	char ps[SIZE];
	int T;
	scanf("%d", &T);

	for (int i = 0;i < T;i++) {
		scanf("%s", ps);

		if (check(ps)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
