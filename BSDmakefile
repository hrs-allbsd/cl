PROG=	cl
SRCS=	cl.c cl_cal.c
MK_MAN=	no

install:
	cp ${PROG} /usr/local/bin
test:
	-./${PROG} 1 2 3 4 + 5 + + + x
	-./${PROG} 1 2 3 4 + 5 5 - / + + x
	./${PROG} 1 2 3 4 + 5 6 + + + x

.include <bsd.prog.mk>
