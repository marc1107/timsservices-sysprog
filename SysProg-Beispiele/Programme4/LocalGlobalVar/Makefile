#
# Makefile
#
# Erzeugt separate Dateien mit Praeprozessor-Ausgaben.
#
# Autor: H.Drachenfels
# Erstellt am: 10.11.2017
#

FLAGS = -g -W -Wall --std=c11 -pedantic

PREPROCESSOR = gcc -E
COMPILER = gcc -c
LINKER = gcc

OBJECTS = \
  localglobalvar.o \
  function.o \
  global.o


all: localglobalvar

clean:
	rm -f localglobalvar $(OBJECTS) $(OBJECTS:.o=.i)

localglobalvar: $(OBJECTS)
	$(LINKER) $(FLAGS) -o localglobalvar $(OBJECTS)

localglobalvar.o: localglobalvar.i
	$(COMPILER) $(FLAGS) localglobalvar.i

function.o: function.i
	$(COMPILER) $(FLAGS) function.i

global.o: global.i
	$(COMPILER) $(FLAGS) global.i


localglobalvar.i: localglobalvar.c function.h global.h
	$(PREPROCESSOR) $(FLAGS) localglobalvar.c -o localglobalvar.i

function.i: function.c function.h global.h
	$(PREPROCESSOR) $(FLAGS) function.c -o function.i

global.i: global.c global.h
	$(PREPROCESSOR) $(FLAGS) global.c -o global.i

