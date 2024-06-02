#ifndef FONTMANAGER_H
#define FONTMANAGER_H

#include <SDL2/SDL_ttf.h>
#include <string>
#include <map>
#include <memory>

/**
 * @brief The FontManager class manages SDL fonts.
 */

class FontManager
{
public:
    /**
     * @brief Loads a font from file.
     * 
     * @param filename The path to the font file.
     * @param key The key to associate with the loaded font.
     * @param size The font size.
     * @return True if the font was loaded successfully, false otherwise.
     */
    bool loadFontFromFile(const std::string& filename, const std::string& key, int size);

    /**
     * @brief Retrieves a font by key.
     * 
     * @param key The key of the font to retrieve.
     * @return A shared pointer to the requested SDL font.
     */
    std::shared_ptr<TTF_Font> getFont(const std::string& key);

    /**
     * @brief Retrieves a font by key.
     * 
     * @param key The key of the font to retrieve.
     * @return A shared pointer to the requested SDL font.
     */
    std::shared_ptr<TTF_Font> operator[](const std::string& key);

private:
    std::map<std::string, std::shared_ptr<TTF_Font>> _fonts;    ///< The fonts.
};

#endif // FONTMANAGER_H