/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** my_hunter
*/

#ifndef HUNTER_
#define HUNTER_

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <unistd.h>


typedef struct bird_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfImage *image;
    sfIntRect rect;
    sfVector2f pos;
    sfClock *anim;
    sfClock *mouvement;
    sfClock *respawn;
    struct bird_s *next;
} bird_t;

typedef struct paralax_s
{
    int speed;
    int limit;
    sfVector2f position;
    sfIntRect rect;
} paralax_t;

typedef struct life_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f scale;
    sfVector2f pos;
} life_t;

typedef struct plan_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f scale;
    sfIntRect rect;
    int speed;
    int limit;
    sfClock *clock;
    paralax_t paralax;
} plan_t;

typedef struct cursor_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f scale;
    sfVector2i temp;
} cursor_t;

typedef struct background_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
} background_t;

typedef struct button_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfFont *font;
    sfText *text;
    sfVector2f scale;
    sfVector2f pos;
} button_t;

typedef struct menu_s
{
    background_t background;
    button_t play;
    button_t tutorial;
    button_t exit;
    button_t continu;
    button_t restart;
} menu_t;

typedef struct game_over_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
    sfVector2f pos;
    sfText *text;
    sfFont *font;
    sfVector2f posText;
    sfClock *clock;
    int state;
} game_over_t;

typedef struct tuto_s
{
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    int test;
} tuto_t;

typedef struct score_s
{
    sfText *text;
    sfFont *font;
    sfText *text2;
    sfVector2f pos;
    sfVector2f pos2;
    int score;
} score_t;

typedef struct variables_s
{
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent event;
    cursor_t cursor;
    sfMusic *music;
    int status;
    life_t life;
    game_over_t game_over;
    tuto_t tuto;
    score_t score;
} variables_t;

#include "my.h"

#endif /*HUNTER_*/