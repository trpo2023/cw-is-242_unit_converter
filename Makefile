OBJ = main.o converter.o parser.o

OBJ_DIR = obj
SRC_DIR = src

all: unit

unit: obj/converter.o obj/main.o obj/parser.o
	gcc -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc -Wall -o $@ -c $<

clean: 
	rm unit obj/converter.o obj/main.o obj/parser.o