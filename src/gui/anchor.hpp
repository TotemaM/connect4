#pragma once

class Anchor {
public:
    enum Type { N, NE, E, SE, S, SW, W, NW, C };
    Anchor() = default;
    void attach(int x, int y, unsigned int width, unsigned int height, Type type) {
        switch (type) {
            case N: this->x = x - width/2; this->y = y; break;
            case NE: this->x = x - width; this->y = y; break;
            case E: this->x = x - width; this->y = y - height/2; break;
            case SE: this->x = x - width; this->y = y - height; break;
            case S: this->x = x - width/2; this->y = y - height; break;
            case SW: this->x = x; this->y = y - height; break;
            case W: this->x = x; this->y = y - height/2; break;
            case NW: this->x = x; this->y = y; break;
            case C: this->x = x - width/2; this->y = y - height/2; break;
            default: break;
        }
    }
    int getX() const { return x; }
    int getY() const { return y; }
private:
    int x = 0;
    int y = 0;
};