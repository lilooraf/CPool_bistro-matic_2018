/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef __MY_H__
#define __MY_H__

#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include "struct.h"
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "fight.h"

void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_str_isalpha(char const *str);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
int my_str_isprintable(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isnum(char *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
void my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *);
int my_putstrn(char const *);
int my_getnbr(char const *str);
int my_strlen(char const *str);
int my_putnbr_base(int nb, char const *base);
char *my_strcpy(char *dest, char *src);
char *my_strdup(char const *src);
void *my_calloc(size_t elem_size, size_t elems);
char **my_str_to_word_array(char *str);
char **my_str_to_word_array_char(char *str, char c);
char *my_clear_str(char *str);
int check_num(char **av, int start);
int usage(int ac, char **av);
char *strcpy_end(char *dest, char *src);
char *get_next_line(int fd);
char *get_flags(char **av);
int check_flag(char c, char *str);
char **get_args(char **av);
char **open_tab(char *str);
sfVector2f vec(float x, float y);
void anim_player(st_t *st);
bool display_menu(sfRenderWindow *wi);
sfSprite *print_img(const char *name, sfTexture **texture, sfSprite *sprite);
bt_t *init_struct_menu(void);
void set_bt(bt_t *bt, sfRenderWindow *wi, sfVector2i *pm, sfVector2i *pm2);
sfMusic* music_p(char *str);
void disp_win(sfRenderWindow *wi, int b);
void display_pnj(st_t *st);
void init_pnj_struct(st_t *st);


char *my_revstr(char *str);

bool fight_scene(sfRenderWindow *window, stats_t *stats, int i);

sfSprite *create_sprite(char *file_path);

void init_stat(stats_t *stats, var_t *var, fight_t *fight, st_t st);

void move_squares(sfRenderWindow *, entity_t *, int, int);

sfVector2f vector(float, float);

sfText *create_text(char *, sfVector2f, int);

char *my_put_nbr_str(int);

void draw_stats(sfRenderWindow *, stats_t *);

void event_window(sfRenderWindow *, var_t *);

int player_turn(sfRenderWindow *, stats_t *, fight_t *, int);

int enemy_turn1(sfRenderWindow *, stats_t *, fight_t *, int);

void display_text(sfRenderWindow *, char *, sfVector2f, int);

void player_fight(stats_t *, fight_t *, int );

void enemy_fight(stats_t *, fight_t *, int);

void init_var(var_t *);

void init_clock_enemy(cl_t *);

void init_player_struct(entity_t *, bool, bool);

void init_enemy_struct(entity_t **);

void manage_sprites(inv_t *inv);
void init_inv(inv_t *inv);
void draw_inventory(inv_t *inv, st_t *st);
sfText *create_text_map(char *str, sfVector2f vect, int size);
char *int_to_str(int nb);
bool check_wall(sfVertexArray *m, int x, int y, int size);
sfVector2f vec(float x, float y);
void pos_vertex(int b, int i, int nb, sfVertex *quad);
void pos_vertex_house(int b, int i, int nb, sfVertex *quad);
sfVertexArray *init_house(int *mapi, int x, int y);
sfRenderStates *init_states(char *file);
sfVertexArray *init_map(int *mapi, int x, int y);
int *fill_map(int *mapi, char *map, int c, int size);
void key_event(st_t *st, sfVertexArray *m);
void event(st_t *st);
int **init_mapi(char *file, int size, int map_nb);
sfSprite *print_img(const char *name, sfTexture **texture, sfSprite *sprite);
sfIntRect create_rect(int top, int left, int height, int width);
void zone_interact(st_t *st);
void init_text(st_t *st);
void set_pos_text(st_t *st);
void init_pl2(st_t *st);
void init_pl(st_t *st);
st_t init_st2(st_t st, float zoom, sfVideoMode mode);
st_t init_st(int size_x, int size_y, float zoom);
void select_text(st_t *st, int i);
void action5(st_t *st, int i);
void action6(st_t *st, int i);
void action7(st_t *st, int i);
void action8(st_t *st, int i);
void action9(st_t *st, int i);
void action0(st_t *st, int i);
void actions(st_t *st, int i);
void check_action(st_t *st);
void disp_map(st_t *st, sfVertexArray **map, sfVertexArray **house);
void check_win(st_t *st);
void disp_all(st_t *st);
#endif
