/*
** EPITECH PROJECT, 2022
** LobbySelector
** File description:
** LobbySelector
*/

#pragma once
#include "ScenesInitializer.hpp"
#include "../../Network/UdpServerClient.hpp"

class CustomServer;
class LobbySelector {
    public:
        LobbySelector() = default;
        ~LobbySelector() = default;

    static void initScene(CustomServer *server, ecs::Registry &registry)
    {
        std::size_t entity;
        registry.setActualScene(ecs::Scenes::GAME);

        entity = ecs::Factory::createEntity(registry, ecs::EntityTypes::BACKGROUND, 0, 0, -80, 0, 0, 0, 0, 0, 1, 0);
        server->sendNetworkComponents(entity);
        entity = ecs::Factory::createEntity(registry, ecs::EntityTypes::BACKGROUND, 1280, 0, -80, 0, 0, 0, 0, 0, 1, 0);
        server->sendNetworkComponents(entity);
        entity = ecs::Factory::createEntity(registry, ecs::EntityTypes::BACKGROUND, 500, 0, -60, 0, 0, 0, 0, 0, 2, 1);
        server->sendNetworkComponents(entity);
        entity = ecs::Factory::createEntity(registry, ecs::EntityTypes::SPACESHIP, 0, 340, 0, 0, 0, 0, 3);
        server->sendNetworkComponents(entity);
        entity = ecs::Factory::createEntity(registry, ecs::EntityTypes::MONSTER, 1000, 450, 0, 0, 0, 0, 3);
        server->sendNetworkComponents(entity);
    }
};
