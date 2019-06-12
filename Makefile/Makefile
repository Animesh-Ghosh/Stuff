# variables
CXX      = g++
TARGET   = "Complex"
OBJS     = main.o complex.o
LINKFLGS = -c
COMPFLGS = -o
RM       = del /p *.o *.exe

# target: prerequisites
$(TARGET): $(OBJS)
	@echo Linking $(OBJS) # recipe echoing
	$(CXX) $(TARGET) $(OBJS) -o

main.o: main.cpp
	@echo Compiling main
	$(CXX) main.cpp -c

complex.o: complex.cpp
	@echo Compiling complex
	$(CXX) complex.cpp -c

# clean using Windows commands, may be changed for other OSs appropriately
# del /p *.o *.exe
clean:
	@echo Cleaning up $(TARGET), $(OBJS)
	$(RM)