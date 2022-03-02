#include "information.h"

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

