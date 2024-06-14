#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h> // NOLINT(*-deprecated-headers)
#include <string>
#include <vector>
#include "main.h"
#include "Texture.h"
#include "GameBoard.h"

//Screen dimension constants
constexpr int SCREEN_WIDTH = 1920;
constexpr int SCREEN_HEIGHT = 1080;


int main(int argc, char *argv[]) {

    SDL_Window *window = nullptr;
    SDL_Renderer *gRenderer = nullptr;
    gRenderer = nullptr;


    if (setup(window, gRenderer)) {
        printf("Setup Failed");
    }

    GameBoard gameBoard(gRenderer);
    gameBoard.loadTextures();



    SDL_Event e;
    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT)
                quit = true;
        }

        //Clear screen
        SDL_RenderClear(gRenderer);


        gameBoard.render(SCREEN_WIDTH,SCREEN_HEIGHT);

        //Update screen
        SDL_RenderPresent(gRenderer);
    }


    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();

    return 0;
}

bool setup(SDL_Window *&window, SDL_Renderer *&gRenderer) {
    bool error = false;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        error = true;
    } else {
        //Create window
        //Manually moving window over in x coords for stream reasons
        window = SDL_CreateWindow("Settlers Six", 1000, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                  SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == nullptr) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        }

        gRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    }

    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
    }


    return error;
}

