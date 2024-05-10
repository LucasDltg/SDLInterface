#ifndef SDLAPP_H
#define SDLAPP_H

#include "../include/SDLComponent.h"
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_audio.h>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <set>

struct ComponentData
{
    std::shared_ptr<SDLComponent> component;
    SDL_FRect location;
    int32_t fps;
    bool draw_fps;
};

/**
 * @brief The SDLApp class represents the main application that manages the SDL window and components.
 * Multiple components can be added to the SDLApp.
 */
class SDLApp {
public:
    /**
     * @brief Minimum screen width for the SDL window.
     */
    static const _Float32 _MIN_SCREEN_WIDTH;

    /**
     * @brief Minimum screen height for the SDL window.
     */
    static const _Float32 _MIN_SCREEN_HEIGHT;
    
    SDLApp(const int32_t screen_width, const int32_t screen_height, const uint32_t window_flags = 0, const std::string& font_path = "arial.ttf");

    
    void addComponent(const std::shared_ptr<SDLComponent>& component, const SDL_FRect location={0.0f, 0.0f, 1.0f, 1.0f}, const bool draw_fps=false);

    void run(std::set<int32_t> targets = {}, const int32_t desired_fps=60);
    
private:
    std::shared_ptr<SDL_Window> _window; ///< The SDL window.
    std::shared_ptr<SDL_Renderer> _renderer; ///< The SDL renderer.
    std::shared_ptr<TTF_Font> _font; ///< The SDL font.
    std::atomic<bool> _is_running; ///< Flag to indicate if the application is running.
    std::vector<ComponentData> _components; ///< The components of the application.
    std::pair<uint32_t, uint32_t> _window_dimensions; ///< Dimensions of the SDL window.
    std::mutex _mutex; ///< Mutex to protect the components vector & window dimensions.

    
    void handleEvents(ComponentData& target, SDL_Event& event);

    void render(ComponentData& target);

    void loop(ComponentData& target, const int32_t desired_fps=60);
};

#endif // SDLAPP_H