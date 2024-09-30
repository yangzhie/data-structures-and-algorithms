CFLAGS = -Wall -g

# Rule to build the executable "main" from linked_list.c
# - The $@ is the target (main), and $^ is the dependencies (linked_list.o)
main: linked_lists.o
	gcc $(CFLAGS) -o $@ $^

# Rule to build the object file linked_list.o from linked_list.c
# - This compiles the .c file into an object file
linked_list.o: linked_lists.c
	gcc $(CFLAGS) -c $<

# Clean rule to remove generated files
clean:
	rm -f arrays linked_lists main linked_lists.o