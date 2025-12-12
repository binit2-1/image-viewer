#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

int main()
{
    const char *ptitle = "Image Viewer";
    int x = SDL_WINDOWPOS_CENTERED;
    int y = SDL_WINDOWPOS_CENTERED;

    freopen("./fastfetch.ppm", "rb", stdin);
    char *buffer = malloc(1000 * sizeof(char));
    fgets(buffer, 1000, stdin); // Collects size
    fgets(buffer, 1000, stdin); // Collects comment

    char *dimensions = malloc(1000 * sizeof(char));
    fgets(dimensions, 1000, stdin);
    char *split = strtok(dimensions, " ");
    int w = atoi(split);
    split = strtok(NULL, " ");
    int h = atoi(split);
    printf("Width: %d, Height: %d\n", w, h);
    free(dimensions);
    fgets(buffer, 1000, stdin); // Collects max color value
    free(buffer);               // frees the throwaway buffer

    Uint32 flags = 0;
    SDL_Window *pwindow = SDL_CreateWindow(ptitle,
                                           x, y, w, h,
                                           flags);
    SDL_Surface *pscreen = SDL_GetWindowSurface(pwindow);
    SDL_Rect pixel = (SDL_Rect){0, 0, 1, 1};
    Uint32 color;
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            Uint8 r, g, b;
            r = (char)getchar();
            g = (char)getchar();
            b = (char)getchar();
            color = SDL_MapRGB(pscreen->format, r, g, b);
            pixel = (SDL_Rect){x, y, 1, 1};
            SDL_FillRect(pscreen, &pixel, color);
        }
    }
    SDL_UpdateWindowSurface(pwindow);
    bool app_is_running = true;
    while (app_is_running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        { // poll until all events are handled!
            if(event.type == SDL_QUIT)
            {
                app_is_running = false;
            }
        }

        // update game state, draw the current frame
    }
}