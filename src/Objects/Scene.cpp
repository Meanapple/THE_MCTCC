//
// Created by jan on 23.07.18.
//

#include <iostream>
#include "Scene.hpp"
#include "Sprite.hpp"
#include "../Management/Util.hpp"

namespace mctcc
{

    Scene::Scene(Gamemanager* gm, SDL_Renderer *renderer, SDL_Window *window) : o_gm(gm), o_renderer(renderer), o_window(window)
    {
        initializeWorld();

        lm = new LayerManager(this);
        em = new EntityManager(this);

        /// Create Tilemap
        m_map = new TileMap(this, 0);
        m_map->scale_map_by_screen();
        m_map->generate_map();

        /// Vornberger
        b2BodyDef definiton;
        definiton.position.Set(2,1);
        definiton.angle = 0;
        definiton.type = b2_dynamicBody;
        b2FixtureDef* fixture = new b2FixtureDef();
        b2PolygonShape* box = new b2PolygonShape();
        box->SetAsBox(1,1);
        fixture->shape = box;
        fixture->density = 2;
        /// Ground
        /// TODO Sprite und Physics sind nicht zusammen
        b2BodyDef grounddef;
        grounddef.position.Set(0, 10);
        grounddef.angle = 0;
        grounddef.type = b2_staticBody;
        b2FixtureDef* groundfix = new b2FixtureDef();
        b2PolygonShape* groundbox = new b2PolygonShape();
        groundbox->SetAsBox(10,1);
        groundfix->shape = groundbox;
        groundfix->density = 2;

        Sprite* spr = new Sprite(o_renderer, LoadTexture(o_renderer, "../res/vornberger.png"), create_rect(16,16,16,16), create_rect(0,0,500,500), nullptr);
        Sprite* groundspr = new Sprite(o_renderer, LoadTexture(o_renderer, "../res/vornberger.png"), create_rect(16,16,100,100), create_rect(0,0,500,500), nullptr);
        lm->add_sprite(spr, 10);
        lm->add_sprite(groundspr, 2);

        Entity* ground = new Entity(em, world, &grounddef, groundfix, groundspr);
        Entity* player = new Entity(em , world, &definiton, fixture, spr);
        em->add_player(player);
        em->add_entity(ground);
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
        gravity = new b2Vec2(0, 10);
        /// Box2D World
        world = new b2World(*gravity);
    }

    void Scene::frame()
    {
        lm->render();
        em->calculate_actions();

        world->Step((float32) 1/20, (int32) 8 , (int32) 3 );
    }
}