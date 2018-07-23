//
// Created by jan on 23.07.18.
//

#ifndef MCTCC_ENTITY_HPP
#define MCTCC_ENTITY_HPP

#include <Box2D/Box2D.h>

namespace mctcc {

    class Entity {
    public:
        // Create entity using b2world, a body definition, a fixture definiton, and sdl shit
        Entity(b2World* world, b2BodyDef* b_def, b2FixtureDef* f_def);
        // Deleting the entity
        ~Entity();
    private:
        // World Pointer
        b2World* o_world;

        // Body
        b2Body* m_body;

        // Fixture
        b2FixtureDef* m_fixture;

    };

}

#endif //MCTCC_ENTITY_HPP
