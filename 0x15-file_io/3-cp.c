#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/**
 * copy_file - Copies the content from one file to another.
 * @file_from: The source file to copy from.
 * @file_to: The destination file to copy to.
 *
 * Return: 0 on success, -1 on failure.
 */

int copy_file(const char *file_from, const char *file_to)
{
	int fd_from, fd_to;
	ssize_t n_read, n_written;
	char buffer[BUFFER_SIZE];

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		return (-1);

	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
	close(fd_from);
	return (-1);
	}

	while ((n_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
	n_written = write(fd_to, buffer, n_read);
	if (n_written != n_read)
	{
	close(fd_from);
	close(fd_to);
	return (-1);
	}
	}

	if (n_read == -1)
	{
	close(fd_from);
	close(fd_to);
	return (-1);
	}
	if (close(fd_from) == -1 || close(fd_to) == -1)
	return (-1);

	return (0);
	}

/**
 * main - Copies the content of a file to another file.
 * @ac: Number of arguments.
 * @av: Array of arguments.
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	if (ac != 3)
	{
	dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", av[0]);
	exit(97);
	}

	if (copy_file(av[1], av[2]) == -1)
	{
	if (access(av[1], F_OK) != 0)
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
	else if (access(av[2], W_OK) != 0)
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
	else
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", -1);

	exit(98);
	}
	return (0);
}
