// Reference header
#include "app.hpp"
// File inclusions
#include "menus/home.hpp"
#include "menus/game.hpp"
#include "menus/config.hpp"

void App::run() {
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) { window.close(); }
            else if (event.type == sf::Event::Resized) { window.setSize({WIDHT, HEIGHT}); }
            else { change_menu = current_menu->handle_event(event); }
        }
        if (change_menu != current_menu->getType()) {
            switch (change_menu) {
                case Menu::HOME: current_menu = make_unique<HomeMenu>(); break;
                case Menu::CONFIG: current_menu = make_unique<GameConfigMenu>(&game_config); break;
                case Menu::GAME: current_menu = make_unique<GameMenu>(game_config); break;
                default: break;
            }
        }
        window.clear();
        window.draw(*current_menu);
        window.display();
    }
}