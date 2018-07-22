//
// Created by jan on 22.07.18.
//

#include "Gamemanager.hpp"

#include <iostream>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

namespace mctcc
{
    /// This game will be amazing and awesome

    Gamemanager::Gamemanager()
    {
        // Init SDL
        gravity = new b2Vec2(0, -2);
        initializeSDL();
    }

    Gamemanager::~Gamemanager()
    {
        // Close SDL
        closeSDL();
    }


    void Gamemanager::initializeSDL() {
        // Initialize SDL
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            std::cout << "SDL could not initialize: " << SDL_GetError() << std::endl;
            return;
        }

        // Generate SDL main window
        m_window = SDL_CreateWindow(
                "Info D Jokes",
                SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED,
                1000,
                1000,
                SDL_WINDOW_SHOWN);

        if (m_window == NULL) {
            std::cout << "SDL window could not be generated: " << SDL_GetError() << std::endl;
        } else {

        // Create renderer for the SDL main window
            m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

            if (m_renderer == NULL) {
                std::cout << "SDL could not generate renderer: " << SDL_GetError() << std::endl;
            } else {
        // Set background color for renderer
                SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 0);
            }
        }

        //Initialize SDL_mixer
        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
            std::cout << "SDL_MUSIC could not initialize! " << std::endl;
        }

        //Initialize PNG loading
        int imgFlags = IMG_INIT_PNG;
        if (!(IMG_Init(imgFlags) & imgFlags)) {
            std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
        }

        if (TTF_Init() < 0) {
            std::cout << "SDL_ttf could not initialize! SDL_ttf Error: " << IMG_GetError() << std::endl;
        }
    }

    void Gamemanager::closeSDL()
    {
        // Destroy window and renderer

        if(m_renderer)
        {
            SDL_DestroyRenderer(m_renderer);
            m_renderer = 0;
        }


        if(m_window)
        {
            SDL_DestroyWindow(m_window);
            m_window = 0;
        }

        // Quit SDL and SDL_Image
        IMG_Quit();
        SDL_Quit();
    }

}