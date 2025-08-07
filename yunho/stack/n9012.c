#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cls(char* a) {
	for (int i = 0; a[i] != '\0'; i++)
		a[i] = '\0';
}

int check(char* a) {
	char tmp[51] = { 0 };
	int idx_t = -1;
	if (strlen(a) <= 1) return 0; //2 �̸��̸� ���� ������
	for (int i = 0; a[i] != '\0'; i++) {
		if (a[i] == '(') {
			tmp[++idx_t] = a[i]; //push ����
		}
		else {
			if (idx_t == -1) return 0; //��ȣ �̼���
			idx_t--; //pop ����
		}
	}
	if (idx_t == -1) return 1; //������ ����� => ��ȣ ��� ����
	else return 0; //������ ������� ���� => ��ȣ�� ��� �������� ����
}

int main() {
	char arr[51] = { 0 };
	int t = 0;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		cls(arr);
		scanf("%s", arr);
		printf("%s", check(arr) == 1 ? "YES\n" : "NO\n");
	}

	return 0;
}