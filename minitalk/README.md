# minitalk

This is a program that stablishes a comunication between UNIX process using UNIX signals.  
It was a very good opportunity to learn about UNIX (SIGUSR1 and SIGUSR2) signals management, with functions like getpid() and kill(). 

There are a server and a client. The program starts with the server opening a process and returning its PID (process identifier). 
Then passing this PID with a string as parameters to client, it should send it to server and the server prints it.

It was very important to understand how signal works, how to catch a signal, and how to manage the handler functions. Since we have two signals to 
deal with, message is received and sent by binaries. So it is necessary a conversion from char to binary and then from binary to char, in a way to decompose and 
compose the message again. As a plus, the program is still capable of deal with emojis, by using unsigned char.

To run the program you should:

```
make

./server

./client <PID> <message>

