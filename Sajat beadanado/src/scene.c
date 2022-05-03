#include "scene.h"

#include <obj/load.h>
#include <obj/draw.h>
#include <math.h>

void init_scene(Scene* scene,Camera* camera)
{
    scene->rotation = 0.0;
    scene->key_roation = 0.0;
    scene->light = 0.0;
    

    load_model(&(scene->Koenig), "assets/models/Koenigsegg.obj");
  
    load_model(&(scene->porsche), "assets/models/Porsche_911_GT2.obj");
    scene->texture_id = load_texture("assets/textures/Porsche.jpg");

    //scene->texture_Koenig = load_texture("assets/textures/Koenigsegg.mtl");

    load_model(&(scene->audi), "assets/models/AUDIA3.obj");
    scene->texture_audi = load_texture("assets/textures/Audi.jpg");

    load_model(&(scene->house), "assets/models/House.obj");
    scene->texture_house = load_texture("assets/textures/House.jpg");

    load_model(&(scene->key), "assets/models/key.obj");
    scene->texture_key = load_texture("assets/textures/Key.jpg");

    load_model(&(scene->table), "assets/models/table.obj");
    scene->texture_table = load_texture("assets/textures/table_col.jpg");

    load_model(&(scene->movingKey.MoveKey), "assets/models/key.obj");

    scene->texture_help = load_texture("assets/textures/help.jpg");


    scene->material.ambient.red = 1;
    scene->material.ambient.green = 1;
    scene->material.ambient.blue = 1;

    scene->material.diffuse.red = 1; 
    scene->material.diffuse.green = 1; 
    scene->material.diffuse.blue = 1;

    scene->material.specular.red = 1;
    scene->material.specular.green = 1;
    scene->material.specular.blue = 1;

    scene->material.shininess = 50; 

    scene->mat_Koenig.ambient.red = 0.309278;
    scene->mat_Koenig.ambient.green = 0.309278;
    scene->mat_Koenig.ambient.blue = 0.309278;

    scene->mat_Koenig.diffuse.red = 0.17868; //1 volt
    scene->mat_Koenig.diffuse.green = 0.17868; //1 volt
    scene->mat_Koenig.diffuse.blue = 0.17868;

    scene->mat_Koenig.specular.red = 0.5;
    scene->mat_Koenig.specular.green = 0.5;
    scene->mat_Koenig.specular.blue = 0.5;//0 mind 3

    scene->mat_Koenig.shininess = 50; 
}

