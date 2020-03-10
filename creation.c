/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** creation
*/

#include "include/my_hunter.h"

void fill_background(plan_t *back,
    char *filepath, paralax_t paralax)
{
    back->sprite = sfSprite_create();
    back->texture = sfTexture_createFromFile(filepath, NULL);
    back->pos.x = paralax.position.x;
    back->pos.y = paralax.position.y;
    back->scale.x = 1;
    back->scale.y = 0.7;
    back->limit = paralax.limit;
    back->speed = paralax.speed;
    sfSprite_setTexture(back->sprite, back->texture, sfTrue);
    sfSprite_setScale(back->sprite, back->scale);
    sfSprite_setPosition(back->sprite, back->pos);
    back->rect = paralax.rect;
    sfSprite_setTextureRect(back->sprite, back->rect);
    back->clock = sfClock_create();
}

void create_background(plan_t *background)
{
    paralax_t sky = {0, 1080, {0, 0}, {0, 0, 1920, 1080}};
    background[0].paralax = sky;
    paralax_t ground = {10, 1920, {0, 583}, {0, 0, 1920, 198}};
    background[1].paralax = ground;
    paralax_t plant = {1, 216, {0, 458}, {0, 0, 1689, 216}};
    background[2].paralax = plant;
    paralax_t mountains = {1, 1919, {0, 60}, {0, 0, 1919, 782}};
    background[3].paralax = mountains;
    paralax_t plateau = {5, 1919, {0, 85}, {0, 0, 1919, 750}};
    background[4].paralax = plateau;

    fill_background(&(background[0]), "Textures/sky.png", sky);
    fill_background(&(background[1]), "Textures/ground2.png", ground);
    fill_background(&(background[2]), "Textures/plant.png", plant);
    fill_background(&(background[3]),
    "Textures/mountains2.png", mountains);
    fill_background(&(background[4]),
    "Textures/plateau2.png", plateau);
}

void create_life(life_t *life)
{
    life->sprite = sfSprite_create();
    life->texture = sfTexture_createFromFile("Textures/health.png", NULL);
    sfSprite_setTexture(life->sprite, life->texture, sfTrue);
    life->scale.x = 0.25;
    life->scale.y = 0.25;
    life->rect.top = 0;
    life->rect.left = 0;
    life->rect.width = 855;
    life->rect.height = 520;
    sfSprite_setScale(life->sprite, life->scale);
    sfSprite_setTextureRect(life->sprite, life->rect);
}

void set_cursor_position(variables_t *object)
{
    object->cursor.temp = sfMouse_getPositionRenderWindow(object->window);
    object->cursor.pos.x = object->cursor.temp.x - 64;
    object->cursor.pos.y = object->cursor.temp.y - 64;
    sfSprite_setPosition(object->cursor.sprite, object->cursor.pos);
}

bird_t *create_new_bird(bird_t *bird)
{
    bird_t *tempo;
    tempo = malloc(sizeof(bird_t) * 1);

    fill_bird(tempo);
    tempo->next = bird;
    return (tempo);
}
