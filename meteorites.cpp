#include "meteorites.h"

Meteorites::Meteorites(const float &velocity_x,const float &velocity_y,const float &a,const float &b,const float &bon_hea,const float &bon_sco)
{
    health_bonus=bon_hea;
    score_bonus=bon_sco;
    v_x=velocity_x;
    v_y=velocity_y;
    x_left=a;
    x_right=b;
    setPosition(rand()%x_right,0);
    setScale(x_right*0.0007,x_right*0.0007);
    if (!texture_met_1.loadFromFile("meteoryt1.png")) {
        std::cerr << "Could not load texture" << std::endl;
    }
    setTexture(texture_met_1);
}

bool Meteorites::collision_met(Meteorites &m1, Meteorites &m2)
{
if(m1.getGlobalBounds().intersects(m2.getGlobalBounds()))
    {
    float v_x_p=m1.v_x;
    float v_y_p=m1.v_y;
    m1.v_x=m2.v_x;
    m1.v_y=m2.v_y;
    m2.v_x=v_x_p;
    m2.v_y=v_y_p;
    return true;
    }
    else
    {
    return false;
    }
}


bool Meteorites::collision_floor(const sf::Sprite &floor)
{
    if(getGlobalBounds().intersects(floor.getGlobalBounds()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Meteorites::falling(const sf::Time &elapsed)
{
    if(getGlobalBounds().left<x_left || getGlobalBounds().left+getGlobalBounds().width>x_right)
    {
        v_x=(-1)*v_x;
    }
    move(v_x*elapsed.asSeconds(),v_y*elapsed.asSeconds());
}


