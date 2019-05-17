### Installation 
1. Clone the Repo

``git clone https://github.com/Animesh-Ghosh/Stuff.git``

2. Include the ClearScreen directory in your source directory.

3. Make a file **test.c**:

    ```cpp
        #include <stdio.h>
        #include "ClearScreen/clearscreen.h"
        int main () {
            printf ("Hello!\n");
            ClearScreen ();
            printf ("It works!");
        }
    ```
	
    > *Note: A **C++** source file also works.*
    
4. Compilation

	a. Debian/Linux:-
	
	- Download and install the libncurses5-dev:
			
		``sudo apt-get install libncurses5-dev``
		
	- Compile using ``-lncurses`` or ``-lterminfo`` flag:
     
	 	``gcc test.c clearscreen.c -lncurses -o test`` **or**,
    	
		``gcc test.c clearscreen.c -lterminfo -o test``
	
	b. Windows:-
	
	``gcc test.c clearscreen.c -o test``
 
## How it works

[Here](http://www.cplusplus.com/articles/4z18T05o/) is how *ClearScreen()* is implemented.

> The implementations for different platforms have been included into a single header file. The original source is not created by any of the contributors nor has it been changed.
