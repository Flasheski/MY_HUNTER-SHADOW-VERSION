# 🦆 MY_HUNTER

## 🧭 DESCRIPTION DU PROJET

Objectif : Refaire le célèbre jeu DUCK HUNT, en CSFML avec l'aide de notre imagination et les fonctions de la lib CSFML.

---

## 🗓️ DATES

📅 **Du 28/10/2025 à 09h00 au 21/11/2025 à 19h42**

---

## 🚀 UTILISATION

```bash
./my_hunter -h (affiche les paramètres du jeu et les différentes fonctionnalités de celui-ci)
./my_hunter -> lance le jeu
```

📁 FICHIERS :

Projet dispersé en plusieurs sous-dossiers et fichiers pour avoir plus de clarté sur celui-ci.

```bash
├── include
│   ├── my.h
│   └── hunter.h
├── lib
│   ├── libmy.a
│   └── my
├── Makefile
├── my_hunter
└── src/
```

📁 STRUCTURE DU PROJET :

Séparation des différentes parties du code dans des dossiers / fichiers distincts.

```bash
├── include
│   ├── assets
│   │   ├── song
│   │   │   ├── all_of_me.ogg
│   │   │   ├── ring_effect.ogg
│   │   │   └── seven_rings_menu.ogg
│   │   └── sprites
│   │       ├── game_over.png
│   │       ├── menu_up.png
│   │       ├── play_shadow.png
│   │       ├── quit_shadow.png
│   │       ├── shadow_game.png
│   │       ├── shadow_menu.png
│   │       ├── shadow_score.png
│   │       └── shadow_sprite.png
│   ├── hunter.h
│   └── my.h
├── lib
│   ├── libmy.a
│   └── my
├── Makefile
├── my_hunter
└── src
    ├── destroy
    │   └── destroy.c
    ├── events
    │   └── manage_events.c
    ├── game
    │   ├── load_music_game.c
    │   └── main_loop.c
    ├── main.c
    ├── menu
    │   ├── load_music_menu.c
    │   └── menu.c
    ├── score
    │   └── load_score.c
    ├── sounds
    │   └── init_sounds.c
    ├── sprite
    │   ├── animations.c
    │   ├── load_sprite.c
    │   └── move_sprite.c
    └── window
        ├── put_game.c
        └── window_game.c
```

⚙️ Étapes pour pouvoir réaliser le projet :

1 - Trouver / Afficher correctement les sprites.

2 - Définir les mouvements des sprites avec sfClock.

3 - Trouver les bons sons / bien les accorder.

4 - Faire un menu / jeu agréables à regarder.

5 - Trouver des bonus à implémenter.

6 - Finir le projet avec quelques références au jeu DUCK HUNT.

