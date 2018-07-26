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

    typedef struct premade_map
    {
        int tile_w;
        int tile_h;
        int map_size_w;
        int map_size_h;
        int** ids;
        std::string tileset_name;
    };

    class TileMap {
    public:

        static premade_map test_map;

        TileMap(Scene* sc, int id);
        ~TileMap();

        void assign_ids(int  amount_width, int amount_height, int** ids);

        void generate_map();

        void generate_entities();

        void render();

        void scale_map(double f);

        void scale_map_by_screen();

    private:
        /// Create all static premade maps
        static void initialize_premade_maps();
        /// Flag that all maps have been created
        static bool init_done;
        /// Convert premade_map into actual Map
        void convert_premade_map(premade_map* pm);

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
