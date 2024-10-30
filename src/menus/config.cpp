// Reference header
#include "menus/config.hpp"

GameConfigMenu::GameConfigMenu(GameConfig* config): config(config) {
    type = CONFIG;
    items = { &background, &user1, &user2, &random1, &random2, &minmax1, &minmax2, &minmax1pp, &minmax2pp, &custom1, &custom2, &start};
    user1.click();
    user2.click();
    config->player1 = Player::Type::USER;
    config->player2 = Player::Type::USER;
}
Menu::Type GameConfigMenu::handle_event(sf::Event event) {
    switch (event.type) {
        case sf::Event::MouseMoved: {
            for (Area* button : buttons) { button->hover(event.mouseMove.x, event.mouseMove.y); }
            break;
        }
        case sf::Event::MouseButtonPressed: {
            if (event.mouseButton.button == sf::Mouse::Left) {
                for (Area* button : buttons) {
                    if (button->isHovered(event.mouseButton.x, event.mouseButton.y)) {
                        if (button == &user1) {
                            config->player1 = Player::Type::USER;
                            user1.click();
                            last_clicked[0]->unclick();
                            last_clicked[0] = &user1;
                            break;
                        }
                        else if (button == &user2) {
                            config->player2 = Player::Type::USER;
                            user2.click();
                            last_clicked[1]->unclick();
                            last_clicked[1] = &user2;
                            break;
                        }
                        else if (button == &random1) {
                            config->player1 = Player::Type::RANDOM;
                            random1.click();
                            last_clicked[0]->unclick();
                            last_clicked[0] = &random1;
                            break;
                        }
                        else if (button == &random2) {
                            config->player2 = Player::Type::RANDOM;
                            random2.click();
                            last_clicked[1]->unclick();
                            last_clicked[1] = &random2;
                            break;
                        }
                        else if (button == &minmax1) {
                            config->player1 = Player::Type::MINIMAX;
                            minmax1.click();
                            last_clicked[0]->unclick();
                            last_clicked[0] = &minmax1;
                            break;
                        }
                        else if (button == &minmax2) {
                            config->player2 = Player::Type::MINIMAX;
                            minmax2.click();
                            last_clicked[1]->unclick();
                            last_clicked[1] = &minmax2;
                            break;
                        }
                        else if (button == &minmax1pp) {
                            config->player1 = Player::Type::MINIMAXPP;
                            minmax1pp.click();
                            last_clicked[0]->unclick();
                            last_clicked[0] = &minmax1pp;
                            break;
                        }
                        else if (button == &minmax2pp) {
                            config->player2 = Player::Type::MINIMAXPP;
                            minmax2pp.click();
                            last_clicked[1]->unclick();
                            last_clicked[1] = &minmax2pp;
                            break;
                        }
                        else if (button == &custom1) {
                            config->player1 = Player::Type::CUSTOM;
                            custom1.click();
                            last_clicked[0]->unclick();
                            last_clicked[0] = &custom1;
                            break;
                        }
                        else if (button == &custom2) {
                            config->player2 = Player::Type::CUSTOM;
                            custom2.click();
                            last_clicked[1]->unclick();
                            last_clicked[1] = &custom2;
                            break;
                        }
                    }
                }
                if (start.isHovered(event.mouseButton.x, event.mouseButton.y)) { return Type::GAME; }
            }
        }
        default: break;
    }
    return type;
}