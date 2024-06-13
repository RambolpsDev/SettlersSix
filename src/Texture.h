#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>

class Texture
{
public:

	SDL_Texture* texture = nullptr;
	SDL_Renderer* renderer = nullptr;
    SDL_Rect destination = {0};

	void load(std::string& path);

    Texture(SDL_Renderer* &gRender, std::string& path);

    void Render(int x, int y, int w, int h) const;

    void clean() const;
};

