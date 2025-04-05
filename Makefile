CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude/

SRCS = $(wildcard src/*/*.c) src/main.c
OBJS = $(SRCS:.c=.o)
TARGET = gerardosh

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean