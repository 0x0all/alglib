SHELL = /bin/sh
CXX = g++
CXXFLAGS = -g

.SUFFIXES:
.SUFFIXES: .c .cpp .o

all: testgraph testliar

testgraph: graph.o
	$(CXX) -o $@ $<

graph.o: graph.h graph.cpp

testliar: liarliar.o
	$(CXX) -o $@ $<

liarliar.o: liarliar.h liarliar.cpp

.PHONY: clean
clean:
	rm testgraph testliar
