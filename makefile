IDIR =/include
CC=g++
CFLAGS=-I$(IDIR)

ODIR=/src

LIBS=-lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

_DEPS = *.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = *.cpp
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

EscapeIsland: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
