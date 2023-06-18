#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>

typedef struct rule
{
	int command;
	int state;
	int cancel;
}rule;

rule add_Cancel(int cancel)
{
	rule result;
	result.command = 1;
	result.state = 1;
	result.cancel = cancel;
	return result;
}

rule add_Declare()
{
	rule result;
	result.command = 0;
	result.state = 1;
	return result;
}

void main()
{
	int n, m, d = 0;
	char command[8];
	scanf("%d", &n);

	rule* array;
	array = (rule*)malloc(n * sizeof(rule));
	int* result;
	result = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) result[i] = 1;

	for (int i = 0; i < n; i++)
	{
		scanf("%s", &command);
		if (command[0] == 'c')
		{
			scanf("%d", &m);
			array[i] = add_Cancel(m - 1);
		}
		else array[i] = add_Declare();
	}

	for (int i = n - 1; i >= 0; i--)
	{
		if (array[i].command && array[i].state)
		{
			result[array[i].cancel] = 0;
			array[array[i].cancel].state = 0;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (result[i])
		{
			d++;
		}
	}
	printf("%d\n", d);
	for (int i = 0; i < n; i++)
	{
		if (result[i])
		{
			printf("%d ", i + 1);
		}
	}

}
