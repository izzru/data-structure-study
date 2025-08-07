#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue {
	int arr[500000];
	int front;
	int rear;
} Queue;

void init(Queue* q) {
	q->front = 0;
	q->rear = 0;
}

void push(Queue* q, int value) {
	q->arr[q->rear++] = value;
}

int size(Queue* q) {
	return q->rear - q->front;
}

void first_del(Queue* q) {
	q->front++;
}
void second_last(Queue* q) {
	int temp = q->arr[q->front++];
	q->arr[q->rear++] = temp;
}

int main() {
	int num = 0;
	scanf("%d", &num);
	Queue q;
	init(&q);

	for (int i = 0; i < num; i++) {
		push(&q, i + 1);
	}

	while (size(&q)>1) {
		first_del(&q);
		second_last(&q);
	}

	printf("%d\n", q.arr[q.front]);
	return 0;
}
