#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>

typedef struct Scene
{
    //float b;
    Model porsche;
    Model house;
    Model Koenig;
    Model audi;
    Model table;
    Model key;
    Material material;
    Material mat_Koenig;
    GLuint texture_id;
    GLuint texture_house;
    GLuint texture_audi;
    GLuint texture_table;
    GLuint texture_key;
    float light;
    float rotation;
    float key_roation;
    int movingKey;
   // bool is_help_visible;
} Scene;

/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);

/**
 * Set the lighting of the scene.
 */
void set_lighting(const Scene* scene);

/**
 * Set the current material.
 */
void set_material(const Material* material);
void set_material2(const Material* mat_Koenig);

/**
 * Update the scene.
 */
void update_scene(Scene* scene, double elapsed_time);

/**
 * Render the scene objects.
 */
void render_scene(const Scene* scene);

void show_help(Scene* scene);

/**
 * Draw a porsche.
 */
void draw_porsche(const Scene* scene);

void draw_Koenig(const Scene* scene);

void draw_audi(const Scene* scene);

void draw_house(const Scene* scene);

void draw_table(const Scene* scene);

void draw_key(const Scene* scene);

void set_sun_brightness_inc(Scene* scene, float b);

void Movie_model(Scene* scene, Camera* camera);
/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();


#endif /* SCENE_H */
