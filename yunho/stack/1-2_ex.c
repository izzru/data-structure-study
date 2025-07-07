#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

typedef struct StackType {
	char arr[SIZE];
	int top;
}StackType;

typedef struct StackTyp {
	char arr[SIZE];
	int top;
}StackTyp;

void init(StackType* s) {
	s->top = -1;
}


void init1(StackTyp* s) {
	s->top = -1;
}

int is_empty(StackType* s) {
	if (s->top == -1)
		return 1;
	else return 0;
}

int is_empty1(StackTyp* s) {
	if (s->top == -1)
		return 1;
	else return 0;
}


int is_full(StackType* s) {
	if (s->top == SIZE - 1) 
		return 1;
	else return 0; 
}

int is_full1(StackTyp* s) {
	if (s->top == SIZE - 1)
		return 1;
	else return 0;
}

void push(StackType* s, char value) {
	if (is_full(s)) {
		printf("Stack is full");
		exit(1);
	}
	s->arr[++(s->top)] = value;
}

void push1(StackTyp* s, int value) {
	if (is_full1(s)) {
		printf("Stack is full");
		exit(1);
	}
	s->arr[++(s->top)] = value;
}

char pop(StackType* s) {
	if (is_empty(s)) {
		printf("Stack is empty");
		exit(1);
	}
	return s->arr[(s->top)--];
}

int pop1(StackTyp* s) {
	if (is_empty1(s)) {
		printf("Stack is empty");
		exit(1);
	}
	return s->arr[(s->top)--];
}

char peek(StackType* s) {
	if (is_empty(s)) {
		printf("Stack is empty");
		exit(1);
	}
	return s->arr[(s->top)];
}

int peek1(StackTyp* s) {
	if (is_empty1(s)) {
		printf("Stack is empty");
		exit(1);
	}
	return s->arr[(s->top)];
}

int prec(char op) {
	switch (op) {
		case'(':case')':
			return 0;
		case'+':case'-':
			return 1;
		case'*':case'/':
			return 2;
	}
}

void infix_to_postfix(char exp[], char result[]) {
	char ch, top_op;
	int len = strlen(exp), a = 0;
	StackType s;
	init(&s);

	for (int i = 0; i < len; i++) {
		ch = exp[i];
		switch (ch) {
		case'+':case'-':case'*':case'/':
			while (!is_empty(&s) && prec(ch) <= prec(peek(&s)))
				result[a++] = pop(&s);
			push(&s, ch);
			break;
		case'(':
			push(&s, ch);
			break;
		case')':
			top_op = pop(&s);
			while (top_op != '(') {
				result[a++] = top_op;
				top_op = pop(&s);
			}
			break;
		default:
			result[a++] = ch;
			break;
		}
	}
	while (!is_empty(&s))
		result[a++] = pop(&s);
	result[a] = '\0';
}

int eval(char exp[]) {
	int op1, op2, value;
	char ch;
	int len = strlen(exp);

	StackTyp s;
	init1(&s);

	for (int i = 0; i < len; i++) {
		ch = exp[i];
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
			value = ch - '0';
			push1(&s, value);
		}
		else {
			op2 = pop1(&s);
			op1 = pop1(&s);
			switch (ch) {
			case '+':
				push1(&s, op1 + op2);
				break;
			case '-':
				push1(&s, op1 - op2);
				break;
			case '*':
				push1(&s, op1 * op2);
				break;
			case '/':
				push1(&s, op1 / op2);
				break;
			}
		}
	}
	return pop1(&s);
}

int main() {
	char *s = "(2+3)*4+9";
	char r[SIZE];
	infix_to_postfix(s, r);
	int result;
	result = eval(r);
	printf("%d", result);
	printf("\n");
	return 0;
}