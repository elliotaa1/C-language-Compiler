#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef COMPILERS_H_
#include "Compilers.h"
#endif

#ifndef CODER_H_
#include "Step1Coder.h"
#endif

// Get size of the file
keets_intg getSizeOfFile(const keets_strg filename) {
    if (!filename) return -1;
    FILE* file = fopen(filename, "rb");
    if (!file) return -1;
    fseek(file, 0, SEEK_END);
    keets_intg size = ftell(file);
    fclose(file);
    return size;
}

// Helper: Get the shift value from a key character
int getShift(char keyChar) {
    return (keyChar % ASCII_RANGE); // Key can be any visible char
}

// Perform Vigenère cipher on file
void vigenereFile(const keets_strg inputFileName, const keets_strg outputFileName, const keets_strg key, keets_intg encode) {
    if (!inputFileName || !outputFileName || !key) return;

    FILE* inputFile = fopen(inputFileName, "r");
    FILE* outputFile = fopen(outputFileName, "w");
    if (!inputFile || !outputFile) {
        if (inputFile) fclose(inputFile);
        if (outputFile) fclose(outputFile);
        return;
    }

    size_t keyLen = strlen(key);
    int keyIndex = 0;
    int ch;

    while ((ch = fgetc(inputFile)) != EOF) {
        if (ch >= ASCII_START && ch <= ASCII_END) {
            int shift = getShift(key[keyIndex % keyLen]);
            int base = ch - ASCII_START;
            if (encode == CYPHER)
                base = (base + shift) % ASCII_RANGE;
            else
                base = (base - shift + ASCII_RANGE) % ASCII_RANGE;
            fputc(base + ASCII_START, outputFile);
            keyIndex++;
        } else {
            fputc(ch, outputFile); // leave non-visible chars unchanged
        }
    }

    fclose(inputFile);
    fclose(outputFile);
}


// Perform Vigenère cipher in memory and return result
keets_strg vigenereMem(const keets_strg inputFileName, const keets_strg key, keets_intg encode) {
    if (!inputFileName || !key) return NULL;

    FILE* inputFile = fopen(inputFileName, "r");
    if (!inputFile) return NULL;

    keets_intg size = getSizeOfFile(inputFileName);
    keets_strg output = (keets_strg)malloc(size + 1);
    if (!output) {
        fclose(inputFile);
        return NULL;
    }
    
    size_t keyLen = strlen(key);
    int keyIndex = 0;
    int ch, i = 0;

    while ((ch = fgetc(inputFile)) != EOF) {
        if (ch >= ASCII_START && ch <= ASCII_END) {
            int shift = getShift(key[keyIndex % keyLen]);
            int base = ch - ASCII_START;
            if (encode == CYPHER)
                base = (base + shift) % ASCII_RANGE;
            else
                base = (base - shift + ASCII_RANGE) % ASCII_RANGE;
            output[i++] = base + ASCII_START;
            keyIndex++;
        } else {
            output[i++] = ch;
        }
    }

    output[i] = '\0';
    fclose(inputFile);
    return output;
}

// Wrapper to encode
void cypher(const keets_strg inputFileName, const keets_strg outputFileName, const keets_strg key) {
    vigenereFile(inputFileName, outputFileName, key, CYPHER);
}

// Wrapper to decode
void decypher(const keets_strg inputFileName, const keets_strg outputFileName, const keets_strg key) {
    vigenereFile(inputFileName, outputFileName, key, DECYPHER);
}
