//#include "menu.hpp"
#include "../include/jeu.hpp"

Game toto;
Menu::Menu()
{

  //Textures
  if (!jouer.loadFromFile("../pictures/play.png"))
    {
      std::cout << "Erreur durant le chargement de l'image de Play." <<std::endl;
    }

  if (!option.loadFromFile("../pictures/option.png"))
    {
      std::cout << "Erreur durant le chargement de l'image de option." <<std::endl;
    }

  if (!quitter.loadFromFile("../pictures/exit.png"))
    {
      std::cout << "Erreur durant le chargement de l'image de quitter." <<std::endl;
    }

   if (!openoption.loadFromFile("../pictures/set-effect-off.png"))
    {
      std::cout << "Erreur durant le chargement de l'image de quitter." <<std::endl;
    }

          
    if(!bruitage.loadFromFile("../pictures/bruitage.wav"))
      {
	//erreur
      }
   
    
    //charger les textures
    recupjouer.setTexture(jouer);
    recupoption.setTexture(option);
    recupquitter.setTexture(quitter);
    bakayoko.setTexture(openoption);
  
    mu.setBuffer(bruitage);
    
    toto.playmusic();
   
}

void Menu::drawMenu(sf::RenderWindow &window)
{
  
  window.clear();
  if (entree == true)
    {
      
      if (choix == 1)
	window.draw(recupjouer);
      
      if (choix == 2)
	window.draw(recupoption);
      
      if (choix == 3)
	window.draw(recupquitter);
      
      if (choix == 4)
	window.draw(bakayoko);
      
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
	  choix=1;
	  mu.play();
	  
	}
      
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
	  choix=2;
	  mu.play();
	  
	}
 
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
	  choix =3;
	  mu.play();
	  
	} 
      
    }
  
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && choix == 1)
   {    
    toto.menu5 = false;
    window.close();
    toto.render();
  }
 
 
 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)&& choix == 2)
   choix = 4;
 
 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace)&& choix == 4)
   choix = 2;
 
 
 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)&& choix == 3)
   window.close();
 
  window.display();
}
