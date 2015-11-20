
SRCS    = $(wildcard *.c)
CFLAGS  = `sdl2-config --cflags`
LIBS    = `sdl2-config --libs`

.PHONY: all

all: $(patsubst %.c,../%,$(SRCS))
	@echo found rules for: $^

../%: %.c
	gcc $(CFLAGS) $< $(LIBS) -lm -o $@
	@echo rules: $@

clean: $(patsubst %.c,../%,$(SRCS))
	rm $(patsubst %.c,../%,$(SRCS))

