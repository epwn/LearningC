#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

//Person struct
struct Person {
	char *name;
	int age;
	int height;
	int weight;
};


//Constructor for Person
struct Person *Person_create(char *name, int age, int height, int weight)
{
	//Allocate memory for a new person using malloc
	struct Person *who = malloc(sizeof(struct Person));
	//Make sure our new memory isn't null	
	assert(who != NULL);
	//Allocate memory for who's name
	who->name = strdup(name);
	//Allocate memory for who's age
	who->age = age;
	//Allocate memory for who's height
	who->height = height;
	//Allocate memory for who's weight
	who->weight = weight;

	//Return the newly created Person
	return who;
}

//Garbage Collection
void Person_destroy(struct Person *who)
{
	//Make sure the variable @who is not null
	assert(who != NULL);	
	
	//Remove who's name from memory because it is a string
	free(who->name);
	//Remove who from memory
	free(who);
}

//TODO: Research this _print method to see what that is all about. is it standard?
void Person_print(struct Person *who)
{
	printf("Name %s\n", who->name);
	printf("\tAge %d\n", who->age);
	printf("\tWeight: %d\n", who->height);
	printf("\tHeight: %d\n", who->weight);
}

int main(int argc, char *argv[])
{
	//make two people structures
	//Create a new Person pointer called joe and intialize the 4 fields
	struct Person *joe = Person_create("Joe Alex", 32, 64, 140);
	//Create a new Person pointer called frank and intialize the 4 fields
	struct Person *frank = Person_create("Frank Blank", 20, 72, 180);

	//print them out and where they are in memory. Notice no deference. You just print them out cause they are pointers which just point to the address
	printf("Joe is at memory location %p:\n", joe);
	//Call the print function for Joe so we can get his information	
	Person_print(joe);

	//Print out Frank's location in memory
	printf("Frank is at memory location %p:\n", frank);
	//Call the print function for Frank so we can get his information	
	Person_print(frank);

	//Age Joe 20 years
	joe->age += 20;
	//Joe shrinks a little because he is old
	joe->height -= 2;
	//Joe gains weight
	joe->weight += 40;
	//Print Joe's new information
	Person_print(joe);

	//Age Frank 20 years as well
	frank->age += 20;
	//Frank also gains weight
	frank->weight += 20;
	//Print Frank's new information
	Person_print(frank);

	//Destroy them both so we can clean up. Calls the garbage collection
	//Destroy Joe	
	Person_destroy(joe);
	//Destroy Frank
	Person_destroy(frank);

	//Gracefully end program
	return 0;
}
