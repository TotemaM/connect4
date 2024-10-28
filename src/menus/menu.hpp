#pragma once
// Standard libraries
#include <vector>
using namespace std;
// SFML libraries
#include <SFML/Graphics.hpp>
// Interface for the menus of the SFML GUI
class Menu : public sf::Drawable {
public:
    Menu() = default;
    virtual ~Menu() {}
    enum Type { NONE, MAIN, GAME };
    Type getType() const;
    virtual Type handle_event(sf::Event event) = 0;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
protected:
    vector<sf::Drawable*> items;
    Type type = NONE;
};