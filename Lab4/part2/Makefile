CC = gcc
CFLAGS = -g

TARGET = prog

SRCS = proc.c sum.s

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)


clean:
	rm -f $(TARGET)