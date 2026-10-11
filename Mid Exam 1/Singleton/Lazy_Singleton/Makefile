CXX = g++
CXXFLAGS = -std=c++17 -Wall

TARGET = app

all: $(TARGET)

$(TARGET): main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o $(TARGET)

clean:
	del /f /q $(TARGET).exe 2>nul || rm -f $(TARGET)