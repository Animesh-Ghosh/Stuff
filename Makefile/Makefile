# variables
CXX      = g++
TARGET   = Complex
OBJS     = main.o complex.o

# target: prerequisites
# recipe echoing
$(TARGET): $(OBJS)
	@echo Linking $(OBJS) together.
	@$(CXX) $(OBJS) -o $(TARGET)

main.o: main.cpp
	@echo Compiling main.
	@$(CXX) main.cpp -c

complex.o: complex.cpp
	@echo Compiling complex.
	@$(CXX) complex.cpp -c

# clean using Windows commands, may be changed for other OSs appropriately

clean:
	@echo Cleaning up $(TARGET), $(OBJS).
	@del /p *.o *.exe