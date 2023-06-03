CC = gcc
CFLAGS = -Wall -Werror
CPPFLAGS = -MMD
SrcDir = src
BinDir = bin
ObjDir = obj
Test_name = unit-test	


LibTarget = $(ObjDir)/lib/libgeometry.a
Target = $(BinDir)/unit
LibTestDir = tests
TestTarget = $(BinDir)/$(Test_name)

all: $(Target)

$(Target): $(ObjDir)/main.o $(LibTarget)
	$(CC) $(CFLAGS) -o $@ $^ -lm

$(LibTarget): $(ObjDir)/parser.o $(ObjDir)/convert.o $(ObjDir)/help.o
	ar rcs $@ $^

$(ObjDir)/main.o: $(SrcDir)/main.c
	$(CC) -c $(CFLAGS) $< $(CPPFLAGS) -o $@ -I $(SrcDir)

$(ObjDir)/help.o: $(SrcDir)/help.c
	$(CC) -c $(CFLAGS) $< $(CPPFLAGS) -o $@ -I $(SrcDir)

$(ObjDir)/convert.o: $(SrcDir)/converter.c
	$(CC) -c $(CFLAGS) $< $(CPPFLAGS) -o $@ -I $(SrcDir)

$(ObjDir)/parser.o: $(SrcDir)/parser.c
	$(CC) -c $(CFLAGS) $< $(CPPFLAGS) -o $@ -I $(SrcDir)

.PHONY: clean

run:
	./$(Target)

test: $(TestTarget)
	$(BinDir)/$(Test_name)

$(TestTarget): $(ObjDir)/tests/main.o $(ObjDir)/tests/test.o
	$(CC) -I $(SrcDir) -I $(LibTestDir) $^ $(LibTarget) -o $(BinDir)/$(Test_name) -lm

$(ObjDir)/tests/main.o: test/main.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -I $(LibTestDir) -c $< -o $@

$(ObjDir)/tests/test.o: test/test.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -I $(SrcDir) -I $(LibTestDir) -c $< -o $@

clean:
	rm -rf $(ObjDir)/*.o $(ObjDir)/*.o $(Target)
	rm -rf $(ObjDir)/*.d $(ObjDir)/*.d
	rm -rf $(LibTarget)
	rm -rf $(ObjDir)/test/*.o $(ObjDir)/test/*.d
	rm -rf $(BinDir)/$(Test_name)
	rm -rf $(ObjDir)/tests/*.d
	rm -rf $(ObjDir)/tests/*.o

-include $(ObjDir)/%.d