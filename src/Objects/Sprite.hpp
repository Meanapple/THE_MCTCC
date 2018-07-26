//
// Created by jan on 23.07.18.
//

#ifndef MCTCC_SPRITE_HPP
#define MCTCC_SPRITE_HPP

#include <SDL_system.h>
#include <vector>
#include <Box2D/Box2D.h>

namespace mctcc {
    class Entity;

    class Sprite {

    public:
        /// Static ID
        static long sprite_static_id;

        /// Constructor using renderer and assigned Texture, aswell as Target and Source Rect and a joint Position to be linked with Entity Objects
        Sprite(SDL_Renderer* renderer, SDL_Texture* text, SDL_Rect target, SDL_Rect source, Entity* o_owner = nullptr);

        /// Deconstructor
        virtual ~Sprite() {};

        /// Renders the Texture at given Position with given size
        virtual void render();

        /// Calculates Position each step
        void calculate_position();

        /// Getter for ID
        inline long get_id(){return sprite_id;}
        /// Getter for Target Rect
        inline SDL_Rect* get_target_rect(){return &m_targetRect;}
        /// Getter for Layer
        inline int get_layer(){ return layer; }
        /// Setter for Layer !THIS DOES NOT CHANGE ACTUAL LAYER, USE LAYERMANAGER FOR THIS
        inline int set_layer(int l){ layer = l; }

        /// Set owner after initialization
        inline void set_owner(Entity* o_o){owner = o_o;}

    protected:
        /// Unique ID
        long sprite_id = 0;
        /// Layer
        int layer = 0;

        /// Renderer
        SDL_Renderer* m_renderer;
        /// Texture
        SDL_Texture* m_texture;

        /// Local Scale
        double m_scale = 1;
        /// Screen Center
        double m_center = 0;
        /// Invisible?
        bool invisible = false;
        /// Source Rect
        SDL_Rect m_sourceRect;
        /// Target Rect
        SDL_Rect m_targetRect;
        /// Target Rect after applying global Scale
        SDL_Rect m_globalScaleRect;

        Entity* owner;
    };
}

#endif //MCTCC_SPRITE_HPP
