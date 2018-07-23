//
// Created by jan on 23.07.18.
//

#include "Entity.hpp"
#include <Box2D/Box2D.h>
#include <iostream>

namespace mctcc
{

    Entity::Entity(b2World *world, b2BodyDef *b_def, b2FixtureDef* f_def)
    {
        if(world == nullptr || b_def == nullptr || f_def == nullptr)
            std::cout << " Error initializing Entity : nullptr at world / b_def / f_def" << std::endl;

        // copy pointers
        o_world = world;
        m_fixture = f_def;

        // Create Body
        m_body = o_world->CreateBody(b_def);
        m_body->CreateFixture(m_fixture);
    }

    Entity::~Entity()
    {
        o_world->DestroyBody(m_body);
    }
}