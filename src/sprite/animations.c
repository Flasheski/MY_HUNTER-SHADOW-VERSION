/*
** EPITECH PROJECT, 2025
** MUL
** File description:
** animations
*/

#include "hunter.h"
#include "my.h"

void update_animation(sfClock *clock, sfIntRect *rect, sfSprite *shadow)
{
    sfTime time = sfClock_getElapsedTime(clock);

    if (sfTime_asMilliseconds(time) > 100) {
        move_rect(rect, (double)34.75, 200);
        sfSprite_setTextureRect(shadow, *rect);
        sfClock_restart(clock);
    }
}

void update_position(hunter_t *hunter, sfIntRect *rect)
{
    sfVector2f position = sfSprite_getPosition(hunter->shadow_sprite);

    sfSprite_move(hunter->shadow_sprite, (sfVector2f){20, 0});
    position = sfSprite_getPosition(hunter->shadow_sprite);
    if (position.x > 1920) {
        hunter->passed_count++;
        if (hunter->passed_count >= 3) {
            show_game_over(hunter);
            return;
        }
        sfSprite_setPosition(hunter->shadow_sprite,
            (sfVector2f){- rect->width, rand() % 880});
    }
}
