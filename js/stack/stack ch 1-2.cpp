#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

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
	printf("pushed %c\n", value);
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

// �Ʒ����� ch 1-2


int prec(char op)
{
	switch (op)
	{
	case '(': case ')':
		return 0;
	case '+': case '-':
		return 1;
	case '*': case '/':
		return 2;
	}
	return -1;
}


void infix_to_postfix(char exp[])
{
	char ch, top_op;
	int len = strlen(exp);
	StackType s;
	init(&s);

	for (int i = 0; i < len; i++)
	{
		ch = exp[i];
		switch (ch)
		{
		case '+': case '-': case '*': case'/':
			while (!is_empty(&s) && prec(ch) <= prec(peek(&s)))
				printf("%c", pop(&s));
			push(&s, ch);
			break;
		case '(':
			push(&s, ch);
			break;
		case ')':
			top_op = pop(&s);
			while (top_op != '(')
			{
				printf("%c", top_op);
				top_op = pop(&s);
			}
			break;
		default:
			printf("%c", ch);
			break;

		}
	}
	while (!is_empty(&s))
		printf("%c", pop(&s));
}

int eval(char exp[])
{
	int op1, op2, value;
	char ch;
	int len = strlen(exp);


	StackType s;
	init(&s);

	for (int i = 0; i < len; i++)
	{
		ch = exp[i];
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/')
		{
			value = ch - '0'; //char to int
			push(&s, value);
		}
		else
		{
			op2 = pop(&s);
			op1 = pop(&s);
			switch (ch)
			{
			case '+':
				push(&s, op1 + op2);
				break;
			case '-':
				push(&s, op1 - op2);
				break;
			case '*':
				push(&s, op1 * op2);
				break;
			case '/':
				push(&s, op1 / op2);
				break;
			}
		}
	}
	return pop(&s);
}



int main()
{
	int result;
	result = eval("82/3-32*+");
	printf("---> %d\n", result);

	return 0;
}