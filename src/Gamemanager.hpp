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

    private:
        b2Vec2* gravity;

        SDL_Renderer* m_renderer;
        SDL_Window* m_window;
    };
}

#endif //MCTCC_GAMEMANAGER_HPP
