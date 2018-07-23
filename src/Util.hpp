//
// Created by jan on 23.07.18.
//

#ifndef MCTCC_UTIL_HPP
#define MCTCC_UTIL_HPP

#include <SDL.h>
#include <iostream>

namespace mctcc {
    class Util {
        /// Create a SDL_Rect from given coordinates
        SDL_Rect create_rect(int x, int y, int w, int h);
        /// Copies a rect
        SDL_Rect const copy_rect(SDL_Rect);
        /// Computes a source rect the size of the Texture
        SDL_Rect computeSourceRect(SDL_Texture*);
        /// Loads a Texture from a string
        SDL_Texture* LoadTexture(
                SDL_Renderer* renderer, std::string texFileName);
        /// Prints out a rect
        std::string print_rect(SDL_Rect* rec);
        /// Prints out a rect
        std::string print_rect(const SDL_Rect* rec);
    };
}

#endif //MCTCC_UTIL_HPP
