#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char Str[100000];
    char last_open = ' ';
    int n, N;
    scanf("%d", &N);
    getchar();
    gets(Str);
    n = strlen(Str);
    if (N > 100000 || N < 1)
    {
        printf("The entered number does not fall within the specified boundaries(1<=N<=100000)");
        return -1;
    }
    if (n != N)
    {
        printf("The entered number differs from the number of brackets");
        return -1;
    }
    int round = 0, figured = 0, squred = 0;
    for (int i = 0; i < n; i++)
    {
        if (Str[i] == '(')
            round++;
        if (Str[i] == ')')
            round--;
        if (Str[i] == '{')
            figured++;
        if (Str[i] == '}')
            figured--;
        if (Str[i] == '[')
            squred++;
        if (Str[i] == ']')
            squred--;

        if (Str[i] == '(' || Str[i] == '{' || Str[i] == '[')
        {
            last_open = Str[i];
        }
        if (Str[i] != '(' && Str[i] != ')' && Str[i] != '{' && Str[i] != '}' && Str[i] != '[' && Str[i] != ']')
        {
            printf("an invalid element is present in the entered line");
            return -1;
        }
        if ((Str[i] == ')' && last_open != '(') || (Str[i] == '}' && last_open != '{') || (Str[i] == ']' && last_open != '['))
            break;
    }
    if (round || figured || squred)
        printf("NO");
    else
        printf("Yes");
    return 0;
}