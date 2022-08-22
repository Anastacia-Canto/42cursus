# minitalk

This is a program that stablishes a comunication between UNIX process using UNIX signals.  
It was a very good opportunity to learn about UNIX (SIGUSR1 and SIGUSR2) signals management, with functions like getpid() and kill(). 

There are a server and a client. The program starts with the server opening a process and returning its PID (process identifier). 
Then passing this PID with a string as parameters to client, it should send it to server and the server prints it.

To run the program you should:

```
make

./server

./client <PID> <message>

