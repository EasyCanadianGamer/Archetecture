CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-Wall -g
LDFLAGS=-g
LDLIBS=

SRCS=readfile.c stats.c
OBJS=$(subst .c,.o,$(SRCS))

all: stats

stats: $(OBJS)
	$(CC) $(LDFLAGS) -o stats $(OBJS) $(LDLIBS)

readfile.o: readfile.c readfile.h
stats.o: stats.c

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) stats