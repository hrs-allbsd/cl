#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cl.h"
#include "cl_cal.h"

#define	STACK_MAXLEN	1024
#ifdef DEBUG
#define	DEBUG_PRINT(a, b, op) \
	do { \
		printf("(%ld " #op " %ld) -> %ld\n", a, b, a op b);	\
	} while (0)
#else
#define	DEBUG_PRINT(a, b, op)
#endif

long
cal(int argc, char *argv[], int *status)
{
	long st[STACK_MAXLEN];
	long tok;
	char *ep;
	int i, pos;

	memset(st, 0, sizeof(st));

	pos = 0;
	for (i = 1; i < argc; i++) {
		/* ERR: Stack overflow */
		if (pos == STACK_MAXLEN) {
			*status = STATUS_STACK_OVERFLOW;
			return (0);
		}
		tok = strtol(argv[i], &ep, 10);
		if (ep != NULL && *ep == '\0') {	/* digit */
#ifdef DEBUG
			printf("(%d) Push %ld\n", pos, tok);
#endif
			st[pos++] = tok;
			continue;
		} else {
			if (strlen(argv[i]) != 1) { /* ERR: invalid op */
				*status = STATUS_INVALID_OP;
				return (0);
			}
			if (pos < 1) {		/* ERR: too few params */
				*status = STATUS_STACK_UNDERFLOW;
				return (0);
			}
			switch (argv[i][0]) {
			case '+':
				DEBUG_PRINT(st[pos - 2], st[pos - 1], +);
				st[pos - 2] += st[pos - 1];
				break;
			case '-':
				DEBUG_PRINT(st[pos - 2], st[pos - 1], -);
				st[pos - 2] -= st[pos - 1];
				break;
			case 'x':
				DEBUG_PRINT(st[pos - 2], st[pos - 1], *);
				st[pos - 2] *= st[pos - 1];
				break;
			case '/':
				if (st[pos - 1] == 0) {
						/* ERR: division by zero */
					*status = STATUS_DIV0;
					return (0);
				}
				DEBUG_PRINT(st[pos - 2], st[pos - 1], /);
				st[pos - 2] /= st[pos - 1];
				break;
			default:
						/* ERR: unknown op */
				*status = STATUS_INVALID_OP;
				return (0);
				break;
			}
			pos = pos - 1;
		}
	}
	if (pos != 1) {
		*status = STATUS_STACK_REMAIN;
		return (0);
	}

	*status = STATUS_OK;
	return (st[0]);
}
