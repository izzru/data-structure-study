#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100

typedef struct stackTyper
{
    char arr[SIZE];
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

void push(StackType* s, char ch)
{
    if (is_full(s))
    {
        printf("Stack overflow\n");
        exit(1);
    }
    s->arr[++(s->top)] = ch;
}

char pop(StackType* s)
{
    if (is_empty(s))
    {
        printf("stack is empty\n");
        exit(1);
    }
    return s->arr[(s->top)--];
}

int isVPS(const char* arr)
{
    StackType s;
    init(&s);

    for (int i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i] == '(')
        {
            push(&s, '('); //'(' 는 stack에 push
        }

        else if (arr[i] == ')')
        {
            if (is_empty(&s))
            {
                return 0;  //'('가 없는데 ')'가 나온경우 (!VPS)
            }
            pop(&s); //'('가 있으면 pop
        }
    }

    return is_empty(&s); // 스택이 비어 있으면 VPS
}

int main()
{
    int count;
    scanf("%d", &count);

    char arr[100];

    for (int i = 0; i < count; i++)
    {
        scanf("%s", arr);

        if (isVPS(arr))
        {
            printf("YES\n");
        }

        else
        {
            printf("NO\n");
        }
    }

    return 0;
}
