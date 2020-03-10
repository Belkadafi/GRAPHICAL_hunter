/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** menu_pause
*/

#include "include/my_hunter.h"

bird_t *my_get_button(variables_t *object, bird_t *bird, menu_t *menu)
{
    if (start_button(object, menu) && (object->status == 0 ||
        object->status == 4))
        object->status = 1;
    if (tuto_button(object, menu) && object->status == 0) {
        object->status = 2;
        bird->pos.x = -110;
    }
    if (tuto_button(object, menu) && object->status == 4) {
        destroy_bird(bird->next);
        bird->next = NULL;
        bird->pos.x = -110;
        object->status = 1;
        object->life.rect.left = 0;
        object->score.score = 0;
    }
    exit_button(object, menu);
    return (bird);
}

void destroy_cursor(cursor_t *cursor)
{
    sfSprite_destroy(cursor->sprite);
    sfTexture_destroy(cursor->texture);
}

void destroy_bird(bird_t *bird)
{
    bird_t *tempo;

    while (bird) {
        tempo = bird;
        bird = bird->next;
        sfSprite_destroy(tempo->sprite);
        sfTexture_destroy(tempo->texture);
        sfImage_destroy(tempo->image);
        sfClock_destroy(tempo->anim);
        sfClock_destroy(tempo->mouvement);
        sfClock_destroy(tempo->respawn);
        free(tempo);
    }
}

void destroy_menu(menu_t *menu)
{
    sfText_destroy(menu->exit.text);
    sfText_destroy(menu->play.text);
    sfText_destroy(menu->tutorial.text);
    sfFont_destroy(menu->exit.font);
    sfFont_destroy(menu->play.font);
    sfFont_destroy(menu->tutorial.font);
    sfSprite_destroy(menu->play.sprite);
    sfSprite_destroy(menu->exit.sprite);
    sfSprite_destroy(menu->tutorial.sprite);
    sfSprite_destroy(menu->background.sprite);
    sfTexture_destroy(menu->play.texture);
    sfTexture_destroy(menu->exit.texture);
    sfTexture_destroy(menu->tutorial.texture);
    sfTexture_destroy(menu->background.texture);
}

void my_destroyer(variables_t *object, bird_t *bird, menu_t *menu)
{
    destroy_menu(menu);
    destroy_bird(bird);
    destroy_cursor(&object->cursor);
    sfMusic_destroy(object->music);
    sfRenderWindow_destroy(object->window);
}