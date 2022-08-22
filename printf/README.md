# ft_printf

It is a function that clones the famous printf basic functionalities. It was developed using the [libft](https://github.com/Anastacia-Canto/42cursus/tree/main/libft) tools.
Is was defined to work with:
- %c - characters
- %s - strings
- %p - void *pointers (in hexadecimal)
- %d - decimal (base 10) number
- %i - integer in base 10
- %u - unsigned decimal (base 10) number
- %x - number in hexadecimal lower case
- %X - number in hexadecimal upper case
- %% - a percent sign

To use this function you have to create the library using a Makefile and then compile and run the executable:
```
make
gcc ft_printf.c -L. -lftprintf
./a.out
```
