#pragma once

class Player {
public:
    enum Type { NONE, USER, RANDOM };
    Player() = default;
    Type getType() const { return type; }
protected:
    Type type = NONE;
};