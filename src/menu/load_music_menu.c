/*
** EPITECH PROJECT, 2025
** MY HUNTER SHADOW
** File description:
** load_music_menu
*/

#include "hunter.h"
#include "my.h"

sfMusic *create_music_menu(void)
{
    sfMusic *menu_song = sfMusic_createFromFile
        ("include/assets/song/seven_rings_menu.ogg");

    if (!menu_song){
        my_puterror("Error: Cannot load music file\n");
        return NULL;
    }
    sfMusic_setLoop(menu_song, sfTrue);
    sfMusic_setVolume(menu_song, 20.0);
    return menu_song;
}

void destroy_music(sfMusic *music_menu)
{
    sfMusic_stop(music_menu);
    sfMusic_destroy(music_menu);
}
