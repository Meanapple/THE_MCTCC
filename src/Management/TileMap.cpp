//
// Created by jan on 26.07.18.
//

#include "TileMap.hpp"
#include "Util.hpp"
#include "Config.hpp"

namespace mctcc
{

    TileMap::TileMap(Scene* o_sc, int w, int h, int m_w, int m_h, int** ids, std::string tileset) : scene(o_sc) ,
                                                                                            tile_width(w),
                                                                                            tile_height(h),
                                                                                            size_w(m_w),
                                                                                            size_h(m_h)
    {
        all_ids = nullptr;

        /// Load Tileset for this Map
        tile_set = LoadTexture(scene->get_renderer(), tileset);
        /// Computes how big the tileset is. Now we know how many tiles per row/column there are
        SDL_Rect temp = computeSourceRect(tile_set);
        tileset_height = temp.h/h;
        tileset_width = temp.w/w;

        /// Error checking
        if(tile_set == nullptr)
            std::cout << "Map Error: No Tileset" << std::endl;
        if(ids != nullptr)
            assign_ids(size_w, size_h, ids);
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

    void TileMap::render()
    {

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