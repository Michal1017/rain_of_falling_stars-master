#include "game_screen.h"

Game_screen::Game_screen(const float &zdr,const std::string &naz,const float &cz,const int &l_m,const float &pr): window(sf::VideoMode(1300,760), "Rain of falling stars")
{
    time=cz;
    velocity=pr;
    if(!texture_sky.loadFromFile("sky.png")){
        std::cerr<<"Could not load texture"<<std::endl;
    }
    background.setTexture(texture_sky);
    background.setPosition(0.0,0.0);
    background.setScale(window.getSize().x*0.00067,window.getSize().y*0.00078);

    hero.set_data(naz,zdr,0,window.getSize().x);
    hero.setPosition(window.getSize().x*0.5,window.getSize().y*0.7);
    hero.setScale(window.getSize().x*0.0004167,window.getSize().y*0.0004167);

    if (!texture_grass.loadFromFile("grass.png")) {
        std::cerr << "Could not load texture" << std::endl;
    }
     texture_grass.setRepeated(true);

     if (!texture_met_1.loadFromFile("meteoryt1.png")) {
         std::cerr << "Could not load texture" << std::endl;
     }

    floor.setTexture(texture_grass);
    floor.setPosition(0.0,window.getSize().y*0.8333);
    floor.setTextureRect(sf::IntRect(0.0,0.0,window.getSize().x,window.getSize().y*0.1667));

    for(int i=0;i<l_m;i++)
    {
    meteorites.emplace_back(add_meteorite());
    }
    if (!texture_met_1.loadFromFile("meteoryt1.png")) {
        std::cerr << "Could not load texture" << std::endl;
    }
    if (!font.loadFromFile("font.ttf"))
    {
        std::cerr << "Could not load font" << std::endl;
    }
    t_number_of_points.setFont(font);
    t_number_of_points.setCharacterSize(window.getSize().x*0.08333);
    t_number_of_points.setFillColor(sf::Color::Red);
    t_number_of_points.setPosition(window.getSize().x-(window.getSize().x*0.4167),0);

    t_number_of_health.setFont(font);
    t_number_of_health.setCharacterSize(window.getSize().x*0.08333);
    t_number_of_health.setFillColor(sf::Color::Red);
    t_number_of_health.setPosition(0,0);
}

Meteorites Game_screen::add_meteorite()
{
    int x=rand()%20;

        if(x<=11)
        {
            Meteorites met(rand()%50-25,(rand()%100)+(velocity-50),0,window.getSize().x,-30,0);
            met.setColor(sf::Color::Red);
            met.setTexture(texture_met_1);
            return met;
        }
        else if(x>11 && x<17)
        {
            Meteorites met(rand()%50-25,(rand()%100)+(velocity-50),0,window.getSize().x,0,-30);
            met.setColor(sf::Color::Yellow);
            met.setTexture(texture_met_1);
            return met;
        }
        else if(x==17)
        {
            Meteorites met(rand()%50-25,(rand()%100)+(velocity-50),0,window.getSize().x,10,0);
            met.setColor(sf::Color::Blue);
            met.setTexture(texture_met_1);
            return met;
        }
        else
        {
            Meteorites met(rand()%50-25,(rand()%100)+(velocity-50),0,window.getSize().x,0,30);
            met.setColor(sf::Color::Green);
            met.setTexture(texture_met_1);
            return met;
        }
}

void Game_screen::show_screen()
{
    window.draw(background);
    window.draw(hero);
    window.draw(floor);
    window.draw(t_number_of_points);
    window.draw(t_number_of_health);
    for(auto &el:meteorites)
    {
        window.draw(el);
    }
}

void Game_screen::update(const sf::Time &elapsed)
{
    std::string punkty= "Score "+std::to_string(hero.number_of_points());
    t_number_of_points.setString(punkty);
    std::string zdrowie="Health "+std::to_string(hero.number_of_health());
    t_number_of_health.setString(zdrowie);
    control_hero(elapsed);
    for(auto it = meteorites.begin(); it != meteorites.end(); it++)
    {
        if(it->collision_floor(floor) || hero.collision_meteorite(*it))
        {
            if(it->collision_floor(floor))
            {
                hero.add_point();
            }
            meteorites.erase(it);
            meteorites.emplace_back(add_meteorite());
        }
        else
        {
            it->falling(elapsed);
        }
    }
    for(size_t i=0;i<meteorites.size();i++)
    {
        for(size_t j=i+1;j<meteorites.size();j++)
        {
            Meteorites::collision_met(meteorites[i],meteorites[j]);
        }
    }
    current_time+=elapsed.asSeconds();
    if(current_time>time)
    {
        meteorites.emplace_back(add_meteorite());
        current_time=0;
        velocity+=10;
    }
}

bool Game_screen::is_lose()
{
    if(hero.is_alive()==false)
    {
        hero.save();
        return true;
    }
    else
    {
        return false;
    }
}

void Game_screen::play_game()
{
    sf::Clock clock;

    while(window.isOpen())
    {
     sf::Event event;
     while (window.pollEvent(event))
     {
       if(event.type==sf::Event::Closed || is_lose())
           window.close();
     }

     sf::Time elapsed=clock.restart();

     window.clear(sf::Color::Blue);

     update(elapsed);

     show_screen();

     window.display();
    }
}

void Game_screen::control_hero(const sf::Time &elapsed)
{
    sf::FloatRect bounds=hero.getGlobalBounds();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
         if(bounds.left>hero.x_left_info()){
            hero.set_is_bool(false,true);
            hero.set_is_move(true);
            hero.setTextureRect(sf::IntRect(180,0,-180,250));
         }
        }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            if(bounds.left+bounds.width<hero.x_right_info())
            {
                hero.set_is_bool(true,false);
                hero.set_is_move(true);
                hero.setTextureRect(sf::IntRect(0,0,180,250));
            }
        }
    else
    {
        hero.set_is_move(false);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) ) {
            if(hero.get_is_jump()==true)
            {
            hero.get_jump();
            hero.set_is_jump(false);
            }
        }
    hero.move_hero(elapsed,floor);
    hero.animation();
}

