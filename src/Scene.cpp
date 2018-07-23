//
// Created by jan on 23.07.18.
//

#include <iostream>
#include "Scene.hpp"


namespace mctcc
{

    Scene::Scene(Gamemanager* gm, SDL_Renderer *renderer, SDL_Window *window) : o_gm(gm), o_renderer(renderer), o_window(window)
    {
        initializeWorld();
    }

    Scene::~Scene()
    {
        if(world)
            delete world;
        if(gravity)
            delete gravity;
    }

    void Scene::initializeWorld()
    {
        /// Gravity Vector
        gravity = new b2Vec2(0, -2);
        /// Box2D World
        world = new b2World(*gravity);
    }

    void Scene::frame()
    {
        Scene* new_scene = new Scene(o_gm , o_renderer, o_window);
        o_gm->start_new_scene(new_scene);
    }
}