#include "Texture.h"
// ReSharper disable All

Texture::Texture(SDL_Renderer* &grender)
{
	renderer = grender;
}


void Texture::load(std::string& path)
{
	SDL_Surface* tmpSurface = IMG_Load(path.c_str());

	if (tmpSurface == nullptr)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());

	}
	else
	{
		texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
		if (texture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(tmpSurface);
	}
}
