#pragma once

#include <SFML/Graphics.hpp>
#include "game/players/player.hpp"
#include "game/board.hpp"
#include <memory>
using namespace std;

class Game : public sf::Drawable {
    unique_ptr<Player> players[2];
    unique_ptr<Board> board = make_unique<Board>();
    short unsigned int currentPlayer = 0;
public:
    Game(Player::Type p1, Player::Type p2) {
        players[0] = make_unique<Player>(p1);
        players[1] = make_unique<Player>(p2);
    }
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(*board, states);
    }
    short unsigned int start() {
        Coordinate c = {8, 8};
        for (unsigned int i = 0; i < board->getMaxRound(); i++) {
            short unsigned int current = i % 2;
            if (display) board->display(current, &c);
            short unsigned int column = players[current]->play(*board);
            while (!board->validPlay(column)) {
                if (display) cout << "Invalid move. Please try again." << endl;
                column = players[current]->play(*board);
            }
            c = board->play(column, players[current]->getColor());
            if (board->checkVictory()) {
                if (display) board->display(current, &c);
                cout << "Player " << current + 1 << " wins !" << endl;
                return current + 1;
            }
        }
        if (display) board->display();
        cout << "It's a draw!" << endl;
        return 0;
    }
    Player::Type getCurrentPlayerType() const { return players[currentPlayer]->getType(); }
    void play(short unsigned int column) {}
};