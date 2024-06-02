#include "../include/FontManager.h"

bool FontManager::loadFontFromFile(const std::string& filename, const std::string& key, int size)
{
    std::shared_ptr<TTF_Font> font(TTF_OpenFont(filename.c_str(), size), TTF_CloseFont);
    if (!font.get())
    {
        return false;
    }
    _fonts[key] = font;
    return true;
}

std::shared_ptr<TTF_Font> FontManager::getFont(const std::string& key)
{
    auto it = _fonts.find(key);
    if (it == _fonts.end())
    {
        return nullptr;
    }
    return it->second;
}

std::shared_ptr<TTF_Font> FontManager::operator[](const std::string& key)
{
    return getFont(key);
}