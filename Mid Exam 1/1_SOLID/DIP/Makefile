CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror

TARGET = main

all: $(TARGET)

$(TARGET): main.cpp DIP.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o $(TARGET)

clean:
	rm -f $(TARGET)