/*
** EPITECH PROJECT, 2025
** MY HUNTER SHADOW
** File description:
** load_score
*/

#include "hunter.h"
#include "my.h"

hunter_t *init_score_sprite(hunter_t *hunter)
{
    hunter->score_sprite = load_sprite(
        "include/assets/sprites/shadow_score.png");
    if (!hunter->score_sprite)
        return NULL;
    sfSprite_setScale(hunter->score_sprite, (sfVector2f){0.4f, 0.4f});
    sfSprite_setPosition(hunter->score_sprite, (sfVector2f){1, 7});
    return hunter;
}
