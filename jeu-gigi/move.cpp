#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "move.hpp"


void jump(Sprite)
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) //appuyé une seule fois
    {
      if (Sprite.getPosition().y == Sprite.getPosition().y)
	{
	  return;
	}
      else
	{
	  Sprite.move(0.f, 10.f);
	}

	  while (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) //appuyé en continu
	    {
	      if (Sprite.getPosition().y == Sprite.getPosition().y)
		{
		  return;
		}
	      else
		{
		  Sprite.move(0.f, 5.f);
		}
	    }
	  while (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
		 sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	    {
	      if (Sprite.getPosition().y == Sprite.getPosition().y || Sprite.getposition().x == Sprite.getPosition().x)
		{
		  return;
		}
	      else
		{
		  Sprite.move(3.f, 4.f);
		}
	    }
	  //partie où il retombe ici
    }
}
