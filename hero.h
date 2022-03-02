#ifndef HERO_H
#define HERO_H
#include <object.h>
#include <meteorites.h>

class Hero: public Object //klasa z której utworzony będzie nasz bohater
{
private:
    int health;      //zmienna do punktów życia
    int score=0;     //wartość punktów zawsze na początku wynosi 0
    std::string name;  //zmienna do przechowywania nazwy gracza
    std::vector<sf::Texture> hero_textures;
    float time;                     //zmienna do określenia co jaki czas będzie zwiększała się liczba meteorytów
    float current_time=0.0;                 //zmienna mająca wartość aktualnego czasu
    bool jump_is=true;
    float h_max=200;    //wysokość na jaką maksymalnie może wyskoczyć bohater
    int number_f_animation=0;
    bool is_left=false;
    bool is_right=false;  //wartosci logiczne przechowujące informacje czy bohater porusza się w prawo czy w lewo
    bool is_move=true;
public:
    Hero();
    void set_data(const std::string &name_,const float &health_,const float &left,const float &right);
    void save(); //metoda zapisujaca wynik do pliku
    bool collision_floor(const sf::Sprite &floor);     //metoda obsługująca kolizje bohatera z podłożem
    bool collision_meteorite(Meteorites &met);
    bool is_alive();
    int number_of_points() {return score;}
    int number_of_health() {return health;}
    void add_point();
    void set_is_bool(const bool &b1,const bool &b2);
    void set_is_move(const bool &b1);
    void set_is_jump(const bool &b1);
    bool get_is_jump() {return jump_is;}
    void animation();
    void move_hero(const sf::Time &elapsed,const sf::Sprite &floor);
    void get_jump();
};

#endif // HERO_H
