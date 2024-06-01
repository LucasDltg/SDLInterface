#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <memory>
#include <SDL2/SDL.h>

struct EventData;

class Widget
{
    friend class WidgetManager;
public:
    Widget(SDL_FRect rect) : _rect(rect), _is_hidden(false) {}
    virtual void render(std::shared_ptr<SDL_Renderer> renderer, std::pair<int32_t, int32_t>& size) = 0;
    virtual void handleEvent(const EventData& event, std::pair<int32_t, int32_t>& size) = 0;

protected:
    SDL_FRect _rect;
    bool _is_hidden;
};

#endif // WIDGET_HPP