/*
** EPITECH PROJECT, 2025
** MUL
** File description:
** move_sprite
*/

#include "hunter.h"
#include "my.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left >= max_value)
        rect->left = 0;
}
