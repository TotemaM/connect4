#pragma once
#include <iostream>
using namespace std;

struct Color {
    enum Type { WHITE = 0, YELLOW = 1, RED = 2 };
    Color(Type color = Type::WHITE) : color(color) {}
    void altPrint() {
        switch (color) {
            case Color::Type::WHITE: cout << "."; break;
            case Color::Type::YELLOW: cout << "\x1B[33m⍟\033[0m"; break;
            case Color::Type::RED: cout << "\x1B[31m⍟\033[0m"; break;
            default: break;
        }
    }
    friend ostream& operator<<(ostream &os, Color color) {
        switch (color) {
            case Color::Type::WHITE: os << "."; break;
            case Color::Type::YELLOW: os << "\x1B[33m●\033[0m"; break;
            case Color::Type::RED: os << "\x1B[31m●\033[0m"; break;
            default: break;
        }
        return os;
    }
    operator int() { return static_cast<int>(color); }
    bool operator == (const Color &c) const { return color == c.color; }
    Color getInverted() const {
        switch (color) {
            case Color::Type::YELLOW: return Color(Color::Type::RED);
            case Color::Type::RED: return Color(Color::Type::YELLOW);
            default: return Color(Color::Type::WHITE);
        }
    }
    Type getType() const { return color; }
private:
     Type color;
};