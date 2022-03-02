#include <naglowki.h>

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

    floor.setTexture(texture_grass);
    floor.setPosition(0.0,window.getSize().y*0.8333);
    floor.setTextureRect(sf::IntRect(0.0,0.0,window.getSize().x,window.getSize().y*0.1667));

    if (!texture_met_1.loadFromFile("meteoryt1.png")) {
        std::cerr << "Could not load texture" << std::endl;
    }

    for(int i=0;i<l_m;i++)
    {
    meteorites.emplace_back(add_meteorite());
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

    if (!texture_hero.loadFromFile("hero_stoi.png")) {
        std::cerr << "Could not load texture" << std::endl;
    }
    if (!run1.loadFromFile("bieganie1.png")) {
        std::cerr << "Could not load texture" << std::endl;
    }
    run1.setRepeated(true);
    if (!run2.loadFromFile("bieganie2.png")) {
        std::cerr << "Could not load texture" << std::endl;
    }
    run2.setRepeated(true);
    if (!run3.loadFromFile("bieganie3.png")) {
        std::cerr << "Could not load texture" << std::endl;
    }
    run3.setRepeated(true);
    if (!texture_jump.loadFromFile("skok.png")) {
        std::cerr << "Could not load texture" << std::endl;
    }
    texture_jump.setRepeated(true);
    if (!texture_jump_2.loadFromFile("jump2.png")) {
        std::cerr << "Could not load texture" << std::endl;
    }
    texture_jump_2.setRepeated(true);
    if (!texture_braking.loadFromFile("hamowanie.png")) {
        std::cerr << "Could not load texture" << std::endl;
    }
    texture_braking.setRepeated(true);
}

Meteorites Game_screen::add_meteorite()
{
    int x=rand()%20;

        if(x<=11)
        {
            Meteorites met(rand()%50-25,(rand()%100)+(velocity-50),0,window.getSize().x,-30,0);
            met.setTexture(texture_met_1);
            met.setColor(sf::Color::Red);
            return met;
        }
        else if(x>11 && x<17)
        {
            Meteorites met(rand()%50-25,(rand()%100)+(velocity-50),0,window.getSize().x,0,-30);
            met.setTexture(texture_met_1);
            met.setColor(sf::Color::Yellow);
            return met;
        }
        else if(x==17)
        {
            Meteorites met(rand()%50-25,(rand()%100)+(velocity-50),0,window.getSize().x,10,0);
            met.setTexture(texture_met_1);
            met.setColor(sf::Color::Blue);
            return met;
        }
        else
        {
            Meteorites met(rand()%50-25,(rand()%100)+(velocity-50),0,window.getSize().x,0,30);
            met.setTexture(texture_met_1);
            met.setColor(sf::Color::Green);
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
    move_ox(elapsed);
    jump(elapsed);

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

void Game_screen::move_ox(const sf::Time &elapsed)
{
    sf::FloatRect bounds=hero.getGlobalBounds();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
         if(bounds.left>hero.x_left_info()){
            is_left=true;
            is_right=false;
            is_move=true;
            v_x=400;
            hero.setTextureRect(sf::IntRect(180,0,-180,250));
         }
        }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            if(bounds.left+bounds.width<hero.x_right_info())
            {
                is_right=true;
                is_left=false;
                is_move=true;
                v_x=400;
                hero.setTextureRect(sf::IntRect(0,0,180,250));
            }
        }
    else
    {
        is_move=false;
    }

    if(is_right==true)
    {
        if(bounds.left+bounds.width<hero.x_right_info())
             {
                hero.move(elapsed.asSeconds()*v_x,0);
              }
    }
    else if(is_left==true)
    {
        if(bounds.left>hero.x_left_info())
             {
               hero.move((-1)*elapsed.asSeconds()*v_x,0);
             }
    }

    if(is_move==true)
    {  
        if(number_f_animation<=32)
        {
        hero.setTexture(run1);

        }
        if(number_f_animation>=33 && number_f_animation<=65)
        {
        hero.setTexture(run2);

        }
        if(number_f_animation>=66)
        {
        hero.setTexture(run3);

        }
        number_f_animation++;
        number_f_animation=number_f_animation%99;
    }
    else if(is_move==false && v_x>0)
    {
        v_x-=3;
        hero.setTexture(texture_braking);
    }

    if(v_y!=0 && v_x<=0)
    {
        hero.setTexture(texture_jump_2);
    }
    else if(v_y!=0 && v_x>0)
    {
        hero.setTexture(texture_jump);
    }
    else if(v_y==0 && v_x<=0)
    {
        hero.setTexture(texture_hero);
    }
}

