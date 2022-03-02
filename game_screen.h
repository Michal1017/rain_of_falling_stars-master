#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H
#include <meteorites.h>
#include <hero.h>

class Game_screen
{
private:
    sf::RenderWindow window;
    Hero hero;
    std::vector<Meteorites> meteorites;
    sf::Sprite floor;                 //podłoże
    sf::Sprite background;                 //zmienna która wczytuje tło ekranu gry
    sf::Texture texture_grass,texture_sky;
    sf::Font font;
    sf::Text t_number_of_points,t_number_of_health;
    float time;                     //zmienna do określenia co jaki czas będzie zwiększała się liczba meteorytów
    float current_time=0.0;                 //zmienna mająca wartość aktualnego czasu
    float velocity;
    sf::Texture texture_met_1;
public:
    Game_screen(const float &zdr,const std::string &naz,const float &cz,const int &l_m,const float &pr);          //konstruktor ekranu gry w którym utworzony jest nasz bohater więc jako argumenty potrzene są wartości niezbędne do utworzenia bohatera
    Meteorites add_meteorite();               //metoda która dodaje kolejny meteoryt do ekranu gry z argumentami jako wartościami potrzebnymi do utworzenia meteorytu
    void show_screen();                  //metoda do ukazania ekranu gry
    void update(const sf::Time &elapsed);
    bool is_lose();
    void play_game();
    void control_hero(const sf::Time &elapsed);
};

#endif // GAME_SCREEN_H
