#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Variaveis globais
SDL_Window *window;
SDL_Renderer *rend;
SDL_Rect player = {
    0,
    0,
    20,
    20,
};
void handlerInput(SDL_Rect *reced, SDL_Event *evnt) {
    if (evnt->key.keysym.sym == 'w') {
        reced->y -= 50;
    }
    if (evnt->key.keysym.sym == 's') {
        reced->y += 50;
    }
    if (evnt->key.keysym.sym == 'a') {
        reced->x += 50;
    }
    if (evnt->key.keysym.sym == 'd') {
        reced->x -= 50;
    }
}

int main(int argc, char *argv[]) {

    if (SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stderr, "SDL Not loaded");
        return EXIT_FAILURE;
    }

    window =
        SDL_CreateWindow("Janela fodona", 0, 0, 800, 600, SDL_WINDOW_SHOWN);

    if (!window) {
        fprintf(stderr, "SDL : Cannot open the window");
        return EXIT_FAILURE;
    }

    rend = SDL_CreateRenderer(window, -1, 0);

    if (!rend) {
        fprintf(stderr, "SDL : Cannot open the renderer");
        SDL_DestroyWindow(window);
        return EXIT_FAILURE;
    }

    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            if (event.type == SDL_KEYDOWN) {
                handlerInput(&player, &event);
            }
        }
    }
    SDL_SetRenderDrawColor(rend, 105, 0, 255, 1);
    SDL_RenderClear(rend);

    SDL_SetRenderDrawColor(rend, 0, 0, 0, 1);
    SDL_RenderFillRect(rend, &player);

    SDL_RenderPresent(rend);
    SDL_Delay(32);
}

// destroy things
SDL_DestroyRenderer(rend);
SDL_DestroyWindow(window);
return EXIT_SUCCESS;
}
