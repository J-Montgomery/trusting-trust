#!/usr/bin/env make
#

SHELL= bash
CSILENCE= 
CWARN= 
CSTD= -std=c23
CDEFINE= 
CINCLUDE= 
OPT= -O3 -march=native -mtune=native -g

CFLAGS= ${CSTD} ${CWARN} ${CSILENCE} ${CDEFINE} ${CINCLUDE} ${OPT}
LDFLAGS= 

CC= clang-19
RM= rm

ENTRY= trust
PROG= ${ENTRY}
OBJ= ${PROG}.o
DATA= 
TARGET= ${PROG}

all: data ${TARGET}
	@${TRUE}

.PHONY: all data everything clean clobber

${PROG}: ${PROG}.c
	${CC} ${CFLAGS} $< -o $@ ${LDFLAGS}

data: ${DATA}
	@${TRUE}

everything: all
	@${TRUE}

run: ${TARGET}
	./${TARGET} $@

format:
	clang-format-16 -i ${PROG}.c

clean:
	${RM} -f ${OBJ}

clobber: clean
	${RM} -f ${TARGET}
	${RM} -rf *.dSYM

