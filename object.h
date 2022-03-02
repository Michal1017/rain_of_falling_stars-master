#ifndef OBJECT_H
#define OBJECT_H
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

class Object: public sf::Sprite
{
protected:
    float v_x;//prędkośc na osi 0X
    float v_y;//prędkość na osi 0Y
    int x_left;//
    int x_right;//dwie zmienne potrzebne do wyznaczenia obszaru w jakim moga poruszac sie obiekty na osi OX
    float g=981.0;  //zmienna imitująca wartość przyspieszenia ziemskiego potrzebna do wyliczenia np. wysokości na jaką może wyskoczyć postać
public:
    int x_left_info();
    int x_right_info();
};

#endif // OBJECT_H
