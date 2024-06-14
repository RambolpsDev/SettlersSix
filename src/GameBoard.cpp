#include "GameBoard.h"
#include <SDL.h>
#include <SDL_image.h>
#include <string>

GameBoard::GameBoard(SDL_Renderer* &renderer) : Renderer(renderer) {}

void GameBoard::loadTextures() {
    Textures.reserve(7);

    std::string Path = "Assets/bgSky.png";
    Textures.emplace_back(Renderer, Path);

    Path = "Assets/Bricks.png";
    Textures.emplace_back(Renderer, Path);

    Path = "Assets/Grass.png";
    Textures.emplace_back(Renderer, Path);

    Path = "Assets/Iron.png";
    Textures.emplace_back(Renderer, Path);

    Path = "Assets/Wheat.png";
    Textures.emplace_back(Renderer, Path);

    Path = "Assets/Wood.png";
    Textures.emplace_back(Renderer, Path);

    Path = "Assets/Wool.png";
    Textures.emplace_back(Renderer, Path);
}

void GameBoard::render(int screenWidth, int screenHeight){
    enum TextureID : uint8_t {
        BG,
        BRICKS,
        GRASS,
        IRON,
        WHEAT,
        WOOD,
        WOOL
    };


    Textures[TextureID::BG].Render(0, 0, 1920, 1080);
    int bx = (screenWidth / 2) - 500;
    int by = (screenHeight / 2);


    Textures[TextureID::IRON].Render(bx + 200, by - 440, 200, 230);
    Textures[TextureID::WOOL].Render(bx + 400, by - 440, 200, 230);
    Textures[TextureID::WOOD].Render(bx + 600, by - 440, 200, 230);

    Textures[TextureID::WHEAT].Render(bx + 100, by - 270, 200, 230);
    Textures[TextureID::BRICKS].Render(bx + 300, by - 270, 200, 230);
    Textures[TextureID::WOOL].Render(bx + 500, by - 270, 200, 230);
    Textures[TextureID::BRICKS].Render(bx + 700, by - 270, 200, 230);

    Textures[TextureID::WHEAT].Render(bx, by - 100, 200, 230);
    Textures[TextureID::WOOD].Render(bx + 200, by - 100, 200, 230);
    Textures[TextureID::GRASS].Render(bx + 400, by - 100, 200, 230);
    Textures[TextureID::WOOD].Render(bx + 600, by - 100, 200, 230);
    Textures[TextureID::IRON].Render(bx + 800, by - 100, 200, 230);

    Textures[TextureID::WOOD].Render(bx + 100, by + 70, 200, 230);
    Textures[TextureID::IRON].Render(bx + 300, by + 70, 200, 230);
    Textures[TextureID::WHEAT].Render(bx + 500, by + 70, 200, 230);
    Textures[TextureID::WOOL].Render(bx + 700, by + 70, 200, 230);

    Textures[TextureID::BRICKS].Render(bx + 200, by + 240, 200, 230);
    Textures[TextureID::WHEAT].Render(bx + 400, by + 240, 200, 230);
    Textures[TextureID::WOOL].Render(bx + 600, by + 240, 200, 230);

};


