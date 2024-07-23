#ifndef DOG_H
#define DOG_H

/**
 * struct dog - a dog's basic information
 * @name: The name of the dog
 * @age: The age of the dog
 * @owner: The name of the dog's owner
 *
 * Description: This structure defines a dog with its basic information,
 * including its name, age, and owner's name. It provides a simple way to
 * represent a dog in a program.
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

/**
 * dog_t - typedef for struct dog
 */
typedef struct dog dog_t;

/**
 * init_dog - initializes a struct dog
 * @d: pointer to the struct dog to initialize
 * @name: name of the dog
 * @age: age of the dog
 * @owner: name of the owner of the dog
 *
 * Description: This function initializes a struct dog with the provided
 * name, age, and owner's name.
 */
void init_dog(struct dog *d, char *name, float age, char *owner);

/**
 * print_dog - prints a struct dog
 * @d: pointer to the struct dog to print
 *
 * Description: This function prints the details of a struct dog,
 * including its name, age, and owner's name. If any of the members are
 * NULL, it prints (nil) instead.
 */
void print_dog(struct dog *d);

/**
 * new_dog - creates a new dog_t
 * @name: name of the dog
 * @age: age of the dog
 * @owner: name of the owner of the dog
 *
 * Return: pointer to the newly created dog_t, or NULL on failure
 *
 * Description: This function allocates memory for a new dog_t and
 * initializes it with the provided name, age, and owner's name.
 */
dog_t *new_dog(char *name, float age, char *owner);

/**
 * free_dog - frees a dog_t
 * @d: pointer to the dog_t to free
 *
 * Description: This function frees the memory allocated for a dog_t.
 */
void free_dog(dog_t *d);

/**
 * _strcpy - copies a string
 * @dest: destination string
 * @src: source string
 *
 * Return: pointer to the destination string
 *
 * Description: This function copies the source string to the destination
 * string, including the terminating null byte.
 */
char *_strcpy(char *dest, char *src);

/**
 * _strlen - calculates the length of a string
 * @s: string to measure
 *
 * Return: length of the string
 *
 * Description: This function returns the length of a string, excluding
 * the terminating null byte.
 */
int _strlen(char *s);

#endif
