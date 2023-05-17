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
        "BINARY_DATA"};
void write_binary_from_stdin(void)
{
    FILE *binary_file;                             //Create file descriptor for binary file
    binary_file = check_file("data.bin", WRITE_BINARY); //Search for "data.bin" if this don't exist this will create it

    HEADER header;
    set_header(&header, binary_file);
  
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
    binary_file = check_file(input_file, READ_BINARY);

    FILE *text_file;
    text_file = check_file("output_file.txt", WRITE_TXT);

    HEADER header;
    check_header(&header, magic_number, binary_file);
    
    DATA_INFO data[header.number_of_packages_received];
    for (char index_of_data = 0; index_of_data < header.number_of_packages_received; index_of_data++)
    {
        add_data(&data[index_of_data], binary_file, text_file);
    }

    fclose(binary_file);
    fclose(text_file);
}
void add_data_to_binary(char *input_file, int magic_number)
{
    FILE *binary_file;                             
    binary_file = check_file(input_file, WRITE_BINARY); 

    HEADER header;
    check_header(&header, magic_number, binary_file);
    
    int n_data = n_data_to_add();
    header.number_of_packages_received += n_data;
    DATA_INFO data[n_data];
    for (short index_of_data = 1; index_of_data <= header.number_of_packages_received; index_of_data++)
    {
        set_data(&data[index_of_data], binary_file, index_of_data);
    }
    fclose(binary_file);
}
int n_data_to_add(void)
{
    int n_data;
    fprintf(stdout, "How many data do you want to add");
    scanf(" %d", &n_data);
    return n_data;
}
FILE *check_file(char *file_name, char *mode)
{
    FILE *file_to_check;
    file_to_check = fopen(file_name, mode);
    if (file_to_check == NULL)
    {
        fprintf(stderr, "Error: Fail to create the file.");
        exit(FAIL_STATUS);
    }
    return file_to_check;
}
void check_header(HEADER *header, int correct_magic_number, FILE *binary_file)
{
    fread(header, sizeof(HEADER), 1, binary_file);
    swap_header_endianness(header);

    if (header->magic_number != correct_magic_number)
    {
        fprintf(stderr, "Error: Magic number was incorrect\n");
        fprintf(stdout, "Magic number = %x\n", header->magic_number);
        exit(FAIL_STATUS);
    }
    print_header(header);
}
void add_data(DATA_INFO *data, FILE *binary_file, FILE *text_file)
{
    fread(data, sizeof(DATA_INFO), 1, binary_file);
    swap_data_info_endianness(data);
    print_data_info(data);

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
        binary_to_string(data->datalength, binary_file, text_file);
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
void set_header(HEADER *header, FILE *binary_file)
{

    fprintf(stdout, "Give me the magic number: ");
    scanf("%x", &header->magic_number);
    fprintf(stdout, "Give me the version number: ");
    scanf("%x", &header->version_number);
    fprintf(stdout, "Give me the number of packages: ");
    scanf("%x", &header->number_of_packages_received);

    swap_header_endianness(header);
    fwrite(header, sizeof(HEADER), 1, binary_file);
    swap_header_endianness(header);
}
void swap_header_endianness(HEADER *header)
{
    swap_endiannes(&header->magic_number, sizeof(header->magic_number));
    swap_endiannes(&header->version_number, sizeof(header->version_number));
    swap_endiannes(&header->number_of_packages_received, sizeof(header->number_of_packages_received));
}
void swap_data_endianness(DATA_INFO* data)
{
    swap_endiannes(&data->id, sizeof(data->id));
    swap_endiannes(&data->type, sizeof(data->type));
    swap_endiannes(&data->datalength, sizeof(data->datalength));
}
void print_header(HEADER* header)
{
    fprintf(stdout, "Magic number = %x\n", header->magic_number);
    fprintf(stdout, "Version number = %x\n", header->version_number);
    fprintf(stdout, "Number of packages received = %x\n", header->number_of_packages_received);
}
void print_data_info(DATA_INFO* data)
{
    fprintf(stdout, "Data ID = %hx\n", data->id);
    fprintf(stdout, "Data Type = %s\n", data_types[data->type]);
    fprintf(stdout, "Datalength = %hx\n", data->datalength);
}
void swap_data_info_endianness(DATA_INFO *data)
{
    swap_endiannes(&data->id, sizeof(data->id));
    swap_endiannes(&data->type, sizeof(data->type));
    swap_endiannes(&data->datalength, sizeof(data->datalength));
}
void set_data(DATA_INFO *data, FILE *binary_file, short id)
{
    data->id = id;
    fprintf(stdout, "Give me the type of data(1-7): \n");
    for (char option_type = 0; option_type < (sizeof(data_types) / sizeof(data_types[0])); option_type++)
    {
        fprintf(stdout, "%d) %s\n", option_type, data_types[option_type]);
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
        fprintf(stdout, "How many bytes(8 bits) will contain? (1, 2, 4, 8)\n");
        scanf("%hd", &data->datalength);
        char data_received[(data->datalength) * 8];
        fprintf(stdout, "Write the binary data = \n");
        scanf(" %s", data_received);
        swap_data_info_endianness(data);
        fwrite(data, sizeof(DATA_INFO), 1, binary_file);
        swap_data_info_endianness(data);
        string_to_binary(data_received, (data->datalength), binary_file);
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
void check_data2(DATA_INFO *data, FILE *binary_file, FILE *text_file)
{
    fread(data, sizeof(DATA_INFO), 1, binary_file);
    swap_data_info_endianness(data);
    print_data_info(data);
    
    void *data_received;
    data_received = malloc((size_t)&data->datalength);
    fread(&data_received,(size_t)&data->datalength, 1, binary_file);
    fwrite(&data_received, (size_t)&data->datalength, 1, text_file);
    free(data_received);

}

///no acepta espacios
/// ya tengfo un binario y quiero hacer un append de mas datos
/// pedir un dato por id
// write dates by id
// especificar dato o realizar converion a hexadecimal 
// especificar id 

//crear un archivo para herramientas comunes
//separa archivos por funcionalidad
//pull request git por funcionalidad 

