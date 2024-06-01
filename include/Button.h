#include "../include/Widget.h"
#include "../include/EventData.h"
#include <SDL2/SDL.h>
#include <functional>
#include <memory>

/**
 * @brief The Button class represents a button widget.
 */
class Button : public Widget
{
public:
    /*
        * @brief Button constructor.
        * @param rect The button rectangle.
        * @param color The button color.
        * @param onClick The function to call when the button is clicked.
    */
    Button(SDL_FRect rect, uint32_t color, std::function<void()> onClick);

    /**
     * @brief Renders the button.
     * @param renderer The SDL renderer.
     * @param size The window size.
     */
    void render(std::shared_ptr<SDL_Renderer> renderer, std::pair<int32_t, int32_t>& size) override;

    /**
     * @brief Handles the button events.
     * @param event The event data.
     * @param size The window size.
     */
    void handleEvent(const EventData& event, std::pair<int32_t, int32_t>& size) override;

private:
    uint32_t _color;                /**< The button color. */
    std::function<void()> _onClick; /**< The function to call when the button is clicked. */
};