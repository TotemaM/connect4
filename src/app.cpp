#include "app.hpp"

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
                case Menu::MAIN: current_menu = make_unique<MainMenu>(); break;
                case Menu::GAME: current_menu = make_unique<GameMenu>(); break;
                default: current_menu = make_unique<MainMenu>(); break;
            }
        }
        window.clear();
        window.draw(*current_menu);
        window.display();
    }
}