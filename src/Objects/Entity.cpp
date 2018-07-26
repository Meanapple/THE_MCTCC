//
// Created by jan on 23.07.18.
//

#include "Entity.hpp"
#include <iostream>
#include <SDL.h>

namespace mctcc
{
    long Entity::entity_static_id = 0;

    Entity::Entity(EntityManager* o_em, b2World *world, b2BodyDef *b_def, b2FixtureDef* f_def, Sprite* spr) : em(o_em), m_sprite(spr)
    {
        if(world == nullptr || b_def == nullptr || f_def == nullptr)
            std::cout << " Error initializing Entity : nullptr at world / b_def / f_def" << std::endl;

        entity_id = entity_static_id++;

        // copy pointers
        o_world = world;
        m_fixture = f_def;

        // Create Body
        m_body = o_world->CreateBody(b_def);
        m_body->CreateFixture(m_fixture);

        if(m_sprite)
        m_sprite->set_owner(this);
    }

    Entity::~Entity()
    {
        delete em->get_scene()->get_layermanager()->delete_sprite(m_sprite->get_id(), m_sprite->get_layer());
        m_sprite = nullptr;

        o_world->DestroyBody(m_body);
        m_body = nullptr;
    }

    void Entity::act()
    {
    }
}