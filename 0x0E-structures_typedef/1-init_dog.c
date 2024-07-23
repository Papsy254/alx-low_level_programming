#include "dog.h"
#include <stdlib.h>

/**
 * init_dog - initializes a variable of tyoe struct dog
 * @d: pointer to struct dog to initialize
 * @name: name of the new dog
 * @age: age of the new dog
 * @owner: the owner of the new dog
 * Description: This function initializes a struct dog with the provided
 * name, age, and owner's name. If the pointer to the struct dog is NULL,
 * it allocates memory for it.
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
	d = malloc(sizeof(struct dog));
	d->name = name;
	d->age = age;
	d->owner = owner;
}
