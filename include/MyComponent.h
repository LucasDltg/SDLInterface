#include "../include/SDLComponent.h"
#include "../include/MyComponent2.h"

class MyComponent : public SDLComponent {
public:
    MyComponent(uint32_t color);
    void handleEvents() override;
    void update(const uint64_t delta_time) override;
    void render(std::shared_ptr<SDL_Renderer> renderer) override;
    void initSurface(std::shared_ptr<SDL_Renderer> renderer) override;
    void onResize(const uint32_t width, const uint32_t height, std::shared_ptr<SDL_Renderer> renderer);
private:
    uint32_t _color;
    MyComponent2 _compo;
};
