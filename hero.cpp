#include "hero.h"

Hero::Hero()
{
    sf::Texture text;
    text.setRepeated(true);
    if (!text.loadFromFile("hero_stoi.png")) {
        std::cerr << "Could not load texture" << std::endl;
    }
    hero_textures.emplace_back(text);
    if (!text.loadFromFile("bieganie1.png")) {
        std::cerr << "Could not load texture" << std::endl;
    }
    hero_textures.emplace_back(text);
    if (!text.loadFromFile("bieganie2.png")) {
        std::cerr << "Could not load texture" << std::endl;
    }
    hero_textures.emplace_back(text);
    if (!text.loadFromFile("bieganie3.png")) {
        std::cerr << "Could not load texture" << std::endl;
    }
    hero_textures.emplace_back(text);
    if (!text.loadFromFile("skok.png")) {
        std::cerr << "Could not load texture" << std::endl;
    }
    hero_textures.emplace_back(text);
    if (!text.loadFromFile("jump2.png")) {
        std::cerr << "Could not load texture" << std::endl;
    }
    hero_textures.emplace_back(text);
    if (!text.loadFromFile("hamowanie.png")) {
        std::cerr << "Could not load texture" << std::endl;
    }
    hero_textures.emplace_back(text);
}

void Hero::set_data(const std::string &name_, const float &health_, const float &left, const float &right)
{
    name=name_;
    health=health_;
    x_left=left;
    x_right=right;
}


void Hero::save()
{
    std::fstream output("Scores.txt",std::ios_base::app);
    if(output.is_open())
    {
        output<<name<<","<<score<<","<<std::endl;
    }
    output.close();
}

bool Hero::collision_floor(const sf::Sprite &floor)
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

bool Hero::collision_meteorite(Meteorites &met)
{
    if(getGlobalBounds().intersects(met.getGlobalBounds()))
    {
        health+=met.health_info();
        score+=met.score_info();
        return true;
    }
    else
    {
        return false;
    }
}

bool Hero::is_alive()
{
    if(health<=0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void Hero::add_point()
{
    score+=10;
}

void Hero::set_is_bool(const bool &b1, const bool &b2)
{
    is_right=b1;
    is_left=b2;
    v_x=400;
}

void Hero::set_is_move(const bool &b1)
{
    is_move=b1;
}

void Hero::animation()
{
    if(is_move==true)
    {
        if(number_f_animation<=32)
        {
        setTexture(hero_textures[1]);
        }
        if(number_f_animation>=33 && number_f_animation<=65)
        {
        setTexture(hero_textures[2]);
        }
        if(number_f_animation>=66)
        {
        setTexture(hero_textures[3]);
        }
        number_f_animation++;
        number_f_animation=number_f_animation%99;

    }
    else if(is_move==false && v_x>0)
    {
        v_x-=3;
        setTexture(hero_textures[6]);
    }

    if(v_y!=0 && v_x<=0)
    {
        setTexture(hero_textures[5]);
    }
    else if(v_y!=0 && v_x>0)
    {
        setTexture(hero_textures[4]);
    }
    else if(v_y==0 && v_x<=0)
    {
        setTexture(hero_textures[0]);
    }
}

void Hero::set_is_jump(const bool &b1)
{
    jump_is=b1;
}

void Hero::move_hero(const sf::Time &elapsed,const sf::Sprite &floor)
{
    if(is_right==true)
    {
        if(getGlobalBounds().left+getGlobalBounds().width<x_right)
             {
                move(elapsed.asSeconds()*v_x,0);
              }
    }
    else if(is_left==true)
    {
        if(getGlobalBounds().left>x_left)
             {
               move((-1)*elapsed.asSeconds()*v_x,0);
             }
    }

    move(0,(-1)*v_y*elapsed.asSeconds());
    v_y-=g*elapsed.asSeconds();

    if(collision_floor(floor))
    {
        jump_is=true;
        v_y=0;
    }
}

void Hero::get_jump()
{
    v_y=sqrt(2*g*h_max);
}
