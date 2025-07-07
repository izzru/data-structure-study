#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define SIZE 100  //stack 크기 선언

typedef struct stackTyper
{
	int arr[100]; //int 데이터 100개  //4*100 byte
	int top;      //stack의 탑(array의 마지막)
}StackType;


void init(StackType* s)
{
	s->top = -1;
}


//empty : 1
//!empty : 0
int is_empty(StackType* s)   //stack이 비었는지 체크
{
	if (s->top == -1)
		return 1;
	return 0;
}


//full : 1
//!full : 0
int is_full(StackType* s)  //stack이 가득찼는지 체크
{
	if (s->top == SIZE - 1)
		return 1;
	return 0;
}


void push(StackType* s, int value)  //stack에 value를 push
{
	if (is_full(s))
	{
		printf("stack is full\n");
		exit(1);
	}
	printf("pushed %d\n", value);
	s->arr[++s->top] = value;  //full이 아니면 top을 증가시키고 그 위치에 value 저장 
}

int pop(StackType* s)    //stack에 top을 pop
{
	if (is_empty(s))
	{
		printf("stack is empty\n");
		exit(1);
	}
	return s->arr[(s->top)--];
}

int peek(StackType* s)   //stack에서 top을 반환
{
	if (is_empty(s))
	{
		printf("stack is empty\n");
		exit(1);
	}
	return s->arr[s->top];  //top의 값을 반환
}



int main()
{
	StackType stack;
	init(&stack); //스택 초기화

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