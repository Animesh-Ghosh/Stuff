#include <unistd.h>
#include <term.h>

void __ClearScreen_PLATFORM () {
	int result;
	if (!cur_term) {
    	setupterm (NULL, STDOUT_FILENO, &result);
    	if (result <= 0) return;
    }
    putp (tigetstr ("clear"));
}