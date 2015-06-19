#include <stdio.h>
#include <ctype.h>

//forward declarations
int can_print_it(char ch);
void print_letters(char arg[]);

/*
	Prints the agruments passed into the program at runtime from the commandline
*/
void print_arguments(int argc, char *argv[])
{
	int i = 0;
	
	for (i = 0; i < argc; i++) {
		print_letters(argv[i]);
	}
}

/*
	Print the letters in arg[] and their corresponding integer value(ASCII number)
*/

void print_letters(char arg[])
{
	int i = 0;
	
	for(i = 0; arg[i] != '\0'; i++) {
		char ch = arg[i];
		
		if(can_print_it(ch)) {
			printf("'%c' == '%d '", ch, ch);
		}
	}
}

/*
	Used to check if a character is a letter or a space("blank")
	Returns a boolean in an integer format(0 or 1)
*/

int can_print_it(char ch)
{
	return isalpha(ch) || isblank(ch);
}

int main(int argc, char *argv[])
{
	print_arguments(argc, argv);
	return 0;
}
