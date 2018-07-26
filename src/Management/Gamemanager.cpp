//
// Created by jan on 22.07.18.
//

#include "Config.hpp"
#include "Gamemanager.hpp"
#include "../Objects/Entity.hpp"

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
        initializeSDL();

        m_scene = new Scene(this, m_renderer, m_window);
    }

    Gamemanager::~Gamemanager()
    {
        // Close SDL
        closeSDL();
    }

    void Gamemanager::run()
    {

        int lol = 0;

        // When true, the game ends
        bool quit = false;

        // SDL_Event for mouse and keyboard input
        SDL_Event e;

        /// FRAME RATE
        int frame_ticks;

        // Keyboard inputs
        const Uint8 *currentKeyStates;

        /// ---
        /// CONTROLLER SUPPORT
        /// ---
        int MaxJoysticks = SDL_NumJoysticks();

        int ControllerIndex = 0;

        game_controller = nullptr;

        for(int i = 0; i < MaxJoysticks ; i++)
        {
            if (!SDL_IsGameController(i))
                continue;
            ControllerIndex = i;
            game_controller = SDL_GameControllerOpen(ControllerIndex);
            controller_used = true;
            break;
        }
        /// ---


        if(game_controller == nullptr)
            std::cout << "No controller" << std::endl;
        else
            std::cout << "Controller plugged in" << std::endl;

        // Start main loop and event handling
        while ( !quit ) {

            // Process events, detect quit signal for window closing
            while (SDL_PollEvent(&e)) {
                switch (e.type) {
                    case SDL_QUIT:
                        quit = true;
                        break;
                    default:
                        break;
                }
            }

            // Clear screen and render level
            SDL_RenderClear(m_renderer);

            /// TODO Input

            /// TODO Scene Frame
            m_scene->frame();

            // Update screen
            SDL_RenderPresent(m_renderer);
        }
    }

    void Gamemanager::end_current_scene()
    {
        delete m_scene;
        m_scene = nullptr;
    }

    void Gamemanager::start_new_scene(Scene *scene)
    {
        end_current_scene();
        m_scene = scene;
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
                window_width,
                window_height,
                SDL_WINDOW_SHOWN);

        if (m_window == nullptr) {
            std::cout << "SDL window could not be generated: " << SDL_GetError() << std::endl;
        } else {

        // Create renderer for the SDL main window
            m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

            if (m_renderer == nullptr) {
                std::cout << "SDL could not generate renderer: " << SDL_GetError() << std::endl;
            } else {
        // Set background color for renderer
                SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);
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