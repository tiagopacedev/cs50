// Copies a file

#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    FILE *src = fopen(argv[1], "rb");   // Open source file for reading in binary mode
    FILE *dst = fopen(argv[2], "wb");   // Open destination file for writing in binary mode

    BYTE b;

    // While there are bytes to read in the source file:
    // fread reads one byte at a time from the source file into the variable b
    while (fread(&b, sizeof(b), 1, src) != 0)
    {
        fwrite(&b, sizeof(b), 1, dst);  // Write the byte to the destination file
    }

    fclose(dst);
    fclose(src);
}
