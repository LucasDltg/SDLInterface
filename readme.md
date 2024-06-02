# SDLInterface
Version: 1.0.0

# This repository provides three major classes for use with the SDL (Simple DirectMedia Layer) library:

## SDLApp:
SDLApp facilitates running multiple programs within the same window. You can achieve this by adding an SDLComponent using the add method and starting it with the run method.
This class utilizes multithreading to improve performance.

## SDLComponent:
To utilize SDLApp, you need to create a class inherited from SDLComponent. Override four methods: handleEvents, update, render, and initSurface.
An example of how to implement this is demonstrated in MyComponent.cpp.

## TextureManager:
TextureManager simplifies the usage of textures from images. It offers the following functionalities:
- loadDefaultTextures: Loads a default texture with the key "default".
- loadTextureFromFile: Loads a texture from a file with your specified key.
- getTexture: Retrieves a pointer to the queried texture.