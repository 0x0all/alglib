SHELL = /bin/sh
CXX = g++
CXXFLAGS = -g

GRAPH_SRC = graph.cpp Graphs.cpp
GRAPH_OBJ = graph.o Graphs.o
LIARLIAR_SRC = liarliar.cpp graph.cpp
LIARLIAR_OBJ = liarliar.o graph.o

all:	liarliar testgraph

liarliar: $(LIARLIAR_OBJ)
	$(CXX) -o $@ $(LIARLIAR_OBJ)

testgraph: $(GRAPH_OBJ)
	$(CXX) -o $@ $(GRAPH_OBJ)

clean:
	rm -f *.o
	rm -f liarliar
	rm -f testgraph