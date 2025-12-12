#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>

int main()
{
    const char *ptitle = "Image Viewer";
    int x = SDL_WINDOWPOS_CENTERED;
    int y = SDL_WINDOWPOS_CENTERED;
    
    

    freopen("./fastfetch.ppm", "rb", stdin);   
    char *buffer = malloc(1000*sizeof(char));
    fgets(buffer, 1000, stdin);
    fgets(buffer, 1000, stdin);
    free(buffer);

    char *dimensions = malloc(1000*sizeof(char));
    fgets(dimensions, 1000, stdin);
    char *split = strtok(dimensions, " ");
    int w = atoi(split);
    split = strtok(NULL, " ");
    int h = atoi(split);
    int *pwidth = &w;
    int *pheight = &h;
    printf("Width: %d, Height: %d\n", *pwidth, *pheight);

    Uint32 flags = 0;
    SDL_Window *pwindow = SDL_CreateWindow(ptitle,
                                 x, y, *pwidth,
                                 *pwidth, flags);
    srand((unsigned int)time(NULL));
    int r = 0;
    int g = 0;
    int b = 255;
    int posx = (rand() % (*pwidth - 20 + 1)) - 20;
    int posy = (rand() % (*pheight - 20 + 1)) - 20; 
    SDL_Surface *pscreen = SDL_GetWindowSurface(pwindow);
    Uint32 color =  SDL_MapRGB(pscreen->format, r, g, b);
    SDL_Rect pixel = (SDL_Rect){posx, posy, 20, 20};
    SDL_FillRect(pscreen, &pixel, color);
    SDL_UpdateWindowSurface(pwindow);
    SDL_Delay(3000);
    
}