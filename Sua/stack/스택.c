#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n, p = 0;

	scanf("%d", &n);
	int* ary = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
	{
		char str[6];

		scanf("%s", str);

		if (!strcmp(str, "push"))
		{
			int x;

			scanf("%d", &x);
			ary[p++] = x;
		}
		else if (!strcmp(str, "pop"))
			printf("%d\n", p ? ary[--p] : -1);
		else if (!strcmp(str, "size"))
			printf("%d\n", p);
		else if (!strcmp(str, "empty"))
			printf("%d\n", p == 0);
		else
			printf("%d\n", p ? ary[p - 1] : -1);
	}
	free(ary);
}