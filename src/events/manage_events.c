/*
** EPITECH PROJECT, 2025
** MUL
** File description:
** manage_events
*/

#include "hunter.h"
#include "my.h"

void manage_mouse_click(sfMouseButtonEvent *event, hunter_t *hunter)
{
    sfFloatRect shadow_area = sfSprite_getGlobalBounds(hunter->shadow_sprite);

    if (sfFloatRect_contains(&shadow_area, (float)event->x, (float)event->y)) {
        sfSound_play(hunter->hit_sound);
        sfSprite_setPosition(hunter->shadow_sprite,
            (sfVector2f){-500.f, rand() % 850});
        hunter->score += 1;
    }
}

void analyse_events(sfRenderWindow *window, sfEvent event, hunter_t *hunter)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonPressed)
            manage_mouse_click(&event.mouseButton, hunter);
    }
}
