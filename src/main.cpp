// ReSharper disable All
//Using SDL and standard IO
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "main.h"
#include "Texture.h"

//Screen dimension constants
constexpr int SCREEN_WIDTH = 1920;
constexpr int SCREEN_HEIGHT = 1080;



int main(int argc, char* argv[])
{

	SDL_Window* window = nullptr;
	SDL_Renderer* gRenderer = NULL;
	gRenderer =nullptr;


	if(setup(window,gRenderer))
	{
		printf("Setup Failed");
	}

	std::string bgPath = "Assets/bgSky.png";
	Texture txBackground(gRenderer);
	txBackground.load(bgPath);


	SDL_Event e;


	bool quit = false;
	while (quit == false)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT) 
				quit = true;
		}

		//Clear screen
		SDL_RenderClear(gRenderer);

		//Render texture to screen
		SDL_RenderCopy(gRenderer, txBackground.texture, NULL, NULL);

		//Update screen
		SDL_RenderPresent(gRenderer);
	}


	SDL_DestroyTexture(txBackground.texture);
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(window);

	IMG_Quit();
	SDL_Quit();

	return 0;
}

bool setup(SDL_Window* &window, SDL_Renderer* &gRenderer)
{
	bool error = false;

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		error = true;
	}
	else
	{
		//Create window
		window = SDL_CreateWindow("Settlers Six", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}

		gRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	}

	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
	}


	return error;
}