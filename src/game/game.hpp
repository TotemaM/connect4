#pragma once

#include "game/board.hpp"
#include "game/players/user.hpp"
#include "game/players/random.hpp"
#include "game/players/minimax.hpp"
#include "game/players/custom.hpp"
#include "gui/text.hpp"
#include <atomic>

class Game : public sf::Drawable {
public:
    enum Winner { YELLOW = 0, RED = 1, DRAW = 2, NONE = 4};
    Game(Player::Type p1, Player::Type p2) {
        board = make_unique<Board>();
        switch (p1) {
            case Player::Type::RANDOM: players[0] = make_unique<Random>(Color(Color::Type::YELLOW)); break;
            case Player::Type::MINIMAX: players[0] = make_unique<Minimax>(Color(Color::Type::YELLOW)); break;
            case Player::Type::CUSTOM: players[0] = make_unique<Custom>(Color(Color::Type::YELLOW)); break;
            default: players[0] = make_unique<User>(Color(Color::Type::YELLOW)); break;
        }
        switch (p2) {
            case Player::Type::RANDOM: players[1] = make_unique<Random>(Color(Color::Type::RED)); break;
            case Player::Type::MINIMAX: players[1] = make_unique<Minimax>(Color(Color::Type::RED)); break;
            case Player::Type::CUSTOM: players[1] = make_unique<Custom>(Color(Color::Type::RED)); break;
            default: players[1] = make_unique<User>(Color(Color::Type::RED)); break;
        }
    }
    void start() {
        Coordinate c = {8, 8};
        for (unsigned int i = 0; i < board->getMaxRound(); i++) {
            current = i % 2;
            short unsigned int copy_current = current;
            if (players[current]->getType() == Player::Type::USER) {
                while (copy_current == current) { }
            } else {
                short unsigned int column = players[current]->play(*board);
                while (!board->validPlay(column)) {
                    column = players[current]->play(*board);
                }
                c = board->play(column, players[current]->getColor());
            }
            if (board->checkVictory()) {
                if (current == 0) { winner = Winner::YELLOW; }
                else { winner = Winner::RED; }
                return;
            }
        }
        winner = Winner::DRAW;
        return;
    }
    // Returning true if move is valid
    bool userPlay(short unsigned int column) {
        if (board->validPlay(column)) {
            board->play(column, players[current]->getColor());
            current = (current + 1) % 2;
            return true;
        }
        return false;
    }
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(*board, states);
        switch (winner) {
            case Winner::YELLOW: target.draw(Text("Yellow wins !", 258, 40, 20, Anchor::Type::C, "font/8bit.ttf", sf::Color::White), states); break;
            case Winner::RED: target.draw(Text("Red wins !", 258, 40, 20, Anchor::Type::C, "font/8bit.ttf", sf::Color::White), states); break;
            case Winner::DRAW: target.draw(Text("Draw !", 258, 40, 20, Anchor::Type::C, "font/8bit.ttf", sf::Color::White), states); break;
            default: break;
        }
    }
    Player::Type getCurrentPlayerType() const {
        return players[current]->getType();
    }
    int getWinner() const { return winner; }
private:
    unique_ptr<Board> board;
    unique_ptr<Player> players[2];
    short unsigned int current;
    atomic<int> winner =  Winner::NONE;
};