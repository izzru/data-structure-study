#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	int num = 0;
	char arr[100][50];
	int j = 0;

	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		while (1) {
			scanf("%s", arr[i]);
			if (strlen(arr[i]) > 2 && strlen(arr[i]) < 50) {
				break;
			}
		}
	}

	for (int j = 0; j < num; j++) {
		while (1) {

			if (arr[j][0] != '(') {
				printf("NO\n");
				break;
			}
			int size = strlen(arr[j]);
			if (arr[j][size - 1] != ')') {
				printf("NO\n");
				break;
			}

			int n1 = 0, n2 = 0;
			for (int i = 0; i < size; i++) {
				if (arr[j][i] == '(') {
					n1++;
				}
				else if (arr[j][i] == ')') {
					n2++;
				}
			}
			if (n1 != n2) {
				printf("NO\n");
				break;
			}

			printf("YES\n");
			break;
		}
	}
}
