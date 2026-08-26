## -------------------------------------------------------------------------
## @author Leonardo Florez-Valencia (florez-l@javeriana.edu.co)
## -------------------------------------------------------------------------

CC := g++
CFLAGS := -std=c++23 -Wall
LDLAGS := -lGL -lglut

all: ClockGLApp

ClockGLApp: main.o App.o Body.o Callbacks.o Circle.o Clock.o Hand.o Object.o Square.o Triangle.o World.o Hexagon.o
	$(CC) main.o App.o Body.o Callbacks.o Circle.o Clock.o Hand.o Object.o Square.o Triangle.o World.o Hexagon.o $(LDLAGS) -o ClockGLApp

main.o: main.cxx
	$(CC) $(CFLAGS) -c main.cxx

Clock.o: Clock.cxx Clock.h
	$(CC) $(CFLAGS) -c Clock.cxx

Object.o: Object.cxx Object.h
	$(CC) $(CFLAGS) -c Object.cxx

World.o: World.cxx World.h Object.h
	$(CC) $(CFLAGS) -c World.cxx

App.o: App.cxx App.h World.h
	$(CC) $(CFLAGS) -c App.cxx

Callbacks.o: Callbacks.cxx Callbacks.h App.h
	$(CC) $(CFLAGS) -c Callbacks.cxx

Circle.o: Circle.cxx Circle.h Object.h
	$(CC) $(CFLAGS) -c Circle.cxx

Square.o: Square.cxx Square.h Object.h
	$(CC) $(CFLAGS) -c Square.cxx

Body.o: Body.cxx Body.h Circle.h
	$(CC) $(CFLAGS) -c Body.cxx

Hand.o: Hand.cxx Hand.h Square.h
	$(CC) $(CFLAGS) -c Hand.cxx

Triangle.o: Triangle.cxx Triangle.h Circle.h Body.h
	$(CC) $(CFLAGS) -c Triangle.cxx

Hexagon.o: Hexagon.cxx Hexagon.h Circle.h Body.h
	$(CC) $(CFLAGS) -c Hexagon.cxx

clean:
	rm -rf *.o ClockGLApp

## eof - Makefile
