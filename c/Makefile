CC=gcc

SRC=$(wildcard ./src/*.c)

OBJ=$(subst src,obj,$(subst .c,.o,$(SRC)))

INCLUDE=include

BIN=main.exe

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN) -I $(INCLUDE)

./obj/%.o: ./src/%.c
	$(CC) -c $< -o $@ -I $(INCLUDE)

./obj/main.o: ./src/main.c
	$(CC) -c $< -o $@ -I $(INCLUDE)

init:
	$(CC) -v
	if not exist obj ( mkdir obj )
	if not exist $(INCLUDE) ( mkdir $(INCLUDE) )

clean:
	rm -f ./obj/*.o $(BIN)