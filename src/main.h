#pragma once
#include "Texture.h"

bool setup(SDL_Window* &window, SDL_Renderer* &gRenderer);

std::vector<Texture> loadTextures(SDL_Renderer* &gRender);

void gameRender(SDL_Renderer* &gRender, const std::vector<Texture> &textures);