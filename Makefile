CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS =
SRCS = $(wildcard src/*.c)
HDRS = $(wildcard src/*.h)
OBJS = $(patsubst %.c, %.o, $(SRCS))
EXECUTABLE = chess

all: $(EXECUTABLE)

%.o: %.c $(HDRS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXECUTABLE): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f src/*.o
	rm -f $(EXECUTABLE)
