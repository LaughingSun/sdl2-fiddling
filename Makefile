
TARGETS := $(shell ./show-targets.sh)
SUBDIRS := $(subst -,/,$(TARGETS))
APPS    = $(TARGETS)

.PHONY: all

all: $(TARGETS)
	@echo targets: $(TARGETS)
	@echo subdirs: $(SUBDIRS)

$(TARGETS):
	$(MAKE) -C $(subst -,/,src/$@)
	cp $(subst -,/,src/$@.a) $@

clean:
	rm $(TARGETS)
	for dir in $(SUBDIRS); do \
	$(MAKE) -C src/$$dir $@; \
	done

