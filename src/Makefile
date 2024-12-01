CC=g++
CFLAGS=-Wall -Wextra
LIBS=-lraylib -lm
DEPS=algorithms.hxx

all: main.o algorithms.o $(DEPS)
	$(CC) $(CFLAGS) $(LIBS) $^ -o out

%.o: %.cxx Makefile
	$(CC) $(CFLAGS) -c $< -o $@
