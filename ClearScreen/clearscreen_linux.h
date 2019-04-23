// http://www.cplusplus.com/articles/4z18T05o/#POSIX

#include <unistd.h>
#include <term.h>

inline void ClearScreen () {
	int result;
	if (!cur_term) {
    	setupterm (NULL, STDOUT_FILENO, &result);
    	if (result <= 0) return;
    }
    putp (tigetstr ("clear"));
}