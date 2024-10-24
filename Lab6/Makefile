CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-Wall -g
LDFLAGS=-g
LDLIBS=

SRCS=my_strings.c stringtester.c
OBJS=$(subst .c,.o,$(SRCS))

all: stringtester

my_strings: $(OBJS)
	$(CC) -c $(OBJS)

stringtester: $(OBJS)
	$(CC) $(LDFLAGS) -o stringtester $(OBJS) $(LDLIBS)

my_strings.o: my_strings.c my_strings.h

stringtester.o: stringtester.c

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) stringtester