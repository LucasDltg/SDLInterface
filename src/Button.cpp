#include "../include/Button.h"

/* -------------------------- TODO ------------------------------
- add text to button
- add hover effect
- add click effect
- add text color
- add text font
- add text size
*/

Button::Button(SDL_FRect rect, uint32_t color, std::shared_ptr<SDL_Texture> texture, uint32_t border_color, uint32_t border_width, std::function<void()> on_click, std::function<void()> on_hover)
: Widget(rect), _color(color), _texture(texture), _border_color(border_color), _border_width(border_width), _on_click(on_click), _on_hover(on_hover)
{}

void Button::render(std::shared_ptr<SDL_Renderer> renderer, std::pair<int32_t, int32_t>& size)
{
    SDL_SetRenderDrawBlendMode(renderer.get(), SDL_BLENDMODE_BLEND);

    // draw border
    SDL_SetRenderDrawColor(renderer.get(), (_border_color >> 24) & 0xFF, (_border_color >> 16) & 0xFF, (_border_color >> 8) & 0xFF, _border_color & 0xFF);
    SDL_Rect rect = {static_cast<int32_t>(_rect.x * size.first), static_cast<int32_t>(_rect.y * size.second), static_cast<int32_t>((_rect.w - _rect.x) * size.first), static_cast<int32_t>((_rect.h - _rect.y) * size.second)};
    SDL_RenderFillRect(renderer.get(), &rect);

    // draw background
    rect.x += _border_width; rect.y += _border_width; rect.w -= _border_width * 2; rect.h -= _border_width * 2;
    if(_texture)
    {
        SDL_RenderCopy(renderer.get(), _texture.get(), nullptr, &rect);
    }
    else
    {
        SDL_SetRenderDrawColor(renderer.get(), (_color >> 24) & 0xFF, (_color >> 16) & 0xFF, (_color >> 8) & 0xFF, _color & 0xFF);
        SDL_RenderFillRect(renderer.get(), &rect);
    }
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
                _on_click();
            }
        }
    }
    else if (event.event.type == SDL_MOUSEMOTION)
    {
        if (event.event.motion.x >= static_cast<int32_t>(_rect.x * size.first) && event.event.motion.x <= static_cast<int32_t>(_rect.w * size.first) &&
            event.event.motion.y >= static_cast<int32_t>(_rect.y * size.second) && event.event.motion.y <= static_cast<int32_t>(_rect.h * size.second))
        {
            _on_hover();
        }
    }
}