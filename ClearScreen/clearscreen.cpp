// www.cplusplus.com/articles/4z18T05o

#if defined (_WIN32) 
	#include <windows.h>
	#define PLATFORM "Windows"
	winClearScreen ()
#elif defined (__linux__)
	#include <unistd.h>
	#include <term.h>
	#define PLATFORM "Linux"
	linxClearScreen ()
#endif

#include "clearscreen.h"

void linxClearScreen () {
	int result;
	if (!cur_term) {
    	setupterm (NULL, STDOUT_FILENO, &result);
    	if (result <= 0) return;
    }
    putp (tigetstr ("clear"));
}

void winClearScreen () { 
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = {0, 0};

	hStdOut = GetStdHandle (STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo (hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X * csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter (
		hStdOut, 
		(TCHAR) ' ', 
		cellCount, 
		homeCoords, 
		&count)
	) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute (
		hStdOut, 
		csbi.wAttributes, 
		cellCount, 
		homeCoords, 
		&count)
	) return;

	/* Move the cursor home */
	SetConsoleCursorPosition (hStdOut, homeCoords);
}

void ClearScreen () {
	if (PLATFORM == "Windows")
		winClearScreen ();
	else if (PLATFORM == "Linux")
		linxClearScreen ();
}