#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef int element;
typedef struct Queue {
	element data[MAX];
	int front, rear;
}Queue;

void error(char* msg) {
	printf("%s\n", msg);
	exit(1);
}

void init(Queue* q) {
	q->front = q->rear = 0;
}

int is_full(Queue* q) {
	return ((q->rear) + 1) % MAX == q->front;
}

int is_empty(Queue* q) {
	return q->front == q->rear;
}

void add_rear(Queue* q, element item) {
	if (is_full(q)) {
		error("Deque is Full");
		exit(1);
	}
	q->rear = (q->rear + 1) % MAX;
	q->data[q->rear] = item;
}

element delete_front(Queue* q) {
	if (is_empty(q)) {
		error("Deque is Empty");
		exit(1);
	}
	q->front = (q->front + 1) % MAX;
	return q->data[q->front];
}

void add_front(Queue* q, element item) {
	if (is_full(q)) {
		error("Deque is Full");
		exit(1);
	}
	q->data[q->front] = item;
	q->front = (q->front - 1 + MAX) % MAX;
}

element delete_rear(Queue* q) {
	int prev = q->rear;
	if (is_empty(q)) {
		printf("Deque is Empty");
		exit(1);
	}
	q->rear = (q->rear - 1 + MAX) % MAX;
	return q->data[prev];
}

element get_rear(Queue* q) {
	if (is_empty(q))
		error("Deque is Empty");
	return q->data[q->rear];
}

element get_front(Queue* q) {
	if (is_empty(q))
		error("Deque is Empty");
	return q->data[(q->front + 1 + MAX) % MAX];
}

int main(int argc, const char* argv[]) {
	Queue q;
	init(&q);

	for (int i = 0; i < 3; i++) {
		add_front(&q, i);
	}

	printf("\n%d", get_front(&q));
	printf("\n%d", get_rear(&q));

	for (int i = 0; i < 3; i++) {
		printf("\n%d", delete_rear(&q));
	}
	return 0;
}