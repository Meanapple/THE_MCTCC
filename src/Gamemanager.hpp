//
// Created by jan on 22.07.18.
//

#ifndef MCTCC_GAMEMANAGER_HPP
#define MCTCC_GAMEMANAGER_HPP

#include <SDL.h>

#include <Box2D/Box2D.h>

namespace mctcc {

    class Gamemanager {
    public:
        /// Initialisiert SDL, startet Startup Screen
        Gamemanager();
        /// Schließt SDL, löscht aktives Level
        ~Gamemanager();
        /// SDL Initialisieren
        void initializeSDL();
        /// SDL Schließen
        void closeSDL();
        /// Game Loop
        void run();

    private:
        /// Controller Support
        bool controller_used = false;
        SDL_GameController* game_controller;

        /// Normal Gravity
        b2Vec2* gravity;

        /// Main World
        b2World* world;

        /// SDL Renderer
        SDL_Renderer* m_renderer;

        /// SDL Window
        SDL_Window* m_window;
    };
}

#endif //MCTCC_GAMEMANAGER_HPP
