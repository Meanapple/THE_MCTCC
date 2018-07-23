//
// Created by jan on 23.07.18.
//

#include <iostream>
#include "Scene.hpp"
#include "Sprite.hpp"
#include "Util.hpp"


namespace mctcc
{

    Scene::Scene(Gamemanager* gm, SDL_Renderer *renderer, SDL_Window *window) : o_gm(gm), o_renderer(renderer), o_window(window)
    {
        initializeWorld();

        b2BodyDef definiton;
        definiton.position.Set(0,10);
        definiton.angle = 0;
        definiton.type = b2_dynamicBody;
        b2FixtureDef fixture;
        b2PolygonShape box;
        box.SetAsBox(2,2);
        fixture.shape = &box;
        fixture.density = 2;

        Sprite* spr = new Sprite(o_renderer, LoadTexture(o_renderer, "../res/vornberger.png"), create_rect(16,16,500,500), create_rect(0,0,500,500), nullptr);

        player = new Entity(world, &definiton, &fixture, spr);
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
        player->get_sprite()->render();

    }
}