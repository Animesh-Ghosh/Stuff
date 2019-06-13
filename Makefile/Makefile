# variables
CXX      = g++
TARGET   = complex
OBJS     = main.o complex.o
FILES    = main.cpp complex.cpp

# target: prerequisites
# recipe echoing
$(TARGET): $(OBJS)
	@echo Linking $(OBJS) together.
	@$(CXX) $(OBJS) -o $(TARGET)

$(OBJS): $(FILES)
	@echo Compiling $(FILES) into object files.
	@$(CXX) main.cpp -c
	@$(CXX) complex.cpp -c

# clean using Windows commands, may be changed for other OSs appropriately
clean:
	@echo Cleaning up $(OBJS) and $(TARGET).
	@del /p *.o *.exe