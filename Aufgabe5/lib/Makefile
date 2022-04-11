# Makefile 

# Kommando-Variablen
CC = gcc 
CFLAGS = -W -Wall -std=c11 -pedantic 
CPPFLAGS = -I. 
RM = rm -f
LIBTYPE = a
LIBNAME = aufgabe5
LIBA = ar rs
LIBSO = -shared

# Hilfsvariablen
TARGET = lib$(LIBNAME).$(LIBTYPE) 
OBJECTS = fachnote.o liste.o
SOURCES = $(OBJECTS:.o=.c)
HEADERS = $(OBJECTS:.o=.h)

# Standardziele
.PHONY: all clean

all: $(TARGET) 

clean:
	$(RM) lib$(LIBNAME).so lib$(LIBNAME).a $(TARGET).o $(OBJECTS) depend

# Musterregeln
%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
	
depend: $(SOURCES) $(HEADERS)
	$(CC) $(CPPFLAGS) -MM $(SOURCES) > $@

# Ziele zur Programmerstellung
$(TARGET:.$(LIBTYPE)=.a): $(OBJECTS)
	$(LIBA) $@ $^
	
$(TARGET:.$(LIBTYPE)=.so): $(OBJECTS)
	$(CC) $(LIBSO) $^ -o $@

# Abhaengigkeiten
include depend
