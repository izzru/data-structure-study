#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int isVPS(const char* ps)
{
    int count = 0; //�Է� �޴� ��

    for (int i = 0; ps[i] != '\0'; i++)
    {
        if (ps[i] == '(')
        {
            count++;
        }
        else if (ps[i] == ')')
        {
            count--;
        }

        if (count < 0)  //������ NO
        {
            return 0; // NO
        }
    }

    return count == 0;  //count �� 0 �̸� YES
}

int main()
{
    int count;
    scanf("%d", &count);

    char ps[51]; // ��ȣ ���ڿ��� �ִ� 50��

    for (int i = 0; i < count; i++)
    {
        scanf("%s", ps); // ���ڿ� �Է�
        if (isVPS(ps))
        {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }

    return 0;
}
