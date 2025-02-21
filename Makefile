# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c99 -Iinclude

# Linker flags (for GMP)
LDFLAGS = -lgmp

# Target executable
TARGET = hello_world

# Source directory
SRCDIR = src

# Source files
SRCS = $(SRCDIR)/main.c $(SRCDIR)/hello_world.c

# Object files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)  # <-- TAB, not spaces

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@  # <-- TAB, not spaces

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)  # <-- TAB, not spaces

# Phony targets (not actual files)
.PHONY: all clean
