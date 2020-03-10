/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** mouvement
*/

#include "include/my_hunter.h"

void move_background(plan_t *background)
{
    for (int i = 0; i < 5; i += 1) {
        if (my_clock(background[i].clock, 0.01)) {
            move_rect(&background[i].rect,
            background[i].paralax.speed, background[i].paralax.limit);
            sfSprite_setTextureRect(background[i].sprite, background[i].rect);
        }
    }
}

void animations_bird(bird_t *bird)
{
    bird_t *tempo = bird;

    while (tempo != NULL) {
        if (my_clock(tempo->anim, 0.1))
            move_rect(&(tempo->rect), 110, 220);
        if (my_clock(tempo->mouvement, 0.01))
            tempo->pos.x += 4;
        sfSprite_setTextureRect(tempo->sprite, tempo->rect);
        sfSprite_setPosition(tempo->sprite, tempo->pos);
        tempo = tempo->next;
    }
}

void draw_birds(bird_t *bird, variables_t *object)
{
    bird_t *tempo = bird;

    while (tempo != NULL) {
    sfRenderWindow_drawSprite(object->window, tempo->sprite, NULL);
    tempo = tempo->next;
    }
}

void my_manage_death(variables_t *object, bird_t *bird)
{
    bird_t *tempo = bird;
    int test = 0;

    while (tempo) {
        if (tempo->pos.x >= 1280) {
            test = 1;
            break;
        }
        tempo = tempo->next;
    }
    if (test == 1 && object->status == 1) {
        destroy_bird(bird->next);
        if (object->life.rect.left >= 800)
            object->status = 5;
        move_rect(&object->life.rect, 855, 855);
        bird->next = NULL;
        bird->pos.x = -550;
    }
}

void display_menu(variables_t *object, menu_t menu)
{
    sfRenderWindow_setMouseCursorVisible(object->window, sfTrue);
    sfRenderWindow_drawSprite(object->window, menu.background.sprite, NULL);
    sfRenderWindow_drawSprite(object->window, menu.play.sprite, NULL);
    sfRenderWindow_drawText(object->window, menu.play.text, NULL);
    sfRenderWindow_drawSprite(object->window, menu.tutorial.sprite, NULL);
    sfRenderWindow_drawText(object->window, menu.tutorial.text, NULL);
    sfRenderWindow_drawSprite(object->window, menu.exit.sprite, NULL);
    sfRenderWindow_drawText(object->window, menu.exit.text, NULL);
}