#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define SIZE 100  //stack ũ�� ����

typedef struct stackTyper
{
	int arr[100]; //int ������ 100��  //4*100 byte
	int top;      //stack�� ž(array�� ������)
}StackType;


void init(StackType* s)
{
	s->top = -1;
}


//empty : 1
//!empty : 0
int is_empty(StackType* s)   //stack�� ������� üũ
{
	if (s->top == -1)
		return 1;
	return 0;
}


//full : 1
//!full : 0
int is_full(StackType* s)  //stack�� ����á���� üũ
{
	if (s->top == SIZE - 1)
		return 1;
	return 0;
}


void push(StackType* s, int value)  //stack�� value�� push
{
	if (is_full(s))
	{
		printf("stack is full\n");
		exit(1);
	}
	printf("pushed %d\n", value);
	s->arr[++s->top] = value;  //full�� �ƴϸ� top�� ������Ű�� �� ��ġ�� value ���� 
}

int pop(StackType* s)    //stack�� top�� pop
{
	if (is_empty(s))
	{
		printf("stack is empty\n");
		exit(1);
	}
	return s->arr[(s->top)--];
}

int peek(StackType* s)   //stack���� top�� ��ȯ
{
	if (is_empty(s))
	{
		printf("stack is empty\n");
		exit(1);
	}
	return s->arr[s->top];  //top�� ���� ��ȯ
}



int main()
{
	StackType stack;
	init(&stack); //���� �ʱ�ȭ

	push(&stack, 123);
	push(&stack, 456);
	push(&stack, 789);

	printf("\npeek: %d\n", peek(&stack));
	printf("\npop: %d\n", pop(&stack));
	printf("\npop: %d\n", pop(&stack));
	printf("\npop: %d\n", pop(&stack));

	printf("pop: %d\n", pop(&stack));

	return 0;
}