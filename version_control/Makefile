MAJOR=1
MINOR=0
BUILD=$(shell cat version.build)
DEFINES=-DMAJOR=$(MAJOR) -DMINOR=$(MINOR) -DBUILD=$(BUILD) -DDEBUG

all:
	gcc version.c -o test $(DEFINES)
	@echo $$(($(BUILD)+1)) > version.build

clean:
	rm test
