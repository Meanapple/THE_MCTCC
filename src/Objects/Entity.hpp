//
// Created by jan on 23.07.18.
//

#ifndef MCTCC_ENTITY_HPP
#define MCTCC_ENTITY_HPP

#include <Box2D/Box2D.h>
#include "Sprite.hpp"
#include "../Management/EntityManager.hpp"

namespace mctcc {
    class EntityManager;
    class Entity {
    public:
        static long entity_static_id;
        /// Create entity using b2world, a body definition, a fixture definiton, and sdl shit
        Entity(EntityManager* em, b2World* world, b2BodyDef* b_def, b2FixtureDef* f_def, Sprite* spr);
        /// Deleting the entity
        ~Entity();
        /// Called every frame
        void act();

        /// Getter
        inline b2Body* get_body(){ return m_body; }
        inline Sprite* get_sprite() { return m_sprite; }
        inline long get_id() { return entity_id; }
    private:
        /// ID
        long entity_id = 0;

        /// Entity Manager Pointer
        EntityManager* em;

        // World Pointer
        b2World* o_world;

        // Body
        b2Body* m_body;

        // Fixture
        b2FixtureDef* m_fixture;

        // Entity Sprite
        Sprite* m_sprite;
    };

}

#endif //MCTCC_ENTITY_HPP
