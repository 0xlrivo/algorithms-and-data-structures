CC = gcc
CFLAGS = -Wall

SRC = src
OBJ = obj
BIN = main
MKDIR = mkdir -p
SRCs := $(shell find $(SRC) -name "*.c")
OBJs := $(subst $(SRC), $(OBJ), $(SRCs:.c=.o))

all: $(BIN)

$(BIN): $(OBJs)
	$(CC) $(CFLAGS) $(OBJs) -o $@

$(OBJs): $(SRCs)
	$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) -c $(subst $(OBJ), $(SRC), $(@:.o=.c)) -o $@

clean:
	$(RM) -R $(BIN)
	$(RM) -R $(OBJ)
