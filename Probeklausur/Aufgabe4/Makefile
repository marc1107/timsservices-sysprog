PDFLATEX = pdflatex
RM = rm –rf
TARGET = hello.pdf

%.pdf: %.tex
	$(PDFLATEX) $<

.PHONY: all clean
all: $(TARGET)

clean:
	$(RM) $(TARGET) $(TARGET:.pdf=.aux) $(TARGET:.pdf=.log)