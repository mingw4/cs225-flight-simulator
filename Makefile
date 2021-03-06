CXX = clang++

LD = clang++

OBJS = graph.o airgraph.o heap.o Dijkstra.o LandmarkPath.o traversalUtil.o



WARNINGS = -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function

CXXFLAGS += $(CS225) -Wno-return-stack-address -std=c++1y -stdlib=libc++ -O0 $(WARNINGS) $(DEPFILE_FLAGS) -g -c

LDFLAGS += $(CS225) -std=c++1y -stdlib=libc++ -lc++abi 



all : $(OBJS) main.o
	$(CXX) $(LDFLAGS) $(OBJS) main.o -o main

test : $(OBJS) test.o
	$(CXX) $(LDFLAGS) $(OBJS) test.o -o test

test.o : test.cpp
	 $(CXX) $(CXXFLAGS) test.cpp

graph.o : graph.cpp edge.h vertex.h
	$(CXX) $(CXXFLAGS) graph.cpp

airgraph.o : airgraph.cpp
	$(CXX) $(CXXFLAGS) airgraph.cpp

heap.o : heap.cpp
	$(CXX) $(CXXFLAGS) heap.cpp

Dijkstra.o : Dijkstra.cpp
	$(CXX) $(CXXFLAGS) Dijkstra.cpp -o Dijkstra.o

main.o : main.cpp
	$(CXX) $(CXXFLAGS) main.cpp

LandmarkPath.o : LandmarkPath.cpp 
	$(CXX) $(CXXFLAGS) LandmarkPath.cpp

traversalUtil.o : traversalUtil.cpp
	$(CXX) $(CXXFLAGS) traversalUtil.cpp

data :
	clang++ test_data_gen.cpp -o data_gen
	./data_gen

clean : 
	rm *.o
