#include "menu.h"

Menu::Menu(): window(sf::VideoMode(1300,760), " Rain of falling stars")
{
    if(!text_menu.loadFromFile("sky.png")){
        std::cerr<<"Could not load texture"<<std::endl;
    }
    menu_background.setTexture(text_menu);
    menu_background.setPosition(0.0,0.0);
    menu_background.setScale(window.getSize().x*0.00066,window.getSize().y*0.00095);

    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(window.getSize().x*0.333,window.getSize().y*0.1167));
    rect.setPosition(window.getSize().x*0.333,window.getSize().y*0.13);
    rect.setFillColor(sf::Color::Red);
    options.emplace_back(std::move(rect));

    sf::RectangleShape rect_1;
    rect_1.setSize(sf::Vector2f(window.getSize().x*0.333,window.getSize().y*0.1167));
    rect_1.setPosition(window.getSize().x*0.333,window.getSize().y*0.27);
    rect_1.setFillColor(sf::Color::Red);
    options.emplace_back(std::move(rect_1));

    sf::RectangleShape rect_2;
    rect_2.setSize(sf::Vector2f(window.getSize().x*0.333,window.getSize().y*0.1167));
    rect_2.setPosition(window.getSize().x*0.333,window.getSize().y*0.4);
    rect_2.setFillColor(sf::Color::Red);
    options.emplace_back(std::move(rect_2));


    if (!music.openFromFile("music.ogg"))
    {
    std::cerr << "Could not load music" << std::endl;
    }
        music.play();

        if (!font.loadFromFile("font.ttf"))
        {
            std::cerr << "Could not load font" << std::endl;
        }

        start.setFont(font);
        start.setCharacterSize(window.getSize().x*0.07);
        start.setFillColor(sf::Color::Black);
        start.setPosition(window.getSize().x*0.4,window.getSize().y*0.133);
        start.setString("START");

        title.setFont(font);
        title.setCharacterSize(window.getSize().x*0.07);
        title.setFillColor(sf::Color::Black);
        title.setPosition(window.getSize().x*0.05,window.getSize().y*0.005);
        title.setString("RAIN OF THE FALLING STARS");

        score.setFont(font);
        score.setCharacterSize(window.getSize().x*0.07);
        score.setFillColor(sf::Color::Black);
        score.setPosition(window.getSize().x*0.4,window.getSize().y*0.2667);
        score.setString("SCORE");

        quit.setFont(font);
        quit.setCharacterSize(window.getSize().x*0.07);
        quit.setFillColor(sf::Color::Black);
        quit.setPosition(window.getSize().x*0.433,window.getSize().y*0.4);
        quit.setString("QUIT");

        name.setFont(font);
        name.setCharacterSize(window.getSize().x*0.07);
        name.setPosition(window.getSize().x*0.5,window.getSize().y*0.6);
        name.setFillColor(sf::Color::Black);

        hard.setFont(font);
        hard.setCharacterSize(window.getSize().x*0.07);
        hard.setFillColor(sf::Color::Black);
        hard.setPosition(window.getSize().x*0.8,window.getSize().y*0.4);
        hard.setString("HARD");

        easy.setFont(font);
        easy.setCharacterSize(window.getSize().x*0.07);
        easy.setFillColor(sf::Color::Blue);
        easy.setPosition(window.getSize().x*0.1,window.getSize().y*0.4);
        easy.setString("EASY");

        set_name.setFont(font);
        set_name.setCharacterSize(window.getSize().x*0.07);
        set_name.setFillColor(sf::Color::Black);
        set_name.setPosition(window.getSize().x*0.025,window.getSize().y*0.6);
        set_name.setString("WRITE NAME ");

        info.setFont(font);
        info.setCharacterSize(window.getSize().x*0.07);
        info.setFillColor(sf::Color::Black);
        info.setPosition(window.getSize().x*0.025,window.getSize().y*0.8);
        info.setString("INFORMATION");
}

void Menu::show_menu()
{
    window.draw(menu_background);

    for(auto &el:options)
    {
        window.draw(el);
    }
    window.draw(start);
    window.draw(title);
    window.draw(score);
    window.draw(quit);
    window.draw(hard);
    window.draw(easy);
    window.draw(set_name);
    window.draw(name);
    window.draw(info);
}

