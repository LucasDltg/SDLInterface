#include "../include/MyComponent.h"
#include <SDL2/SDL_ttf.h>
#include <iostream>

MyComponent2::MyComponent2(uint32_t color)
    : SDLComponent(), _color(color)
{
}

void MyComponent2::handleEvents()
{
    EventData event;
    while(hasEvents())
    {
        event = popEvent();

        if (event.event.type == SDL_WINDOWEVENT && event.event.window.event == SDL_WINDOWEVENT_RESIZED)
        {
            // std::cout << event.event.window.data1 << " " << event.event.window.data2 << " " << *(int32_t*)event.data1.get() << " " << *(int32_t*)event.data2.get() << std::endl;
        }
        else if (event.event.type == SDL_KEYDOWN)
        {
            if (event.event.key.keysym.sym == SDLK_ESCAPE)
            {
                _is_running = false;
                // std::cout << "Exiting" << std::endl;
            }
        }
        else if (event.event.type == SDL_MOUSEMOTION)
        {
            // std::cout << "Mouse motion: " << event.event.motion.x << " " << event.event.motion.y << " on color " << std::hex << _color << std::dec << std::endl;
        }
    }
}

void MyComponent2::update(const uint64_t delta_time)
{
}

const std::shared_ptr<SDL_Texture> MyComponent2::render(std::shared_ptr<SDL_Renderer> renderer)
{
    // draw image on background
    SDL_SetRenderDrawBlendMode(renderer.get(), SDL_BLENDMODE_NONE); 
    SDL_RenderCopy(renderer.get(), _texture_manager.getTexture("bmp").get(), nullptr, nullptr);

    SDL_Rect rect = {_texture_size.first / 4, _texture_size.second / 4, _texture_size.first / 2, _texture_size.second / 2};
    SDL_SetRenderDrawBlendMode(renderer.get(), SDL_BLENDMODE_MUL);
    SDL_SetRenderDrawColor(renderer.get(), (_color >> 24) & 0xFF, (_color >> 16) & 0xFF, (_color >> 8) & 0xFF, _color & 0xFF);
    SDL_RenderFillRect(renderer.get(), &rect);

    // std::cout << "Component2 " << _texture_size.first << " " << _texture_size.second << std::endl;

    return _texture;
}

void MyComponent2::initSurface(std::shared_ptr<SDL_Renderer> renderer)
{
    _texture_manager.loadTextureFromFile("assets/image.bmp", "bmp", renderer);
    _texture_manager.loadTexture(std::shared_ptr<SDL_Texture>(SDL_CreateTexture(renderer.get(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 100, 100), SDL_DestroyTexture), "def");
    _texture_manager.loadTexture(std::shared_ptr<SDL_Texture>(SDL_CreateTexture(renderer.get(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 100, 100), SDL_DestroyTexture), "defa");
    _texture_manager.loadDefaultTextures(renderer);

    
    std::shared_ptr<SDL_Texture> texture = _texture_manager.getTexture("def");
    SDL_SetTextureBlendMode(texture.get(), SDL_BLENDMODE_NONE);
    SDL_SetRenderTarget(renderer.get(), texture.get());
    SDL_SetRenderDrawColor(renderer.get(), 0xFF, 0x00, 0xFF, 0x00);
    SDL_RenderClear(renderer.get());

    texture = _texture_manager.getTexture("defa");
    SDL_SetTextureBlendMode(texture.get(), SDL_BLENDMODE_NONE);
    SDL_SetRenderTarget(renderer.get(), texture.get());
    SDL_SetRenderDrawColor(renderer.get(), 0xFF, 0xFF, 0x00, 0x80);
    SDL_RenderClear(renderer.get());
}