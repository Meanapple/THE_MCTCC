//
// Created by jan on 26.07.18.
//

#ifndef MCTCC_MAP_HPP
#define MCTCC_MAP_HPP


#include <SDL_system.h>
#include "../Objects/Scene.hpp"

namespace mctcc {

    typedef struct entity_object
    {
        int id = 0;
        b2Vec2 position;
        /*
         *  0 ???
         *  1 Player
         *  2 Static Entity
         *  3 Dynamic Entity
         *  4 Kinematic Entity
         *  5 Sprite
         */
        int entity_type;
    };

    class TileMap {
    public:

        TileMap(Scene* sc, int tile_width = 64, int tile_height = 64, int map_size_width = 10, int map_size_length = 10, int** ids = NULL,
            std::string = "../res/unknown.png");
        ~TileMap();

        void assign_ids(int  amount_width, int amount_height, int** ids);

        void generate_map();

        void generate_entities();

        void render();

        void scale_map(double f);

        void scale_map_by_screen();

    private:
        //Tile Size
        int tile_width;
        int tile_height;

        //Tileset Size
        int tileset_width;
        int tileset_height;

        //Map size
        int size_w;
        int size_h;

        //Scale
        double scale = 1;

        Scene* scene;

        SDL_Texture* tile_set;
        int** all_ids;
        entity_object* all_entities;
    };

}

#endif //MCTCC_MAP_HPP
