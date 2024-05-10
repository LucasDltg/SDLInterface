#include "../include/SDLApp.h"
#include "../include/MyComponent.h"
#include <SDL2/SDL.h>

int32_t main(int32_t argc, char* argv[])
{
    (void)argc;
    (void)argv;

    SDLApp app(SDLApp::_MIN_SCREEN_WIDTH, SDLApp::_MIN_SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE, "assets/arial.ttf");
    app.addComponent(std::make_shared<MyComponent>(0xFF0000FF), {0.0f, 0.5f, 1.0f, 1.0f}, true);
    app.addComponent(std::make_shared<MyComponent>(0x00FF00FF), {0.5f, 0.0f, 1.0f, 0.5f}, true);
    app.addComponent(std::make_shared<MyComponent>(0x0000FFFF), {0.0f, 0.0f, 0.5f, 0.5f});
    
    // get screen refresh rate
    SDL_DisplayMode screen_mode;
    SDL_GetDisplayMode(0, 0, &screen_mode);
    
    app.run({0}, screen_mode.refresh_rate); 
    app.run({1}, screen_mode.refresh_rate); 
    app.run({2}, screen_mode.refresh_rate); 
    app.run({}, screen_mode.refresh_rate); 

    return 0;
}