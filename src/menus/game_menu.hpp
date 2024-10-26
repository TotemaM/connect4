#pragma once

#include "menu.hpp"
#include "gui/image.hpp"
#include "game/game.hpp"

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>
#include <thread>
#include <iostream>
using namespace std;

class GameMenu: public Menu {
    Game game = Game(Player::CUSTOM, Player::CUSTOM);
    Image background = Image("img/game_menu.png", 0, 0);
public:
    GameMenu() {
        type = GAME;
        items = { &background, &game };
        thread GameThread(&Game::start, &game);
        GameThread.detach();
    }
    Type handle_event(sf::Event event) override {
        switch (event.type) {
            case sf::Event::MouseMoved: {
                break;
            }
            case sf::Event::MouseButtonPressed: {
                if (game.getWinner() != Game::Winner::NONE) {
                    return Menu::MAIN;
                } else {
                    if (game.getCurrentPlayerType() == Player::USER && event.mouseButton.y >= 96) {
                        game.userPlay( ((event.mouseButton.x-32) / 64) );
                    }
                }
                break;
            }
            default: break;
        }
        return type;
    }
};