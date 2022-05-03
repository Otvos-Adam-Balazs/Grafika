#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"
#include "utils.h"

#include <obj/model.h>

typedef struct Key
{
    Model MoveKey;
    GLuint texture_keyid;
    vec3 position;
    vec3 rotation;
} Key;


typedef struct Scene
{
    //float b;
    Model porsche;
    Model house;
    Model Koenig;
    Model audi;
    Model table;
    Model key;
    Key movingKey;
    Material material;
    Material mat_Koenig;
    GLuint texture_id;
    GLuint texture_house;
    GLuint texture_audi;
    GLuint texture_table;
    GLuint texture_key;
    GLuint texture_help;
    float light;
    float rotation;
    float key_roation;
    bool is_help_visible;
} Scene;

/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene, Camera* camera);

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
void update_scene(Scene* scene, Camera* camera, double elapsed_time);

/**
 * Render the scene objects.
 */
void render_scene(const Scene* scene);

/**
 * Draw a porsche.
 */
void draw_porsche(const Scene* scene);

void draw_Koenig(const Scene* scene);

void draw_audi(const Scene* scene);

void draw_house(const Scene* scene);

void draw_table(const Scene* scene);

void draw_key(const Scene* scene);

void draw_key_move(const Scene* scene);

void Key_up(Scene* scene, int a, Camera* camera);

void set_sun_brightness_inc(Scene* scene, float b);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();


#endif /* SCENE_H */
