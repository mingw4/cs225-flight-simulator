CXX = clang++

LD = clang++

OBJS = graph.o



WARNINGS = -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function

CXXFLAGS += $(CS225) -Wno-return-stack-address -std=c++1y -stdlib=libc++ -O0 $(WARNINGS) $(DEPFILE_FLAGS) -g -c

LDFLAGS += $(CS225) -std=c++1y -stdlib=libc++ -lc++abi



all : graph.o airgraph.o main.o
	$(CXX) $(LDFLAGS) graph.o airgraph.o main.o -o main

test : graph.o airgraph.o test.o
	$(CXX) $(LDFLAGS) graph.o airgraph.o test.o -o test

test.o : test.cpp
	 $(CXX) $(CXXFLAGS) test.cpp

graph.o : graph.cpp edge.h vertex.h
	$(CXX) $(CXXFLAGS) graph.cpp

airgraph.o : airgraph.cpp
	$(CXX) $(CXXFLAGS) airgraph.cpp

main.o : main.cpp
	$(CXX) $(CXXFLAGS) main.cpp
 
