
#ifndef PARSE_H_
#define PARSE_H_

#define READ_BINARY "rb+"
#define WRITE_TXT "w"
#define FAIL_STATUS 1

//////////ENDIANESS//////////////

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
void check_header(HEADER* header, int correct_magic_number);
void swap_endiannes(void *ptr, char ptr_size);

#endif 
