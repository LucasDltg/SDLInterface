#include "../include/MyComponent.h"
#include <SDL2/SDL_ttf.h>
#include <iostream>

MyComponent::MyComponent(uint32_t color)
    : SDLComponent(), _color(color)
{}

void MyComponent::handleEvents()
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

void MyComponent::update(const uint64_t delta_time)
{
    (void)delta_time;
}

const std::shared_ptr<SDL_Texture> MyComponent::render(std::shared_ptr<SDL_Renderer> renderer)
{
    SDL_RenderCopy(renderer.get(), _texture_manager.getTexture("bmp").get(), nullptr, nullptr);

    int32_t width, height;
    SDL_QueryTexture(_texture.get(), nullptr, nullptr, &width, &height);

    SDL_Rect rect = {width / 4, height / 4, width / 2, height / 2};
    SDL_SetRenderDrawColor(renderer.get(), (_color >> 24) & 0xFF, (_color >> 16) & 0xFF, (_color >> 8) & 0xFF, _color & 0xFF);
    SDL_RenderFillRect(renderer.get(), &rect);

    return _texture;
}

void MyComponent::initSurface(std::shared_ptr<SDL_Renderer> renderer)
{
    (void)renderer;
    _texture_manager.loadTexture("assets/image.bmp", "bmp", renderer);
}