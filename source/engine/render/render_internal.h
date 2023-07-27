#pragma once

#include <SDL2/SDL.h>
#include "engine/types.h"
#include "engine/render/render.h"

typedef struct {
    u32 vao_quad;
    u32 vbo_quad;
    u32 ebo_quad;
} RenderStateInternal;

SDL_Window *render_init_window(u32 width, u32 height);
void render_init_quad(u32 *vao, u32 *vbo, u32 *ebo);
