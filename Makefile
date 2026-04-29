CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude 

OBJS = src/main.o src/user.o src/calculation.o
TARGET = calc

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)
