#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class Menu
  {
  public:

    //constructeur
    Menu();
    
    //Fonction
void drawMenu(sf::RenderWindow &window);
    int choix = 1;
            
  private:
    sf::Texture jouer;
    sf::Sprite recupjouer;
    sf::Texture option;
    sf::Sprite recupoption;
    sf::Texture quitter;
    sf::Sprite recupquitter;
    sf::SoundBuffer bruitage;
    sf::Sound mu;
    int music;
    bool menu1 = true;

    sf::Texture openoption;
    sf::Sprite bakayoko;
    bool entree = true;
};  
    
  
  

	  	
