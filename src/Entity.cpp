//
// Created by jan on 23.07.18.
//

#include "Entity.hpp"
#include <iostream>
#include <SDL.h>

namespace mctcc
{

    Entity::Entity(Scene* o_gm, b2World *world, b2BodyDef *b_def, b2FixtureDef* f_def, Sprite* spr) : gm(o_gm), m_sprite(spr)
    {
        if(world == nullptr || b_def == nullptr || f_def == nullptr)
            std::cout << " Error initializing Entity : nullptr at world / b_def / f_def" << std::endl;

        // copy pointers
        o_world = world;
        m_fixture = f_def;

        // Create Body
        m_body = o_world->CreateBody(b_def);
        m_body->CreateFixture(m_fixture);

        m_sprite->set_owner(this);
    }

    Entity::~Entity()
    {
        delete gm->get_layermanager()->delete_sprite(m_sprite->get_id(), m_sprite->get_layer());
        m_sprite = nullptr;

        o_world->DestroyBody(m_body);
        m_body = nullptr;
    }

    void Entity::act()
     {
        std::cout << " Box2D " <<  m_body->GetPosition().y  << " SDL: << "  << m_sprite->get_target_rect()->y << std::endl;
    }
}