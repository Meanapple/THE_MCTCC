//
// Created by jan on 26.07.18.
//

#include "TileMap.hpp"
#include "Util.hpp"
#include "Config.hpp"

namespace mctcc
{
    /// Premade Maps
    premade_map TileMap::test_map;
    bool TileMap::init_done = false;

    TileMap::TileMap(Scene* o_sc, int id) : scene(o_sc)
    {
        all_ids = nullptr;

        if(!init_done)
            initialize_premade_maps();

        switch(id)
        {
            case 0:
            default:
            {
                convert_premade_map(&test_map);
                 break;
            }
        }
    }

    TileMap::~TileMap()
    {
        if(all_ids)
        {
            for(int i = 0; i < size_h; i++)
                delete[] all_ids[i];
            delete all_ids;
        }
    }

    void TileMap::convert_premade_map(premade_map* pm)
    {
        /// Load Tileset for this Map
        tile_set = LoadTexture(scene->get_renderer(), pm->tileset_name);

        /// Computes how big the tileset is. Now we know how many tiles per row/column there are
        SDL_Rect temp = computeSourceRect(tile_set);


        tile_width = pm->tile_w;
        tile_height = pm->tile_h;
        size_w = pm->map_size_w;
        size_h = pm->map_size_h;

        tileset_height = temp.h/size_h;
        tileset_width = temp.w/size_w;

        assign_ids(size_w, size_h, pm->ids);
    }

    void TileMap::initialize_premade_maps()
    {
        /// Map #0
        /// Test Map
        int temp_size = 10;

        int** test_array_1 = new int*[temp_size];
        for(int i = 0; i < temp_size ; i++)
        {
            test_array_1[i] = new int[temp_size];
            for(int j = 0; j < temp_size; j++)
            {
                if(i == 0 || j == 0 || i == temp_size-1 || j == temp_size-1)
                    test_array_1[i][j] = 7;
                else
                    test_array_1[i][j] = 1;
            }
        }

        test_map = {16,16,10,10, test_array_1, "../res/InfA_PureTileset.png"};

        init_done = true;

        /// Map #1
        /// Tutorial
        /// TODO shit
    }

    void TileMap::scale_map_by_screen()
    {
        global_scale_by_screensize = (double)((double)window_height / ((double)size_h * (double)tile_height)) ;
        std::cout << window_height << " " << size_h << " " << tile_height << " " <<  global_scale_by_screensize << std::endl;
    }

    void TileMap::generate_map()
    {
        if(all_ids == nullptr)
            return;

        SDL_Rect source;
        SDL_Rect target;
        int id = 0;
        int max_id = tileset_width * tileset_height;

        for(int i = 0; i < size_h; i++)
        {
            for(int j = 0; j < size_w; j++)
            {
                // Assign id
                id = all_ids[i][j]-1;
                if(id < -1 || id > max_id)
                    id = 0;

                //Compute rects
                target = {i*tile_width,j*tile_height, tile_width, tile_height};
                source = {(id%tileset_width)*16,(id/tileset_width)*16,tile_width, tile_height};

                //Create Sprite
                Sprite* temp  = new Sprite(scene->get_renderer(), tile_set, target,source );
                scene->get_layermanager()->add_sprite(temp, 10);
            }
        }
    }

    void TileMap::assign_ids(int w, int h, int** ids)
    {
        if(ids == NULL || w <= 0 || h <= 0)
            return;

        std::cout << h << " " << w << std::endl;

        all_ids = new int*[h];
        for(int i = 0; i < h; i++)
        {
            all_ids[i] = new int[w];
            for(int j = 0; j < w; j++)
            {
                all_ids[i][j] = ids[i][j];
            }
        }
    }
}