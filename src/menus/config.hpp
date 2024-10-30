#pragma once
// File inclusions
#include "menus/menu.hpp"
#include "game/players/player.hpp"
#include "game/gameconfig.hpp"
#include "gui/image.hpp"
#include "gui/area.hpp"

#define BUTTON_WIDTH 128
#define BUTTON_HEIGHT 48

class GameConfigMenu : public Menu {
    GameConfig* config;
    Image background = Image("img/config_menu.png", 0, 0);
    Area user1 = Area(40, 128, BUTTON_WIDTH, BUTTON_HEIGHT, sf::Color::Yellow);
    Area user2 = Area(40, 320, BUTTON_WIDTH, BUTTON_HEIGHT, sf::Color::Red);
    Area random1 = Area(192, 128, BUTTON_WIDTH, BUTTON_HEIGHT, sf::Color::Yellow);
    Area random2 = Area(192, 320, BUTTON_WIDTH, BUTTON_HEIGHT, sf::Color::Red);
    Area minmax1 = Area(40, 192, BUTTON_WIDTH, BUTTON_HEIGHT, sf::Color::Yellow);
    Area minmax2 = Area(40, 384, BUTTON_WIDTH, BUTTON_HEIGHT, sf::Color::Red);
    Area minmax1pp = Area(192, 192, BUTTON_WIDTH, BUTTON_HEIGHT, sf::Color::Yellow);
    Area minmax2pp = Area(192, 384, BUTTON_WIDTH, BUTTON_HEIGHT, sf::Color::Red);
    Area custom1 = Area(344, 192, BUTTON_WIDTH, BUTTON_HEIGHT, sf::Color::Yellow);
    Area custom2 = Area(344, 384, BUTTON_WIDTH, BUTTON_HEIGHT, sf::Color::Red);
    Area start = Area(157, 469, 354-157, 491-469, sf::Color::Transparent, sf::Color::Transparent);
public:
    GameConfigMenu(GameConfig* config);
    Type handle_event(sf::Event event) override;
    vector<Area*> buttons = { &user1, &user2, &random1, &random2, &minmax1, &minmax2, &minmax1pp, &minmax2pp, &custom1, &custom2 };
    Area* last_clicked[2] = { &user1, &user2 };
};