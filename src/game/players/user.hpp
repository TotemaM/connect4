#pragma once
#include "game/players/player.hpp"

class User : public Player {
    bool validInput(const string &input) const {
        try {
            int move = stoi(input);
            move--;
            return move >= 0 && move <= 6;
        } catch (const invalid_argument &e) { return false; }
    }
public:
    User(const Color color): Player(color) { type = Type::USER; }
    short unsigned int play(const Board board [[maybe_unused]]) override {
        string move;
        cin >> move;
        while (!validInput(move)) {
            cout << "Invalid move. Please try again." << endl;
            cin >> move;
        }
        return stoi(move)-1;
    }
};