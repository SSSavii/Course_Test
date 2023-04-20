#include <stdio.h>
long long h[1000000];
int i, n, left, right;
long long S, result;
int main()
{
    scanf("%d", &n);
    if (n == NULL || n > 1000000 || n < 1)
    {
        printf("value input error");
        return -1;
    }
    for (i = 1; i <= n; i++)
        scanf("%d", &h[i]);
    if (h[i] == NULL || h[i] < 0)
    {
        printf("value input error");
        return -1;
    }
    result = 0;
    for (i = 1; i <= n; i++)
    {
        left = right = i;
        while (left > 1 && h[left - 1] >= h[i]) left--;
        while (right < n && h[right + 1] >= h[i]) right++;
        S = (right - left + 1) * h[i];
        if (S > result) result = S;
    }
    printf("%lld\n", result);
    return 0;
}
/*i variable for the loop.
n the number of elements.
left right are the boundaries of the area that I work with in the loop

In the loop, I check the area for each i element many times and expand its boundaries,
after which I compare it with the result.*/