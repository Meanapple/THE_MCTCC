//
// Created by jan on 23.07.18.
//

#ifndef MCTCC_SCENE_HPP
#define MCTCC_SCENE_HPP

#include <Box2D/Box2D.h>
#include <SDL.h>
#include "Gamemanager.hpp"
#include "Entity.hpp"
#include "LayerManager.hpp"

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

        /// Getter
        inline SDL_Renderer* get_renderer() {return o_renderer;}
        inline LayerManager* get_layermanager() { return lm; }

    protected:
        /// Gamemanager Pointer
        Gamemanager* o_gm;

        /// Normal Gravity
        const b2Vec2* gravity;

        /// Main World
        b2World* world;

        /// LayerManager
        LayerManager* lm;

        /// SDL Renderer pointer
        SDL_Renderer* o_renderer;

        /// SDL Window pointer
        SDL_Window* o_window;

        /// Player Entity
        Entity* player;
    };

}

#endif //MCTCC_SCENE_HPP
