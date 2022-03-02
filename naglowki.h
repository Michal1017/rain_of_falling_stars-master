#ifndef NAGLOWKI_H
#define NAGLOWKI_H
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

class Object : public  sf::Sprite
{
protected:
    float v_x;//prędkośc na osi 0X
    float v_y;//prędkość na osi 0Y
    int x_left;//
    int x_right;//dwie zmienne potrzebne do wyznaczenia obszaru w jakim moga poruszac sie obiekty na osi OX
public:
    int x_left_info() {return x_left;}
    int x_right_info(){return x_right;}
};


class Meteorites : public Object //klasa wytworzona do spadajacych obiektów
{
protected:
     float v_x;//prędkośc na osi 0X
     float v_y;//prędkość na osi 0Y
     int health_bonus;   //bonus do zdrowia w zależnosci od meteorytu, może być pozytywny albo negatywny
     int score_bonus;    //bonus do punktów w zależnosci od meteorytu, może być pozytywny albo negatywny
public:
     Meteorites(const float &velocity_x,const float &velocity_y,const float &a,const float &b,const float &bon_hea,const float &bon_sco);
     static bool collision_met(Meteorites &m1,Meteorites &m2);
     bool collision_floor(const sf::Sprite &floor);       //metody obsługujące kolizje z różnymi elementami sceny
     void falling(const sf::Time &elapsed); //metoda obslugujaca spadanie meteorytu z gory
     int health_info() {return health_bonus;}
     int score_info()  {return score_bonus;}
};


class Hero: public Object //klasa z której utworzony będzie nasz bohater
{
protected:
    int health;      //zmienna do punktów życia
    int score=0;     //wartość punktów zawsze na początku wynosi 0
    std::string name;  //zmienna do przechowywania nazwy gracza
public:
    void set_data(const std::string &name_,const float &health_,const float &left,const float &right);
    void save(); //metoda zapisujaca wynik do pliku
    bool collision_floor(const sf::Sprite &floor);     //metoda obsługująca kolizje bohatera z podłożem
    bool collision_meteorite(Meteorites &met);
    bool is_alive();
    int number_of_points() {return score;}
    int number_of_health() {return health;}
    void add_point();
};

class Game_screen
{
private:
    sf::RenderWindow window;
    Hero hero;
    std::vector<Meteorites> meteorites;
    sf::Sprite floor;                 //podłoże
    sf::Sprite background;                 //zmienna która wczytuje tło ekranu gry
    sf::Texture texture_grass,texture_sky;
    sf::Texture texture_met_1;
    sf::Font font;
    sf::Text t_number_of_points,t_number_of_health;
    sf::Texture run1,run2,run3,texture_hero,texture_jump,texture_jump_2,texture_braking;
    float time;                     //zmienna do określenia co jaki czas będzie zwiększała się liczba meteorytów
    float current_time=0.0;                 //zmienna mająca wartość aktualnego czasu
    float g=981.0;  //zmienna imitująca wartość przyspieszenia ziemskiego potrzebna do wyliczenia np. wysokości na jaką może wyskoczyć postać
    float velocity;                  //zmienna sredniej predkosci na osi OY meteorytow
    bool jump_is=true;
    float h_max=200;    //wysokość na jaką maksymalnie może wyskoczyć bohater
    int number_f_animation=0;
    bool is_left=false;
    bool is_right=false;  //wartosci logiczne przechowujące informacje czy bohater porusza się w prawo czy w lewo
    bool is_move=true;
    float v_x;//prędkośc na osi 0X
    float v_y;//prędkość na osi 0Y
public:
    Game_screen(const float &zdr,const std::string &naz,const float &cz,const int &l_m,const float &pr);          //konstruktor ekranu gry w którym utworzony jest nasz bohater więc jako argumenty potrzene są wartości niezbędne do utworzenia bohatera
    Meteorites add_meteorite();               //metoda która dodaje kolejny meteoryt do ekranu gry z argumentami jako wartościami potrzebnymi do utworzenia meteorytu
    void show_screen();                  //metoda do ukazania ekranu gry
    void update(const sf::Time &elapsed);
    bool is_lose();
    void play_game();
    void move_ox(const sf::Time &elapsed);
    void jump(const sf::Time &elapsed);
};

class Menu
{
private:
    sf::RenderWindow window;
    sf::Event event;
    std::vector<sf::RectangleShape> options;    //wektor prostokątów które będą kafelkami do kliknięnia: start,score,settings,quit
    sf::Sprite menu_background;                        //sprite który będzie tłem gry
    sf::Texture text_menu;
    sf::Music music;
    sf::Clock clock;
    sf::Font font;
    sf::Text start,title,score,quit,name,hard,easy,set_name,info;
    bool is_easy=true;
    bool is_hard=false;
    std::vector<float> game_parametrs={150,30.0,5,250.0};
public:
    Menu();
    void show_menu();  //metoda do pokazania menu gry
    void show_settings();
    bool choose_game();  //metoda obsługująca wybór odpowiedniej części gry
    bool close_menu();
    bool choose_score();
    bool is_easy_clicked();
    bool is_hard_clicked();
    bool choose_info();
    void play();
};

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

#endif // NAGLOWKI_H
