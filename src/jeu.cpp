#include<iostream>
#include "../include/jeu.hpp"


void Game::initWindow()
{
  window.create(sf::VideoMode(1280, 720), "ESCAPE ISLAND", sf::Style::Close | sf::Style::Titlebar);
  window.setFramerateLimit(60);
}

void Game::initPlayer()
{
   player = new Player();
}

void Game::initMap()
{
   map = new Map();
}

void Game::initMenu()
{
   menu = new Menu();
}

Game::Game()
{
  initWindow();
  initPlayer();
  initMenu();
  initMap();
}

Game::~Game()
{
  delete player;
  delete map;
  delete menu;
}

void Game::updatePlayer()
{
  player->update();
}

void Game::updateCollision()
{
  //collion bas
  if (player->getPosition().y + player->getGlobalBounds().height > window.getSize().y)
    {
      player->resetVelocityY();
      player->setPosition (player->getPosition().x, window.getSize().y - player->getGlobalBounds().height);
      Render = false;
      
      while (Render == false)
	{
	  Gameover();
	  window.clear();
	  window.draw(gameover);
	  window.display();
	  
	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X)&& Render == false)
	    {
	      render();
	      Render = true;
	      player->setPosition(80.f, 80.f);
	    }  
	}
    }
  
  //collision droit
  if (player->getPosition().x + player->getGlobalBounds().width > window.getSize().x)
    {
      player->resetVelocityY();
      player->setPosition (window.getSize().x - player->getGlobalBounds().height, player->getPosition().y);
    }

}

void Game::colisionMap1()
{
  if (player->getPosition().y+player->getGlobalBounds().height > 640)//sol
    {
      player->resetVelocityY();
      player->setPosition (player->getPosition().x, 640 - player->getGlobalBounds().height);
      collisionMap1 = true;
    }
  else
    {
      if (player->getPosition().x+player->getGlobalBounds().width > 240 && player->getPosition().x
	  < 300 && player->getPosition().y+player->getGlobalBounds().height > 540)//petit cube
        {
	  player->setPosition (player->getPosition().x, 560 - player->getGlobalBounds().height);
	  collisionMap1 = true;
        }
      else
        {
          if (player->getPosition().x+player->getGlobalBounds().width > 440 && player->getPosition().x
	      < 440 && player->getPosition().y+player->getGlobalBounds().height > 470)//double cube
            {
	      player->setPosition (player->getPosition().x, 480 - player->getGlobalBounds().height);
	      collisionMap1 = true;
            }
	  else
            {
	      if (player->getPosition().x+player->getGlobalBounds().width > 570 && player->getPosition().x
		  < 927 && player->getPosition().y+player->getGlobalBounds().height > 400 &&
		  player->getPosition().y < 480)//grande plateforme
                {
		  player->setPosition (player->getPosition().x, 400 - player->getGlobalBounds().height);
		  collisionMap1 = true;
                }
	      else
                {
		  if (player->getPosition().x+player->getGlobalBounds().width > 960 && player->getPosition().x
		      < 1005 && player->getPosition().y+player->getGlobalBounds().height > 480)//deuxième marche
                    {
		      player->setPosition (player->getPosition().x, 480 - player->getGlobalBounds().height);
		      collisionMap1 =true;
                    }
		  else
		    {
		      if (player->getPosition().x+player->getGlobalBounds().width > 1040 && player->getPosition().x
			  < 1090 && player->getPosition().y+player->getGlobalBounds().height > 560)
			//première marche
			{
			  player->setPosition (player->getPosition().x, 560 - player->getGlobalBounds().height);
			  collisionMap1 = true;
			}
		      else
			{
			  collisionMap1 = false;
			}
		    }
                }
            }
        }
    }
  
  if (player->getPosition().x+player->getGlobalBounds().width > 1200 && player->getPosition().y+player->getGlobalBounds().height > 560)
    {
      soundkey.play();
      map->cle1 = true;
      map->recupKey1();
    }
  
  if (player->getPosition().x+player->getGlobalBounds().width > 800 && player->getPosition().x <
      960 && player->getPosition().y+player->getGlobalBounds().height > 480 && player->getPosition().y < 640
      && map->cle1 == true && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z))
    {
      map1 = 2;
    }
}

