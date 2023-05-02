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
};
void write_binary_from_stdin(void)
{
    FILE *binary_file;
    binary_file = fopen("data.bin", WRITE_BINARY);

    if (binary_file == NULL)
    {
        fprintf(stderr, "Error: Fail to open the file.");
        exit(FAIL_STATUS);
    }

    HEADER header;
    set_header(&header);
    fwrite(&header, sizeof(HEADER), 1, binary_file);
    swap_header_endianness(&header);
    DATA_INFO data[header.number_of_packages_received];
    for (short index_of_data = 1; index_of_data <= header.number_of_packages_received; index_of_data++)
    {
        set_data(&data[index_of_data], binary_file, index_of_data);
    }   
    fclose(binary_file);   
}
void parse_binary_to_txt(char *input_file, int magic_number)
{
    FILE *binary_file;
    binary_file = fopen(input_file, READ_BINARY);

    if (binary_file == NULL)
    {
        fprintf(stderr, "Error: Fail to open the file.");
        exit(FAIL_STATUS);
    }

    FILE *text_file;
    text_file = fopen("output_file.txt", WRITE_TXT);
    if (text_file == NULL)
    {
        fprintf(stderr, "Error: Fail to create the file.");
        exit(FAIL_STATUS);
    }

    HEADER header;
    fread(&header, sizeof(HEADER), 1, binary_file);
    check_header(&header, magic_number);
    DATA_INFO data[header.number_of_packages_received];
    for (char index_of_data = 0; index_of_data < header.number_of_packages_received; index_of_data++)
    {
        fread(&data[index_of_data], sizeof(DATA_INFO), 1, binary_file);
        check_data(&data[index_of_data], binary_file, text_file);
    }
    fclose(binary_file);  
    fclose(text_file);
}

