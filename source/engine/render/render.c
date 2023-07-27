#include <glad/glad.h>
#include "engine/global.h"
#include "engine/render/render.h"
#include "engine/render/render_internal.h"

static RenderStateInternal state = {0};

void render_init(void) {
    global.render.width = 800;
    global.render.height = 640;
    global.render.window = render_init_window(global.render.width, global.render.height);
    render_init_quad(&state.vao_quad, &state.vbo_quad, &state.ebo_quad);
}

void render_deinit(void) {
    /* Frees memory */
    SDL_DestroyWindow(global.render.window);

    /* Shuts down all SDL subsystems */
    SDL_Quit(); 
}

void render_begin(void) {
    glClearColor(0.08f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void render_end(void) {
    SDL_GL_SwapWindow(global.render.window);
}

void render_quad(vec2 pos, vec2 size, vec4 color) {
    glBindVertexArray(state.vao_quad);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
    glBindVertexArray(0);
}
