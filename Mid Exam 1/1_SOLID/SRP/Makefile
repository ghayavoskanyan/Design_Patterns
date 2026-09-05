CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror

TARGET = main

all: $(TARGET)

$(TARGET): main.cpp SRP.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o $(TARGET)

clean:
	rm -f $(TARGET)


#mingw32-make 
#g++ -std=c++17 -Wall -Wextra -Werror main.cpp -o main ./main.exe