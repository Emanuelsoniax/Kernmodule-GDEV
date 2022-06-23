#include <SFML/Graphics.hpp>
#include "GameManager.h"

using namespace sf;

int main()
{
    srand(time(0));

    Clock deltaClock;

    GameManager gamemanager;
    gamemanager.Start();

    while (gamemanager.GetWindow().isOpen())
    {
       float dt = deltaClock.restart().asSeconds();
       
       gamemanager.Update(dt);
    }
}