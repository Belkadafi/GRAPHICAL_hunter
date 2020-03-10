/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** score
*/

#include "include/my_hunter.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int n = 0;
    while (dest[i] != '\0')
        i++;
    while (src[n] != '\0') {
        dest[i] = src[n];
        i++;
        n++;
    }
    dest[i] = '\0';
    return (dest);
}

int my_compute_power_rec(int nb, int p)
{
    if (p == 0)
        return 1;
    if (nb < 0 || p < 0)
        return 0;
    nb = nb * my_compute_power_rec(nb, p - 1);
    return nb;
}

char *my_revgetnbr(int nb)
{
    int len = 0;
    char *dest;
    int i = 0;

    if (nb == 0) {
        return ("0\0");
    }
    for (int tempo = nb; tempo > 0; tempo = tempo/10)
        len += 1;
    dest = malloc(sizeof(char) * (len + 2));
    for (int tempo = my_compute_power_rec(10, len - 1); tempo > 0;) {
        dest[i] = (nb / tempo) % 10 + '0';
        i += 1;
        tempo = tempo / 10;
    }
    dest[i] = 0;
    return (dest);
}

void create_score(variables_t *object)
{
    object->score.text = sfText_create();
    object->score.font = sfFont_createFromFile("Textures/AldotheApache.ttf");
    object->score.score = 0;
    sfText_setFont(object->score.text, object->score.font);
    sfText_setCharacterSize(object->score.text, 50);
    object->score.pos.x = 1200;
    object->score.pos.y = 0;
    sfText_setPosition(object->score.text, object->score.pos);
    object->score.text2 = sfText_create();
    object->score.font = sfFont_createFromFile("Textures/AldotheApache.ttf");
    object->score.score = 0;
    sfText_setFont(object->score.text2, object->score.font);
    sfText_setCharacterSize(object->score.text2, 50);
    object->score.pos2.x = 1000;
    object->score.pos2.y = 0;
    sfText_setPosition(object->score.text2, object->score.pos2);
}

void display_score(variables_t *object)
{
    sfText_setString(object->score.text2, "Score :");
    sfText_setString(object->score.text, my_revgetnbr(object->score.score));
    sfRenderWindow_drawText(object->window, object->score.text, NULL);
    sfRenderWindow_drawText(object->window, object->score.text2, NULL);
}