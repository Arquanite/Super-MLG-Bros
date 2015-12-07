#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "MainMenu.h"
using namespace sf;

int main()
{
    //Create, clear, and show window
    RenderWindow *window;
    window = new RenderWindow(VideoMode(800, 600), "Super-MLG-Bros", Style::Titlebar | Style::Close);
    window->clear();
    window->display();
    //window->setFramerateLimit(24); //Filmowe doznania
    View Stachu;
    FloatRect Zbychu(0,0,800,600);
    Stachu.reset(Zbychu);
    //Load and show loading screen
    Texture LoadingTexture;
    LoadingTexture.loadFromFile("res/Loading.png");
    Sprite Loading;
    Loading.setTexture(LoadingTexture);
    int x,y;
    x = window->getSize().x/2-LoadingTexture.getSize().x/2;
    y = window->getSize().y/2-LoadingTexture.getSize().y/2;
    Loading.setPosition(x ,y);
    window->draw(Loading);
    window->display();
    window->setView(Stachu);
    //Show menu screen
    MainMenu Menu(window);
    Menu.Start();

    return 0;
}
