/*
** EPITECH PROJECT, 2025
** MY HUNTER SHADOW
** File description:
** window
*/

#include "hunter.h"
#include "my.h"

hunter_t *set_sprites_scales(hunter_t *hunter)
{
    sfSprite_setScale(hunter->shadow_sprite, (sfVector2f){4.0f, 4.0f});
    sfSprite_setOrigin(hunter->shadow_sprite, (sfVector2f){17.5f, 25.f});
    sfSprite_setPosition(hunter->shadow_sprite, (sfVector2f){0, 400});
    return hunter;
}

static void init_game_over(hunter_t *hunter)
{
    if (!hunter)
        return;
    hunter->game_over_sprite = load_sprite(
        "include/assets/sprites/game_over.png");
    hunter->passed_count = 0;
}

static void draw_game_over_sprite(hunter_t *hunter)
{
    if (!hunter || !hunter->game_over_sprite || !hunter->window_game)
        return;
    sfRenderWindow_clear(hunter->window_game, sfBlack);
    sfRenderWindow_drawSprite(hunter->window_game,
        hunter->game_over_sprite, NULL);
    sfRenderWindow_display(hunter->window_game);
}

static void close_after_delay(hunter_t *hunter)
{
    if (!hunter || !hunter->window_game)
        return;
    sfSleep(sfSeconds(2.0f));
    sfRenderWindow_close(hunter->window_game);
}

void show_game_over(hunter_t *hunter)
{
    if (!hunter || !hunter->game_over_sprite || !hunter->window_game)
        return;
    my_putstr("Game over ! GL next time :)\n");
    my_putstr("- Flasheski\n");
    draw_game_over_sprite(hunter);
    close_after_delay(hunter);
}

hunter_t *open_window_game(void)
{
    hunter_t *hunter = malloc(sizeof(hunter_t));
    sfVideoMode mode = {1920, 1080, 32};

    if (!hunter)
        return NULL;
    hunter->window_game = sfRenderWindow_create(mode, "SHADOW HUNT",
        sfResize | sfClose, NULL);
    hunter->background_shadow = load_sprite(
        "include/assets/sprites/shadow_game.png");
    hunter->shadow_sprite = load_sprite(
        "include/assets/sprites/shadow_sprite.png");
    init_game_over(hunter);
    if (!hunter->window_game || !hunter->background_shadow ||
        !hunter->shadow_sprite)
        return NULL;
    init_score_sprite(hunter);
    set_sprites_scales(hunter);
    sfRenderWindow_setFramerateLimit(hunter->window_game, 60);
    init_sounds(hunter);
    return hunter;
}
