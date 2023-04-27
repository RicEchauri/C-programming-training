#include "parse.h"
#include <stdio.h>
#include <stdlib.h>

char *data_types[] =
{
    "INVALID_DATA",
    "SIXTEEN_BIT_SIGNED_INTEGER",
    "THIRTY_TWO_BIT_SIGNED_INTEGER",
    "SIXTY_FOUR_BIT_SIGNED_INTEGER",
    "THIRTY_TWO_BIT_FLOATING_POINT_VALUE",
    "SIXTY_FOUR_BIT_FLOATING_POINT_VALUE",
    "ASCII_STRING",
    "BINARY_DATA"
}
void parse_binary_to_txt(char *input_file, char *output_file)
{
    FILE *binary_file;
    binary_file = fopen(input_file, READ_BINARY);

    if (binary_file == NULL)
    {
        fprintf(stderr, "Error: Fail to open the file.");
        exit(FAIL_STATUS);
    }

    HEADER header;
    fread(&header, sizeof(HEADER), 1, binary_file);
    check_header(&header);
    DATA_INFO data[header.number_of_packages_received];
    for (char index_of_data = 0; index_of_data < header.number_of_packages_received; index_of_data++)
    {
        check_data(&data[index_of_data], binary_file);
    }
    fclose(binary_file);
    
}

void check_header(HEADER* header, int correct_magic_number)
{
    swap_endiannes(&header->magic_number, (char)sizeof(header->magic_number));
    swap_endiannes(&header->version_number, (char)sizeof(header->version_number));
    swap_endiannes(&header->number_of_packages_received, (char)sizeof(header->number_of_packages_received));

    if (header->magic_number != correct_magic_number)
    {
        fprintf(stderr, "Error: Magic number was incorrect\n");
        fprintf(stdout, "Magic number = %x\n", header->magic_number);
        exit(FAIL_STATUS);
    }   

    fprintf(stdout, "Magic number = %x\n", header->magic_number);
    fprintf(stdout, "Version number = %x\n", header->magic_number);
    fprintf(stdout, "Number of packages received = %x\n", header->number_of_packages_received);
    
}
void check_data(DATA_INFO* data, FILE *binary_file)
{
    FILE *text_file;
    text_file = fopen(output_file, WRITE_TXT);
    if (text_file == NULL)
    {
        fprintf(stderr, "Error: Fail to create the file.");
        exit(FAIL_STATUS);
    }
    swap_endiannes(&data->id, (char)sizeof(data->id));
    swap_endiannes(&data->type, (char)sizeof(data->type));
    swap_endiannes(&data->datalength, (char)sizeof(data->datalength));

    fprintf(stdout, "Data ID = %x\n", data->id);
    fprintf(stdout, "Data Type = %s\n", data_types[data->type]);
    fprintf(stdout, "Datalength = %x\n", data->datalength);

    DATA_TYPES type_of_data;
    type_of_data = data->type;
    switch (type_of_data)
    {
        case INVALID_DATA:
        {
            fprintf(stderr, "Error: Recive invalid data\n.");
            exit(FAIL_STATUS);
            break;
        }
        case SIXTEEN_BIT_SIGNED_INTEGER:
        {
            short data_received;
            fread(&data_received, sizeof(data_received), 1, binary_file);
            fprintf(stdout, "Data received = %d\n", data_received);
            fwrite(&data_received, sizeof(data_received), 1, text_file);
            break;
        }
        case THIRTY_TWO_BIT_SIGNED_INTEGER:
        {
            int data_received;
            fread(&data_received, sizeof(data_received), 1, binary_file);
            fprintf(stdout, "Data received = %d\n", data_received);
            fwrite(&data_received, sizeof(data_received), 1, text_file);
            break;
        }
        case SIXTY_FOUR_BIT_SIGNED_INTEGER:
        {
            long data_received;
            fread(&data_received, sizeof(data_received), 1, binary_file);
            fprintf(stdout, "Data received = %ld\n", data_received);
            fwrite(&data_received, sizeof(data_received), 1, text_file);
            break;
        }
        case THIRTY_TWO_BIT_FLOATING_POINT_VALUE:
        {
            float data_received;
            fread(&data_received, sizeof(data_received), 1, binary_file);
            fprintf(stdout, "Data received = %f\n", data_received);
            fwrite(&data_received, sizeof(data_received), 1, text_file);
            break;
        }
        case SIXTY_FOUR_BIT_FLOATING_POINT_VALUE:
        {
            double data_received;
            fread(&data_received, sizeof(data_received), 1, binary_file);
            fprintf(stdout, "Data received = %f\n", data_received);
            fwrite(&data_received, sizeof(data_received), 1, text_file);
            break;
        }
        case ASCII_STRING:
        {
            char data_received[data->datalength];
            fread(&data_received, sizeof(data_received), 1, binary_file);
            fprintf(stdout, "Data received = %d\n", data_received);
            fwrite(&data_received, sizeof(data_received), 1, text_file);
            break;
        }
        case BINARY_DATA:
        {
            break;
        }
        default:
        {
            fprintf(stderr, "Error: Recive invalid data\n.");
            exit(FAIL_STATUS);
            break;
        } 
    }

    fclose(text_file);
}
void swap_endiannes(void *ptr, char ptr_size)
{
    char *temp_byte, index;
    for(index = 0; index < (ptr_size / 2); index++)
    {
        *temp_byte = *((char*)ptr + (ptr_size - 1 - index));
        *((char*)ptr + (ptr_size - 1 - index)) = *((char*)ptr + index);
        *((char*)ptr + index) = *temp_byte;
    }
}
