/*
** EPITECH PROJECT, 2025
** MUL
** File description:
** main_loop
*/

#include "hunter.h"
#include "my.h"

void display_all(hunter_t *hunter)
{
    sfRenderWindow_clear(hunter->window_game, sfBlack);
    sfRenderWindow_drawSprite(hunter->window_game,
        hunter->background_shadow, NULL);
    sfRenderWindow_drawSprite(hunter->window_game,
        hunter->shadow_sprite, NULL);
    sfRenderWindow_drawSprite(hunter->window_game,
        hunter->score_sprite, NULL);
    sfRenderWindow_display(hunter->window_game);
}

int run_loop_game(hunter_t *hunter)
{
    sfClock *clock = sfClock_create();
    sfEvent event = {0};
    sfMusic *music_game = create_music_game();
    sfIntRect rect = {0, 0, (double)34.75, 50};

    if (!clock)
        return 84;
    sfMusic_play(music_game);
    while (sfRenderWindow_isOpen(hunter->window_game)) {
        analyse_events(hunter->window_game, event, hunter);
        update_animation(clock, &rect, hunter->shadow_sprite);
        update_position(hunter, &rect);
        display_all(hunter);
    }
    sfClock_destroy(clock);
    sfMusic_destroy(music_game);
    return 0;
}
