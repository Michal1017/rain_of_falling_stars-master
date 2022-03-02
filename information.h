#ifndef INFORMATION_H
#define INFORMATION_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <SFML/Audio.hpp>

class Information
{
private:
    sf::Font font;
    sf::RenderWindow window;
    sf::Sprite background;
    sf::Text info;
    sf::Texture text_background;
public:
    Information();
    void show_info();
};
#endif // INFORMATION_H