void Game::colisionMap2()
{
  if (player->getPosition().y+player->getGlobalBounds().height > 640 && player->getPosition().x < 320)//en bas à gauche
    {
      player->setPosition (player->getPosition().x, 640 - player->getGlobalBounds().height);
      collisionMap2 = true;
    }
  else
    {
      if (player->getPosition().x+player->getGlobalBounds().width
	  > 400 && player->getPosition().y+player->getGlobalBounds().height >640 && player->getPosition().x < 770)//au milieu à gauche
	{
	  player->setPosition (player->getPosition().x, 640 - player->getGlobalBounds().height);
	  collisionMap2 = true;
	}
      else
	{
	  if (player->getPosition().x+player->getGlobalBounds().width > 895 && player->getPosition().y+player->getGlobalBounds().height > 640)//en bas à droite
	    {
	      player->setPosition (player->getPosition().x, 640 - player->getGlobalBounds().height);
	      collisionMap2 = true;
	    }
	  else
	    {
	      if (player->getPosition().x < 800 && player->getPosition().y+player->getGlobalBounds().height >400 && player->getPosition().y < 460)//branche basse
		{
		  player->setPosition (player->getPosition().x, 400 - player->getGlobalBounds().height);
		  collisionMap2 = true;
		}
	      else
		{
		  if (player->getPosition().x+player->getGlobalBounds().width > 800 && player->getPosition().y+player->getGlobalBounds().height
		      > 240 && player->getPosition().y < 300)//branche à droite
                    {
		      player->setPosition (player->getPosition().x, 240 - player->getGlobalBounds().height);
		      collisionMap2 =true;
                    }
		  else
		    {
		      if (player->getPosition().x < 320 && player->getPosition().y+player->getGlobalBounds().height > 160 && player->getPosition().y < 210)//branche haute
			{
			  player->setPosition (player->getPosition().x, 160 - player->getGlobalBounds().height);
			  collisionMap2 = true;
			}
		      else
			{
			  collisionMap2 = false;
			}
		    }
		}
	    }
	}
    }
  
  if (player->getPosition().x+player->getGlobalBounds().width > 1200 && player->getPosition().y+player->getPosition().y > 160 && player->getPosition().y < 240)
    {
      soundkey.play();
       map->cle2 = true;
      map->recupKey2();

    }
  
  if (player->getPosition().x+player->getGlobalBounds().width > 0 && player->getPosition().x
      < 160 && player->getPosition().y+player->getGlobalBounds().height > 480 && player->getPosition().y < 640
      && map->cle2 == true && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z))
    {
      map1 = 3;
    }
}

