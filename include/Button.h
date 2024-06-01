#include "../include/Widget.h"
#include "../include/EventData.h"
#include <SDL2/SDL.h>
#include <functional>
#include <memory>


class Button : public Widget
{
public:
    Button(SDL_FRect rect, uint32_t color, std::function<void()> onClick);

    void render(std::shared_ptr<SDL_Renderer> renderer, std::pair<int32_t, int32_t>& size) override;
    void handleEvent(const EventData& event, std::pair<int32_t, int32_t>& size) override;

private:
    uint32_t _color;
    std::function<void()> _onClick;
};