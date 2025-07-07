#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
	int arr[100];
	int top;
	int size;
}Stack;

void init(Stack *s) {
	s->top = -1;
	s->size = 0;
}

void empty(Stack* s) {
	if (s->top == -1) {
		printf("1\n");
	}
	else
		printf("0\n");
}

void push(Stack* s, int value) {
	s->arr[++(s->top)] = value;
	s->size++;
}

void pop(Stack* s) {
	if (s->top == -1) {
		printf("-1\n");
	}
	else {
		printf("%d\n", s->arr[s->top--]);
		s->size--;
	}
}


void size(Stack* s) {
	printf("%d\n", s->size);
}

void top(Stack* s) {
	if (s->top == -1) {
		printf("-1\n");
	}
	else {
		printf("%d\n", s->arr[s->top]);
	}
}


int main() {
	Stack s;
	init(&s);

	char ind[5][100] = {"push","pop","size","empty","top"};
	int num = 0;
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		char itr[100];
		int num1 = 0;
		scanf("%s", itr);

		if (strcmp(ind[0], itr) == 0) {
			scanf("%d", &num1);
			push(&s, num1);
		}
		else if (strcmp(ind[1], itr) == 0) {
			pop(&s);
		}
		else if (strcmp(ind[2], itr) == 0) {
			size(&s);
		}
		else if (strcmp(ind[3], itr) == 0) {
			empty(&s);
		}
		else if (strcmp(ind[4], itr) == 0) {
			top(&s);
		}
	}
	return 0;
}
