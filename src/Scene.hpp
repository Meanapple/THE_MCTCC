//
// Created by jan on 23.07.18.
//

#ifndef MCTCC_SCENE_HPP
#define MCTCC_SCENE_HPP

#include <Box2D/Box2D.h>
#include <SDL.h>
#include "Gamemanager.hpp"

namespace mctcc {
    class Gamemanager;
    class Scene {
    public:
        /// Constructor
        Scene(Gamemanager* gm, SDL_Renderer* renderer, SDL_Window* window);
        /// Deconstructor
        ~Scene();
        /// Initialize Scene
        void initializeWorld();
        /// One Frame
        void frame();

        inline SDL_Renderer* get_renderer() {return o_renderer;}

    protected:
        /// Gamemanager Pointer
        Gamemanager* o_gm;

        /// Normal Gravity
        const b2Vec2* gravity;

        /// Main World
        b2World* world;

        /// SDL Renderer pointer
        SDL_Renderer* o_renderer;

        /// SDL Window pointer
        SDL_Window* o_window;
    };

}

#endif //MCTCC_SCENE_HPP
