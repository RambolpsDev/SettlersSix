#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>

// ReSharper disable All

class Texture
{
public:

	SDL_Texture* texture = nullptr;
	SDL_Renderer* renderer = nullptr;

	void load(std::string& path);

	Texture(SDL_Renderer*& grender);
};

