#include <stdio.h>
#include "cl_cal.h"

int
main(int argc, char *argv[])
{
	int result;

	result = cal(argc, argv);
	printf("result = %d\n", result);

	return (0);
}
