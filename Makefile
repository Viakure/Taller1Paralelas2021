CXX=g++
CXXFLAGS=-Wall -g3
LDFLAGS=-lm
OBJETOS=funciones.o

main: main.cpp $(OBJETOS)
	$(CXX) $(CXXFLAGS) -o Taller1 main.cpp $(OBJETOS) $(LDFLAGS)

funciones.o: funciones.h funciones.cpp
	$(CXX) $(CXXFLAGS) -c funciones.cpp

.PHONY: clean
clean:
	rm -fr *.o Taller1
