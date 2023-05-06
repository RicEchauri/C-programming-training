
/* Parser

Create a binary parser that can read and write a binary file format that consists of a header followed by a series of data packets.

    The header contains a magic number (4 bytes), the version number (4 bytes), and the number of data packets (4 bytes).

    Each data packet consists of an ID(2 bytes), type(2 bytes), followed by datalength(2 bytes), and payload (variable length).

    ID can be any value between 1 - 6535

    The type field can be one of the following values:

    0x0000: invalid data
    0x0001: 16-bit signed integer
    0x0002: 32-bit signed integer
    0x0003: 64-bit signed integer
    0x0004: 32-bit floating-point value
    0x0005: 64-bit floating-point value
    0x0006: ASCII string
    0x0007: Binary data

    The payload consists of the actual data.

Your parser should be able to: Read: Verify that the file starts with the correct magic number and version number. Print all the data packets. Print packet by ID

Write:
    Provide an API for writing the data packets in a file.
    Generate a binary file in the specified format.
    Erase packets by ID

The purpose of this parser is to save the state of these values into a compact file(write).

You can use any programming language or platform that you are comfortable with, as long as it can be used for embedded development. You should also include test cases to verify that your parser works correctly.

Be sure to organize your code in a maintainable way.
*/
#include "parse.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    char option;
    while (1)
    {
        fprintf(stdout, "Chosse one option: \n a)Write a binary form standar input.\n b)Parse a binary file to a text file\n");
        scanf(" %c", &option);
        if (option == 'a')
        {
            write_binary_from_stdin();
            break;
        }
        else if (option == 'b')
        {
            parse_binary_to_txt("data.bin", CORRECT_MAGIC_NUMBER);
            break;
        }
        else
        {
            fprintf(stderr, "Incorrect option please select <a> or <b>\n");
        }
    }

    return 0;
}
