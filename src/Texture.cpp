#include "Texture.h"
// ReSharper disable All

Texture::Texture(SDL_Renderer* &gRender, std::string& path)
{
	renderer = gRender;
    load(path);
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
		if (texture == nullptr)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(tmpSurface);
	}
}

void Texture::Render(int x, int y, int w, int h) const {

    SDL_Rect des = {x, y, w, h};
    SDL_RenderCopy(renderer, texture, nullptr, &des);
}

void Texture::clean() const {
    delete texture;
}

