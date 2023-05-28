OBJ = main.o converter.o parser.o

APP = unit
BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src

all: $(BIN_DIR)/$(APP)

$(BIN_DIR)/$(APP): $(OBJ_DIR)/converter.o $(OBJ_DIR)/main.o $(OBJ_DIR)/parser.o $(OBJ_DIR)/help.o
	gcc -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc -Wall -o $@ -c $<

clean: 
	rm $(BIN_DIR)/$(APP) $(OBJ_DIR)/converter.o $(OBJ_DIR)/main.o $(OBJ_DIR)/parser.o $(OBJ_DIR)/help.o
