#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <memory>
#include <SDL2/SDL.h>

struct EventData;

/**
 * @brief The Widget class represents a widget.
 */
class Widget
{
    friend class WidgetManager;
public:
    /**
     * @brief Widget constructor.
     * @param rect The widget rectangle.
     */
    Widget(SDL_FRect rect) : _rect(rect), _is_hidden(false) {}

    /**
     * @brief Gets the widget rectangle.
     * @param renderer The SDL renderer.
     * @param size The window size.
     */
    virtual void render(std::shared_ptr<SDL_Renderer> renderer, std::pair<int32_t, int32_t>& size) = 0;

    /**
     * @brief Handles the widget events.
     * @param event The event data.
     * @param size The window size.
     */
    virtual void handleEvent(const EventData& event, std::pair<int32_t, int32_t>& size) = 0;

protected:
    SDL_FRect _rect;    ///< The widget rectangle.
    bool _is_hidden;    ///< Indicates if the widget is hidden.
};

#endif // WIDGET_HPP