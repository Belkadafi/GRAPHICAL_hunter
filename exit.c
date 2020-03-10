/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** exit
*/

#include "include/my_hunter.h"

void exit_button(variables_t *object, menu_t *menu)
{
    float y1 = object->event.mouseButton.y;
    float x1 = object->event.mouseButton.x;

    if ((x1 >= menu->exit.pos.x && x1 <= (menu->exit.pos.x + 345)) &&
        (y1 >= menu->exit.pos.y && y1 <= (menu->exit.pos.y + 150) &&
        (object->status == 0 || object->status == 4)))
        object->status = 3;
}

void create_exit(button_t *button, sfVector2f position, char *str)
{
    sfVector2f scale = {0.5, 0.75};
    sfVector2f text = {position.x + 86.25, position.y + 32.5};
    button->sprite = sfSprite_create();
    button->text = sfText_create();
    button->font = sfFont_createFromFile("Textures/amita-bold.ttf");
    sfText_setFont(button->text, button->font);
    sfText_setString(button->text, str);
    button->pos = position;
    button->texture = sfTexture_createFromFile("Textures/button.png", NULL);
    sfText_setCharacterSize(button->text, 50);
    sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    sfSprite_setPosition(button->sprite, position);
    sfSprite_setScale(button->sprite, scale);
    sfText_setPosition(button->text, text);
}

void game_over(variables_t *object, plan_t *background)
{
    for (int i = 0; i < 5; i += 1)
        sfRenderWindow_drawSprite(object->window, background[i].sprite, NULL);
    sfRenderWindow_drawSprite(object->window, object->game_over.sprite, NULL);
    sfRenderWindow_drawText(object->window, object->game_over.text, NULL);
    display_score(object);
}

void manage_restart(variables_t *object)
{
    object->status = 1;
    object->score.score = 0;
}

void create_all(variables_t *object,
    plan_t *background, menu_t *menu)
{
    create_background(background);
    create_object(object);
    create_menu(menu);
    create_menu_pause(menu);
    sfMusic_play(object->music);
    sfRenderWindow_setFramerateLimit(object->window, 120);
}