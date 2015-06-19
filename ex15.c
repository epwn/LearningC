#include <stdio.h>

int main(int argc, char *argv[])
{
	//create two arrays we care about
	int ages[] = {23, 43, 12, 89, 2};
	char *names[] = {"Alan", "Frank", "Mary", "John", "Lisa"};

	//safely get the size of the ages[]
	int count = sizeof(ages) / sizeof(int);
	int i = 0;
	
	//first way using indexing
	for (i = 0; i < count; i++) {
		printf("%s has %d years alive.\n", names[i], ages[i]);
	}

	//print this cute little divider that only C programmers would do
	printf("---\n");
	
	//second way we can print the arrays using pointers!
	int *cur_age = ages;
	char **cur_name = names; //kek this is a pointer to a pointer. We can do this because strings are 2d arrays of chars
	
	//second way using pointers. "the value of (pointer cur_name + i)"
	for(i = 0; i < count; i++) {
		printf("%s has %d years alive.\n", *(cur_name+i), *(cur_age+i));
	}

	printf("---\n");
	
	//pointers are just arrays! ...but not really
	for(i = 0; i < count; i++) {
		printf("%s has %d years alive.\n", cur_name[i], cur_age[i]);
	}
	
	printf("---\n");
	
	//fourth cute way
	for(cur_name = names, cur_age = ages; (cur_age - ages) < count; cur_name++, cur_age++) {
		printf("%s has %d years alive.\n", *cur_name, *cur_age);
	}
	
	return 0;
}
