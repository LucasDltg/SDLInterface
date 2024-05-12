#include "../include/MyComponent.h"
#include <SDL2/SDL_ttf.h>
#include <iostream>

MyComponent::MyComponent(uint32_t color)
    : SDLComponent(), _color(color), _compo(color)
{
}

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
        else if (event.event.type == SDL_MOUSEBUTTONDOWN)
        {
            
        }
    }
}

void MyComponent::update(const uint64_t delta_time)
{
    (void)delta_time;
}

const std::shared_ptr<SDL_Texture> MyComponent::render(std::shared_ptr<SDL_Renderer> renderer)
{
    // draw image on background
    SDL_SetRenderDrawBlendMode(renderer.get(), SDL_BLENDMODE_NONE);
    SDL_RenderCopy(renderer.get(), _texture_manager.getTexture("bmp").get(), nullptr, nullptr);

    int32_t width, height;
    SDL_QueryTexture(_texture.get(), nullptr, nullptr, &width, &height);

    // draw big rectangle
    SDL_SetRenderDrawBlendMode(renderer.get(), SDL_BLENDMODE_MUL);
    SDL_Rect rect = {width / 4, height / 4, width / 2, height / 2};
    SDL_SetRenderDrawColor(renderer.get(), (_color >> 24) & 0xFF, (_color >> 16) & 0xFF, (_color >> 8) & 0xFF, _color & 0xFF);
    SDL_RenderFillRect(renderer.get(), &rect);

    SDL_SetRenderDrawBlendMode(renderer.get(), SDL_BLENDMODE_NONE);
    // draw rectangle on top left
    rect = {width / 4, height / 4, width / 4, height / 4};
    SDL_RenderCopy(renderer.get(), _texture_manager.getTexture("def").get(), nullptr, &rect);

    // draw rectangle on bottom right
    rect = {width / 2, height / 2, width / 4, height / 4};
    SDL_RenderCopy(renderer.get(), _texture_manager.getTexture("defa").get(), nullptr, &rect);

    rect = {width / 4, height / 2, width / 4, height / 4};
    // SDL_Texture *t = SDL_CreateTexture(_renderer.get(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width / 4, height / 4);
    
    // SDL_SetRenderTarget(_renderer.get(), t);
    // SDL_SetRenderDrawBlendMode(_renderer.get(), SDL_BLENDMODE_NONE);
    // _compo.render(_renderer);
    // SDL_SetRenderTarget(_renderer.get(), _texture.get());
    // SDL_RenderCopy(_renderer.get(), t, nullptr, &rect);
    // SDL_DestroyTexture(t);

    SDL_SetRenderDrawBlendMode(renderer.get(), SDL_BLENDMODE_NONE);
    SDL_SetRenderTarget(renderer.get(), _compo._texture.get());
    _compo.render(renderer);
    SDL_SetRenderTarget(renderer.get(), _texture.get());
    SDL_RenderCopy(renderer.get(), _compo._texture.get(), nullptr, &rect);

    std::cout << "Component1 " << _texture_size.first << " " << _texture_size.second << std::endl;
    return _texture;
}

void MyComponent::initSurface(std::shared_ptr<SDL_Renderer> renderer)
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

    _compo.initSurface(renderer);
    _compo.setSurfaceDimensions(_texture_size.first / 4, _texture_size.second / 4, renderer);
}

void MyComponent::beforeResize(const uint32_t width, const uint32_t height, std::shared_ptr<SDL_Renderer> renderer)
{
    (void)width;
    (void)height;
    (void)renderer;
    if(_compo._texture)
    {
        _compo.setSurfaceDimensions(_texture_size.first / 4, _texture_size.second / 4, renderer);
    }
}