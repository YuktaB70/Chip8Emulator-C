#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "chip8.c"
#include "display.c"


int main() {
    init();
    loadProgram("ROMS/airplane.ch8");

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Chip-8 Emulator", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH * SCALE, HEIGHT * SCALE, 0);
    
    // Create an instance of Chip8Emulator
    Chip8Display emulator;
    initChip8Emulator(&emulator, window); // Initialize the emulator

    // Main loop
    int running = 1;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }

        // Clear the screen
        SDL_SetRenderDrawColor(emulator.renderer, 0, 0, 0, 255);
        SDL_RenderClear(emulator.renderer);

        // Draw the display
        draw(&emulator); // Call the draw method
        SDL_RenderPresent(emulator.renderer);
    }

    // Cleanup
    SDL_DestroyRenderer(emulator.renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();


    return 0;
};

