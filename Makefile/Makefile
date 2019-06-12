C++ = g++
TARGET = "Complex"
LINKFLGS = -c
COMPFLGS = -o

# target: dependency
$(TARGET): main.o complex.o
	$(C++) main.o complex.o $(COMPFLGS) $(TARGET)

main.o: main.cpp
	$(C++) main.cpp $(LINKFLGS)

complex.o: complex.cpp
	$(C++) complex.cpp $(LINKFLGS)

# using Windows commands, may be changed for other OSs appropriately
clean:
	del /q *.o *.exe