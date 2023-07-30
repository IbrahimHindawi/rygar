#pragma once

#include <SDL2/SDL.h>
#include <linmath.h>

#include "engine/types.h"

typedef struct {
    SDL_Window *window;
    f32 width;
    f32 height;
} RenderState;

void render_init(void);
void render_deinit(void);

void render_begin(void);
void render_end(void);
void render_quad(vec2 pos, vec2 size, vec4 color);

