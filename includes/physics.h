/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myworld-david.gozlan
** File description:
** physics
*/

#ifndef PHYSICS_H_
#define PHYSICS_H_

#include "world.h"

typedef struct gen_data_s {
    float relief_ratio; // Relief population
    float hole_ratio;
    float rigidity; // Flatten ratio -> break ratio
    int max_height;
    int max_material;
} gen_data_t;

// Biome
static const gen_data_t BASIC_BIOME = {1.5, -0.7, 0.6, 40, 2};

// Buttons
static const butt_data_t CREATE_BUTTON = {350, 530, "Create", "", STATE_MENU,
        1, &changeto_editor};
static const butt_data_t EXIT_BUTTON = {350, 610, "Quit", "", STATE_MENU,
        1, &changeto_exit};
static const butt_data_t MSIZE_BUTTON = {500, 420, "-", "", STATE_MENU,
        1, &changesize_minus};
static const butt_data_t ASIZE_BUTTON = {660, 420, "+", "", STATE_MENU,
        1, &changesize_add};

static const butt_data_t SAVE_BUTTON = {1110, 10, "", "Save", STATE_EDITOR,
        1, &save_button};
static const butt_data_t EXIT_EDITOR_BUTTON = {1110, 125, "",
        "Quit", STATE_EDITOR, 1, &changeto_mainme};
static const butt_data_t CHANGE_MODE_EDITOR_BUTTON = {20, 20, "", "Change mode",
        STATE_EDITOR, 1, &mode_button};

static const sfIntRect MAIN_BASIC_RECT = {0, 60, 600, 60};
static const sfIntRect MAIN_HOV_RECT = {0, 120, 600, 60};
static const sfIntRect MAIN_CLICK_RECT = {0, 0, 600, 60};
static const sfIntRect SQ_BASIC_RECT = {0, 72, 74, 72};
static const sfIntRect SQ_HOV_RECT = {0, 144, 74, 72};
static const sfIntRect SQ_CLICK_RECT = {0, 0, 74, 72};
static const sfIntRect CORNER_RECT = {0, 0, 72, 74};
static const sfIntRect EDGE_RECT = {74, 0, 72, 74};
static const sfIntRect SAVE_RECT = {144, 0, 72, 74};
static const sfIntRect CLOSE_RECT = {232, 0, 72, 74};
static const sfIntRect PAINT_RECT = {306, 0, 72, 74};

#define NB_TEXT_BUTTONS 2

#endif /* !PHYSICS_H_ */
