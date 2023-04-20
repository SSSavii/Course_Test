#include <stdio.h>
int main() {
	int n;
	int stack[100000];
	scanf("%d", &n);
	while (n--)
	{
		int k, i, head = 0, tail = 0;
		double priority, lastPriority = -1;
		scanf("%d", &k);
		for (i = 0; i < k; i++)
		{
			scanf("%lf", &priority);
			if (priority >= lastPriority)
			{
				// ���������� ��� ���������� �� ������ � ��� �
				while (tail > 0 && priority >= lastPriority)
				{
					tail--;
					lastPriority = tail > 0 ? stack[tail - 1] : -1;
				}
				lastPriority = priority;
			}
			else
			{
				// �������� ��������� � �����
				stack[tail++] = priority;
			}
		}
		// ���������, ��� � ������ ��� ���������� ����������� �� �������� ������� ���������
		int sorted = 1;
		for (i = 1; i < tail; i++) {
			if (stack[i] > stack[i - 1]) {
				sorted = 0;
				break;
			}
		}
		printf("%d\n", sorted);
	}
	return 0;
}