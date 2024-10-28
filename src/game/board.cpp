// Reference header
#include "game/board.hpp"
// File inclusions
#include "gui/image.hpp"
#include "gui/anchor.hpp"

Board::Board() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = Color(Color::Type::WHITE);
        }
    }
}
void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (short unsigned int i = 0; i < HEIGHT; i++) {
        for (short unsigned int j = 0; j < WIDTH; j++) {
            int x = j*64 + 64;
            int y = i*64 + 128;
            switch (board[i][j].getType()) {
                case Color::Type::YELLOW: target.draw(Image("img/circle_yellow.png", x, y, Anchor::Type::C), states); break;
                case Color::Type::RED: target.draw(Image("img/circle_red.png", x, y, Anchor::Type::C), states); break;
                default: break;
            }
        }
    }
}
void Board::display(const short unsigned int playerID = 2, const Coordinate* lastMove = nullptr) const {
    //system("clear");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (lastMove != nullptr && i == lastMove->i && j == lastMove->j) {
                Color c = board[i][j];
                c.altPrint();
                cout << " ";
            } else { cout << board[i][j] << " "; }
            
        }
        cout << endl;
    }
    for (short unsigned int i = 1; i <= WIDTH; i++) {
        switch(playerID) {
            case 0: cout << "\x1B[33m"; break;
            case 1: cout << "\x1B[31m"; break;
            default: break;
        }
        cout << i << " ";
    }
    cout << "\033[0m" << endl << endl;
}
unsigned int Board::getMaxRound() const { return MAX_ROUND; }
bool Board::validPlay(const short unsigned int &column) const {
    return (/* column >= 0 && */ column < WIDTH) && \
            (board[0][column] == Color(Color::Type::WHITE));
}
/* !!! Check if the play is valid before calling this function */
Coordinate Board::play(const short unsigned int &column, const Color &color) {
    current_round++;
    for (short unsigned int i = HEIGHT - 1; /* i >= 0 */ ; i--) {
        if (board[i][column] == Color(Color::Type::WHITE)) {
            board[i][column] = color;
            return {i, column};
        }
    }
}
bool Board::checkVictory() {
    for (short unsigned int cj = 0; cj < WIDTH; cj++) {
        for (short unsigned int ci = 0; ci < HEIGHT; ci++) {
            if (board[ci][cj] == Color(Color::Type::WHITE)) continue;
            Color color = board[ci][cj];
            short unsigned int count = 0;
            for (short int i = -1; i <= 1; i++) {
                for (short int j = -1; j <= 1; j++) {
                    if (i == 0 && j == 0) continue;
                    Coordinate temp = {ci, cj};
                    while ((/* temp.i >= 0 && */ temp.i < HEIGHT) && (/* temp.j >= 0 && */ temp.j < WIDTH) && (board[temp.i][temp.j] == color)) {
                        count++;
                        temp.i += i;
                        temp.j += j;
                    }
                    if (count >= 4) {
                        winner = color;
                        return true;
                    }
                    count = 0;
                }
            }
        }
    }
    return false;
}
bool Board::isBoardFull() const { return current_round == MAX_ROUND; }
vector<short unsigned int> Board::getValidMoves() const {
    vector<short unsigned int> validPlays;
    for (short unsigned int i = 0; i < WIDTH; i++) {
        if (board[0][i] == Color(Color::Type::WHITE)) {
            validPlays.push_back(i);
        }
    }
    return validPlays;
}
Color Board::getWinner() const { return winner; }