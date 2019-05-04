## Installation 
1. Clone the Repo

```git clone https://github.com/Animesh-Ghosh/Stuff.git```

2. If one a Debian/Linux System, follow below steps :
    - Download and install the libncurses5-dev:
    
      ```sudo apt-get install libncurses5-dev```
    - Make a file **test.c**
      ```
      #include<stdio.h>
      #include"clearscreen.h"
      int main(){
          printf("Hello");
          ClearScreen();
          printf("\n It works\n");
      }
      ```
     - Compile using ```-lncurses``` or ```-lterminfo```flag
     
        ```gcc test.c clearscreen.c -lncurses -o test``` or,
      
        ```gcc test.c clearscreen.c -lterminfo -o test```
        
## How it works
Check the following [link](http://www.cplusplus.com/articles/4z18T05o/) for how _ClearScreen()_ is implemeted
> Note : the code has been made cross-platform specifc
