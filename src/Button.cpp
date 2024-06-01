#include "../include/Button.h"

/* -------------------------- TODO ------------------------------
- add text to button
- add hover effect
- add click effect
- add border
- add border color
- add border width
- add text color
- add text font
- add text size
*/




Button::Button(SDL_FRect rect, uint32_t color, std::function<void()> onClick)
: Widget(rect), _color(color), _onClick(onClick)
{}

void Button::render(std::shared_ptr<SDL_Renderer> renderer, std::pair<int32_t, int32_t>& size)
{
    SDL_SetRenderDrawBlendMode(renderer.get(), SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer.get(), (_color >> 24) & 0xFF, (_color >> 16) & 0xFF, (_color >> 8) & 0xFF, _color & 0xFF);
    SDL_Rect rect = {static_cast<int32_t>(_rect.x * size.first), static_cast<int32_t>(_rect.y * size.second), static_cast<int32_t>((_rect.w - _rect.x) * size.first), static_cast<int32_t>((_rect.h - _rect.y) * size.second)};
    SDL_RenderFillRect(renderer.get(), &rect);
}

void Button::handleEvent(const EventData& event, std::pair<int32_t, int32_t>& size)
{
    if (event.event.type == SDL_MOUSEBUTTONDOWN)
    {
        if (event.event.button.button == SDL_BUTTON_LEFT)
        {
            if (event.event.button.x >= static_cast<int32_t>(_rect.x * size.first) && event.event.button.x <= static_cast<int32_t>(_rect.w * size.first) &&
                event.event.button.y >= static_cast<int32_t>(_rect.y * size.second) && event.event.button.y <= static_cast<int32_t>(_rect.h * size.second))
            {
                _onClick();
            }
        }
    }
}