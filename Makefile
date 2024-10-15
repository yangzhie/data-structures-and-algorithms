# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror

# Source and object files
SRC = stacks/implement_arrays.c
OBJ = implement_arrays.o

# Target executable
TARGET = implement_arrays

# Default target
all: $(TARGET)

# Link the object file to create the executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Compile the source file into an object file
$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

# Clean up object and executable files
clean:
	rm -f $(OBJ) $(TARGET)