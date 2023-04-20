#include <stdio.h>
int main() {
    int n, count = 1, top = -1;
    scanf("%d", &n);
    int train[n]; //array for storing wagons (dead end)
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &train[i]);
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