CXX = g++
CXXFLAGS = -Wall

main: int-node.o main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	$(RM) main *.o
