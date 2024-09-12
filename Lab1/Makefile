CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-Wall -g
LDFLAGS=-g
LDLIBS=

SRCS=readfile.c sorter.c
OBJS=$(subst .c,.o,$(SRCS))

all: sorter

sorter: $(OBJS)
	$(CC) $(LDFLAGS) -o sorter $(OBJS) $(LDLIBS)

readfile.o: readfile.c readfile.h
sorter.o: sorter.c

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) sorter