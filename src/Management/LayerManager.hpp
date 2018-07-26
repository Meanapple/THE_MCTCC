//
// Created by jan on 24.07.18.
//

#ifndef MCTCC_LAYERMANAGER_HPP
#define MCTCC_LAYERMANAGER_HPP

#include <set>
#include "../Objects/Scene.hpp"

namespace mctcc {
    class Gamemanager;
    class Sprite;

    class LayerManager {
    public:
        /// Layer Manager keeps track of all Sprites and orders them to render according to their layer
        LayerManager(Scene* scene);
        /// Deconstructor
        ~LayerManager();
        /// Renders all layers from min to max bound, -1 for all
        void render(int min_bound = 0, int max_bound = 100);
        /// Adds a Sprite to the LayerManager
        void add_sprite(Sprite* spr, int layer);
        /// Deletes Sprite by id
        Sprite* delete_sprite(long id, int layer = -1);
        /// Asks if layer q_layer is empty
        bool has_layer(int q_layer);

    private:
        /// Gamemanager Pointer
        Scene* scene;
        /// Set of 100 Layers
        std::set<Sprite*>* layer_list;
    };
}

#endif //MCTCC_LAYERMANAGER_HPP
