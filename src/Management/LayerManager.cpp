//
// Created by jan on 24.07.18.
//

#include <iostream>
#include "LayerManager.hpp"
#include "Config.hpp"
#include "../Objects/Sprite.hpp"

namespace mctcc
{
    LayerManager::LayerManager(Scene *o_sc) : scene(o_sc)
    {
        layer_list = new std::set<Sprite*>[100];
    }

    LayerManager::~LayerManager()
    {
        if(layer_list)
        {
            layer_list->clear();
            delete layer_list;
        }
    }

    bool LayerManager::has_layer(int q_layer)
    {
        if(q_layer < 0 || q_layer >= 100)
            return false;

        return layer_list[q_layer].empty();
    }

    void LayerManager::add_sprite(Sprite *spr, int layer)
    {
        if(layer < 0 || layer > 100)
            return;
        spr->set_layer(layer);
        layer_list[layer].insert(spr);
    }

    void LayerManager::render(int min_bound, int max_bound)
    {
        for(int i = min_bound; i < max_bound; i++)
        {
            if(layer_list[i].empty())
                continue;
            for(auto it = layer_list[i].begin(); it != layer_list[i].end(); ++it)
            {
                (*it)->render();
            }
        }
    }

    Sprite* LayerManager::delete_sprite(long id, int layer)
    {
        Sprite* deleted_sprite;
        if(layer >= 0 || layer <= 100)
        {
            if(layer_list[layer].empty())
                std::cout << "hhu" << std::endl;
            if(layer_list[layer].empty())
                return deleted_sprite;
            for(auto it = layer_list[layer].begin(); it != layer_list[layer].end(); ++it)
            {
                if((*it)->get_id() == id)
                {
                    deleted_sprite = (*it);
                    layer_list[layer].erase((*it));
                    break;
                }
            }
        }else{
            for(int i = 0; i < 100; i++)
            {
                if(layer_list[i].empty())
                    continue;
                for(auto it = layer_list[i].begin(); it != layer_list[i].end(); ++it)
                {
                    if((*it)->get_id() == id)
                    {
                        deleted_sprite = (*it);
                        layer_list[layer].erase((*it));
                        break;
                    }
                }
            }
        }
        return deleted_sprite;
    }
}