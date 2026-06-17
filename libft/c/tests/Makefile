# compiler
CC = gcc
# compilation flags
CFLAGS = -I../src -Wall -Wextra -Werror -Wno-unused-variable
# linkage flags:
# * `-L../src` -> add the path where to search files for linkage;
# * `-lft` -> link the library ft which will be prepended with the "lib" prefix, so `libft.a` or `libft.so` will be looked for.
LDFLAGS = -L../src -lcheck -lcheck_pic -lm -lsubunit -lft

# target executable name
TARGET = tests

# all C files are included
SOURCES = $(wildcard *.c)

# object files (replace .c with .o)
OBJECTS = $(SOURCES:.c=.o)

.PHONY: test clean rebuild re

# test target - goes first, therefore, the default when `make` is run
test: $(TARGET)
	./$(TARGET)

# $@ - target executable name, $^ - all dependencies
$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS)

# compilation rule: each .c file is compiled into .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# clean target
clean:
	rm -f $(OBJECTS) $(TARGET)

# rebuild the target
rebuild: clean $(TARGET)

# retest: rebuild and run tests
re: rebuild test
