/*
** EPITECH PROJECT, 2025
** MY HUNTER SHADOW
** File description:
** init_sounds
*/

#include "hunter.h"
#include "my.h"

void init_sounds(hunter_t *hunter)
{
    hunter->hit_buffer = sfSoundBuffer_createFromFile(
        "include/assets/song/ring_effect.ogg");
    hunter->hit_sound = sfSound_create();
    sfSound_setBuffer(hunter->hit_sound, hunter->hit_buffer);
    sfSound_setVolume(hunter->hit_sound, 10.0);
}
