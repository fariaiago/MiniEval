#ifndef OPERATION_H
#define OPERATION_H

typedef enum
{
	OperationTypeSum,
	OperationTypeSubtraction
} OperationType;

struct Operation
{
	OperationType type;
	int (*do_op)(int, int);
};

#endif