/*
** EPITECH PROJECT, 2025
** G-MUL-100-LIL-1-1-myhunter-6
** File description:
** hunter
*/

#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/Network.h>
#include <SFML/System/Clock.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#ifndef HUNTER_H_
    #define HUNTER_H_

typedef struct menu_s {
    sfRenderWindow *window_menu;
    sfSprite *back_shadow;
    sfSprite *exit_but;
    sfSprite *play_but;
    sfSprite *menu_up;
} menu_t;

typedef struct hunter_s {
    sfRenderWindow *window_game;
    sfSprite *background_shadow;
    sfSprite *shadow_sprite;
    sfSprite *score_sprite;
    sfSound *hit_sound;
    sfSoundBuffer *hit_buffer;
    int passed_count;
    sfSprite *game_over_sprite;
    int score;
} hunter_t;

// menu
void analyse_events(sfRenderWindow *window, sfEvent event, hunter_t *hunter);
// boucles pr les différents events
int run_loop_game(hunter_t *hunter);
int menu_loop(void);
// Sprites
sfSprite *load_sprite(char *full_path);
void update_position(hunter_t *hunter, sfIntRect *rect);
void show_game_over(hunter_t *hunter);
void update_animation(sfClock *clock, sfIntRect *rect, sfSprite *shadow);
void move_rect(sfIntRect *rect, int offset, int max_value);
// ING
hunter_t *init_score_sprite(hunter_t *hunter);
int put_game(void);
hunter_t *open_window_game(void);
// -> musiques
void init_sounds(hunter_t *hunter);
sfMusic *create_music_game(void);
sfMusic *create_music_menu(void);
// destroy everything
void destroy_music(sfMusic *music_menu);
void destroy_all(hunter_t *hunter);
void destroy_menu(menu_t *menu);

#endif /* !HUNTER_H_ */
