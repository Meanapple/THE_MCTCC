//
// Created by jan on 23.07.18.
//

#include <iostream>
#include "Scene.hpp"
#include "Sprite.hpp"
#include "../Management/Util.hpp"

namespace mctcc
{
    int TEMP_SIZE = 10;

    Scene::Scene(Gamemanager* gm, SDL_Renderer *renderer, SDL_Window *window) : o_gm(gm), o_renderer(renderer), o_window(window)
    {
        initializeWorld();

        lm = new LayerManager(this);
        em = new EntityManager(this);

        /// Create Test TileMap
        ///// TODO this is shit tier
        int** test_array = new int*[TEMP_SIZE];
        for(int i = 0; i < TEMP_SIZE ; i++)
        {
            test_array[i] = new int[TEMP_SIZE];
            for(int j = 0; j < TEMP_SIZE; j++)
            {
                if(i == 0 || j == 0 || i == TEMP_SIZE-1 || j == TEMP_SIZE-1)
                    test_array[i][j] = 7;
                else
                    test_array[i][j] = 1;
            }
        }
        std::string s = "../res/Tilesets/tile_set_1.png";

        m_map = new TileMap(this, 16,16,10,10, test_array, "../res/InfA_PureTileset.png");
        m_map->scale_map_by_screen();
        m_map->generate_map();

        for(int i = 0; i < TEMP_SIZE ; i++)
            delete [] test_array[i];
        delete test_array;
        /// SHIT TIER ENDS HERE

        b2BodyDef definiton;
        definiton.position.Set(0,10);
        definiton.angle = 0;
        definiton.type = b2_dynamicBody;
        b2FixtureDef* fixture = new b2FixtureDef();
        b2PolygonShape* box = new b2PolygonShape();
        box->SetAsBox(2,2);
        fixture->shape = box;
        fixture->density = 2;

        Sprite* spr = new Sprite(o_renderer, LoadTexture(o_renderer, "../res/vornberger.png"), create_rect(16,16,500,500), create_rect(0,0,500,500), nullptr);
        lm->add_sprite(spr, 10);
        Entity* player = new Entity(em , world, &definiton, fixture, spr);
        em->add_player(player);
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