#ifndef WIDGETMANAGER_H
#define WIDGETMANAGER_H

#include <map>
#include <string>
#include <algorithm>
#include <memory>
#include "../include/Widget.h"

struct EventData;

class WidgetManager
{
public:
    void addWidget(std::string key, std::shared_ptr<Widget> widget);
    void removeWidget(std::string key);
    void hideWidget(std::string key);
    void showWidget(std::string key);
    void renderWidgets(std::shared_ptr<SDL_Renderer> renderer, std::pair<int32_t, int32_t>& size);
    void handleEvent(const EventData& event, std::pair<int32_t, int32_t>& size);

    std::shared_ptr<Widget>& operator[](const std::string& key);
private:
    std::map<std::string, std::shared_ptr<Widget>> _widgets;
};

#endif // WIDGETMANAGER_H