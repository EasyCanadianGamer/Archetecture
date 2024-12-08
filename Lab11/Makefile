CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-Wall -g
LDFLAGS=-g -pthread
LDLIBS=

SRCS=xfer.c
OBJS=$(subst .c,.o,$(SRCS))

all: xfer

xfer: $(OBJS)
	$(CC) $(LDFLAGS) -o xfer $(OBJS) $(LDLIBS)

xfer.o: xfer.c

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) xfer
