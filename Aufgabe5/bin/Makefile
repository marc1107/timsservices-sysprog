# Makefile 

# Kommando-Variablen
CC = gcc 
CFLAGS = -W -Wall -std=c11 -pedantic 
CPPFLAGS = -I. 
LDFLAGS = -L
RM = rm -f

# Hilfsvariablen
TARGET = notenspiegel 
OBJECTS = notenspiegel.o 
SOURCES = $(OBJECTS:.o=.c)
HEADERS = $(OBJECTS:.o=.h)
LIBDIR =../lib
LIB = aufgabe5
# Standardziele
.PHONY: all clean

all: $(TARGET) 

clean:
	$(RM) $(TARGET) $(OBJECTS) depend

# Musterregeln
%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
	
# Ziele zur Programmerstellung
$(TARGET): $(OBJECTS)
	$(CC) $^ $(LDFLAGS) $(LIBDIR) -l $(LIB) -o $@

