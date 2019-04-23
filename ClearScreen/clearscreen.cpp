// www.cplusplus.com/articles/4z18T05o

#if defined (_WIN32) 
	#define PLATFORM "Windows"
	#include "clearscreen_windows.cpp"
#elif defined (__linux__)
	#define PLATFORM "Linux"
	#include "clearscreen_linux.cpp"
#endif

void ClearScreen () {
	__ClearScreen_PLATFORM ();
}