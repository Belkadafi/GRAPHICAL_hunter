/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** Animation
*/

#include "include/my_hunter.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left < max_value)
        rect->left += offset;
    else
        rect->left = 0;
}

int my_clock(sfClock *clock, float max)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > max) {
        sfClock_restart(clock);
        return 1;
    }
    return 0;
}

void create_cursor(cursor_t *cursor)
{
    cursor->sprite = sfSprite_create();
    cursor->texture = sfTexture_createFromFile("Textures/cursor.png", NULL);
    cursor->scale.x = 0.125;
    cursor->scale.y = 0.125;
    sfSprite_setTexture(cursor->sprite, cursor->texture, sfTrue);
    sfSprite_setScale(cursor->sprite, cursor->scale);
}

void create_object(variables_t *objects)
{
    sfVector2f scale = {3, 3};
    sfVector2f pos = {350, 100};

    objects->game_over.clock = sfClock_create();
    objects->mode.width = 1280;
    objects->mode.height = 720;
    objects->mode.bitsPerPixel = 32;
    objects->window =
    sfRenderWindow_create(objects->mode, "My_hunter", sfClose, NULL);
    create_cursor(&(objects->cursor));
    create_life(&(objects->life));
    create_score(objects);
    objects->music = sfMusic_createFromFile("Textures/music.ogg");
    objects->status = 0;
    create_game_over(objects, scale, pos);
    create_tutorial(objects);
}

void sprite_draw(variables_t *object, bird_t *bird, plan_t *background)
{
    for (int i = 0; i < 5; i += 1)
        sfRenderWindow_drawSprite(object->window, background[i].sprite, NULL);
    draw_birds(bird, object);
    if (object->status == 1)
        sfRenderWindow_drawSprite(object->window, object->cursor.sprite, NULL);
    sfSprite_setTextureRect(object->life.sprite, object->life.rect);
    sfRenderWindow_drawSprite(object->window, object->life.sprite, NULL);
    my_manage_death(object, bird);
}