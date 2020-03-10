/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** menu_pause
*/

#include "include/my_hunter.h"

int start_button(variables_t *object, menu_t *menu)
{
    float y1 = object->event.mouseButton.y;
    float x1 = object->event.mouseButton.x;

    if ((x1 >= menu->play.pos.x && x1 <= (menu->play.pos.x + 345)) &&
        (y1 >= menu->play.pos.y && y1 <= (menu->play.pos.y + 150)))
        return 1;
    return 0;
}

int tuto_button(variables_t *object, menu_t *menu)
{
    float y1 = object->event.mouseButton.y;
    float x1 = object->event.mouseButton.x;

    if ((x1 >= menu->tutorial.pos.x && x1 <= (menu->tutorial.pos.x + 345)) &&
        (y1 >= menu->tutorial.pos.y && y1 <= (menu->tutorial.pos.y + 150)))
        return 1;
    return 0;
}

void create_tuto(button_t *button, sfVector2f position, char *str)
{
    sfVector2f scale = {0.5, 0.75};
    sfVector2f text = {position.x + 86, position.y + 32};
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

void create_start(button_t *button, sfVector2f position, char *str)
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

void create_menu(menu_t *menu)
{
    sfVector2f position_play = {475, 140};
    sfVector2f position_tuto = {475, 350};
    sfVector2f position_exit = {475, 560};

    menu->background.sprite = sfSprite_create();
    menu->background.texture =
        sfTexture_createFromFile("Textures/background.png", NULL);
    menu->background.scale.x = 2.2;
    menu->background.scale.y = 4;
    sfSprite_setTexture(menu->background.sprite,
    menu->background.texture, sfTrue);
    sfSprite_setScale(menu->background.sprite, menu->background.scale);
    create_start(&(menu->play), position_play, "Play");
    create_tuto(&(menu->tutorial), position_tuto, "Tutorial");
    create_exit(&(menu->exit), position_exit, "Exit");
}
