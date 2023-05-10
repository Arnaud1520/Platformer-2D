#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/main.hpp"
#include "../include/map.hpp"
#include "../include/collision.hpp"

void perso()
{
    shape.setFillColor(sf::Color(100, 250, 50));
    if (map == 1)
        {
            shape.setPosition(sf::Vector2f(80.f, 560.f));
        }
        else if (map == 2)
        {
            shape.setPosition(sf::Vector2f(80.f, 80.f));
        }
        else if (map == 3)
        {
            shape.setPosition(sf::Vector2f(80.f, 560.f));
        }
}

void colision()
{
    if (shape.getPosition().x >= 0 || shape.getPosition().x+shape.getSize().x <= 1280 || shape.getPosition().y >= 0 || shape.getPosition().y+shape.getSize().y <= 720)
    {
        collision = false;
    }

    if (shape.getPosition().x < 0 || shape.getPosition().x+shape.getSize().x > 1280 || shape.getPosition().y < 0 || shape.getPosition().y+shape.getSize().y > 720)
    {
        collision = true;
    }
}

void colisionMap1()
{
    if (shape.getPosition().y+shape.getSize().y > 640)//sol
    {
        collisionMap1 = true;
    }
    else
    {
        if (shape.getPosition().x+shape.getSize().x > 240 && shape.getPosition().x < 320 && shape.getPosition().y+shape.getSize().y > 560)//petit cube
        {
            collisionMap1 = true;
        }
        else
        {
            if (shape.getPosition().x+shape.getSize().x > 400 && shape.getPosition().x < 480 && shape.getPosition().y+shape.getSize().y > 480)//double cube
            {
                collisionMap1 = true;
            }
            else
            {
                if (shape.getPosition().x+shape.getSize().x > 560 && shape.getPosition().x < 960 && shape.getPosition().y+shape.getSize().y > 400 && shape.getPosition().y < 480)//grande plateforme
                {
                    collisionMap1 = true;
                }
                else
                {
                    if (shape.getPosition().x+shape.getSize().x > 960 && shape.getPosition().x < 1040 && shape.getPosition().y+shape.getSize().y > 480)//deuxième marche
                    {
                        collisionMap1 =true;
                    }
                    else
                    {
                        if (shape.getPosition().x+shape.getSize().x > 1040 && shape.getPosition().x < 1120 && shape.getPosition().y+shape.getSize().y > 560)//première marche
                        {
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

    if (shape.getPosition().x+shape.getSize().x > 1200 && shape.getPosition().y+shape.getSize().y > 560)
    {
        cle = true;
    }
    
    if (shape.getPosition().x+shape.getSize().x > 800 && shape.getPosition().x < 960 && shape.getPosition().y+shape.getSize().y > 480 && shape.getPosition().y < 640)
    {
        cle = false;
        map = 2;
    }
}

void colisionMap2()
{
    if (shape.getPosition().y+shape.getSize().y > 640 && shape.getPosition().x < 320)//en bas à gauche
    {
        collisionMap2 = true;
    }
    else
    {
        if (shape.getPosition().x+shape.getSize().x > 400 && shape.getPosition().y+shape.getSize().y >640 && shape.getPosition().x < 800)//au milieu à gauche
        {
            collisionMap2 = true;
        }
        else
        {
            if (shape.getPosition().x+shape.getSize().x > 880 && shape.getPosition().y+shape.getSize().y > 640)//en bas à droite
            {
                collisionMap2 = true;
            }
            else
            {
                if (shape.getPosition().x < 800 && shape.getPosition().y+shape.getSize().y >400 && shape.getPosition().y < 460)//branche basse
                {
                    collisionMap2 = true;
                }
                else
                {
                    if (shape.getPosition().x+shape.getSize().x > 800 && shape.getPosition().y+shape.getSize().y > 240 && shape.getPosition().y < 300)//branche à droite
                    {
                        collisionMap2 =true;
                    }
                    else
                    {
                        if (shape.getPosition().x < 320 && shape.getPosition().y+shape.getSize().y > 160 && shape.getPosition().y < 220)//branche haute
                        {
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

    if (shape.getPosition().x+shape.getSize().x > 1200 && shape.getPosition().y+shape.getPosition().y > 160 && shape.getPosition().y < 240)
    {
        cle = true;
    }
    
    if (shape.getPosition().x+shape.getSize().x > 0 && shape.getPosition().x < 160 && shape.getPosition().y+shape.getSize().y > 480 && shape.getPosition().y < 640)
    {
        cle = false;
        map = 3;
    }
}

void colisionMap3()
{
    if (shape.getPosition().y+shape.getSize().y > 640 && shape.getPosition().x < 320)//en bas à gauche
    {
        collisionMap3 = true;
    }
    else
    {
        if (shape.getPosition().x+shape.getSize().x > 480 && shape.getPosition().y+shape.getSize().y > 640)//en bas à droite
        {
            collisionMap3 = true;
        }
        else
        {
            if (shape.getPosition().x < 80)//tout le mur à gauche
            {
                collisionMap3 = true;
            }
            else
            {
                if (shape.getPosition().y < 80)//tout le toit de la grotte
                {
                    collisionMap3 = true;
                }
                else
                {
                    if (shape.getPosition().y < 480 && shape.getPosition().x+shape.getSize().x > 1200)//mur à droite
                    {
                        collisionMap3 =true;
                    }
                    else
                    {
                        if (shape.getPosition().x < 160 && shape.getPosition().y < 240)//bloc seul à gauche
                        {
                            collisionMap3 = true;
                        }
                        else
                        {
                            if (shape.getPosition().x < 560 && shape.getPosition().y < 160)//à gauche de la chute de stalagtite
                            {
                                collisionMap3 = true;
                            }
                            else
                            {
                                if (shape.getPosition().x+shape.getSize().x > 1060 && shape.getPosition().x < 1120 && shape.getPosition().y+shape.getSize().y > 240)
                                {
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

    if (shape.getPosition().x+shape.getSize().x > 80 && shape.getPosition().x < 160 && shape.getPosition().y+shape.getPosition().y > 480 && shape.getPosition().y < 560)
    {
        cle = true;
    }
    
    if (shape.getPosition().x+shape.getSize().x > 1200 && shape.getPosition().x < 1280 && shape.getPosition().y+shape.getSize().y > 480 && shape.getPosition().y < 640)
    {
        cle = false;
        //map = 4;
    }
}

void move()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        colision();
        if (map == 1)
            colisionMap1();
        else if (map == 2)
            colisionMap2();
        else if (map == 3)
            colisionMap3();
        if (collision == false || collisionMap1 == false || collisionMap2 == false || collisionMap3 == false)
        {
            shape.move(20.f, 0.f);
            colision();
            if (map == 1)
                colisionMap1();
            else if (map == 2)
                colisionMap2();
            else if (map == 3)
                colisionMap3();
        }

        if (collision == true || collisionMap1 == true || collisionMap2 == true || collisionMap3 == true)
        {
            shape.setPosition(shape.getPosition().x-20, shape.getPosition().y);//on rajoute -(la vitesse)
            colision();
            if (map == 1)
                colisionMap1();
            else if (map == 2)
                colisionMap2();
            else if (map == 3)
                colisionMap3();
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        colision();
        if (map == 1)
            colisionMap1();
        else if (map == 2)
            colisionMap2();
        else if (map == 3)
            colisionMap3();
        if (collision == false || collisionMap1 == false || collisionMap2 == false || collisionMap3 == false)
        {
            shape.move(-20.f, 0.f);
            colision();
            if (map == 1)
                colisionMap1();
            else if (map == 2)
                colisionMap2();
            else if (map == 3)
                colisionMap3();
        }

        if (collision == true || collisionMap1 == true || collisionMap2 == true || collisionMap3 == true)
        {
            shape.setPosition(shape.getPosition().x+20, shape.getPosition().y);//on rajoute -(la vitesse)
            colision();
            if (map == 1)
                colisionMap1();
            else if (map == 2)
                colisionMap2();
            else if (map == 3)
                colisionMap3();
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        colision();
        if (map == 1)
            colisionMap1();
        else if (map == 2)
            colisionMap2();
        else if (map == 3)
            colisionMap3();
        if (collision == false || collisionMap1 == false || collisionMap2 == false || collisionMap3 == false)
        {
            shape.move(0.f, 20.f);
            colision();
            if (map == 1)
                colisionMap1();
            else if (map == 2)
                colisionMap2();
            else if (map == 3)
                colisionMap3();
        }

        if (collision == true || collisionMap1 == true || collisionMap2 == true || collisionMap3 == true)
        {
            shape.setPosition(shape.getPosition().x, shape.getPosition().y-20);//on rajoute -(la vitesse)
            colision();
            if (map == 1)
                colisionMap1();
            else if (map == 2)
                colisionMap2();
            else if (map == 3)
                colisionMap3();
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        colision();
        if (map == 1)
            colisionMap1();
        else if (map == 2)
            colisionMap2();
        else if (map == 3)
            colisionMap3();
        if (collision == false || collisionMap1 == false || collisionMap2 == false || collisionMap3 == false)
        {
            shape.move(0.f, -20.f);
            colision();
            if (map == 1)
                colisionMap1();
            else if (map == 2)
                colisionMap2();
            else if (map == 3)
                colisionMap3();
        }

        if (collision == true || collisionMap1 == true || collisionMap2 == true || collisionMap3 == true)
        {
            shape.setPosition(shape.getPosition().x, shape.getPosition().y+20);//on rajoute -(la vitesse)
            colision();
            if (map == 1)
                colisionMap1();
            else if (map == 2)
                colisionMap2();
            else if (map == 3)
                colisionMap3();
        }
        
    }
}