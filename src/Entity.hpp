//
// Created by jan on 23.07.18.
//

#ifndef MCTCC_ENTITY_HPP
#define MCTCC_ENTITY_HPP

#include <Box2D/Box2D.h>
#include "Sprite.hpp"
#include "Scene.hpp"

namespace mctcc {
    class Scene;
    class Entity {
    public:
        /// Create entity using b2world, a body definition, a fixture definiton, and sdl shit
        Entity(Scene* gm, b2World* world, b2BodyDef* b_def, b2FixtureDef* f_def, Sprite* spr);
        /// Deleting the entity
        ~Entity();
        /// Called every frame
        void act();
        /// Get Body
        inline b2Body* get_body(){ return m_body; }
        /// Get Sprite
        inline Sprite* get_sprite() { return m_sprite; }
    private:
        /// Gamemanager
        Scene* gm;

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
