/*
** EPITECH PROJECT, 2021
** My World
** File description:
** Header
*/

#ifndef WORLD_H
#define WORLD_H

// Includes
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "my.h"

typedef int state_t;
typedef int edit_mode_t;
typedef int material_t;

#define STATE_MENU 1
#define STATE_EDITOR 2

#define MODE_CORNER 1
#define MODE_EDGE 2
#define MODE_FACE 3

#define GRASS_MATERIAL 1
#define SAND_MATERIAL 2
#define STONE_MATERIAL 3

typedef struct infos_s infos_t;
typedef struct gen_data_s gen_data_t;

// Structures

typedef struct map_data_s {
    int x;
    int y;
    int **relief;
    int *materials;
    char *save_name;
} map_data_t;

typedef struct butt_textures_s {
    sfTexture *basic_tex;
    sfTexture *hover_tex;
    sfTexture *click_tex;
} butt_textures_t;

typedef struct butt_data_s {
    int x;
    int y;
    char *text;
    char *hover_text;
    state_t state;
    int enabled;
    void (*call_func)(infos_t*);
} butt_data_t;

typedef struct sounds_s {
    sfSoundBuffer *buff_click;
    sfSound *click;
    sfSoundBuffer *buff_music;
    sfSound *music;
} sounds_t;

typedef struct fonts_s {
    sfFont *basic;
    sfFont *alphakind;
} fonts_t;

typedef struct textures_s {
    sfTexture *fader;
    sfTexture *sky;
    sfTexture *but_main_basic;
    sfTexture *but_main_hov;
    sfTexture *but_main_click;
    sfTexture *but_sq_basic;
    sfTexture *but_sq_hov;
    sfTexture *but_sq_click;
    sfTexture *mode_corner;
    sfTexture *mode_edge;
    sfTexture *grass;
    sfTexture *blow;
    sfTexture *save;
    sfTexture *close;
    sfTexture *paint;
    sfTexture *num_box;
    sfTexture *text_box;
    sfTexture *sand;
    sfTexture *stone;
    sfTexture *title;
} textures_t;

typedef struct ressources_s {
    textures_t *tex;
    fonts_t *fonts;
    butt_textures_t *buttons;
    sounds_t *sounds;
} ressources_t;

typedef struct button_s {
    sfTexture *basic_tex;
    sfTexture *hover_tex;
    sfTexture *click_tex;
    sfSprite *button;
    sfText *text;
    sfText *hover_text;
    state_t state;
    int enabled;
    sfClock *clock;
    void (*call_func)(infos_t*);
    struct button_s *next;
} button_t;

typedef struct global_system_s {
    sfSprite *fader;
    sfClock *fade_clock;
    int anim_fade;
    void (*fade_func)(infos_t*);
} global_system_t;

typedef struct main_menu_system_s {
    sfSprite *background;
    button_t *buttons;
    sfClock *rotate_block;
    sfText *text;
    sfText *pos_text;
    char str[32];
    int pos;
    sfSprite *title;
    sfSprite *text_box;
    sfSprite *num_box;
} main_menu_system_t;

typedef struct editor_system_s {
    sfSprite *background;
    int xy_angle;
    int z_angle;
    int xy_scale;
    int z_scale;
    sfSprite *mode;
    sfSprite *save;
    sfSprite *close;
} editor_system_t;

struct infos_s {
    char *file_name;
    state_t state;
    sfRenderWindow *window;
    global_system_t *global_sys;
    main_menu_system_t *mainme_sys;
    ressources_t *res;
    button_t *buttons;
    map_data_t *map_data;
    sfVector2f **map_2d;
    editor_system_t *editor_sys;
    sfVector2f mouse;
    sfBool error;
    edit_mode_t mode;
    sfVector2f *ordered_map;
    sfVector2f **correct_map;
    int modified;
    int select_size;
    int size;
    material_t select_mat;
    int ancient_size;
};

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 720
#define WINDOW_BPP 32

// Prototype
int handle_error(int argc, char **argv, char **buff);
infos_t *load_game(char *buff, char *path);
void unload_game(infos_t *infos);
void execute_global_events(sfEvent event, infos_t *infos);
void start_system(infos_t *infos);
void use_window_menu(infos_t *infos);
void use_editor(infos_t *infos);
void save_map(map_data_t map_data);
map_data_t *load_map(char *buff, char *path);
void draw_2d_map(infos_t *infos);
sfVector2f **create_2d_map(int **map, infos_t *infos, int size);
void execute_editor_events(sfEvent event, infos_t *infos);
void create_global_objects(infos_t *infos);
void delete_global_objects(infos_t *infos);
void create_editor_objects(infos_t *infos);
void delete_editor_objects(infos_t *infos);
void execute_global_animations(infos_t *infos);
map_data_t *gen_default_map(int size, gen_data_t data, char *save_name);
void free_map_2d(sfVector2f **map, int size);
int is_button_hovered(button_t *but, infos_t *infos);
void hover_buttons(infos_t *infos);
void render_buttons(infos_t *infos);
void create_button(infos_t *infos, butt_data_t data, butt_textures_t textures);
void create_mainme_objects(infos_t *infos);
void delete_mainme_objects(infos_t *infos);
sfText *create_text(sfFont *font, sfColor color, int size, char *str);
void click_buttons(infos_t *infos);
void start_fade_animation(infos_t *infos, void (*fade_func)(infos_t*));
void delete_buttons(infos_t *infos);
int show_error(char *message);
void execute_buttons(infos_t *infos);
void execute_load_events(sfEvent event, infos_t *infos);
void use_load(infos_t *infos);
void execute_mainme_events(sfEvent event, infos_t *infos);
void execute_draw(infos_t *infos, sfVector2f **map, int size, int *vals);
void use_edit_click(infos_t *infos, int x, int y, int add);
int check_file(char *file_path, char **buffer);
sfVertexArray *create_line(sfVector2f *point1, sfVector2f *point2);
int is_in_range(sfVector2f point, int x, int y);
int use_corner_mode(infos_t *infos, int vals[6]);
int use_edge_mode(infos_t *infos, int vals[6]);
int use_face_mode(infos_t *infos, int vals[6]);
void regen_ordered_map(infos_t *infos, sfVector2f **map, int size);
void regen_correct_map(infos_t *infos, sfVector2f **map, int size);
void regen_2d_map(infos_t *infos);
void gen_pixels(sfUint8 *pixels, sfUint8 *pi_sky, sfUint8 *pi_blo, int size);
void load_sounds(ressources_t *res);

void random_seed(void);
int mrand(void);

void endto_editor(infos_t *infos);
void endto_mainme(infos_t *infos);

void changeto_exit(infos_t *infos);
void changeto_editor(infos_t *infos);
void changeto_mainme(infos_t *infos);
void save_button(infos_t *infos);
void mode_button(infos_t *infos);
void changesize_add(infos_t *infos);
void changesize_minus(infos_t *infos);
void free_map_data(map_data_t *data);

// Resources
#include "resources.h"
#include "physics.h"

// Error Macro
#define OPEN_ERROR show_error("Error: Can't open file\n")
#define ALLOC_ERROR show_error("Error: Allocation problem\n")
#define READ_ERROR show_error("Error: Can't read file\n")

#define UNKNOWN_OPTION_ERROR show_error("Unknown option. Retry with -h.\n")
#define NB_ARGS_ERROR show_error("Error: bad number of arguments\n")
#endif /* !WORLD_H */