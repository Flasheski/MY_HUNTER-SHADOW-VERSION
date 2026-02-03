/*
** EPITECH PROJECT, 2025
** MY HUNTER SHADOW
** File description:
** load_sprite
*/

#include "hunter.h"
#include "my.h"

sfSprite *load_sprite(char *full_path)
{
    sfTexture *texture = sfTexture_createFromFile(full_path, NULL);
    sfSprite *sprite;

    if (!texture)
        return NULL;
    sprite = sfSprite_create();
    if (!sprite)
        return NULL;
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}
