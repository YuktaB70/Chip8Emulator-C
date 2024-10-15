#include <SDL2/SDL.h>
#include <stdint.h>
#include <stdio.h>
#include "display.h"

void initChip8Emulator(Chip8Display *display, SDL_Window *window) {
    memset(display->display, 0, sizeof(display->display)); // Initialize display to off
    display->renderer = SDL_CreateRenderer(window, -1, 0); // Create the renderer
}



void draw(Chip8Display *display) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (display->display[y][x]) {
                SDL_SetRenderDrawColor(display->renderer, 255, 255, 255, 255); // White for on pixels
            } else {
                SDL_SetRenderDrawColor(display->renderer, 0, 0, 0, 255); // Black for off pixels
            }
            SDL_Rect rect = {x * SCALE, y * SCALE, SCALE, SCALE};
            SDL_RenderFillRect(display->renderer, &rect);
        }
    }
}


