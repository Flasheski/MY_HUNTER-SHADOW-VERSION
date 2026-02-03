/*
** EPITECH PROJECT, 2025
** MY HUNTER SHADOW
** File description:
** menu
*/

#include "hunter.h"
#include "my.h"

void init_menu(menu_t *menu)
{
    sfVideoMode mode = (sfVideoMode){1920, 1080, 32};

    menu->window_menu = sfRenderWindow_create(
        mode, "MENU SHADOW", sfClose | sfResize, NULL);
    menu->back_shadow = load_sprite("include/assets/sprites/shadow_menu.png");
    menu->play_but = load_sprite("include/assets/sprites/play_shadow.png");
    menu->exit_but = load_sprite("include/assets/sprites/quit_shadow.png");
    menu->menu_up = load_sprite("include/assets/sprites/menu_up.png");
    sfSprite_setPosition(menu->play_but, (sfVector2f){100, 150});
    sfSprite_setPosition(menu->exit_but, (sfVector2f){100, 500});
    sfSprite_setPosition(menu->menu_up, (sfVector2f){600, -75});
}

int check_clicks_menu(menu_t *menu)
{
    sfVector2i mouse;
    sfFloatRect play_rect = sfSprite_getGlobalBounds(menu->play_but);
    sfFloatRect exit_rect = sfSprite_getGlobalBounds(menu->exit_but);

    mouse = sfMouse_getPositionRenderWindow(menu->window_menu);
    if (sfFloatRect_contains(&play_rect, mouse.x, mouse.y)) {
        sfRenderWindow_close(menu->window_menu);
        return 1;
    }
    if (sfFloatRect_contains(&exit_rect, mouse.x, mouse.y)) {
        sfRenderWindow_close(menu->window_menu);
        return 2;
    }
    return -1;
}

int handle_menu_events(menu_t *menu)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(menu->window_menu, &event)) {
        if (event.type == sfEvtClosed ||
            (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)) {
            sfRenderWindow_close(menu->window_menu);
            return 2;
        }
        if (event.type == sfEvtMouseButtonPressed &&
            event.mouseButton.button == sfMouseLeft)
            return check_clicks_menu(menu);
    }
    return -1;
}

void draw_menu(menu_t *menu)
{
    sfRenderWindow_clear(menu->window_menu, sfBlack);
    sfRenderWindow_drawSprite(menu->window_menu, menu->back_shadow, NULL);
    sfRenderWindow_drawSprite(menu->window_menu, menu->play_but, NULL);
    sfRenderWindow_drawSprite(menu->window_menu, menu->exit_but, NULL);
    sfRenderWindow_drawSprite(menu->window_menu, menu->menu_up, NULL);
    sfRenderWindow_display(menu->window_menu);
}

int menu_loop(void)
{
    menu_t menu;
    sfMusic *music_menu = create_music_menu();
    int result = -1;

    init_menu(&menu);
    sfMusic_play(music_menu);
    while (sfRenderWindow_isOpen(menu.window_menu)){
        result = handle_menu_events(&menu);
        if (result == 1)
            break;
        draw_menu(&menu);
    }
    if (music_menu)
        destroy_music(music_menu);
    destroy_menu(&menu);
    return result;
}
