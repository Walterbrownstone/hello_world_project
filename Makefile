# Compiler
GMP_LIBS = -lgmp
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c99 -Iinclude
OPTFLAGS = -O3

# Linker flags
LDFLAGS = -lgmp

# Directories
BINDIR = bin
SRCDIR = src

# Programs
PROGRAMS = hello_world pfield

# Source files
HELLO_SRCS = $(SRCDIR)/main.c $(SRCDIR)/hello_world.c
PFIELD_SRCS = $(SRCDIR)/pfield.c

# Object files
HELLO_OBJS = $(HELLO_SRCS:.c=.o)
PFIELD_OBJS = $(PFIELD_SRCS:.c=.o)

# Ensure bin directory exists
$(shell mkdir -p $(BINDIR))

# Default target
all: $(PROGRAMS)

# Hello World
hello_world: $(HELLO_OBJS)
	$(CC) $(CFLAGS) -o $(BINDIR)/$@ $(HELLO_OBJS) $(LDFLAGS)

# Prime Field
pfield: $(PFIELD_OBJS)
	$(CC) $(CFLAGS) $(OPTFLAGS) -o $(BINDIR)/$@ $(PFIELD_OBJS) $(GMP_LIBS)


# Compile rule
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(HELLO_OBJS) $(PFIELD_OBJS) $(addprefix $(BINDIR)/,$(PROGRAMS))

.PHONY: all clean
