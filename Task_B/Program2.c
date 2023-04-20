#include <stdio.h>
int main() {
    int n, count = 1, top = -1;
    scanf("%d", &n);
    if (n < 1 || n>100)
    {
        printf("value input error");
        return -1;
    }
    int train[n]; //array for storing wagons (dead end)
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &train[i]);
        if (train[i]<1 || train[i]>n)
        {
            printf("wrong wagon number");
            return -1;
        }
        for (int j = i - 1; j > 0; j--)
        {
            if (train[i] == train[j])
            {
                printf("repeated wagon number");
                return -1;
            }
        }
    }
    int stack[n];
    for (int i = 0; i < n; i++)
    {
        if (train[i] == count)
        { // search for a wagon in a dead end
            count++;
            while (top >= 0 && stack[top] == count)
            {
                top--;
                count++;
            }
        }
        else if (top >= 0 && stack[top] == count)
        {
            top--;
            count++;
            i--;
        }
        else
        {
            top++;
            stack[top] = train[i];
        }
    }
    // checking wagons in the stack
    while (top >= 0 && stack[top] == count)
    {
        top--;
        count++;
    }
    // if the final number is equal to the number of wagons
    if (count == n + 1) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
    return 0;
}