void check_header(HEADER* header, int correct_magic_number)
{
    swap_endiannes(&header->magic_number, sizeof(header->magic_number));
    swap_endiannes(&header->version_number, sizeof(header->version_number));
    swap_endiannes(&header->number_of_packages_received, sizeof(header->number_of_packages_received));

    if (header->magic_number != correct_magic_number)
    {
        fprintf(stderr, "Error: Magic number was incorrect\n");
        fprintf(stdout, "Magic number = %x\n", header->magic_number);
        exit(FAIL_STATUS);
    }   

    fprintf(stdout, "Magic number = %x\n", header->magic_number);
    fprintf(stdout, "Version number = %x\n", header->version_number);
    fprintf(stdout, "Number of packages received = %x\n", header->number_of_packages_received);
    
}
void check_data(DATA_INFO* data, FILE *binary_file, FILE *text_file)
{
    
    swap_endiannes(&data->id, sizeof(data->id));
    swap_endiannes(&data->type, sizeof(data->type));
    swap_endiannes(&data->datalength, sizeof(data->datalength));

    fprintf(stdout, "Data ID = %hx\n", data->id);
    fprintf(stdout, "Data Type = %s\n", data_types[data->type]);
    fprintf(stdout, "Datalength = %hx\n", data->datalength);

    DATA_TYPES type_of_data;
   type_of_data = (DATA_TYPES)data->type;
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
            fprintf(stdout, "Data received = %s\n", data_received);
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

}
void set_header(HEADER* header)
{
    fprintf(stdout, "Give me the magic number:\n");
    scanf("%x",&header->magic_number);
    fprintf(stdout, "Give me the version number:\n");
    scanf("%x",&header->version_number);
    fprintf(stdout, "Give me the number of packages:");
    scanf("%x",&header->number_of_packages_received);
    swap_endiannes(&header->magic_number, sizeof(header->magic_number));
    swap_endiannes(&header->version_number, sizeof(header->version_number));
    swap_endiannes(&header->number_of_packages_received, sizeof(header->number_of_packages_received));
}
void swap_header_endianness(HEADER* header)
{
    swap_endiannes(&header->magic_number, sizeof(header->magic_number));
    swap_endiannes(&header->version_number, sizeof(header->version_number));
    swap_endiannes(&header->number_of_packages_received, sizeof(header->number_of_packages_received));
}
void swap_data_info_endianness(DATA_INFO* data)
{
    swap_endiannes(&data->id, sizeof(data->id));
    swap_endiannes(&data->type, sizeof(data->type));
    swap_endiannes(&data->datalength, sizeof(data->datalength));   
}
void set_data(DATA_INFO* data, FILE *binary_file, short id)
{
    data->id = id;
    fprintf(stdout,"Give me the type of data(1-7): \n");
    for(char option_type = 0; option_type < (sizeof(data_types)/sizeof(data_types[0])); option_type++)
    {
        fprintf(stdout,"%d) %s\n", option_type, data_types[option_type]);
    }
    scanf("%hd", &data->type);
    
    DATA_TYPES type_of_data;
    type_of_data = (DATA_TYPES)data->type;
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
            fprintf(stdout, "Write the data = \n");
            scanf("%hd", &data_received);
            data->datalength = (short)sizeof(data_received);
            swap_data_info_endianness(data);
            fwrite(data, sizeof(DATA_INFO), 1, binary_file);
            fwrite(&data_received, sizeof(data_received), 1, binary_file);
            break;
        }
        case THIRTY_TWO_BIT_SIGNED_INTEGER:
        {
            int data_received;
            fprintf(stdout, "Write the data = \n");
            scanf("%d", &data_received);
            data->datalength = (short)sizeof(data_received);
            swap_data_info_endianness(data);
            fwrite(data, sizeof(DATA_INFO), 1, binary_file);
            fwrite(&data_received, sizeof(data_received), 1, binary_file);
            break;
        }
        case SIXTY_FOUR_BIT_SIGNED_INTEGER:
        {
            long data_received;
            fprintf(stdout, "Write the data = \n");
            scanf("%ld", &data_received);
            data->datalength = (short)sizeof(data_received);
            swap_data_info_endianness(data);
            fwrite(data, sizeof(DATA_INFO), 1, binary_file);
            fwrite(&data_received, sizeof(data_received), 1, binary_file);
            break;
        }
        case THIRTY_TWO_BIT_FLOATING_POINT_VALUE:
        {
            float data_received;
            fprintf(stdout, "Write the data = \n");
            scanf("%f", &data_received);
            data->datalength = (short)sizeof(data_received);
            swap_data_info_endianness(data);
            fwrite(data, sizeof(DATA_INFO), 1, binary_file);
            fwrite(&data_received, sizeof(data_received), 1, binary_file);
            break;
        }
        case SIXTY_FOUR_BIT_FLOATING_POINT_VALUE:
        {
            double data_received;
            fprintf(stdout, "Write the data = \n");
            scanf("%lf", &data_received);
            data->datalength = (short)sizeof(data_received);
            swap_data_info_endianness(data);
            fwrite(data, sizeof(DATA_INFO), 1, binary_file);
            fwrite(&data_received, sizeof(data_received), 1, binary_file);
            break;
        }
        case ASCII_STRING:
        {
            fprintf(stdout, "How many characters will contain?\n");
            scanf("%hd", &data->datalength);
            char data_received[data->datalength];
            fprintf(stdout, "Write the data = \n");
            scanf("%s", data_received);
            swap_data_info_endianness(data);
            fwrite(data, sizeof(DATA_INFO), 1, binary_file);
            fwrite(&data_received, sizeof(data_received), 1, binary_file);
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
    printf("%hX, %hX, %hX\n", data->id, data->type, data->datalength);
}



void swap_endiannes(void *ptr, long ptr_size)
{
    char *temp_byte, index;
    temp_byte = malloc(sizeof(char));
    for(index = 0; index < (ptr_size / 2); index++)
    {
        *temp_byte = *((char*)ptr + (ptr_size - 1 - index));    
        *((char*)ptr + (ptr_size - 1 - index)) = *((char*)ptr + index);
        *((char*)ptr + index) = *temp_byte;
    }
    free(temp_byte);
}
