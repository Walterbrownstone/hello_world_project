# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c99 -Iinclude
OPTFLAGS = -O3

# Linker flags (for GMP)
LDFLAGS = -lgmp

# Programs to build
PROGRAMS = hello_world pfield

# Source directory
SRCDIR = src

# Source files for each program
HELLO_SRCS = $(SRCDIR)/main.c $(SRCDIR)/hello_world.c
PFIELD_SRCS = $(SRCDIR)/pfield.c

# Object files
HELLO_OBJS = $(HELLO_SRCS:.c=.o)
PFIELD_OBJS = $(PFIELD_SRCS:.c=.o)

# Default target - builds all programs
all: $(PROGRAMS)

# Hello World program
hello_world: $(HELLO_OBJS)
	$(CC) $(CFLAGS) -o $@ $(HELLO_OBJS) $(LDFLAGS)  # Added $(LDFLAGS) here

# Prime Field program
pfield: $(PFIELD_OBJS)
	$(CC) $(CFLAGS) $(OPTFLAGS) -o $@ $(PFIELD_OBJS) $(LDFLAGS)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(HELLO_OBJS) $(PFIELD_OBJS) $(PROGRAMS)

# Phony targets (not actual files)
.PHONY: all clean
