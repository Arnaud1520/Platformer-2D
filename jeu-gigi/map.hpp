#ifndef MAP_H_
#define MAP_H_

void setBackgroundMap1();
void setDoorMap1();
void setKeyMap1();
void setBlocMap1();
void initMap1();

void setBackgroundMap2();
void setDoorMap2();
void setKeyMap2();
void setBlocMap2();
void initMap2();

void BackgroundMap3();
void setDoorMap3();
void setKeyMap3();
void setBlocMap3();
void initMap3();

int n=0;
bool cle = false;
sf::Sprite bloc[50];
sf::Sprite key;
sf::Sprite water;
sf::Sprite sap[4];
sf::Sprite door;
sf::Sprite echelle[5];
sf::Sprite stalactite[2]; 

sf::Texture keyT;
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

#endif