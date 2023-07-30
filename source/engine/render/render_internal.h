#pragma once

#include <SDL2/SDL.h>
#include "engine/types.h"
#include "engine/render.h"

typedef struct {
    u32 vao_quad;
    u32 vbo_quad;
    u32 ebo_quad;
    u32 shader_default;
    u32 texture_color;
    mat4x4 projection;
} RenderStateInternal;

SDL_Window *render_init_window(u32 width, u32 height);
void render_init_quad(u32 *vao, u32 *vbo, u32 *ebo);
void render_init_color_texture(u32 *texture);
void render_init_shaders(RenderStateInternal *state);
u32 render_shader_create(const char *path_vert, const char *path_frag);
