OBJ = main.o converter.o parser.o

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src

all: $(BIN_DIR)/unit

$(BIN_DIR)/unit: obj/converter.o obj/main.o obj/parser.o
	gcc -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc -Wall -o $@ -c $<

clean: 
	rm $(BIN_DIR/)unit $(OBJ_DIR)/converter.o $(OBJ_DIR)/main.o $(OBJ_DIR)/parser.o