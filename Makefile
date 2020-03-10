PROG=	cl
OBJS=	cl.o cl_cal.o

all: ${PROG}

.SUFFIXES:
.SUFFIXES: .c .o

.c.o:
	cc -c -o ${.TARGET} ${.IMPSRC}

cl.o: cl_cal.h
cl_cal.o: cl_cal.h

${PROG}: ${OBJS}
	cc -o ${.TARGET} ${.ALLSRC}

clean:
	rm -f ${PROG} ${OBJS}
install:
	cp ${PROG} /usr/local/bin
test:
	./${PROG} 1 2 3 4 5 + + +
