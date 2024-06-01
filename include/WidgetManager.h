#ifndef WIDGETMANAGER_H
#define WIDGETMANAGER_H

#include <map>
#include <string>
#include <algorithm>
#include <memory>
#include "../include/Widget.h"

struct EventData;

/**
 * @brief The WidgetManager class manages widgets.
 */
class WidgetManager
{
public:
    /**
     * @brief Adds a widget to the manager.
     * 
     * @param key The key to associate with the widget.
     * @param widget A shared pointer to the widget.
     */
    void addWidget(std::string key, std::shared_ptr<Widget> widget);

    /**
     * @brief Removes a widget from the manager.
     * 
     * @param key The key of the widget to remove.
     */
    void removeWidget(std::string key);

    /**
     * @brief Hides a widget.
     * 
     * @param key The key of the widget to hide.
     */
    void hideWidget(std::string key);

    /**
     * @brief Shows a widget.
     * 
     * @param key The key of the widget to show.
     */
    void showWidget(std::string key);

    /**
     * @brief Renders the widgets.
     * 
     * @param renderer A shared pointer to the SDL renderer.
     * @param size The window size.
     */
    void renderWidgets(std::shared_ptr<SDL_Renderer> renderer, std::pair<int32_t, int32_t>& size);

    /**
     * @brief Handles the widget events.
     * 
     * @param event The event data.
     * @param size The window size.
     */
    void handleEvent(const EventData& event, std::pair<int32_t, int32_t>& size);

    /**
     * @brief Retrieves a widget by key.
     * 
     * @param key The key of the widget to retrieve.
     * @return A shared pointer to the requested widget.
     */
    std::shared_ptr<Widget>& getWidget(const std::string& key);

    /**
     * @brief Retrieves a widget by key.
     * 
     * @param key The key of the widget to retrieve.
     * @return A shared pointer to the requested widget.
     */
    std::shared_ptr<Widget>& operator[](const std::string& key);
private:
    std::map<std::string, std::shared_ptr<Widget>> _widgets;    ///< The widgets.
};

#endif // WIDGETMANAGER_H