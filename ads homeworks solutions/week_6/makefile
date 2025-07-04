
CXX = g++
CXXFLAGS = -Wall -O2

EXEC = program.exe

SRCS = HeapSort.cpp varriant.cpp comparison.cpp
OBJS = $(SRCS:.cpp=.o)


all: $(EXEC)


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC)

clean:
	rm -f $(OBJS) $(EXEC)
