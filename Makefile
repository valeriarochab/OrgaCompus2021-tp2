CFLAGS= -mno-mips16 -mgp32 -mfp32 -gpubnames  -mlong32 -mips1 -mabicalls -mlong-calls -mframe-header-opt -march=r2k

OBJS= tp2

all: tp2 tp2_pf

prof: tp2_pf

tp2: main.c addressHelper.c cache.c command.c fileReader.c fileWriter.c mainMemory.c parser.c set.c way.c utils.c stringUtils.c executor.c
	gcc -g $^ -o $@ -lm

tp2_pf: main.c addressHelper.c cache.c command.c fileReader.c fileWriter.c mainMemory.c parser.c set.c way.c utils.c stringUtils.c executor.c
	gcc -no-pie -pg -g $^ -o $@ -lm

clean:
	rm tp2*