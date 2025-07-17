#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue {
	int arr[100];
	int front;
	int rear;
}Queue;

void init(Queue* q) {
	q->front = 0;
	q->rear = 0;
}

void empty(Queue* q) {
	if (q->front == q->rear)
		printf("1\n");
	printf("0\n");
}

void push(Queue* q, int value) {
	q->arr[q->rear++] = value;
}

void pop(Queue* q) {
	if (q->front == q->rear)
		printf("-1\n");
	else
		printf("%d\n", q->arr[q->front++]);

}


void size(Queue* q) {
	printf("%d\n", q->rear-q->front);
}

void front(Queue* q) {
	if (q->front == q->rear)
		printf("-1\n");
	printf("%d\n", q->arr[q->front]);
}

void back(Queue* q) {
	if (q->front == q->rear)
		printf("-1\n");
	printf("%d\n", q->arr[q->rear - 1]);
}


int main() {
	Queue q;
	init(&q);

	char ind[6][100] = { "push","pop","size","empty","front","back"};
	int num = 0;
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		char itr[100];
		int num1 = 0;
		scanf("%s", itr);

		if (strcmp(ind[0], itr) == 0) {
			scanf("%d", &num1);
			push(&q, num1);
		}
		else if (strcmp(ind[1], itr) == 0) {
			pop(&q);
		}
		else if (strcmp(ind[2], itr) == 0) {
			size(&q);
		}
		else if (strcmp(ind[3], itr) == 0) {
			empty(&q);
		}
		else if (strcmp(ind[4], itr) == 0) {
			front(&q);
		}
		else if (strcmp(ind[5], itr) == 0) {
			back(&q);
		}
	}
	return 0;
}
