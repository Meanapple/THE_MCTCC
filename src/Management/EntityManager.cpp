//
// Created by jan on 25.07.18.
//

#include "EntityManager.hpp"
#include "../Objects/Entity.hpp"


namespace mctcc
{
    EntityManager::EntityManager(Scene *o_sc) : scene(o_sc)
    {
        entity_list = new std::vector<Entity*>();
        player = nullptr;
    }

    EntityManager::~EntityManager()
    {
        entity_list->clear();
        delete entity_list;
    }

    void EntityManager::add_entity(Entity *et)
    {
        if(entity_list && !entity_exists(et->get_id()))
        {
            entity_list->push_back(et);
        }
    }

    void EntityManager::add_player(Entity *et) {
        if (entity_list && !entity_exists(et->get_id())) {
            entity_list->push_back(et);
            player = et;
        }
    }

    bool EntityManager::entity_exists(long id)
    {

        for (auto it = entity_list->begin(); it != entity_list->end(); ++it) {
            if ((*it)->get_id() == id)
                return true;
        }

        return false;
    }

    void EntityManager::remove_entity(long id)
    {
    }

    void EntityManager::apply_input_on_controllable_units(double x, double y)
    {
    }

    void EntityManager::calculate_actions()
    {
        for(auto it = entity_list->begin(); it != entity_list->end(); ++it)
        {
            (*it)->act();
        }
    }
}