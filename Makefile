OBJ = src/main.o

OBJ_DIR = obj
SRC_DIR = src

all: main

main: $(OBJ_DIR)/$(OBJ)
    gcc -o unit $^

$(SRC_DIR)/%.o: src/%.c
    gcc -Wall -o $@ $<

clean: $(OBJ_DIR)/$(OBJ)
    rm unit $^