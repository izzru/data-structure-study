#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int priority(char c) 
{
	if (c == '(') 
		return 0;
	if (c == '+' || c == '-') 
		return 1;
	if (c == '*' || c == '/') 
		return 2;
	return -1;
}

int main()
{
	char str[101] = { '\0' };

	scanf("%s", str);

	char stack[101] = { '\0' };
	int stackp = -1;
	int len = strlen(str);

	for (int i = 0; i < len; i++)
	{
		if (str[i] > 64)
		{
			printf("%c", str[i]);
			continue;
		}

		if (str[i] == '(')
			stack[++stackp] = '(';
		else if (str[i] == ')')
		{
			while (stack[stackp] != '(')
				printf("%c", stack[stackp--]);
			stackp--;
		}
		else
		{
			while (stackp >= 0 && priority(stack[stackp]) >= priority(str[i]))
				printf("%c", stack[stackp--]);
			stack[++stackp] = str[i];
		}
	}
	while (stackp >= 0)
		printf("%c", stack[stackp--]);
}