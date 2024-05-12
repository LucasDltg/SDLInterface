#include "../include/SDLComponent.h"


class MyComponent2 : public SDLComponent {
public:
    friend class MyComponent;

    MyComponent2(uint32_t color);
    void handleEvents() override;
    void update(const uint64_t delta_time) override;
    const std::shared_ptr<SDL_Texture> render(std::shared_ptr<SDL_Renderer> renderer) override;
    void initSurface(std::shared_ptr<SDL_Renderer> renderer) override;
private:
    uint32_t _color;
};
