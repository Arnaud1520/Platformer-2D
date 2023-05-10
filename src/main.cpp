#include <iostream>
#include "../include/jeu.hpp"


int main()
{
  
    Game game;

    while (game.getWindow().isOpen())
    {
        game.update();
    }

    return 0;
}
