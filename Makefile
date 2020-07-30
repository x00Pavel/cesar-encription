CFLAGS= -Wall -Wextra -Wpedantic
MAIN=main

make:
	gcc ${CFLAGS} ${MAIN}.c -o ${MAIN}

run:
	./${MAIN}
