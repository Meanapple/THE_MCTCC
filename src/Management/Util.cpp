//
// Created by jan on 23.07.18.
//

#include "Util.hpp"
#include <iostream>
#include <SDL_image.h>

namespace mctcc
{
    SDL_Rect create_rect(int x, int y, int w, int h)
    {
        SDL_Rect s;
        s.x = x; s.y = y; s.w = w; s.h = h;
        return s;
    }

    SDL_Rect computeSourceRect(SDL_Texture* texture)
    {
        SDL_Rect src = { 0, 0, 0, 0 };
        if(texture)
        {
            Uint32 format;
            int access, w, h;
            SDL_QueryTexture(texture, &format, &access, &w, &h);
            src.w = w;
            src.h = h;
        }

        return src;
    }

    std::string print_rect(SDL_Rect* str)
    {
        if(str == NULL)
            return "INVALID";
        return "X : " + std::to_string(str->x) + " Y : " + std::to_string(str->y) + " W: " + std::to_string(str->w) + " H: " + std::to_string(str->h);
    }
    std::string print_rect(const SDL_Rect* str)
    {
        if(str == NULL)
            return "INVALID";
        return "X : " + std::to_string(str->x) + " Y : " + std::to_string(str->y) + " W: " + std::to_string(str->w) + " H: " + std::to_string(str->h);
    }

    SDL_Rect copy_rect(SDL_Rect copy)
    {
        return create_rect(copy.x,copy.y,copy.w,copy.h);
    }

    SDL_Texture* LoadTexture(SDL_Renderer* renderer, std::string texFileName)
    {
        // The loaded texture
        SDL_Texture* newTexture = nullptr;

        // Load image at specified path
        SDL_Surface* loadedSurface = IMG_Load(texFileName.c_str());
        if( loadedSurface == nullptr )
        {
            std::cout << "Unable to load image! SDL_image Error: " <<  IMG_GetError() << std::endl;
            return nullptr;
        }
        else
        {
            // Create texture from surface pixels
            newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
            if( newTexture == nullptr )
            {
                std::cout <<  "Unable to create texture from! SDL Error: " << texFileName <<  SDL_GetError() << std::endl;
                return nullptr;
            }

            // Get rid of old loaded surface
            SDL_FreeSurface( loadedSurface );
        }
        return newTexture;
    }
}