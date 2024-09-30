# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror

# Source and object files
SRC = linked_lists/singly/insertion.c
OBJ = insertion.o

# Target executable
TARGET = insertion

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