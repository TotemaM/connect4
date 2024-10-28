// Reference header
#include "menus/game_menu.hpp"

GameMenu::GameMenu() {
    type = GAME;
    items = { &background, &game };
    thread GameThread(&Game::start, &game);
    GameThread.detach();
}
Menu::Type GameMenu::handle_event(sf::Event event) {
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