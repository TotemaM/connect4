#pragma once

#include "game/players/player.hpp"
#include "game/rng.hpp"

enum Heurisitcs {
    WIN = 5,
    DRAW = 0,
    DEPTH = 10,
    CENTER = 3,
    SIDE = 1,
    EDGE = 0,
};

class MinimaxPP : public Player {
    bool display = false;
    int minimax(Board board, short unsigned int depth, bool maximizingPlayer) {
        if (depth == 0 || board.checkVictory() || board.isBoardFull()) { return heuristic(board, depth); }
            if (maximizingPlayer) {
                int value = -2147483648;
                for (short unsigned int move : board.getValidMoves()) {
                    Board copy = board;
                    copy.play(move, getColor());
                    if (display) copy.display();
                    value = minimax(copy, depth - 1, false);
                    value += evaluateMove(move);
                    if (display) cout << move + 1 << " : " << value << endl;
                }
                return value;
            } else {
                int value = 2147483647;
                for (short unsigned int move : board.getValidMoves()) {
                    Board copy = board;
                    copy.play(move, getColor().getInverted());
                    if (display) copy.display();
                    value = min(value, minimax(copy, depth - 1, true));
                    value -= evaluateMove(move);
                    if (display) cout << move + 1 << " : " << value << endl;
                }
            return value;
        }
    }
    int evaluateMove(short unsigned int move) {
        if (move == 3) { return CENTER; }
        if (move == 2 || move == 4) { return SIDE; }
        if (move == 1 || move == 5) { return EDGE; }
        return 0;
    }
    int heuristic(Board board, short unsigned int depth) {
        if (board.checkVictory()) { return WIN + (DEPTH*depth); }
        if (board.isBoardFull()) { return DRAW + (DEPTH*depth); }
        return 0;
    }
public:
    MinimaxPP(const Color color): Player(color) { type = Type::MINIMAXPP; }
    short unsigned int play(Board board) override {
        int bestValue = -2147483648;
        short unsigned int bestMove = 0;
        for (short unsigned int move : board.getValidMoves()) {
            Board copy = board;
            copy.play(move, getColor());
            if (display) copy.display();
            int value = minimax(copy, 6, false);
            value += evaluateMove(move);
            //cout << move + 1 << " : " << value << endl;
            if (value == bestValue) {
                if (RNG::randRange(0, 1)) { 
                    bestMove = move;
                }
            }
            else if (value > bestValue) {
                bestValue = value;
                bestMove = move;
            }
            board = copy; // Undo move
        }
        return bestMove;
    }
};