CXX = clang++

LD = clang++

OBJS = graph.o airgraph.o Dijkstra.o heap.o



WARNINGS = -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function

CXXFLAGS += $(CS225) -Wno-return-stack-address -std=c++1y -stdlib=libc++ -O0 $(WARNINGS) $(DEPFILE_FLAGS) -g -c

LDFLAGS += $(CS225) -std=c++1y -stdlib=libc++ -lc++abi



all : $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) main.o -o main

test : $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) test.o -o test

test.o : test.cpp
	 $(CXX) $(CXXFLAGS) test.cpp

graph.o : graph.cpp edge.h vertex.h
	$(CXX) $(CXXFLAGS) graph.cpp

airgraph.o : airgraph.cpp
	$(CXX) $(CXXFLAGS) airgraph.cpp

Dijkstra.o : Dijkstra.cpp
	$(CXX) $(CXXFLAGS) Dijkstra.cpp
main.o : main.cpp
	$(CXX) $(CXXFLAGS) main.cpp

heap.o : heap.cpp
	$(CXX) $(CXXFLAGS) heap.cpp
 
