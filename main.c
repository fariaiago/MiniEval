#include "operation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum_op(int a, int b)
{
	return a + b;
}

int sub_op(int a, int b)
{
	return a - b;
}

void generic_op(struct Operation *op, int *a, int *b, char num[32])
{
	if(*a == 0)
		*a = atoi(num);
	else
	{
		*b = atoi(num);
		*a = op->do_op(*a, *b);
		printf("%d\n", *a);
	}
	memset(num, 0, strlen(num));
}

int main(void)
{
	struct Operation sum = { .do_op = &sum_op }, sub = { .do_op = &sub_op }, op;
	int a = 0, b = 0, num_tmh = 0;
	char c, num[32];
	while (scanf("%c", &c) == 1)
	{
		switch (c)
		{
		case '+':
			generic_op(&op, &a, &b, num);
			op = sum;
			num_tmh = 0;
			break;
		case '-':
			generic_op(&op, &a, &b, num);
			num_tmh = 0;
			op = sub;
			break;
		default:
			num[num_tmh] = c;
			num_tmh++;
			break;
		}
	}
	generic_op(&op, &a, &b, num);
	return 0;
}