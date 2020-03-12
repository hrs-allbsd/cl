#define	STATUS_OK		1
#define	STATUS_INVALID_OP	2
#define	STATUS_STACK_UNDERFLOW	3
#define	STATUS_STACK_OVERFLOW	4
#define	STATUS_DIV0		5
#define	STATUS_STACK_REMAIN	6

#define	CASE_ERR(x)	case x: return(#x); break

static inline const char *
str_status_err(int code)
{
	switch (code) {
	CASE_ERR(STATUS_OK);
	CASE_ERR(STATUS_INVALID_OP);
	CASE_ERR(STATUS_STACK_UNDERFLOW);
	CASE_ERR(STATUS_STACK_OVERFLOW);
	CASE_ERR(STATUS_DIV0);
	CASE_ERR(STATUS_STACK_REMAIN);
	}

	return (NULL);
}
