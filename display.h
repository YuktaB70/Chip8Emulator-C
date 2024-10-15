#include <SDL2/SDL.h>
#include <stdint.h>

#define WIDTH 64
#define HEIGHT 32
#define SCALE 10 

typedef struct {
unsigned char display[HEIGHT][WIDTH];
SDL_Renderer *renderer; 
} Chip8Display;

void initChip8Emulator(Chip8Display *display, SDL_Window *window);
void draw(Chip8Display *display);