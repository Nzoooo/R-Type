/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <filesystem>
#include <iostream>
#include <fstream>
#include "Exceptions/Exception.hpp"
#include "Exceptions/ExceptionDirectoryNotFound.hpp"
#include "Network/network.hpp"
#include "ParserYaml.hpp"
#include "Sfml/GameLoop.hpp"
#include "Sfml/SpritesManager.hpp"

void assetsFolderExists()
{
    if (!std::filesystem::is_directory(std::filesystem::current_path() / "assets"))
        throw ExceptionDirectoryNotFound("directory /assets not found", "bool assetsFolderExists()");
    if (!std::filesystem::is_directory(std::filesystem::current_path() / "assets/sprites"))
        throw ExceptionDirectoryNotFound("directory /sprites not found in /assets", "bool assetsFolderExists()");
    if (!std::filesystem::is_directory(std::filesystem::current_path() / "assets/sounds"))
        throw ExceptionDirectoryNotFound("directory /sounds not found in /assets", "bool assetsFolderExists()");
    if (!std::filesystem::is_directory(std::filesystem::current_path() / "assets/font"))
        throw ExceptionDirectoryNotFound("directory /font not found in /assets", "bool assetsFolderExists()");
}

int main(int ac, char **av)
{
    (void)av;
    (void)ac;
    std::ofstream errorLogsFile("ErrorLogs.txt");
    try {
        // assetsFolderExists();
        graphics::SpritesManager sprites_manager;
        ParserYaml::parseYaml(sprites_manager, std::filesystem::current_path() / "assets/sprites/sprites_config.yaml");
        sprites_manager.printSpritesData();

        std::shared_ptr<void()> s;
        network_player net;
        std::thread f(&network_player::process_player, &net, s);
        GameLoop game;
        game.launchLoop(s);
        f.join();
    } catch (const Exception &e) {
        errorLogsFile << e.what() << std::endl;
        errorLogsFile << e.where() << std::endl;
        errorLogsFile.close();
        return (84);
    }
    return (0);
}
