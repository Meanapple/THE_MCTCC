//
// Created by jan on 22.07.18.
//

#ifndef MCTCC_GAMEMANAGER_HPP
#define MCTCC_GAMEMANAGER_HPP

#include <SDL.h>

#include <Box2D/Box2D.h>
#include "Scene.hpp"

namespace mctcc {
    class Scene;
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
        /// Ends last scene and starts the new one
        void start_new_scene(Scene* scene);
        /// Ends last scene
        void end_current_scene();

    private:
        /// Controller Support
        bool controller_used = false;
        SDL_GameController* game_controller;

        /// SDL Renderer
        SDL_Renderer* m_renderer;

        /// SDL Window
        SDL_Window* m_window;

        /// Currently Active Scene
        Scene* m_scene;
    };
}

#endif //MCTCC_GAMEMANAGER_HPP
