CXX=g++
CPPFLAGS=-Iinclude
CXXFLAGS=-O2 -std=gnu++17 -Wall -Wextra

SRC_CPP=$(wildcard src/*.cpp)
OBJ_CPP=$(SRC_CPP:.cpp=.o)
BIN=math_suite

all: $(BIN)

src/%.o: src/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

$(BIN): $(OBJ_CPP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $^

clean:
	rm -f src/*.o $(BIN)

.PHONY: all clean
