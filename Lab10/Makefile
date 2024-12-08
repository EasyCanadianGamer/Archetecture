CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-Wall -g
LDFLAGS=-g -pthread
LDLIBS=

SRCS=threads.c
OBJS=$(subst .c,.o,$(SRCS))

all: threads

threads: $(OBJS)
	$(CC) $(LDFLAGS) -o threads $(OBJS) $(LDLIBS)

threads.o: threads.c

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) threads
