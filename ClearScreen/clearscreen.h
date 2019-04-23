// www.cplusplus.com/articles/4z18T05o
#ifndef CLEARSCREEN_H
	#define CLEARSCREEN_H

	// lot's of help from Discord!
	// inline to avoid linking errors
	/* allows this definition to be defined in 
	multiple translation units (whatever that means) */

	inline void ClearScreen();

	#if defined (_WIN32) 
		#define PLATFORM "Windows"
		#include "clearscreen_windows.h"
	#elif defined (__linux__)
		#define PLATFORM "Linux"
		#include "clearscreen_linux.h"
	#endif
	
#endif