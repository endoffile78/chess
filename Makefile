CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lncurses
SRCS = $(wildcard src/*.c)
HDRS = $(wildcard src/*.h)
OBJS = $(patsubst %.c, %.o, $(SRCS))
EXECUTABLE = chess

all: $(EXECUTABLE)

%.o: %.c $(HDRS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXECUTABLE): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS) $(CFLAGS)

clean:
	rm -f src/*.o
	rm -f $(EXECUTABLE)
