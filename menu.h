#ifndef MENU_H
#define MENU_H
#include <game_screen.h>
#include <information.h>
#include <score.h>

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


#endif // MENU_H
