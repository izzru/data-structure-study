#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n = 0, num = 0, arr[10000] = { 0 }, idx_t = -1;
	char tmp[6] = { 0 };
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		num = 0;
		for (int a = 0; a < 6; a++) tmp[a] = '\0';
		scanf("%s", tmp);
		if (strcmp(tmp, "push") == 0) {
			scanf("%d", &num);
			arr[++idx_t] = num;
			continue;
		}
		else if (strcmp(tmp, "pop") == 0) {
			if (idx_t > -1) printf("%d\n", arr[idx_t--]);
			else printf("-1\n");
			continue;
		}
		else if (strcmp(tmp, "size") == 0) {
			printf("%d\n", idx_t + 1);
			continue;
		}
		else if (strcmp(tmp, "empty") == 0) {
			if (idx_t == -1) printf("1\n");
			else printf("0\n");
			continue;
		}
		else if (strcmp(tmp, "top") == 0) {
			if (idx_t > -1) printf("%d\n", arr[idx_t]);
			else printf("-1\n");
			continue;
		}
	}
	return 0;
}