#include "../include/WidgetManager.h"

void WidgetManager::addWidget(std::string key, std::shared_ptr<Widget> widget)
{
    _widgets[key] = widget;
}

void WidgetManager::removeWidget(std::string key)
{
    _widgets.erase(key);
}

void WidgetManager::hideWidget(std::string key)
{
    _widgets[key]->_is_hidden = true;
}

void WidgetManager::showWidget(std::string key)
{
    _widgets[key]->_is_hidden = false;
}

void WidgetManager::renderWidgets(std::shared_ptr<SDL_Renderer> renderer, std::pair<int32_t, int32_t>& size)
{
    for (auto widget : _widgets)
    {
        if (!widget.second->_is_hidden)
        {
            widget.second->render(renderer, size);
        }
    }
}

void WidgetManager::handleEvent(const EventData& event, std::pair<int32_t, int32_t>& size)
{
    for (auto widget : _widgets)
    {
        if (!widget.second->_is_hidden)
        {
            widget.second->handleEvent(event, size);
        }
    }
}

std::shared_ptr<Widget>& WidgetManager::operator[](const std::string& key)
{
    return _widgets[key];
}