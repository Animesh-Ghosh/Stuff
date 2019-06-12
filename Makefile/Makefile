C++ = g++
TARGET = "Complex"
LINKFLGS = -c
COMPFLGS = -o

# target: dependency
$(TARGET): main.o Complex.o
	$(C++) main.o Complex.o $(COMPFLGS) $(TARGET)

main.o: main.cpp
	$(C++) main.cpp $(LINKFLGS)

Complex.o: Complex.cpp
	$(C++) Complex.cpp $(LINKFLGS)

# using Windows commands, may be changed for other OSs appropriately
clean:
	del /q *.o