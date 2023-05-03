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
