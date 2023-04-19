#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int N;
    char Str[100000];
    char last_open = ' ';
    scanf("%d", &N);
    gets(Str);
    int round = 0, figured = 0, squred = 0;
    for (int i = 0; i < N; i++)
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
        if ((Str[i] == ')' && last_open != '(') || (Str[i] == '}' && last_open != '{') || (Str[i] == ']' && last_open != '['))
            break;
    }
    if (round || figured || squred)
        return false;
    else
        return true;
    return 0;
}