#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	int ary[100001] = { 0 };
	char str[200001] = { '\0' };
	int n;
	int p = 0;
	int strp = 0;
	int num = 1;
	int wrong = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		
		if (x > ary[p])
		{
			for (; num <= x; num++)
			{
				ary[++p] = num;
				str[strp++] = '+';
			}
		}

		if (x == ary[p])
		{
			str[strp++] = '-';
			p--;
		}

		if (x < ary[p])
			wrong = 1;
	}

	if (wrong)
	{
		printf("NO\n");
		return 0;
	}

	p = strlen(str);

	for (int i = 0; i < p; i++)
		printf("%c\n", str[i]);
}