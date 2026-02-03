/*
** EPITECH PROJECT, 2025
** MY HUNTER SHADOW
** File description:
** main
*/

#include "hunter.h"
#include "my.h"

int main(int argc, char **argv)
{
    int result = 0;

    if (argc > 1 && my_strcmp(argv[1], "-h") == 0){
        my_putstr("MY_HUNTER : Done by Flasheski -> ShadowGOAT\n");
        my_putstr("./my_hunter -h for help\n");
        my_putstr("./my_hunter to access to the full game and menu ! :)\n");
        return 0;
    }
    result = menu_loop();
    if (result == 1) {
        put_game();
        return 0;
    } else {
        my_putstr("\nDon't want to play the game ?\n");
        my_putstr("You're missing something, goodbye ! :)\n");
        my_putstr("Flasheski <3\n");
    }
    return 0;
}
