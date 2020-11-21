CXX = clang++

LD = clang++

OBJS_DIR = .objs



WARNINGS = -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function

CXXFLAGS =  += $(CS225) -Wno-return-stack-address -std=c++1y -stdlib=libc++ -O0 $(WARNINGS) $(DEPFILE_FLAGS) -g -c

LDFLAGS += $(CS225) -std=c++1y -stdlib=libc++ -lc++abi


graph: $(CXX) 


