#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc < 2 || argc > 2)
    {
        printf("Usage: ./recover [file to recover]\n");

        return 1;
    }

    FILE *inputFile;
    FILE *outputFile;
    uint8_t buffer[512];
    int pictures = 0;

    inputFile = fopen(argv[1], "r");

    if (inputFile == NULL)
    {
        printf("Not able to open file.\n");

        return 1;
    }

    while (fread(buffer, sizeof(uint8_t) * 512, 1, inputFile) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff)
        {
            if (outputFile != NULL)
            {
                fclose(outputFile);
            }

            sprintf(argv[1], "%03d.jpg", pictures++);

            outputFile = fopen(argv[1], "w");
        }

        if (outputFile != NULL)
        {
            fwrite(buffer, sizeof(uint8_t) * 512, 1, outputFile);
        }
    }

    if (outputFile != NULL)
    {
        fclose(outputFile);
    }

    fclose(inputFile);
}
