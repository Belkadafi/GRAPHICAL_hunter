/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

void move_rect(sfIntRect *rect, int offset, int max_value);
int my_clock(sfClock *clock, float max);
void create_background(plan_t *background);
void fill_background(plan_t *back, char *filepath, paralax_t paralax);
void create_object(variables_t *objects);
void sprite_draw(variables_t *object, bird_t *bird, plan_t *background);
void set_cursor_position(variables_t *object);
void move_background(plan_t *background);
void animations_bird(bird_t *bird);
bird_t *create_new_bird(bird_t *bird);
void fill_bird(bird_t *bird);
void draw_birds(bird_t *bird, variables_t *object);
void create_menu(menu_t *menu);
void display_menu(variables_t *object, menu_t menu);
int start_button(variables_t *object, menu_t *menu);
int tuto_button(variables_t *object, menu_t *menu);
void tuto(variables_t *object, bird_t *bird, plan_t *background);
void create_exit(button_t *button, sfVector2f position, char *str);
void exit_button(variables_t *object, menu_t *menu);
bird_t *my_get_button(variables_t *object, bird_t *bird, menu_t *menu);
void my_destroyer(variables_t *object, bird_t *bird, menu_t *menu);
void create_menu_pause(menu_t *menu);
void menu_pause(variables_t *object, menu_t menu);
void destroy_bird(bird_t *bird);
void manage_button(variables_t *object,
bird_t *bird, plan_t *background, menu_t *menu);
void game_loop(variables_t *object, bird_t *bird, plan_t *background);
void create_life(life_t *life);
void my_manage_death(variables_t *object, bird_t *bird);
void game_over(variables_t *object, plan_t *background);
void create_tutorial(variables_t *object);
void create_score(variables_t *object);
void display_score(variables_t *object);
void manage_restart(variables_t *object);
void create_all(variables_t *object, plan_t *background, menu_t *menu);
void print_help(void);
void create_game_over(variables_t *object, sfVector2f scale, sfVector2f pos);
int manage_game_over(sfClock *clock, float max, int status);

#endif /* !MY_H_ */