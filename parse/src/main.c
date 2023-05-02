#include "parse.h"

int main(int argc, char *argv[])
{
    //write_binary_from_stdin();
    parse_binary_to_txt("data.bin", CORRECT_MAGIC_NUMBER);
    
    return 0;
}
