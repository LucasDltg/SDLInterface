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
        * @param texture The button texture.
        * @param border_color The button border color.
        * @param border_width The button border width.
        * @param on_click The function to call when the button is clicked.
        * @param on_hover The function to call when the button is hovered.
    */
    Button(SDL_FRect rect, uint32_t color=0xFFFFFFFF, std::shared_ptr<SDL_Texture> texture=nullptr, uint32_t border_color=0xFFFFFFFF, uint32_t border_width=0, std::function<void()> on_click=[](){}, std::function<void()> on_hover=[](){});

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

public:
    uint32_t _color;                /**< The button color. */
    std::shared_ptr<SDL_Texture> _texture; /**< The button texture. */
    uint32_t _border_color;         /**< The button border color. */
    uint32_t _border_width;         /**< The button border width.*/
private:
    std::function<void()> _on_click; /**< The function to call when the button is clicked. */
    std::function<void()> _on_hover; /**< The function to call when the button is clicked. */
};