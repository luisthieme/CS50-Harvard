#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    if (argc < 3 || argc > 3)
    {
        printf("Usage: ./reverse [input] [output]\n");
        return 1;
    }

    char *inputFileName = argv[1];
    char *outputFileName = argv[2];
    bool inputIsWavFile = false;
    bool outputIsWavFile = false;

    for (int letterInArgument = 0; letterInArgument < strlen(inputFileName); letterInArgument++)
    {
        bool inputIsWavFile = (inputFileName[letterInArgument] == '.' && inputFileName[letterInArgument + 1] == 'w' && inputFileName[letterInArgument + 2] == 'a' && inputFileName[letterInArgument + 3] == 'v');
    }

    for (int letterInArgument = 0; letterInArgument < strlen(outputFileName); letterInArgument++)
    {
        bool outputIsWavFile = (outputFileName[letterInArgument] == '.' && outputFileName[letterInArgument + 1] == 'w' && outputFileName[letterInArgument + 2] == 'a' && outputFileName[letterInArgument + 3] == 'v');
    }

    if (!inputIsWavFile || !outputIsWavFile)
    {
        printf("Please only enter .wav files!\n");

        return 1;
    }

    FILE *inputFile;
    FILE *outputFile;

    inputFile = fopen(inputFileName, "r");

    WAVHEADER wavHeader;

    fread(&wavHeader.chunkID, sizeof(BYTE) * 4, 1, inputFile);
    fread(&wavHeader.chunkSize, sizeof(BYTE) * 4, 1, inputFile);
    fread(&wavHeader.format, sizeof(BYTE) * 4, 1, inputFile);
    fread(&wavHeader.subchunk1ID, sizeof(BYTE) * 4, 1, inputFile);
    fread(&wavHeader.subchunk1Size, sizeof(BYTE) * 4, 1, inputFile);
    fread(&wavHeader.audioFormat, sizeof(BYTE) * 2, 1, inputFile);
    fread(&wavHeader.numChannels, sizeof(BYTE) * 2, 1, inputFile);
    fread(&wavHeader.sampleRate, sizeof(BYTE) * 4, 1, inputFile);
    fread(&wavHeader.byteRate, sizeof(BYTE) * 4, 1, inputFile);
    fread(&wavHeader.blockAlign, sizeof(BYTE) * 2, 1, inputFile);
    fread(&wavHeader.bitsPerSample, sizeof(BYTE) * 2, 1, inputFile);
    fread(&wavHeader.subchunk2ID, sizeof(BYTE) * 4, 1, inputFile);
    fread(&wavHeader.subchunk2Size, sizeof(BYTE) * 4, 1, inputFile);

    check_format(wavHeader);

    outputFile = fopen(outputFileName, "wb");

    size_t headerSize = sizeof(WAVHEADER);
    size_t bytesWritten = fwrite(&wavHeader, 1, headerSize, outputFile);
    if (bytesWritten != headerSize)
    {
        perror("Error writing WAV header");
        fclose(outputFile);

        return 1;
    }

    int blockSize = get_block_size(wavHeader);

    short *blockBuffer = (short *)malloc(blockSize);
    long numBlocks = (wavHeader.subchunk2Size - sizeof(WAVHEADER)) / blockSize;
    size_t channelSize = blockSize / wavHeader.numChannels;

    for (long i = numBlocks - 1; i >= 0; i--)
    {
        fseek(inputFile, sizeof(WAVHEADER) + i * blockSize, SEEK_SET);
        fread(blockBuffer, sizeof(short), blockSize, inputFile);

        for (int channel = 0; channel < wavHeader.numChannels; channel++)
        {
            size_t channelOffset = channel * channelSize;

            for (size_t j = 0; j < channelSize / 2; j++)
            {
                short temp = blockBuffer[channelOffset + j];
                blockBuffer[channelOffset + j] = blockBuffer[channelOffset + channelSize - j - 1];
                blockBuffer[channelOffset + channelSize - j - 1] = temp;
            }
        }

        fwrite(blockBuffer, sizeof(short), blockSize, outputFile);
    }

    free(blockBuffer);
    fclose(inputFile);
    fclose(outputFile);
}

int check_format(WAVHEADER header)
{

    if (header.format[0] == 0b01010111 && header.format[1] == 0b01000001 && header.format[2] == 0b01010110 && header.format[3] == 0b01000101)
    {
        return 0;
    }

    return 1;
}

int get_block_size(WAVHEADER header)
{
    int channels = header.numChannels;
    int bytesPerSample = header.bitsPerSample / 8;
    int blockSize = channels * bytesPerSample;

    return blockSize;
}
