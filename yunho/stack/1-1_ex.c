#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct StackType {
	int arr[SIZE];
	int top; //arr의 맨 끝 index 값
}StackType;

void init(StackType* s) {
	s->top = -1; //배열 index는 0부터 >> -1은 empty. 0부터는 데이터 있다는 뜻
}

int is_empty(StackType* s) {
	if (s->top == -1) //비었을때
		return 1;
	else return 0;//데이터 있을때
}

int is_full(StackType* s) {
	if (s->top == SIZE - 1) //배열이 꽉 찼는가 (최대 index인 MAX-1 (index는 0부터 시작이기때문) 값인가)
		return 1;
	else return 0; //아닌가
}

void push(StackType* s, int value) {
	if (is_full(s)) {
		printf("Stack is full");
		exit(1);
	}
	printf("\nPushed: %d\n", value);
	s->arr[++(s->top)] = value;
}

int pop(StackType* s) {
	if (is_empty(s)) {
		printf("Stack is empty");
		exit(1);
	}
	return s->arr[(s->top)--];
}

int peek(StackType* s) {
	if (is_empty(s)) {
		printf("Stack is empty");
		exit(1);
	}
	return s->arr[(s->top)];
}

int main() {
	StackType s;
	init(&s);

	push(&s, 3); //3 push
	push(&s, 2); //2 push
	push(&s, 1); //1 push

	printf("\nPeek: %d\n", peek(&s)); // 1이 표시되어야 함. 현재 (끝)3/2/1(처음(top)) 순서로 데이터가 들어가 있고, stack은 lifo 형식이기 때문.

	printf("\nPop: %d\n", pop(&s)); //1 pop 후 출력
	printf("\nPop: %d\n", pop(&s)); //2 pop 후 출력
	printf("\nPop: %d\n", pop(&s)); //3 pop 후 출력

	printf("\nPop: %d\n", pop(&s)); //stack is empty가 출력되어야 함. (no data)
	return 0;
}