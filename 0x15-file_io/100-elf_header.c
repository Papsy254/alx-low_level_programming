#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <string.h>

/**
 * print_magic - Prints the ELF magic number.
 * @header: A pointer to the ELF header structure.
 *
 * This function prints the magic number of the ELF file in hexadecimal format.
 */
void print_magic(const Elf64_Ehdr *header)
{
    printf("  Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++)
    {
        printf("%02x ", header->e_ident[i]);
    }
    printf("\n");
}

/**
 * print_class - Prints the ELF class (32-bit or 64-bit).
 * @header: A pointer to the ELF header structure.
 *
 * This function prints the class of the ELF file, indicating whether it is
 * 32-bit or 64-bit.
 */
void print_class(const Elf64_Ehdr *header)
{
    printf("  Class:                              ");
    switch (header->e_ident[EI_CLASS])
    {
        case ELFCLASS32:
            printf("ELF32\n");
            break;
        case ELFCLASS64:
            printf("ELF64\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }
}

/**
 * print_data - Prints the data encoding (little-endian or big-endian).
 * @header: A pointer to the ELF header structure.
 *
 * This function prints the data encoding of the ELF file.
 */
void print_data(const Elf64_Ehdr *header)
{
    printf("  Data:                               ");
    switch (header->e_ident[EI_DATA])
    {
        case ELFDATA2LSB:
            printf("2's complement, little endian\n");
            break;
        case ELFDATA2MSB:
            printf("2's complement, big endian\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }
}

/**
 * print_version - Prints the ELF version.
 * @header: A pointer to the ELF header structure.
 *
 * This function prints the version of the ELF file.
 */
void print_version(const Elf64_Ehdr *header)
{
    printf("  Version:                           %d\n", header->e_ident[EI_VERSION]);
}

/**
 * print_osabi - Prints the OS/ABI information.
 * @header: A pointer to the ELF header structure.
 *
 * This function prints the OS/ABI information of the ELF file.
 */
void print_osabi(const Elf64_Ehdr *header)
{
    printf("  OS/ABI:                            ");
    switch (header->e_ident[EI_OSABI])
    {
        case ELFOSABI_SYSV:
            printf("UNIX - System V\n");
            break;
        case ELFOSABI_HPUX:
            printf("UNIX - HP-UX\n");
            break;
        case ELFOSABI_NETBSD:
            printf("UNIX - NetBSD\n");
            break;
        case ELFOSABI_LINUX:
            printf("UNIX - Linux\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }
}

/**
 * print_abi_version - Prints the ABI version.
 * @header: A pointer to the ELF header structure.
 *
 * This function prints the ABI version of the ELF file.
 */
void print_abi_version(const Elf64_Ehdr *header)
{
    printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
}

/**
 * print_type - Prints the ELF type (e.g., relocatable, executable).
 * @header: A pointer to the ELF header structure.
 *
 * This function prints the type of the ELF file.
 */
void print_type(const Elf64_Ehdr *header)
{
    printf("  Type:                              ");
    switch (header->e_type)
    {
        case ET_NONE:
            printf("None\n");
            break;
        case ET_REL:
            printf("Relocatable\n");
            break;
        case ET_EXEC:
            printf("Executable\n");
            break;
        case ET_DYN:
            printf("Shared object\n");
            break;
        case ET_CORE:
            printf("Core file\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }
}

/**
 * print_entry_point - Prints the entry point address.
 * @header: A pointer to the ELF header structure.
 *
 * This function prints the entry point address of the ELF file.
 */
void print_entry_point(const Elf64_Ehdr *header)
{
    printf("  Entry point address:               %016lx\n", header->e_entry);
}

/**
 * print_elf_header - Prints the ELF header information.
 * @header: A pointer to the ELF header structure.
 *
 * This function prints various fields from the ELF header, including the magic number,
 * class, data encoding, version, OS ABI, ABI version, type, and entry point address.
 */
void print_elf_header(const Elf64_Ehdr *header)
{
    printf("ELF Header:\n");
    print_magic(header);
    print_class(header);
    print_data(header);
    print_version(header);
    print_osabi(header);
    print_abi_version(header);
    print_type(header);
    print_entry_point(header);
}

/**
 * print_error - Prints an error message.
 * @msg: The error message to be printed.
 *
 * This function prints the specified error message to standard error.
 */
void print_error(const char *msg)
{
    fprintf(stderr, "%s\n", msg);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: The array of command-line arguments.
 *
 * This function opens the specified ELF file, reads its header, and prints
 * its contents. It ensures that the file is an ELF file before attempting
 * to read and print its header.
 *
 * Return: 0 on success, or 98 if an error occurs.
 */
int main(int argc, char *argv[])
{
    int fd;
    ssize_t n_read;
    Elf64_Ehdr header;

    if (argc != 2)
    {
        print_error("Usage: ./elf_header <ELF file>");
        return 98;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        print_error("Error opening file");
        return 98;
    }

    n_read = read(fd, &header, sizeof(header));
    if (n_read < sizeof(header) || memcmp(header.e_ident, "\x7fELF", 4) != 0)
    {
        print_error("Not an ELF file");
        close(fd);
        return 98;
    }

    print_elf_header(&header);
    close(fd);
    return 0;
}
