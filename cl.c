/*
 * RPN Calculator
 *
 */
#include <stdio.h>
#include "cl.h"
#include "cl_cal.h"

int
main(int argc, char *argv[])
{
	int result;
	int status;

	result = cal(argc, argv, &status);
	if (status == STATUS_OK)
		printf("result = %d\n", result);
	else
		printf("ERR: %d\n", status);

	return (0);
}