void Game_screen::jump(const sf::Time &elapsed)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) ) {
            if(jump_is==true)
            {
            v_y=sqrt(2*g*h_max);
            jump_is=false;
            }
        }

    hero.move(0,(-1)*v_y*elapsed.asSeconds());
    v_y-=g*elapsed.asSeconds();

    if(hero.collision_floor(floor))
    {
        jump_is=true;
        v_y=0;
    }
}


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

Score::Score(): window(sf::VideoMode(800,800),"Score")
{
    if (!font.loadFromFile("font.ttf"))
    {
        std::cerr<<"Could not load font"<<std::endl;
    }

    if(!text_menu.loadFromFile("sky.png")){
        std::cerr<<"Could not load texture"<<std::endl;
    }
    menu_background.setTexture(text_menu);
    menu_background.setPosition(0.0,0.0);
    menu_background.setScale(window.getSize().x*0.00066,window.getSize().y*0.00095);

    std::fstream file("Scores.txt");
    if(file.is_open())
    {
        std::string line;
        while (std::getline(file,line)) {
            std::pair<std::string,int> data;
            std::string to_int;
            std::stringstream str(line);
            std::getline(str,data.first,',');
            std::getline(str,to_int,',');
            data.second=std::stoi(to_int.c_str());
            scores.emplace_back(data);
        }
    }
    std::sort(scores.begin(),scores.end(),[](std::pair<std::string,int> &p1,std::pair<std::string,int> &p2){return p1.second>p2.second;});

    sf::Text text;
    std::string str="NAME  SCORE";
    text.setString(str);
    text.setFont(font);
    text.setFillColor(sf::Color::Black);
    text.setPosition(window.getSize().x*0.25,0);
    text.setCharacterSize(window.getSize().x*0.07);
    scores_texts.emplace_back(text);


    if(scores.size()>=10)
    {
    for(size_t i=0;i<10;i++)
    {
        sf::Text text;
        std::string str=std::to_string(i+1)+" "+scores[i].first+"          "+std::to_string(scores[i].second);
        text.setString(str);
        text.setFont(font);
        text.setFillColor(sf::Color::Black);
        text.setPosition(window.getSize().x*0.25,((window.getSize().y*0.08*i)+(window.getSize().y*0.08)));
        text.setCharacterSize(window.getSize().x*0.07);
        scores_texts.emplace_back(text);
    }
    }
    else
    {
        for(size_t i=0;i<scores.size();i++)
        {
            sf::Text text;
            std::string str=std::to_string(i+1)+" "+scores[i].first+"         "+std::to_string(scores[i].second);
            text.setString(str);
            text.setFont(font);
            text.setFillColor(sf::Color::Black);
            text.setPosition(window.getSize().x*0.25,((window.getSize().y*0.08*i)+(window.getSize().y*0.08)));
            text.setCharacterSize(window.getSize().x*0.07);
            scores_texts.emplace_back(text);
        }
    }
}

void Score::show_scores()
{
    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
     {
       if(event.type==sf::Event::Closed)
           window.close();
     }

     window.clear(sf::Color::Blue);

     window.draw(menu_background);

     for(auto &el:scores_texts)
     {
         window.draw(el);
     }
     window.display();
    }
}

Information::Information(): window(sf::VideoMode(800,800),"Score")
{
    if(!text_background.loadFromFile("sky.png")){
        std::cerr<<"Could not load texture"<<std::endl;
    }
    if (!font.loadFromFile("font.ttf"))
    {
        std::cerr<<"Could not load font"<<std::endl;
    }

    background.setTexture(text_background);
    background.setPosition(0.0,0.0);
    background.setScale(window.getSize().x*0.00066,window.getSize().y*0.00095);

    info.setFont(font);
    info.setCharacterSize(window.getSize().x*0.07);
    info.setFillColor(sf::Color::Black);
    info.setPosition(window.getSize().x*0.1,window.getSize().y*0.01);
    info.setString("CONTROL \n\n"
                   "W     JUMP \n"
                   "A     LEFT \n"
                   "D     RIGHT \n\n"
                   "TYPES OF METEORITES \n\n"
                   "RED       MINUS 30 HEALTH \n"
                   "YELLOW       MINUS 30 SCORE \n"
                   "BLUE       PLUS 10 HEALTH \n"
                   "GREEN       PLUS 30 SCORE \n");

}

void Information::show_info()
{
    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
     {

         if(event.type==sf::Event::Closed)
           window.close();
     }

     window.clear(sf::Color::Blue);

     window.draw(background);

     window.draw(info);

     window.display();
    }
}
