SHELL = /bin/sh
CXX = g++
CC = gcc
CXXFLAGS = -g

OBJS := test_graph.o

%.o: %.cc
	$(CXX) -c $(CXXFLAGS) $*.cc -o $*.o
	$(CXX) -MM $(CXXFLAGS) $*.cc > $*.d
	@cp -f $*.d $*.d.tmp
	@sed -e 's/.*://' -e 's/\\$$//' < $*.d.tmp | fmt -1 | \
	 sed -e 's/^ *//' -e 's/$$/:/' >> $*.d
	@rm -f $*.d.tmp

# this line tells make to suspend reading current Makefile
# but read (include
-include $(OBJS:.o=.d)

all: test_graph

test_graph: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

clean:
	@rm -f *.o
	@rm -f testgraph
	@rm -f *.d
	@rm -f a.out
