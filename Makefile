CC=g++
CFLAGS=-c -I include 
LFLAGS=-lncurses
PROGRAM_NAME=console-graphics

SRC_FILES=$(wildcard src/*.cpp)
OBJ_FILES=$(patsubst src/%.cpp,%.o,$(SRC_FILES))
BDIR=build
BDIR_OBJ=$(patsubst %,$(BDIR)/%,$(OBJ_FILES))

all: $(BDIR_OBJ)
	$(CC) $(LFLAGS) $^ -o $(PROGRAM_NAME)

$(BDIR_OBJ): $(SRC_FILES) $(BDIR)
	$(CC) $(CFLAGS) $(SRC_FILES)
	mv *.o $(BDIR) # BAAAAAD!!!

$(BDIR):
	mkdir $(BDIR)

.PHONY: install clean clear

install:
	echo "Not implemented yet"

clean:
	rm -rf $(BDIR)

clear: clean
	rm -f $(PROGRAM_NAME)

# Define a pattern rule that compiles every .c file into a .o file
#%.o : %.c
#		$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@
