#include <stdio.h>
#ifndef PARSE_H_
#define PARSE_H_

#define READ_BINARY "rb+"
#define WRITE_BINARY "wb+"
#define WRITE_TXT "w"
#define FAIL_STATUS 1

#define CORRECT_MAGIC_NUMBER 0xF00DBABE

///////VARIABLES TYPES///////////
typedef enum
{
    INVALID_DATA,
    SIXTEEN_BIT_SIGNED_INTEGER,
    THIRTY_TWO_BIT_SIGNED_INTEGER,
    SIXTY_FOUR_BIT_SIGNED_INTEGER,
    THIRTY_TWO_BIT_FLOATING_POINT_VALUE,
    SIXTY_FOUR_BIT_FLOATING_POINT_VALUE,
    ASCII_STRING,
    BINARY_DATA
}DATA_TYPES;
///////BINARY_TYPES///////////////
typedef enum
{
    ONE_BYTE = 1,
    TWO_BYTES = 2,
    FOUR_BYTES = 4,
    EIGTH_BYTES = 8,
}BINARY_TYPES;
///////STRUCT FOR HEADER////////
typedef struct
{
    int magic_number;
    int version_number;
    int number_of_packages_received;
}HEADER;
//////STRUCT FOR DATA INFORMATION////
typedef struct
{
    short id;
    short type;
    short datalength;
}DATA_INFO;
/////FUNCTIONS////////////////////
void write_binary_from_stdin(void);
FILE *check_file(char *file_name, char *mode);
void set_header(HEADER *header, FILE *binary_file);
void swap_header_endianness(HEADER* header);
void swap_data_info_endianness(DATA_INFO* data);
void set_data(DATA_INFO* data, FILE *binary_file, short id);
void parse_binary_to_txt(char *input_file, int magic_number);
void check_header(HEADER *header, int correct_magic_number, FILE *binary_file);
void check_data(DATA_INFO* data, FILE *binary_file, FILE *text_file);
void swap_endiannes(void *ptr, long ptr_size);
void string_to_binary(char *data_received, short datalength,  FILE *binary_file);
void binary_to_string(short datalength, FILE *binary_file, FILE *text_file);
void print_header(HEADER* header);
void print_data_info(DATA_INFO* data);
void check_data2(DATA_INFO *data, FILE *binary_file, FILE *text_file);

#endif 
