#pragma once
#include "game/players/player.hpp"
#include "game/rng.hpp"

class Minimax : public Player {
    const unsigned int DEPTH = 6;
    vector<int> minimax(Board &board, const unsigned int &depth, int alpha, int beta, bool maximizing) {
        if (depth == 0 || board.checkVictory() || board.isBoardFull()) { return {0, heuristic(board, depth)}; }
        if (maximizing) {
            int bestScore = -2147483648;
            short unsigned int bestMove = 0;
            for (short unsigned int move : board.getValidMoves()) {
                Board copy_board = board;
                copy_board.play(move, getColor());
                int score = minimax(copy_board, depth - 1, alpha, beta, false)[1];
                score += evaluateMove(move);
                //cout << move + 1 << " : " << score << endl;
                if (score == bestScore) {
                    if (RNG::randRange(0, 1)) {
                        bestMove = move;
                    }
                } else if (score > bestScore) {
                    bestScore = score;
                    bestMove = move;
                }
                alpha = max(alpha, score);
                if (alpha >= beta) { break; }
            }
            return {bestMove, bestScore};
        } else {
            int bestScore = 2147483647;
            short unsigned int bestMove = 0;
            for (short unsigned int move : board.getValidMoves()) {
                Board copy_board = board;
                copy_board.play(move, getColor().getInverted());
                int score = minimax(board, depth - 1, alpha, beta, true)[1];
                score -= evaluateMove(move);
                //cout << move + 1 << " : " << score << endl;
                if (score == bestScore) {
                    if (RNG::randRange(0, 1)) {
                        bestMove = move;
                    }
                } else if (score < bestScore) {
                    bestScore = score;
                    bestMove = move;
                }
                beta = min(beta, score);
                if (alpha >= beta) { break; }
            }
            return {bestMove, bestScore};
        }
    }
    int evaluateMove(const short unsigned int &move) {
        if (move == 3) { return 100; }
        if (move == 2 || move == 4) { return 30; }
        if (move == 1 || move == 5) { return 8; }
        return 0;
    }
    int heuristic(Board &board, const unsigned int &depth) {
        if (board.checkVictory()) { return 1000 - depth; }
        if (board.isBoardFull()) { return 0; }
        return 0;
    }
public:
    Minimax(const Color color): Player(color) { type = Type::MINIMAX; }
    short unsigned int play(Board board) override {
        return minimax(board, DEPTH, -2147483648, 2147483647, true)[0];
    }
};