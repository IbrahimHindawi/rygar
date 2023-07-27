#include "SDL2/SDL_events.h"
#include "SDL2/SDL_video.h"
#ifdef _MSC_VER
    #define SDL_MAIN_HANDLED
#endif

#include <math.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <glad/glad.h>
#include <SDL2/SDL.h>

#include <linmath.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "engine/types.h"
#include "engine/global.h"
#include "engine/render/render.h"


int main(int argc, char *argv[]) {

    render_init();
    bool should_quit = false;
    while (!should_quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT: {
                    should_quit = true;
                    break;
                }
                default: {
                    break;
                }
            }
        }
        render_begin();
        render_quad(
                (vec2){global.render.width * 0.5, global.render.height * 0.5}, 
                (vec2){50, 50}, 
                (vec4){1, 1, 1, 1} 
        );
        render_end();
    }

    render_deinit();
    return 0;
}

