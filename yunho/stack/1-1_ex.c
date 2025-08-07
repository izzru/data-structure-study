#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct StackType {
	int arr[SIZE];
	int top; //arr�� �� �� index ��
}StackType;

void init(StackType* s) {
	s->top = -1; //�迭 index�� 0���� >> -1�� empty. 0���ʹ� ������ �ִٴ� ��
}

int is_empty(StackType* s) {
	if (s->top == -1) //�������
		return 1;
	else return 0;//������ ������
}

int is_full(StackType* s) {
	if (s->top == SIZE - 1) //�迭�� �� á�°� (�ִ� index�� MAX-1 (index�� 0���� �����̱⶧��) ���ΰ�)
		return 1;
	else return 0; //�ƴѰ�
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

	printf("\nPeek: %d\n", peek(&s)); // 1�� ǥ�õǾ�� ��. ���� (��)3/2/1(ó��(top)) ������ �����Ͱ� �� �ְ�, stack�� lifo �����̱� ����.

	printf("\nPop: %d\n", pop(&s)); //1 pop �� ���
	printf("\nPop: %d\n", pop(&s)); //2 pop �� ���
	printf("\nPop: %d\n", pop(&s)); //3 pop �� ���

	printf("\nPop: %d\n", pop(&s)); //stack is empty�� ��µǾ�� ��. (no data)
	return 0;
}