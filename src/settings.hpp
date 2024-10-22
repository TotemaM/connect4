#pragma once

#include <string>
#include <fstream>
using namespace std;

class SettingsManager {
    const string PATH = "static/settings.ini";
    unsigned int width;
    unsigned int height;
public:
    SettingsManager() {
        ifstream file(PATH);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                if (line.find("width") != string::npos) { width = stoi(line.substr(line.find("=")+1)); }
                if (line.find("height") != string::npos) { height = stoi(line.substr(line.find("=")+1)); }
            }
            file.close();
        }
    }
    void saveSettings() {
        ofstream file(PATH);
        if (file.is_open()) {
            file << "width=" << width << endl;
            file << "height=" << height << endl;
            file.close();
        }
    }
    void setResolution(int width, int height) {
        this->width = width;
        this->height = height;
        saveSettings();
    }
    unsigned int getWidth() const { return width; }
    unsigned int getHeight() const { return height; }
};

// TODO make singleton