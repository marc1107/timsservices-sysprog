# Makefile 

# Kommando-Variablen
CC = gcc 
CFLAGS = -W -Wall -std=c11 -pedantic 
RM = rm -f

# Hilfsvariablen
BOTH = filecopy filesize 
SOURCES_COPY = filecopy.c
SOURCES_SIZE = filesize.c

# Standardziele
.PHONY: all clean

all: $(BOTH) 

clean:
	$(RM) $(BOTH)

# Ziele zur Programmerstellung
filecopy:
	$(CC) $(SOURCES_COPY) $(CFLAGS) -o $@

filesize:
	$(CC) $(SOURCES_SIZE)  $(CFLAGS) -o $@