bool Menu::choose_game()
{
    if (event.type == sf::Event::MouseButtonPressed) {
        if(event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
            float x=mouse_pos.x;
            float y=mouse_pos.y;
            if(x >=options[0].getGlobalBounds().left && x<= options[0].getGlobalBounds().left+options[0].getGlobalBounds().width &&
                                y>=options[0].getGlobalBounds().top && y<=options[0].getGlobalBounds().top+options[0].getGlobalBounds().height){
                        return true;
                }
        }
      }
    return false;
}

bool Menu::close_menu()
{
    if (event.type == sf::Event::MouseButtonPressed) {
        if(event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
            float x=mouse_pos.x;
            float y=mouse_pos.y;
            if(x >=options[2].getGlobalBounds().left && x<= options[2].getGlobalBounds().left+options[2].getGlobalBounds().width &&
                                y>=options[2].getGlobalBounds().top && y<=options[2].getGlobalBounds().top+options[2].getGlobalBounds().height){
                    return true;
                    }
        }
      }
    return false;
}
bool Menu::choose_score()
{
    if (event.type == sf::Event::MouseButtonPressed) {
        if(event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
            float x=mouse_pos.x;
            float y=mouse_pos.y;
            if(x >=options[1].getGlobalBounds().left && x<= options[1].getGlobalBounds().left+options[1].getGlobalBounds().width &&
                                y>=options[1].getGlobalBounds().top && y<=options[1].getGlobalBounds().top+options[1].getGlobalBounds().height){
                    return true;
                    }
        }
      }
    return false;
}

bool Menu::is_easy_clicked()
{
    if (event.type == sf::Event::MouseButtonPressed) {
        if(event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
            float x=mouse_pos.x;
            float y=mouse_pos.y;
            if(x >=easy.getGlobalBounds().left && x<= easy.getGlobalBounds().left+easy.getGlobalBounds().width &&
                                y>=easy.getGlobalBounds().top && y<=easy.getGlobalBounds().top+easy.getGlobalBounds().height){

                        is_easy=true;
                        is_hard=false;
                        easy.setFillColor(sf::Color::Blue);
                        hard.setFillColor(sf::Color::Black);
                        return true;
                    }
        }
      }
    return false;
}

bool Menu::is_hard_clicked()
{
    if (event.type == sf::Event::MouseButtonPressed) {
        if(event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
            float x=mouse_pos.x;
            float y=mouse_pos.y;
            if(x >=hard.getGlobalBounds().left && x<= hard.getGlobalBounds().left+hard.getGlobalBounds().width &&
                                y>=hard.getGlobalBounds().top && y<=hard.getGlobalBounds().top+hard.getGlobalBounds().height){

                        is_easy=false;
                        is_hard=true;
                        hard.setFillColor(sf::Color::Blue);
                        easy.setFillColor(sf::Color::Black);
                        return true;
                    }
        }
      }
    return false;
}

bool Menu::choose_info()
{
    if (event.type == sf::Event::MouseButtonPressed) {
        if(event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
            float x=mouse_pos.x;
            float y=mouse_pos.y;
            if(x >=info.getGlobalBounds().left && x<= info.getGlobalBounds().left+info.getGlobalBounds().width &&
                                y>=info.getGlobalBounds().top && y<=info.getGlobalBounds().top+info.getGlobalBounds().height){
                        return true;
                    }
        }
      }
    return false;
}

void Menu::play()
{
    std::string str;
    music.play();
    while(window.isOpen())
    {
     while (window.pollEvent(event))
     {
         if (event.type == sf::Event::TextEntered)
         {
             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace) && str.size()>0)
             {
                 str.erase(str.size()-1);
                 name.setString(str);
             }
             if (event.text.unicode < 128 && !sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace))
             {
                 str += static_cast<char>(event.text.unicode);
                 name.setString(str);
             }
         }
         if(event.type==sf::Event::Closed || close_menu()==true)
           window.close();
     }



     window.clear(sf::Color::Blue);

     if(is_easy_clicked())
     {
         game_parametrs={150,30.0,5,250.0};
     }


     if(is_hard_clicked())
     {
         game_parametrs={100,15.0,6,300.0};
     }

     if(choose_game()==true)
     {
         window.clear(sf::Color::Blue);
         Game_screen game(game_parametrs[0],str,game_parametrs[1],game_parametrs[2],game_parametrs[3]);
         game.play_game();
         str.erase(0);
         name.setString(str);
     }
     if(choose_score()==true)
     {
         Score score;
         score.show_scores();
     }

     if(choose_info()==true)
     {
         Information information;
         information.show_info();
     }

     show_menu();

     window.display();
    }
}
