#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#include"Player.hpp"
#include"map.hpp"
#include "menu.hpp"

class Game
{
private:
    sf::RenderWindow window;
    sf::Event ev;

    Player* player;
    Map* map;
    Menu* menu;
  void initWindow();
  void initMap();
  void initMenu();
  void initPlayer();

  bool collision;
  bool collisionMap1;
  bool collisionMap2;
  bool collisionMap3;

  sf::Sprite gameover;
  sf::Texture over;
  sf::Texture Ending;
  sf::Sprite theEnd;
  
public:
  bool Render = true;
  bool menu5 = true;

  sf::SoundBuffer sauter;
  sf::Sound saut;
  sf::Music menu1;
  sf::Music jungle;
  sf::Sound soundkey;
  sf::SoundBuffer keysound;
  int map1 = 1;
  
  
  Game();
  virtual ~Game();

  //Fonctions
  void ending();
  void Gameover();
  void updatePlayer();
  void updateCollision();
  void update();
  void renderPlayer();
  void renderMenu();
  void renderMap();
  void render();
  void playmusic();

  void colision();//fonction colision != variable collision                                                                                                                        
  void colisionMap1();
  void colisionMap2();
  void colisionMap3();
  void perso();
  
  const sf::RenderWindow& getWindow() const;
  
};
