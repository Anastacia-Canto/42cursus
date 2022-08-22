# get_next_line

This is a program that returns a line from a file each time it is invoked. So if you put it in a loop, you can read an entire file, line by line.
This is a very good challenge to learn about static variables, since the program can not read the entire file and process it in lines. It should read
and buffer information only until it reaches a "\n". And, obviously, It can not have memory leaks. So is trick to realize the exact points where 
you should free the memory. Also you learn how to deal with file descriptors.
 

To run the program you should compile it with:
``` 
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c 
``` 

The BUFFERSIZE is the amount of characters the program read each time it reads the file. So it can be any value bigger than zero. 
