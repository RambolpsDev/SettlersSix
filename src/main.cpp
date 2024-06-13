#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h> // NOLINT(*-deprecated-headers)
#include <string>
#include <vector>
#include "main.h"
#include "Texture.h"

//Screen dimension constants
constexpr int SCREEN_WIDTH = 1920;
constexpr int SCREEN_HEIGHT = 1080;




int main(int argc, char* argv[])
{

	SDL_Window* window = nullptr;
	SDL_Renderer* gRenderer = nullptr;
	gRenderer = nullptr;


	if(setup(window,gRenderer))
	{
		printf("Setup Failed");
	}

    std::vector<Texture> textures = loadTextures(gRenderer);


	SDL_Event e;


	bool quit = false;
	while (!quit)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT) 
				quit = true;
		}

        gameRender(gRenderer, textures);
	}


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
		if (window == nullptr)
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

std::vector<Texture> loadTextures(SDL_Renderer* &gRender){
    std::vector<Texture> textures;

    std::string Path = "Assets/bgSky.png";
    textures.emplace_back(gRender, Path);

    Path = "Assets/bricks.png";
    textures.emplace_back(gRender, Path);

    Path = "Assets/grass.png";
    textures.emplace_back(gRender, Path);

    Path = "Assets/iron.png";
    textures.emplace_back(gRender, Path);

    Path = "Assets/wheat.png";
    textures.emplace_back(gRender, Path);

    Path = "Assets/wood.png";
    textures.emplace_back(gRender, Path);

    Path = "Assets/wool.png";
    textures.emplace_back(gRender, Path);

    return textures;
}

void gameRender(SDL_Renderer* &gRender, const std::vector<Texture>& textures){
    //Clear screen
    SDL_RenderClear(gRender);

    enum TextureID: uint8_t {
        BG,
        BRICKS,
        GRASS,
        IRON,
        WHEAT,
        WOOD,
        WOOL
    };


    textures[TextureID::BG].Render(0,0,1920,1080);
    int bx = (SCREEN_WIDTH/2)-500;
    int by = (SCREEN_HEIGHT/2);



    textures[TextureID::IRON].Render(bx+200,by-500,200,200);
    textures[TextureID::WOOL].Render(bx+400,by-500,200,200);
    textures[TextureID::WOOD].Render(bx+600,by-500,200,200);

    textures[TextureID::WHEAT].Render(bx+100,by-300,200,200);
    textures[TextureID::BRICKS].Render(bx+300,by-300,200,200);
    textures[TextureID::WOOL].Render(bx+500,by-300,200,200);
    textures[TextureID::BRICKS].Render(bx+700,by-300,200,200);

    textures[TextureID::WHEAT].Render(bx,by-100,200,200);
    textures[TextureID::WOOD].Render(bx+200,by-100,200,200);
    textures[TextureID::GRASS].Render(bx+400,by-100,200,200);
    textures[TextureID::WOOD].Render(bx+600,by-100,200,200);
    textures[TextureID::IRON].Render(bx+800,by-100,200,200);

    textures[TextureID::WOOD].Render(bx+100,by+100,200,200);
    textures[TextureID::IRON].Render(bx+300,by+100,200,200);
    textures[TextureID::WHEAT].Render(bx+500,by+100,200,200);
    textures[TextureID::WOOL].Render(bx+700,by+100,200,200);

    textures[TextureID::BRICKS].Render(bx+200,by+300,200,200);
    textures[TextureID::WHEAT].Render(bx+400,by+300,200,200);
    textures[TextureID::WOOL].Render(bx+600,by+300,200,200);

    //Update screen
    SDL_RenderPresent(gRender);
}