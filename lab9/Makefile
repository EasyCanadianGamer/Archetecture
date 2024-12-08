CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-Wall -g
LDFLAGS=-g
LDLIBS=

SRCS=nash.c
OBJS=$(subst .c,.o,$(SRCS))

all: nash

nash: $(OBJS)
	$(CC) $(LDFLAGS) -o nash $(OBJS) $(LDLIBS)

nash.o: nash.c

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) nash
