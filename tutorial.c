/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** tutorial
*/

#include "include/my_hunter.h"

void tuto(variables_t *object, bird_t *bird, plan_t *background)
{
    sfRenderWindow_setMouseCursorVisible(object->window, sfFalse);
    bird->next = NULL;
    bird->pos.x += 5;
    set_cursor_position(object);
    if (my_clock(bird->mouvement, 0.1))
        move_rect(&bird->rect, 110, 220);
    if (bird->pos.x >= 1280)
        bird->pos.x = -330;
    sfSprite_setTextureRect(bird->sprite, bird->rect);
    sfSprite_setPosition(bird->sprite, bird->pos);
    sprite_draw(object, bird, background);
    sfRenderWindow_drawSprite(object->window, object->cursor.sprite, NULL);
    sfRenderWindow_drawText(object->window, object->tuto.text, NULL);
    if (object->tuto.test <= 0)
        object->status = 1;
}

void create_tutorial(variables_t *object)
{
    object->game_over.scale.x = 2.5;
    object->game_over.scale.y = 2.5;
    object->game_over.pos.x = 350;
    object->game_over.pos.y = 150;
    object->tuto.test = 2;
    object->tuto.text = sfText_create();
    object->tuto.font = sfFont_createFromFile("Textures/AldotheApache.ttf");
    sfText_setFont(object->tuto.text, object->tuto.font);
    sfText_setCharacterSize(object->tuto.text, 50);
    sfText_setColor(object->tuto.text, sfBlack);
    sfText_setString(object->tuto.text, "KILL THE BIRDS\n"
    "To kill them, click on them, \n every time you will click\none more"
    " bird will spawn. if one of them reach the right side\n of the "
    "screen you'll lose a life\nyou have two lives"
    " and then it\'s \ngame over.\n"
    " You can press escape to pause the game\n"
    "Kill two birds to begin\nGOOD LUCK");
}

void manage_button(variables_t *object,
bird_t *bird, plan_t *background, menu_t *menu)
{
    if (object->status == 0)
        display_menu(object, *menu);
    if (object->status == 1)
        game_loop(object, bird, background);
    if (object->status == 2)
        tuto(object, bird, background);
    if (object->status == 4)
        menu_pause(object, *menu);
    if (object->status == 5)
        game_over(object, background);
}

void print_help(void)
{
    write(1, "MY_HUNTER\n"
    "Click on the birds to kill them you have a main menu"
    "and you can pause the game\n"
    "read the tutorial in the main menu for more details.\n", 142);
}