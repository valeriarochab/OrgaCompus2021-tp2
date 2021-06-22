CFLAGS= -mno-mips16 -mgp32 -mfp32 -gpubnames  -mlong32 -mips1 -mabicalls -mlong-calls -mframe-header-opt -march=r2k

OBJS= tp2

all: tp2

tp2: main.c addressHelper.c cache.c command.c fileReader.c fileWriter.c mainMemory.c parser.c set.c way.c utils.c stringUtils.c executor.c
	gcc -g $^ -o $@ -lm

run_tests: tp2
	./tests/tests.sh


clean:
	rm tp2*