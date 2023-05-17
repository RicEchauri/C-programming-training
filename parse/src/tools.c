#include "parse.h"
#include <stdio.h>
#include <stdlib.h>

void binary_to_string(short datalength, FILE *binary_file, FILE *text_file)
{
    BINARY_TYPES binary_type;
    binary_type = (BINARY_TYPES)datalength;
    switch (binary_type)
    {
    case ONE_BYTE:
    {
        char binary_data = 0;
        fread(&binary_data, sizeof(binary_data), 1, binary_file);
        swap_endiannes(&binary_data, sizeof(binary_data));
        char data_received[sizeof(binary_data) * 8];

        for (char index = 0; index < (sizeof(binary_data) * 8); index++)
        {
            if (binary_data & (1 << ((sizeof(binary_data) * 8) - 1 - index)))
            {
                data_received[index] = '1';
            }
            else if (~(binary_data & (0 << ((datalength * 8) - 1 - index))))
            {
                data_received[index] = '0';
            }
            else
            {
                fprintf(stderr, "Error: Fail in binary_to_string() function\n");
            }
        }
        fprintf(stdout, "Data received = %s\n", data_received);
        fwrite(data_received, sizeof(data_received), 1, text_file);
        break;
    }
    case TWO_BYTES:
    {
        short binary_data = 0;
        fread(&binary_data, sizeof(binary_data), 1, binary_file);
        swap_endiannes(&binary_data, sizeof(binary_data));
        char data_received[sizeof(binary_data) * 8];

        for (char index = 0; index < (sizeof(binary_data) * 8); index++)
        {
            if (binary_data & (1 << ((sizeof(binary_data) * 8) - 1 - index)))
            {
                data_received[index] = '1';
            }
            else if (~(binary_data & (0 << ((datalength * 8) - 1 - index))))
            {
                data_received[index] = '0';
            }
            else
            {
                fprintf(stderr, "Error: Fail in binary_to_string() function\n");
            }
        }
        fprintf(stdout, "Data received = %s\n", data_received);
        fwrite(data_received, sizeof(data_received), 1, text_file);
        break;
    }
    case FOUR_BYTES:
    {
        int binary_data = 0;
        fread(&binary_data, sizeof(binary_data), 1, binary_file);
        swap_endiannes(&binary_data, sizeof(binary_data));
        char data_received[sizeof(binary_data) * 8];

        for (char index = 0; index < (sizeof(binary_data) * 8); index++)
        {
            if (binary_data & (1 << ((sizeof(binary_data) * 8) - 1 - index)))
            {
                data_received[index] = '1';
            }
            else if (~(binary_data & (0 << ((datalength * 8) - 1 - index))))
            {
                data_received[index] = '0';
            }
            else
            {
                fprintf(stderr, "Error: Fail in binary_to_string() function\n");
            }
        }
        fprintf(stdout, "Data received = %s\n", data_received);
        fwrite(data_received, sizeof(data_received), 1, text_file);
        break;
    }
    case EIGTH_BYTES:
    {
        long binary_data = 0;
        fread(&binary_data, sizeof(binary_data), 1, binary_file);
        swap_endiannes(&binary_data, sizeof(binary_data));
        char data_received[sizeof(binary_data) * 8];

        for (char index = 0; index < (sizeof(binary_data) * 8); index++)
        {
            if (binary_data & (1 << ((sizeof(binary_data) * 8) - 1 - index)))
            {
                data_received[index] = '1';
            }
            else if (~(binary_data & (0 << ((datalength * 8) - 1 - index))))
            {
                data_received[index] = '0';
            }
            else
            {
                fprintf(stderr, "Error: Fail in binary_to_string() function\n");
            }
        }
        fprintf(stdout, "Data received = %s\n", data_received);
        fwrite(data_received, sizeof(data_received), 1, text_file);
        break;
    }
    default:

        break;
    }
}
void string_to_binary(char *data_received, short datalength, FILE *binary_file)
{
    BINARY_TYPES binary_type;
    binary_type = (BINARY_TYPES)datalength;
    switch (binary_type)
    {
    case ONE_BYTE:
    {
        char binary_data = 0;
        for (char index = 0; index < (datalength * 8); index++)
        {
            if (data_received[index] == '1')
            {
                binary_data = binary_data | (1 << ((datalength * 8) - 1 - index));
            }
            else if (data_received[index] == '0')
            {
                binary_data = binary_data | (0 << ((datalength * 8) - 1 - index));
            }
            else
            {
                fprintf(stderr, "Error: Fail in string_to_binary() function\n");
            }
        }
        swap_endiannes(&binary_data, sizeof(binary_data));
        fwrite(&binary_data, sizeof(binary_data), 1, binary_file);
        break;
    }
    case TWO_BYTES:
    {
        short binary_data = 0;
        for (char index = 0; index < (datalength * 8); index++)
        {
            if (data_received[index] == '1')
            {
                binary_data = binary_data | (1 << ((datalength * 8) - 1 - index));
            }
            else if (data_received[index] == '0')
            {
                binary_data = binary_data | (0 << ((datalength * 8) - 1 - index));
            }
            else
            {
                fprintf(stderr, "Error: Fail in string_to_binary() function\n");
            }
        }
        swap_endiannes(&binary_data, sizeof(binary_data));
        fwrite(&binary_data, sizeof(binary_data), 1, binary_file);
        break;
    }
    case FOUR_BYTES:
    {
        int binary_data = 0;
        for (char index = 0; index < (datalength * 8); index++)
        {
            if (data_received[index] == '1')
            {
                binary_data = binary_data | (1 << ((datalength * 8) - 1 - index));
            }
            else if (data_received[index] == '0')
            {
                binary_data = binary_data | (0 << ((datalength * 8) - 1 - index));
            }
            else
            {
                fprintf(stderr, "Error: Fail in string_to_binary() function\n");
            }
        }
        swap_endiannes(&binary_data, sizeof(binary_data));
        fwrite(&binary_data, sizeof(binary_data), 1, binary_file);
        break;
    }
    case EIGTH_BYTES:
    {
        long binary_data = 0;
        for (char index = 0; index < (datalength * 8); index++)
        {
            if (data_received[index] == '1')
            {
                binary_data = binary_data | (1 << ((datalength * 8) - 1 - index));
            }
            else if (data_received[index] == '0')
            {
                binary_data = binary_data | (0 << ((datalength * 8) - 1 - index));
            }
            else
            {
                fprintf(stderr, "Error: Fail in string_to_binary() function\n");
            }
        }
        swap_endiannes(&binary_data, sizeof(binary_data));
        fwrite(&binary_data, sizeof(binary_data), 1, binary_file);
        break;
    }
    default:

        break;
    }
}
void swap_endiannes(void *ptr, long ptr_size)
{
    char *temp_byte, index;
    temp_byte = malloc(sizeof(char));
    for (index = 0; index < (ptr_size / 2); index++)
    {
        *temp_byte = *((char *)ptr + (ptr_size - 1 - index));
        *((char *)ptr + (ptr_size - 1 - index)) = *((char *)ptr + index);
        *((char *)ptr + index) = *temp_byte;
    }
    free(temp_byte);
}