void set_lighting(const Scene* scene)
{
   float b;
    b = scene->light / 255 ;
    float ambient_light[] = { b, b, b, b };
    float diffuse_light[] = { b, b, b, b };
    float specular_light[] = { b, b, b, b };
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

void set_material2(const Material* mat_Koenig)
{
    float ambient_material_color[] = {
        mat_Koenig->ambient.red,
        mat_Koenig->ambient.green,
        mat_Koenig->ambient.blue
    };

    float diffuse_material_color[] = {
        mat_Koenig->diffuse.red,
        mat_Koenig->diffuse.green,
        mat_Koenig->diffuse.blue
    };

    float specular_material_color[] = {
        mat_Koenig->specular.red,
        mat_Koenig->specular.green,
        mat_Koenig->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(mat_Koenig->shininess));
}

void update_scene(Scene* scene, Camera* camera,double elapsed_time)
{
    scene->movingKey.position.x = camera->position.x;
    scene->movingKey.position.y = camera->position.y;
   

    scene->rotation += 0.5 ;
    scene->key_roation += 3;
}

void render_scene(const Scene* scene)
{
    set_material(&(scene->material));
    //set_material2(&(scene->mat_Koenig));
    set_lighting(scene);
    draw_origin();
    draw_Koenig(scene);
    draw_house(scene);
    draw_table(scene);
    draw_key(scene);
    draw_porsche(scene);
    draw_audi(scene);
    draw_key_move(scene);
}


void draw_porsche(const Scene* scene){
    glPushMatrix();
    glTranslatef(1.5, 1, 0.35);
    glRotatef(90, 1, 0, 0);
    glRotatef(scene->rotation, 0, 1, 0);
    glScalef(0.5, 0.5, 0.5);
    glBindTexture(GL_TEXTURE_2D, scene->texture_id);
    set_material(&(scene->material));
    draw_model(&(scene->porsche));
    glPopMatrix();
}

void draw_Koenig(const Scene* scene){
    glPushMatrix();
    glTranslatef(4.5, 1, 0.05);
    glRotatef(90, 1, 0, 0);
    glRotatef(scene->rotation, 0, 1, 0);
    glScalef(0.05, 0.05, 0.05);
    set_material(&(scene->material));
    draw_model(&(scene->Koenig));
    glPopMatrix();
}

void draw_audi(const Scene* scene){
    glPushMatrix();
    glTranslatef(-1.5, 1, 0.05);
    glRotatef(90, 1, 0, 0);
    glRotatef(scene->rotation, 0, 1, 0);
    glScalef(0.2, 0.2, 0.2);
    glBindTexture(GL_TEXTURE_2D, scene->texture_audi);
    set_material(&(scene->material));
    draw_model(&(scene->audi));
    glPopMatrix();
}


void draw_house(const Scene* scene){
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glRotatef(90, 1, 0, 0);
    glScalef(0.15, 0.15, 0.15);
    glBindTexture(GL_TEXTURE_2D, scene->texture_house);
    set_material(&(scene->material));
    draw_model(&(scene->house));
    glPopMatrix();
}

void draw_table(const Scene* scene){
    glPushMatrix();
    glTranslatef(0, -1, 0);
    glRotatef(90, 1, 0, 0);
    glScalef(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, scene->texture_table);
    set_material(&(scene->material));
    draw_model(&(scene->table));
    glPopMatrix();
}

void draw_key(const Scene* scene){
    glPushMatrix();
    glTranslatef(0, -1, 0.5);
    glRotatef(90, 1, 0, 0);
    glRotatef(scene->key_roation, 0, 1, 0);
    glScalef(0.05, 0.05, 0.05);
    glBindTexture(GL_TEXTURE_2D, scene->texture_key);
    set_material(&(scene->material));
    draw_model(&(scene->key));
    glPopMatrix();
}

void draw_key_move(const Scene* scene){
    float x,y;
    x = scene->movingKey.position.x + 0.1;
    y = scene->movingKey.position.y + 0.06; 
    glBindTexture(GL_TEXTURE_2D, scene->texture_key);
    glPushMatrix();
    glTranslatef(x, y, 0.9);
    glRotatef(90, 1, 0, 0);
    glScalef(0.02, 0.02, 0.02);
    draw_model(&(scene->movingKey));
    glPopMatrix();
}

void Key_up(Scene* scene, int a, Camera* camera){
    int c = a;
    if(c == 1){
        scene->movingKey.position.x = camera->position.x;
        scene->movingKey.position.y = camera->position.y;
        scene->movingKey.position.z = camera->position.z;
    }
}

void set_sun_brightness_inc(Scene* scene, float b)
{
   scene->light += b;

    if(scene->light > 255.0){
        scene->light = 255.0;
    }
    if(scene->light < 0.0){
        scene->light = 0.0;
    }
}

void show_help(GLuint help_texture) {
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, help_texture);

    glBegin(GL_QUADS);
        glTexCoord2f(0, 0);
        glVertex3d(-2, 1.5, -3);
        glTexCoord2f(1, 0);
        glVertex3d(2, 1.5, -3);
        glTexCoord2f(1, 1);
        glVertex3d(2, -1.5, -3);
        glTexCoord2f(0, 1);
        glVertex3d(-2, -1.5, -3);
    glEnd();


    glDisable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);

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