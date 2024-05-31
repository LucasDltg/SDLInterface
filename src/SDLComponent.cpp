#include "../include/SDLComponent.h"

SDLComponent::SDLComponent(bool run)
    : _texture(nullptr, SDL_DestroyTexture), _texture_size({0, 0}), _is_running(run), _texture_manager()
{}

void SDLComponent::setSurfaceDimensions(uint32_t width, uint32_t height, std::shared_ptr<SDL_Renderer> renderer)
{
    _texture.reset(SDL_CreateTexture(renderer.get(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height), SDL_DestroyTexture);
    if (!_texture.get())
    {
        throw std::runtime_error("SDL_CreateRGBSurface failed");
    }
    _texture_manager.updateTextures(renderer);
    _texture_size = {width, height};
}

void SDLComponent::onResize(const uint32_t width, const uint32_t height, std::shared_ptr<SDL_Renderer> renderer)
{
    (void)renderer;
    (void)width;
    (void)height;
}

void SDLComponent::pushEvent(const EventData& event)
{
    _events.push_back(event);
}

void SDLComponent::setRunning(bool running)
{
    _is_running.store(running);
}

bool SDLComponent::isRunning() const
{
    return _is_running.load();
}

std::shared_ptr<SDL_Texture> SDLComponent::getTexture() const
{
    return _texture;
}

EventData SDLComponent::popEvent()
{
    EventData event;
    if (_events.size() > 0)
    {
        event = _events.front();
        _events.pop_front();
    }
    return event;
}

bool SDLComponent::hasEvents() const
{
    return _events.size() > 0;
}