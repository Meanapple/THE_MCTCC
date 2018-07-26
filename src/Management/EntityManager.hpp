//
// Created by jan on 25.07.18.
//

#ifndef MCTCC_ENTITYMANAGER_HPP
#define MCTCC_ENTITYMANAGER_HPP

#include "../Objects/Scene.hpp"
#include "../Objects/Entity.hpp"

namespace mctcc {
    class Scene;
    class EntityManager {
    public:
        /// Keeps Track of all Entities
        EntityManager(Scene* scene);
        /// Deconstructor
        ~EntityManager();

        //INLINER (GETTER)
        inline Entity* get_player(){return player;}
        inline Scene* get_scene() { return scene; }

        /// Go through all entities and lets them do their shit
        void calculate_actions();
        /// Apply Input on Player / Controllable units
        void apply_input_on_controllable_units(double x, double y);
        /// Add entity
        void add_entity(Entity* et);
        /// Add Player specifically
        void add_player(Entity *et);
        /// Asks if Entity exists
        bool entity_exists(long id);
        /// Removes Entity
        void remove_entity(long id);

    private:
        /// Scene Pointer
        Scene* scene;
        /// Vector of all entities
        std::vector<Entity*>* entity_list;
        /// Specific Player Entity
        Entity* player;
    };
}

#endif //MCTCC_ENTITYMANAGER_HPP
