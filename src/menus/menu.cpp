// Reference header
#include "menus/menu.hpp"

Menu::Type Menu::getType() const { return type; }

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (auto item: items) { target.draw(*item, states); }
}