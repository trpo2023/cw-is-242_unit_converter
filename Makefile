OBJ = main.o converter.o

OBJ_DIR = obj
SRC_DIR = src

all: unit

unit: obj/converter.o obj/main.o
	gcc -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc -Wall -o $@ -c $<

clean: $(OBJ_DIR)/*.o
	rm unit $^