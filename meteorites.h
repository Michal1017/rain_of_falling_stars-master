#ifndef METEORITES_H
#define METEORITES_H
#include <object.h>

class Meteorites : public Object //klasa wytworzona do spadajacych obiektów
{
private:
     int health_bonus;   //bonus do zdrowia w zależnosci od meteorytu, może być pozytywny albo negatywny
     int score_bonus;    //bonus do punktów w zależnosci od meteorytu, może być pozytywny albo negatywny
     sf::Texture texture_met_1;
public:
     Meteorites(const float &velocity_x,const float &velocity_y,const float &a,const float &b,const float &bon_hea,const float &bon_sco);
     static bool collision_met(Meteorites &m1,Meteorites &m2);
     bool collision_floor(const sf::Sprite &floor);       //metody obsługujące kolizje z różnymi elementami sceny
     void falling(const sf::Time &elapsed); //metoda obslugujaca spadanie meteorytu z gory
     int health_info() {return health_bonus;}
     int score_info()  {return score_bonus;}
};

#endif // METEORITES_H
