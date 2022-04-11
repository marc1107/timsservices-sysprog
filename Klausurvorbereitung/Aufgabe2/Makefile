#Makefile

#Kommando-Variablen
TAR = tar
FLAGS = -czf 
RM = rm -rf

#Hilfsvariablen
TARGET = aufgabe1.tar.gz
TARGETFILES = ../Aufgabe1/*.c

#Standardziele
.PHONY: all clean

all: $(TARGET)

clean:
	$(RM) $(TARGET)

#Ziele zur Programmerstellung
$(TARGET):
	$(TAR) $(FLAGS) $(TARGET) $(TARGETFILES)