void Game::colisionMap3()
{
  if (player->getPosition().y+player->getGlobalBounds().height > 640 && player->getPosition().x < 320)//en bas à gauche
    {
      player->setPosition (player->getPosition().x, 640 - player->getGlobalBounds().height);
      collisionMap3 = true;
    }
  else
    {
      if (player->getPosition().x+player->getGlobalBounds().width > 480 && player->getPosition().y+player->getGlobalBounds().height > 640)//en bas à droite
        {
	  player->setPosition (player->getPosition().x, 640 - player->getGlobalBounds().height);
	  collisionMap3 = true;
        }
      else
        {
	  if (player->getPosition().x < 80)//tout le mur à gauche
            {
	      player->setPosition (player->getPosition().x, 80 - player->getGlobalBounds().height);
	      collisionMap3 = true;
            }
	  else
            {
	      if (player->getPosition().y < 80)//tout le toit de la grotte
                {
		  // player->setPosition (player->getPosition().x, 80 - player->getGlobalBounds().height);
		  collisionMap3 = true;
                }
	      else
                {
		  if (player->getPosition().y < 480 && player->getPosition().x+player->getGlobalBounds().width > 1200)//mur à droite
                    {
		      collisionMap3 =true;
                    }
		  else
                    {
		      if (player->getPosition().x < 160 && player->getPosition().y < 240)//bloc seul à gauche
                        {
			  collisionMap3 = true;
                        }
		      else
                        {
			  if (player->getPosition().x < 560 && player->getPosition().y < 160)//à gauche de la chute de stalagtite
                            {
			      collisionMap3 = true;
                            }
			  else
                            {
			      if (player->getPosition().x+player->getGlobalBounds().width
				  > 1060 && player->getPosition().x < 1100 && player->getPosition().y+player->getGlobalBounds().height > 240)
                                {
				  player->setPosition (player->getPosition().x, 240 - player->getGlobalBounds().height);
				  collisionMap3 = true;
                                }
			      else
                                {
				  collisionMap3 = false;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

  if (player->getPosition().x+player->getGlobalBounds().width > 80 && player->getPosition().x
      < 160 && player->getPosition().y+player->getPosition().y > 480 && player->getPosition().y < 560)
    {
      soundkey.play();
      map->cle3 = true;
      map->recupKey3();
    }
  
  if (player->getPosition().x+player->getGlobalBounds().width > 1200 && player->getPosition().x
      < 1280 && player->getPosition().y+player->getGlobalBounds().height > 480 && player->getPosition().y < 640
      && map->cle3 == true && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z))
    {
      Render = false;
      while (Render == false)
	{
      ending();
      window.clear();
      window.draw(theEnd);
      window.display();
	}
    }
}

void Game::playmusic()
{
  //CHARGEMENT MUSIQUE 
  if (!menu1.openFromFile("../pictures/menu.ogg"))
    {
      std::cout<<"menu pas charger"<<std::endl; 
    }   

  if (!jungle.openFromFile("../pictures/theme_jungle.ogg"))
    {
      std::cout<<"jungle pas charger"<<std::endl;
    }

  //saut
  if (!sauter.loadFromFile("../pictures/jump.wav"))
    {
      //erreur
    }
  saut.setBuffer(sauter);

  //son cle
  if (!keysound.loadFromFile("../pictures/key-sound.wav"))
    {
      //erreur
    }
  soundkey.setBuffer(keysound);

  
  //PLAY MUSIQUE//
  if (menu5 == true)
    {
      menu1.play();
      menu1.setLoop(true);
      menu1.setVolume(20);
      
      jungle.play();
      jungle.setLoop(true);
      jungle.setVolume(0);
      
    }
  
}

void Game::update()
{
  while (window.pollEvent(ev))
    {
      if (ev.type == sf::Event::Closed)	  
	window.close();
      
      else if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape)
	{Render = false;
	  window.close();}
      
       if (ev.key.code == sf::Keyboard::Space)
	 {
	   saut.play();
	 }

      if (ev.key.code == sf::Keyboard::Enter)
	{
	  menu1.stop();
	  jungle.setVolume(30);
	}
      
      if (ev.type == sf::Event::KeyReleased && (ev.key.code == sf::Keyboard::Q || ev.key.code == sf::Keyboard::D || ev.key.code == sf::Keyboard::Space))
        {
	  player->resetAnimationTimer();
        }
    }
  
  if (menu5 == true)
    renderMenu();	
  
  updatePlayer();
  
  if (map1 == 1)
    {	 
      // player->setPosition(80.f, 560.f);
      colisionMap1();
    }
  else if (map1 == 2)
    {
      //player->setPosition(80.f, 64.f);
      colisionMap2();
    }
  else if (map1 == 3)
    {
      // player->setPosition(80.f, 544.f);
      colisionMap3();
    }
     
  updateCollision();
}

void Game::Gameover()
{
  if (over.loadFromFile("../pictures/game-over.png"))
    {
      //erreur
    }
  
  gameover.setTexture(over);
  
}

void Game::ending()
{
  if (Ending.loadFromFile("../pictures/ending.png"))
    {
      //erreur
    }

  theEnd.setTexture(Ending);
  
}
void Game::renderPlayer()
{
  player->render(window);
}

void Game::renderMenu()
{
  menu->drawMenu(window);
}

void Game::renderMap()
{
  //map 1
  if (map1 == 1)
    {
      map->setBackgroundMap1(window);
      map->setDoorMap1(window);
      map->setKeyMap1(window);
      map->setBlocMap1(window);
    }
  //map 2
  else if (map1 == 2)
    {
      map->setBackgroundMap2(window);
      map->setDoorMap2(window);
      map->setKeyMap2(window);
      map->setBlocMap2(window);
    }
  //map 3
  else if (map1 == 3)
    {
      map->BackgroundMap3(window);
      map->setDoorMap3(window);
      map->setKeyMap3(window);
      map->setBlocMap3(window);
    }
}
void Game::render()
{
  
  while (Render == true)
    {
      update();
      window.clear();
      renderMap();   
      renderPlayer();
      window.display();
    } 
}

const sf::RenderWindow & Game::getWindow() const
{
  return window;
}
