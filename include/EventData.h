#ifndef EVENTDATA_H
#define EVENTDATA_H

#include <SDL2/SDL.h>
#include <memory>

/**
 * @brief The EventData struct represents an SDL event with additional shared data.
 */
struct EventData
{
    SDL_Event event;               ///< The SDL event.
    std::shared_ptr<void> data1;   ///< Additional shared data (optional).
    std::shared_ptr<void> data2;   ///< Additional shared data (optional).
};

#endif // EVENTDATA_H