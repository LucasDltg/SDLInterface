#ifndef SDLCOMPONENT_H
#define SDLCOMPONENT_H

#include "../include/TextureManager.h"
#include <mutex>
#include <deque>
#include <atomic>

class SDLApp;
struct ComponentData;

struct EventData
{
    SDL_Event event;
    std::shared_ptr<void> data1;
    std::shared_ptr<void> data2;
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
     */
    virtual void setSurfaceDimensions(const uint32_t width, const uint32_t height, std::shared_ptr<SDL_Renderer> renderer) final;

    /**
     * @brief Handles SDL events.
     * 
     * This method should be overridden by subclasses to handle specific events.
     * 
     * @param event The SDL event to handle.
     * @param data1 Additional shared data (optional).
     * @param data2 Additional shared data (optional).
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
     * @return A shared pointer to the SDL surface representing the rendered component.
     */
    virtual const std::shared_ptr<SDL_Texture> render(std::shared_ptr<SDL_Renderer> renderer) = 0;

    /**
     * @brief Initializes the surface.
     * 
     * This method should be overridden by subclasses to initialize the surface after the initial size is known.
     * This method is called by the SDLApp after the component is added (so the size is known and can be accessed via _surface)
     */
    virtual void initSurface(std::shared_ptr<SDL_Renderer> renderer) = 0;

protected:
    std::shared_ptr<SDL_Texture> _texture; ///< The SDL surface.
    std::atomic<bool> _is_running; ///< Flag indicating if the component is running.
    TextureManager _texture_manager; ///< The texture manager for the component.
    EventData popEvent();
    bool hasEvents() const;

private:
    std::deque<EventData> _events; ///< The events for the component.
    void pushEvent(const EventData& event);
};

#endif
