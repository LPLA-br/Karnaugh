#NOME DO PROJETO
PROJ_NAME=mapas

#COMPILADOR
CC=gcc

#FLAGS
FLAGS= -lm

#FONTES
SRCS= mapas.c

#COMPILAÇÃO FINAL
all: $(OBJS)
	$(CC) $(SRCS) -o $(PROJ_NAME).out $(FLAGS)

clean:
	rm ./${PROJ_NAME}.out

