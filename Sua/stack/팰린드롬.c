#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	int n;

	scanf("%d", &n);
	getchar();

	for (int i = 0; i < n; i++)
	{
		char str[19];
		
		gets(str);

		int p = 0, q = strlen(str) - 1;

		while (p < q)
		{
			if (str[p] != str[q] && str[p] != str[q] + 32 && str[p] != str[q] - 32)
				break;
			p++;
			q--;
		}
		p < q ? printf("No\n") : printf("Yes\n");
	}
}