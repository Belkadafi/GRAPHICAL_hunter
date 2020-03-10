/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** menu_pause
*/

#include "include/my_hunter.h"

void create_button(button_t *button, sfVector2f position, char *str)
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

void menu_pause(variables_t *object, menu_t menu)
{
    sfRenderWindow_setMouseCursorVisible(object->window, sfTrue);
    sfRenderWindow_drawSprite(object->window, menu.background.sprite, NULL);
    sfRenderWindow_drawSprite(object->window, menu.continu.sprite, NULL);
    sfRenderWindow_drawText(object->window, menu.continu.text, NULL);
    sfRenderWindow_drawSprite(object->window, menu.restart.sprite, NULL);
    sfRenderWindow_drawText(object->window, menu.restart.text, NULL);
    sfRenderWindow_drawSprite(object->window, menu.exit.sprite, NULL);
    sfRenderWindow_drawText(object->window, menu.exit.text, NULL);
}

void create_menu_pause(menu_t *menu)
{
    sfVector2f position_continu = {475, 140};
    sfVector2f position_restart = {475, 350};

    create_button(&(menu->continu), position_continu, "Continue");
    create_button(&(menu->restart), position_restart, "Restart");
}

void create_game_over(variables_t *object, sfVector2f scale, sfVector2f pos)
{
    sfVector2f text_pos = {370, 530};

    object->game_over.posText = text_pos;
    object->game_over.scale = scale;
    object->game_over.pos = pos;
    object->game_over.sprite = sfSprite_create();
    object->game_over.texture =
        sfTexture_createFromFile("Textures/game-over.png", NULL);
    sfSprite_setTexture(object->game_over.sprite,
        object->game_over.texture, sfTrue);
    sfSprite_setScale(object->game_over.sprite, object->game_over.scale);
    sfSprite_setPosition(object->game_over.sprite, object->game_over.pos);
    object->game_over.text = sfText_create();
    object->game_over.font =
    sfFont_createFromFile("Textures/AldotheApache.ttf");
    sfText_setCharacterSize(object->game_over.text, 75);
    sfText_setFont(object->game_over.text, object->game_over.font);
    sfText_setString(object->game_over.text, "click to restart");
    sfText_setColor(object->game_over.text, sfBlack);
    sfText_setPosition(object->game_over.text, object->game_over.posText);
}

int manage_game_over(sfClock *clock, float max, int status)
{
    sfTime time;
    float seconds;

    if (status == 5)
        time = sfClock_getElapsedTime(clock);
    else {
        sfClock_restart(clock);
        return 0;
    }
    seconds = time.microseconds / 1000000.0;
    if (seconds > max)
        return 1;
    return 0;
}