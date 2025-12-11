#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

int main()
{
    const char *ptitle = "Image Viewer";
    int x = SDL_WINDOWPOS_CENTERED;
    int y = SDL_WINDOWPOS_CENTERED;
    int w  = 800;
    int h  = 400;
    Uint32 flags = 0;
    SDL_Window *pwindow = SDL_CreateWindow(ptitle,
                                 x, y, w,
                                 h, flags);
    
    
    SDL_Surface *pscreen = SDL_GetWindowSurface(pwindow);
    SDL_FillRect(pscreen, NULL, SDL_MapRGB(pscreen->format, 0, 0, 255));
    SDL_UpdateWindowSurface(pwindow);
    SDL_Delay(3000);

    
}