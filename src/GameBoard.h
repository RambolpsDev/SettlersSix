#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "Texture.h"


class GameBoard {
public:

    std::vector<Texture> Textures;
    SDL_Renderer* Renderer;

    explicit GameBoard(SDL_Renderer* &renderer);

    void loadTextures();

    void render(int screenWidth, int screenHeight);

};
