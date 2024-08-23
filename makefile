CXX = g++
CXX_FLAGS = -std=c++17
SRC = KMP.cpp
CXX_LNK = -static
TARGET = KMP.exe

$(TARGET): $(SRC)
	$(CXX) $(CXX_FLAGS) $(SRC) $(CXX_LNK) -o $(TARGET)

.PHONY: clean
clean:
	-rm -f $(TARGET)