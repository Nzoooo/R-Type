/*
** EPITECH PROJECT, 2022
** Enum
** File description:
** Enum
*/

#pragma once

#define NB_MAX_PLAYERS_PER_ROOM 4
#define DISCONNECTION_TIME 2000

namespace ecs
{
    enum Scenes { ROOM1, GAME1, ROOM2, GAME2, ROOM3, GAME3, ROOM4, GAME4,
                PUBLICROOM, PRIVATEROOM, LISTROOM, JOINROOMBYID,
                MENU, SETTINGS, WIN, LOOSE, GAME, TYPEPSEUDO };
    enum EntityTypes { SPACESHIP, MONSTER, SHOT, BUTTON, WALL, BACKGROUND, ROOM, ROOMID, SHAPE, TEXT };
} // namespace ecs
