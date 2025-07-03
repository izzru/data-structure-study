#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define SIZE 10000

typedef struct structtype {
	int arr[SIZE];
	int top;
}st;





void push(st* s, int value) {
	s->arr[++(s->top)] = value;
}

int pop(st* s) {
	if (s->top == -1) return -1;
	return s->arr[(s->top)--];

}

int empty(st* s) {
	if (s->top == -1) {
		return 1;
	}
	else{
		return 0;
	}
}

int size(st* s) {
	return s->top+1;
}

int peek(st* s) {
	if (s->top == -1) return -1;
	return s->arr[(s->top)];
}
void init(st* s) {
	s->top = -1;
}

int main() {
	st s;
	int n = 0;
	init(&s);

	scanf("%d", &n);
	char ans[10];
	for (int i = 0;i < n;i++) {
		scanf("%s", ans);


		if (strcmp(ans, "push") == 0) {
			int x;
			scanf("%d", &x);
			push(&s, x);
		}
		else if (strcmp(ans, "pop") == 0) {
			printf("%d\n", pop(&s));
		}
		else if (strcmp(ans, "size") == 0) {
			printf("%d\n", size(&s));
		}
		else if (strcmp(ans, "empty") == 0) {
			printf("%d\n", empty(&s));
		}
		else if (strcmp(ans, "top") == 0) {
			printf("%d\n", peek(&s));
		}
	}
	return 0;
}



