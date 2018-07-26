//
// Created by jan on 23.07.18.
//

#ifndef MCTCC_SCENE_HPP
#define MCTCC_SCENE_HPP

#include <Box2D/Box2D.h>
#include <SDL.h>
#include "../Management/Gamemanager.hpp"
#include "../Management/EntityManager.hpp"
#include "../Management/LayerManager.hpp"
#include "../Management/TileMap.hpp"

namespace mctcc {
    class Gamemanager;
    class EntityManager;
    class LayerManager;
    class TileMap;

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
        inline EntityManager* get_entitymanager() { return em; }

    protected:
        /// Gamemanager Pointer
        Gamemanager* o_gm;

        /// Normal Gravity
        const b2Vec2* gravity;

        /// Main World
        b2World* world;

        /// LayerManager
        LayerManager* lm;

        /// EntityManager
        EntityManager* em;

        /// Map Generator
        TileMap* m_map;

        /// SDL Renderer pointer
        SDL_Renderer* o_renderer;

        /// SDL Window pointer
        SDL_Window* o_window;
    };

}

#endif //MCTCC_SCENE_HPP
