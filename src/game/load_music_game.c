/*
** EPITECH PROJECT, 2025
** MUL
** File description:
** load_music_game
*/

#include "hunter.h"
#include "my.h"

sfMusic *create_music_game(void)
{
    sfMusic *game_song = sfMusic_createFromFile(
        "include/assets/song/all_of_me.ogg");

    if (!game_song)
        return NULL;
    sfMusic_setLoop(game_song, sfTrue);
    sfMusic_setVolume(game_song, 20.0);
    return game_song;
}
