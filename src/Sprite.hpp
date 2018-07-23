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
        /// Constructor using renderer and assigned Texture, aswell as Target and Source Rect and a joint Position to be linked with Entity Objects
        Sprite(SDL_Renderer* renderer, SDL_Texture* text, SDL_Rect target, SDL_Rect source, Entity* o_owner = nullptr);

        /// Deconstructor
        virtual ~Sprite() {};

        /// Renders the Texture at given Position with given size
        virtual void render();

        /// Calculates Position each step
        void calculate_position();

        inline SDL_Rect* get_target_rect(){return &m_targetRect;}
        /// Set owner after initialization
        inline void set_owner(Entity* o_o){owner = o_o;}

    protected:
        SDL_Renderer* m_renderer;
        SDL_Texture* m_texture;

        double m_scale = 1;
        double m_center = 0;

        bool position_has_been_calculated = false;
        bool invisible = false;

        SDL_Rect m_sourceRect;
        SDL_Rect m_targetRect;
        SDL_Rect m_globalScaleRect;

        Entity* owner;
    };
}

#endif //MCTCC_SPRITE_HPP
