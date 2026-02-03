/*
** EPITECH PROJECT, 2025
** MUL
** File description:
** destroy
*/

#include "hunter.h"
#include "my.h"

void destroy_sprite_and_texture(sfSprite *sprite)
{
    const sfTexture *texture = sfSprite_getTexture(sprite);

    if (!sprite)
        return;
    sfSprite_destroy(sprite);
    if (texture)
        sfTexture_destroy((sfTexture *)texture);
}

void destroy_all(hunter_t *hunter)
{
    destroy_sprite_and_texture(hunter->shadow_sprite);
    destroy_sprite_and_texture(hunter->background_shadow);
    destroy_sprite_and_texture(hunter->score_sprite);
    destroy_sprite_and_texture(hunter->game_over_sprite);
    sfSound_destroy(hunter->hit_sound);
    sfSoundBuffer_destroy(hunter->hit_buffer);
    sfRenderWindow_destroy(hunter->window_game);
    free(hunter);
}

void destroy_menu(menu_t *menu)
{
    destroy_sprite_and_texture(menu->back_shadow);
    destroy_sprite_and_texture(menu->play_but);
    destroy_sprite_and_texture(menu->exit_but);
    destroy_sprite_and_texture(menu->menu_up);
    sfRenderWindow_destroy(menu->window_menu);
}
