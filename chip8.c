#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "chip8.h"


Chip8 chip8; 


void init() {
    chip8.memory = (unsigned char *)malloc(4096 * sizeof(unsigned char));
    chip8.stack = (unsigned char *)malloc(16 *sizeof(unsigned char));
    chip8.display = (unsigned char *)malloc(64 * 32 * sizeof(unsigned char));
    
    if(!chip8.memory || !chip8.stack || !chip8.display) {
        printf("Memory Allocation failed");
    }

    //Ensure that registers and memory are initalized to 0
    for (int i = 0; i < 16; i++) {
        chip8.V[i] = 0;
        chip8.keys[i] = 0;
    }
    for (int i = 0; i < 4096; i++) {
        chip8.memory[i] = 0;
    }

    chip8.AP = 0x0;
    chip8.PC = 0x200;
    chip8.SP = 0;
    chip8.delay_timer = 0;
    chip8.sounds_timer = 0;
};

void loadProgram(const char *filename) {
   FILE *file = fopen(filename, "rb");


    if (file == NULL) {
        printf("file can't be opened \n");
    }    
    int offset = 0;
    while (offset < (4096 - 0x200)) {
        int byte = fgetc(file);
        if (byte == EOF) {
            break; // End of file reached
        }
        chip8.memory[0x200 + offset] = (unsigned char)(byte & 0xFF);
        offset++;
    }
    printf("working");

    fclose(file);
}
