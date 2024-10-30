#pragma once
// File inclusions
#include "menus/menu.hpp"
#include "gui/image.hpp"
#include "game/game.hpp"
// Standard libraries
#include <vector>
#include <memory>
#include <thread>
#include <iostream>
using namespace std;
// Class for the game menu of the SFML GUI
class GameMenu: public Menu {
    Game game;
    Image background = Image("img/game_menu.png", 0, 0);
public:
    GameMenu(GameConfig config);
    Type handle_event(sf::Event event) override;
};