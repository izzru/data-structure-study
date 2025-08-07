#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10000

typedef struct stackTyper
{
	int arr[SIZE];
	int top;
} StackType;

void init(StackType* s)
{
	s->top = -1;
}

int is_empty(StackType* s)
{
	if (s->top == -1)
		return 1;
	return 0;
}

int is_full(StackType* s)
{
	if (s->top == SIZE - 1)
		return 1;
	return 0;
}

void push(StackType* s, int value)
{
	if (is_full(s))
		return;
	s->arr[++s->top] = value;
}

int pop(StackType* s)
{
	if (is_empty(s))
		return -1;               //return -1로 수정
	return s->arr[(s->top)--];
}

int peek(StackType* s)
{
	if (is_empty(s))
		return -1;              //return -1로 수정
	return s->arr[s->top];
}

int size(StackType* s)
{
	return s->top + 1;
}

int empty(StackType* s)
{
	return is_empty(s) ? 1 : 0;
}

int main()
{
	int N;
	scanf("%d", &N);

	StackType s;
	init(&s);

	char command[10];
	int value;

	for (int i = 0; i < N; i++)
	{
		scanf("%s", command);

		if (strcmp(command, "push") == 0)
		{
			scanf("%d", &value);
			push(&s, value);
		}
		else if (strcmp(command, "pop") == 0)
		{
			printf("%d\n", pop(&s));
		}
		else if (strcmp(command, "size") == 0)
		{
			printf("%d\n", size(&s));
		}
		else if (strcmp(command, "empty") == 0)
		{
			printf("%d\n", empty(&s));
		}
		else if (strcmp(command, "top") == 0)
		{
			printf("%d\n", peek(&s));
		}
	}

	return 0;
}