#ifndef SCORE_H
#define SCORE_H
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


class Score
{
private:
    std::vector<std::pair<std::string,int>> scores;
    std::vector<sf::Text> scores_texts;
    sf::Font font;
    sf::RenderWindow window;
    sf::Sprite menu_background;
    sf::Texture text_menu;
public:
    Score();
    void show_scores();
};

#endif // SCORE_H
