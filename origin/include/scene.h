#ifndef SCENE_H
#define SCENE_H

#include "camera.h"

typedef struct Scene
{
    float teapot_rotation;
	float sphere_rotation;
	int old_x;
	int old_y;
} Scene;

/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);

/**
 * Update the scene.
 */
void update_scene(Scene* scene);

/**
 * Render the scene objects.
 */
void render_scene(const Scene* scene);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

#endif /* SCENE_H */
