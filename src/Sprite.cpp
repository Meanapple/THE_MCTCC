//
// Created by jan on 23.07.18.
//

#include <iostream>
#include "Sprite.hpp"
#include "Config.hpp"
#include "Entity.hpp"

namespace mctcc
{
    long Sprite::sprite_static_id = 0;

    Sprite::Sprite(SDL_Renderer* rend, SDL_Texture* texture, SDL_Rect target, SDL_Rect source, Entity* o_owner) : m_renderer(rend), m_texture(texture)
    {
        sprite_id = sprite_static_id++;

        owner = nullptr;

        m_sourceRect = source;
        m_targetRect = target;
        m_scale = 1;
        m_globalScaleRect = target;

        if(o_owner)
            owner = o_owner;

        SDL_SetTextureBlendMode(m_texture, SDL_BLENDMODE_BLEND);
    }

    void Sprite::render()
    {
        /// Break if invisible
        if(invisible)
            return;
        ///Calculate Position
        calculate_position();
        /// Apply on Renderer
        SDL_RenderCopyEx(
                m_renderer,
                m_texture,
                &m_sourceRect, &m_globalScaleRect,
                0,
                NULL, SDL_FLIP_NONE);
    }

    void Sprite::calculate_position()
    {
        /// Set x and y Position to Entity Position
        if(owner)
        {
            m_targetRect.x = owner->get_body()->GetPosition().x;
            m_targetRect.y = owner->get_body()->GetPosition().y;
        }

        /// Scale all attributes by Local and Global Scale
        m_globalScaleRect.x = (int) (m_targetRect.x * global_scale_by_screensize * m_scale + m_center);
        m_globalScaleRect.y = (int) (m_targetRect.y * global_scale_by_screensize * m_scale);
        m_globalScaleRect.w = (int) ((m_targetRect.w * global_scale_by_screensize * m_scale) +
                                     (((m_targetRect.x * global_scale_by_screensize * m_scale + m_center))-m_globalScaleRect.x));
        m_globalScaleRect.h = (int) ((m_targetRect.h * global_scale_by_screensize * m_scale) +
                                     (((m_targetRect.y * global_scale_by_screensize * m_scale))-m_globalScaleRect.y));
    }
}