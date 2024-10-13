CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-Wall -g
LDFLAGS=-g
LDLIBS=

SRCS=sum.s prog.c
OBJS=$(subst .c,.o,$(SRCS))

all: prog

prog: $(OBJS)
	$(CC) $(LDFLAGS) -o prog $(OBJS) $(LDLIBS)

sum.o: sum.s
prog.o: prog.c

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) prog
