#include <SFML/Graphics.hpp>
#include <iostream>
 
class Map
{
public:
 
//Constructeur
Map();
 
//Fonctions
//void drawBackground(sf::RenderWindow &window);
void setBackgroundMap1(sf::RenderWindow &window);
void setDoorMap1(sf::RenderWindow &window);
void setKeyMap1(sf::RenderWindow &window);
void setBlocMap1(sf::RenderWindow &window);
void initMap1();

void setBackgroundMap2(sf::RenderWindow &window);
void setDoorMap2(sf::RenderWindow &window);
void setKeyMap2(sf::RenderWindow &window);
void setBlocMap2(sf::RenderWindow &window);
void initMap2();

void BackgroundMap3(sf::RenderWindow &window);
void setDoorMap3(sf::RenderWindow &window);
void setKeyMap3(sf::RenderWindow &window);
void setBlocMap3(sf::RenderWindow &window);
void initMap3();
void recupKey1();
void recupKey2();
void recupKey3();
bool cle1 = false;
bool cle2 = false;
bool cle3 = false;  
private:
 

int n=0;
sf::Sprite bloc[50];
sf::Sprite key1;
sf::Sprite key2;
sf::Sprite key3;
sf::Sprite water;
sf::Sprite sap[4];
sf::Sprite door;
sf::Sprite echelle[5];
sf::Sprite stalactite[2];

sf::Texture Key1;
sf::Texture Key2;
sf::Texture Key3;
sf::Texture doorT;

sf::Texture grass1;
sf::Texture grass2;
sf::Texture grass3;
sf::Texture grass4;

sf::Texture branch1;
sf::Texture branch2;
sf::Texture branch3;
sf::Texture branch4;
sf::Texture waterT;
sf::Texture sapT;

sf::Texture rock;
sf::Texture echelleT;
sf::Texture stalactiteT; 
};
