#include "scene.h"

#include <obj/load.h>
#include <obj/draw.h>

void init_scene(Scene* scene)
{
    scene->rotation = 0.0;
    load_model(&(scene->cube), "assets/models/cube.obj");
    scene->texture_id = load_texture("assets/textures/raptor.png");
    
    load_model(&(scene->porsche), "assets/models/porsche.obj");
    

    //glBindTexture(GL_TEXTURE_2D, scene->texture_id);

    scene->material.ambient.red = 0.0;
    scene->material.ambient.green = 0.0;
    scene->material.ambient.blue = 0.0;

    scene->material.diffuse.red = 0.1; //1 volt
    scene->material.diffuse.green = 0.1; //1 volt
    scene->material.diffuse.blue = 0.1;

    scene->material.specular.red = 0.5;
    scene->material.specular.green = 0.5;
    scene->material.specular.blue = 0.5;//0 mind 3

    scene->material.shininess = 32; // 0
}

void set_lighting()
{
    float ambient_light[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float diffuse_light[] = { 1.0f, 1.0f, 1.0, 1.0f };
    float specular_light[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float position[] = { 0.0f, 0.0f, 10.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}


void set_material(const Material* material)
{
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue
    };

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue
    };

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}

void update_scene(Scene* scene, double time)
{
    //scene->rotation += 10 * time;
    scene->light.position.x = scene->light.position.x + scene->light.speed.x * time * 2;
    scene->light.position.y = scene->light.position.y + scene->light.speed.y * time * 2;
    scene->light.position.z = scene->light.position.z + scene->light.speed.z * time * 2;

    if(scene->light.brightness > 255){
        scene->light.bspeed = -1;
    }

    if(scene->light.brightness < 0){
       scene->light.bspeed = 1;
    }
    
    scene->light.brightness += scene->light.bspeed / 2;
    scene->light.diffuse.red = scene->light.brightness / 255.0;
    scene->light.diffuse.green = scene->light.brightness / 255.0;
    scene->light.diffuse.blue = scene->light.brightness / 255.0;
}

void set_light_speed(Scene* scene, float x)
{
    scene->light.speed.x = x;
}

void set_light_side_speed(Scene* scene, float y)
{
    scene->light.speed.y = y;
}

void set_light_lift_speed(Scene* scene, float z)
{
    scene->light.speed.z = z;
}

void set_brightness(Scene* scene, float brightness)
{
    scene->light.brightness += brightness;
    if(scene->light.brightness > 255){
        scene->light.brightness = 255;
    }
    else if(scene->light.brightness < 0){
        scene->light.brightness = 0;
    }

    scene->light.diffuse.red = scene->light.brightness / 255.0;
    scene->light.diffuse.green = scene->light.brightness / 255.0;
    scene->light.diffuse.blue = scene->light.brightness / 255.0;

}

void render_scene(const Scene* scene)
{
    set_material(&(scene->material));
    set_lighting(&(scene->light));
    draw_origin();
    draw_porsche(scene);
    draw_cat(scene);
   // draw_model(&(scene->cube));
}


void draw_cat(const Scene* scene){
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->texture_id);
    glTranslatef(5, 0, 0);
    //glRotatef(180, 1, 0, 0);
    //glRotatef(180, 0, 1, 0);
    //glRotatef(scene->rotation, 0, 0, 1);
    glScalef(1, 1, 1);
    set_material(&(scene->material));
    //set_lighting(&(scene->light));
    //set_material(&(scene->plastic_material));
    draw_model(&(scene->cube));
    glPopMatrix();
}

void draw_porsche(const Scene* scene){
    glPushMatrix();
    glTranslatef(0, 0, 0.8);
    glScalef(1.5, 1.5, 1.5);
    glRotatef(90, 1, 0, 0);
    set_material(&(scene->material));
    //set_material(&(scene->gold_material));
    draw_model(&(scene->porsche));
    glPopMatrix();
}

void draw_origin()
{
    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);

    glEnd();
}