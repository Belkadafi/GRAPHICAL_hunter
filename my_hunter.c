/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** my_hunter
*/

#include "include/my_hunter.h"

bird_t *getposition(variables_t *object, bird_t *bird, menu_t *menu)
{
    sfColor color;
    float y1 = object->event.mouseButton.y;
    float x1 = object->event.mouseButton.x;

    for (bird_t *tmp = bird; tmp != NULL; tmp = tmp->next) {
        if ((x1 >= tmp->pos.x && x1 <= (tmp->pos.x + 110)) &&
            y1 >= tmp->pos.y && y1 <= (tmp->pos.y + 110)) {
            color = sfImage_getPixel(bird->image,
            (x1 - tmp->pos.x), (y1 - tmp->pos.y));
            if (color.a  != 0) {
                tmp->pos.x = -220;
                bird = create_new_bird(bird);
                object->score.score += 1;
                object->tuto.test -= 1;
            }
        }
    }
    return (my_get_button(object, bird, menu));
}

bird_t *analyse_events(variables_t *object, bird_t *bird, menu_t *menu)
{
    while (sfRenderWindow_pollEvent(object->window, &object->event)) {
        if (object->event.type == sfEvtKeyPressed) {
            if (sfKeyboard_isKeyPressed(sfKeyX))
                sfRenderWindow_close(object->window);
            if (sfKeyboard_isKeyPressed(sfKeyEscape) && object->status == 1)
                object->status = 4;
            if (sfKeyboard_isKeyPressed(sfKeyEscape) && object->status == 2)
                object->status = 0;
        }
        if (object->event.type == sfEvtMouseButtonPressed)
            bird = getposition(object, bird, menu);
        if (object->event.type == sfEvtMouseButtonPressed &&
            manage_game_over(object->game_over.clock, 1, object->status))
            manage_restart(object);
        if (object->event.type == sfEvtClosed ||
            object->status == 3)
            sfRenderWindow_close(object->window);
    }
    return (bird);
}

void fill_bird(bird_t *bird)
{
    bird->sprite = sfSprite_create();
    bird->texture =
            sfTexture_createFromFile("Textures/my_hunter.png", NULL);
    bird->pos.x = -330;
    bird->pos.y = (rand()% 400) + 130;
    sfSprite_setPosition(bird->sprite, bird->pos);
    bird->image = sfImage_createFromFile("Textures/my_hunter.png");
    bird->rect.top = 0;
    bird->rect.left = 0;
    bird->rect.height = 110;
    bird->rect.width = 110;
    bird->anim = sfClock_create();
    bird->mouvement = sfClock_create();
    bird->respawn = sfClock_create();
    sfSprite_setTexture(bird->sprite, bird->texture, sfTrue);
}

void game_loop(variables_t *object, bird_t *bird, plan_t *background)
{
    sfRenderWindow_clear(object->window, sfBlack);
    sfSprite_setPosition(bird->sprite, bird->pos);
    set_cursor_position(object);
    sfRenderWindow_setMouseCursorVisible(object->window, sfFalse);
    sprite_draw(object, bird, background);
    sfSprite_setTextureRect(bird->sprite, bird->rect);
    move_background(background);
    animations_bird(bird);
    display_score(object);
}

int main(int ac, char **av)
{
    variables_t object;
    bird_t *bird = NULL;
    plan_t background[5];
    menu_t menu;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
        print_help();
    else {
        create_all(&object, background, &menu);
        bird = create_new_bird(bird);
        while (sfRenderWindow_isOpen(object.window)) {
            bird = analyse_events(&object, bird, &menu);
            manage_button(&object, bird, background, &menu);
            sfRenderWindow_display(object.window);
        }
        my_destroyer(&object, bird, &menu);
    }
}