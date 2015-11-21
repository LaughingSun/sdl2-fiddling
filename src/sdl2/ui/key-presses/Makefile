 
CC      = gcc
SRCS    = $(wildcard *.c)
TARGET  = ../$(notdir $(CURDIR)).a
CFLAGS  = `sdl2-config --cflags` -I../common
LIBS    = `sdl2-config --libs` -L../common

.PHONY: all

all: $(TARGET)
	

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $< $(LIBS) -lm -o $(TARGET)

clean: $(patsubst %.c,../%,$(SRCS))
	rm $(TARGET)

