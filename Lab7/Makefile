CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-Wall -g
LDFLAGS=-g
LDLIBS=

SRCS=lab7.c
OBJS=$(subst .c,.o,$(SRCS))

all: lab7

lab7: $(OBJS)
	$(CC) $(LDFLAGS) -o lab7 $(OBJS) $(LDLIBS)

lab7.o: lab7.c

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) lab7