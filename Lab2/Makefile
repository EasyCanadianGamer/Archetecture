CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-Wall -g
LDFLAGS=-g
LDLIBS=

SRCS=lab2.c
OBJS=$(subst .c,.o,$(SRCS))

all: lab2

lab2: $(OBJS)
	$(CC) $(LDFLAGS) -o lab2 $(OBJS) $(LDLIBS)

lab2.o: lab2.c

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) lab2