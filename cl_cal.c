#include <stdio.h>
#include "cl_cal.h"

int
cal(int argc, char *argv[])
{
	int i;

	for (i = 1; i < argc; i++)
		printf("%s\n", argv[i]);
	
#if 0
	long tok;
	char *ep;
	int 

	tok = strtol(argv[i], NULL, 10);
	if (ep != NULL) {	/* digit */
	} else {
		switch (argv[i][0]) {
		case '+':
		case '-':
		case 'x':
		case '/':
		default:
			return (-1);
		}
	}
#endif

	return (0);
}
