#ifndef COLLISION_H_
#define COLLISION_H_

void perso();
void move();
void colision();//fonction colision != variable collision
void colisionMap1();
void colisionMap2();
void colisionMap3();
//void gravity();
//void jumping();
//void jump();

sf::RectangleShape shape(sf::Vector2f(80.f, 80.f));
//sf::Vector2f velocity;
sf::Vector2f position;
bool collision;
bool collisionMap1;
bool collisionMap2;
bool collisionMap3;

#endif