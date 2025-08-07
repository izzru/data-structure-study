#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int isVPS(const char* ps)
{
    int count = 0; //입력 받는 수

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

        if (count < 0)  //음수면 NO
        {
            return 0; // NO
        }
    }

    return count == 0;  //count 가 0 이면 YES
}

int main()
{
    int count;
    scanf("%d", &count);

    char ps[51]; // 괄호 문자열은 최대 50자

    for (int i = 0; i < count; i++)
    {
        scanf("%s", ps); // 문자열 입력
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
