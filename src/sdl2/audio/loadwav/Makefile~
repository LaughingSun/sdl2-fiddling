 
CC      = gcc
SRCS    = $(wildcard *.c)
TARGET  = ../$(notdir $(CURDIR)).a
CFLAGS  = `sdl2-config --cflags`
LIBS    = `sdl2-config --libs`

.PHONY: all

all: $(TARGET)
	

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $< $(LIBS) -lm -o $(TARGET)

clean: $(patsubst %.c,../%,$(SRCS))
	rm $(TARGET)

