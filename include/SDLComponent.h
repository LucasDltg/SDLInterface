#ifndef SDLCOMPONENT_H
#define SDLCOMPONENT_H

#include "../include/TextureManager.h"
#include <mutex>
#include <deque>
#include <atomic>

class SDLApp;
struct ComponentData;

/**
 * @brief The EventData struct represents an SDL event with additional shared data.
 */
struct EventData
{
    SDL_Event event;               ///< The SDL event.
    std::shared_ptr<void> data1;   ///< Additional shared data (optional).
    std::shared_ptr<void> data2;   ///< Additional shared data (optional).
};

/**
 * @brief The SDLComponent class represents a base class for SDL components.
 */
class SDLComponent {
public:
    friend SDLApp;
    friend ComponentData;

    /**
     * @brief Constructor for SDLComponent.
     */
    SDLComponent();

    /**
     * @brief Sets the dimensions of the surface.
     * 
     * @param width The width of the surface.
     * @param height The height of the surface.
     * @param renderer The SDL renderer to set dimensions for.
     */
    virtual void setSurfaceDimensions(const uint32_t width, const uint32_t height, std::shared_ptr<SDL_Renderer> renderer) final;

    /**
     * @brief Handles SDL events.
     * 
     * This method should be overridden by subclasses to handle specific events.
     */
    virtual void handleEvents() = 0;

    /**
     * @brief Updates the component.
     * 
     * This method should be overridden by subclasses to update the component's state.
     * 
     * @param delta_time The time elapsed since the last update.
     */
    virtual void update(const uint64_t delta_time) = 0;

    /**
     * @brief Renders the component.
     * 
     * This method should be overridden by subclasses to render the component.
     * 
     * @param renderer The SDL renderer to render the component with.
     * @return A shared pointer to the SDL texture representing the rendered component.
     */
    virtual const std::shared_ptr<SDL_Texture> render(std::shared_ptr<SDL_Renderer> renderer) = 0;

    /**
     * @brief Initializes the surface.
     * 
     * This method should be overridden by subclasses to initialize the surface after the initial size is known.
     * This method is called by the SDLApp after the component is added (so the size is known and can be accessed via _surface)
     * 
     * @param renderer The SDL renderer to initialize the surface for.
     */
    virtual void initSurface(std::shared_ptr<SDL_Renderer> renderer) = 0;

protected:
    std::shared_ptr<SDL_Texture> _texture; ///< The SDL texture.
    std::pair<int32_t, int32_t> _texture_size; ///< The size of the texture
    std::atomic<bool> _is_running; ///< Flag indicating if the component is running.
    TextureManager _texture_manager; ///< The texture manager for the component.

    /**
     * @brief Pop an event from the event queue.
     * 
     * @return The popped event.
     */
    EventData popEvent();

    /**
     * @brief Check if there are events in the event queue.
     * 
     * @return True if there are events, false otherwise.
     */
    bool hasEvents() const;

private:
    std::deque<EventData> _events; ///< The events for the component.

    /**
     * @brief Push an event onto the event queue.
     * 
     * @param event The event to push.
     */
    void pushEvent(const EventData& event);
};

#endif
