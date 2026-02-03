/*
** EPITECH PROJECT, 2025
** MUL
** File description:
** put_game
*/

#include "hunter.h"
#include "my.h"

int put_game(void)
{
    hunter_t *hunter = open_window_game();
    int result = 0;

    if (!hunter)
        return 84;
    result = run_loop_game(hunter);
    destroy_all(hunter);
    return result;
}
