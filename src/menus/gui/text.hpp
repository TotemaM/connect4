#include <SFML/Graphics.hpp>

#include <string>
using namespace std;

class Text : public sf::Drawable {
    sf::Text text;
    sf::Font font;
public:
    Text(string txt, int x, int y, int size = 30, string font_path = "font/8bit.ttf", sf::Color color = sf::Color::White) {
        text.setString(txt);
        text.setCharacterSize(size);
        font.loadFromFile(font_path);
        text.setFont(font);
        text.setPosition(x-this->text.getGlobalBounds().width/2, y-this->text.getGlobalBounds().height/2);
        text.setFillColor(color);
    }
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(text, states);
    }
};