CC = gcc
CFLAGS = -Wall -Wextra -pedantic -ggdb
LIBS = ncurses

BIN_DIR = ./bin
OUT = woeusb_installer
SOURCES = $(wildcard src/*.c) $(wildcard include/*.h)

$(OUT):
	mkdir $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$(OUT) $(SOURCES) -l $(LIBS)

clean:
	rm -r $(BIN_DIR)
