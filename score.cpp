#include "score.h"

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
