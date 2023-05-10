#include <SFML/Graphics.hpp>
#include<iostream>
#include "../include/Player.hpp"

void Player::initVariables()
{
  animState = PLAYER_ANIMATION_STATES::IDLE;
}

void Player::initTexture()
{
  if (!textureSheet.loadFromFile("../pictures/cc.png"))
    {
      std::cout << "ERROR::PLAYER::ne peut être charger-_-" << "\n";
    }
}

void Player::initSprite()
{
  currentFrame = sf::IntRect(0, 0, 32, 32);

  sprite.setTextureRect(currentFrame);
	
  sprite.setTexture(textureSheet);
  sprite.setScale(3.f, 3.f);
}

void Player::initAnimations()
{
  animationTimer.restart();
  animationSwitch = true;
}

void Player::initPhysics()
{
  velocityMax = 7.f;
  velocityMin = 1.f;
  acceleration = 2.0f;
  drag = 0.85f;
  gravity = 3.f;
  velocityMaxY = 15.f;
}

Player::Player()
{
  
  initVariables();
  initTexture();
  initSprite();
  initAnimations();
  initPhysics();
}

Player::~Player()
{
  
}

const bool& Player::getAnimSwitch()
{
  bool anim_switch = animationSwitch;

  if (animationSwitch)
    animationSwitch = false;
  
  return animationSwitch;       
}

const sf::Vector2f Player::getPosition()  
{
  return sprite.getPosition();
}

const sf::FloatRect Player::getGlobalBounds() const
{
  return sprite.getGlobalBounds();
}

void Player::setPosition(const float x, const float y)
{
  sprite.setPosition(x, y);
}

void Player::resetVelocityY()
{
  velocity.y = 0.f;
}

void Player::resetAnimationTimer()
{
  animationTimer.restart();
  animationSwitch = true;
}

void Player::move(const float dir_x, const float dir_y)
{
  //Acceleration
  velocity.x += dir_x * acceleration;
  
  //Limit velocity
  if (std::abs(velocity.x) > velocityMax)
    {
      velocity.x = velocityMax * ((velocity.x < 0.f) ? -1.f : 1.f);
    }
}

void Player::updatePhysics()
{
  //Gravité
  velocity.y += 1.0 * gravity;
  if (std::abs(velocity.x) > velocityMaxY)
    {
      velocity.y = velocityMaxY * ((velocity.y < 0.f) ? -1.f : 1.f);
    }
  
  //Deceleration
  velocity *= drag;
  
  //Limit deceleration
  if (std::abs(velocity.x) < velocityMin)
    velocity.x = 0.f;
  if (std::abs(velocity.y) < velocityMin)
    velocity.y = 0.f;
  
  sprite.move(velocity);
}

void Player::startjump()
{
  jumpingspeed = 35.f;
  move(0, velocity.y = -jumpingspeed);
  
}

void Player::updateMovement()
{
  animState = PLAYER_ANIMATION_STATES::IDLE;
  
  if (resetAnimation == true && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) //gauche
    {
      move(-1.f, 0.f);
      animState = PLAYER_ANIMATION_STATES::MOVING_LEFT;
      resetAnimation = false;
    }
  
  if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
    resetAnimation = true;
  
  if (resetAnimation == true && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) //droite
    {
      move(1.f, 0.f);
      animState = PLAYER_ANIMATION_STATES::MOVING_RIGHT;
      resetAnimation = false;      
    }
  
  if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    resetAnimation = true;
  
  if (canjump == true && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && sprite.getPosition().y > 210) //sauter
    {
      startjump();
      canjump = false;      
      animState = PLAYER_ANIMATION_STATES::JUMPING;
    }
  
  if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
    {   
      canjump = true;          
    }
}

void Player::updateAnimations()
{
  if (animState == PLAYER_ANIMATION_STATES::IDLE)
      {
      if (animationTimer.getElapsedTime().asSeconds() >= 0.2f || getAnimSwitch())
	  {
	  currentFrame.top = 0.f;
            currentFrame.left += 32.f;
            if (currentFrame.left > 96.f)
	      currentFrame.left = 0;
	    
            animationTimer.restart();
            sprite.setTextureRect(currentFrame);
        }
    }
    else  if (animState == PLAYER_ANIMATION_STATES::MOVING_RIGHT)
    {
      if (animationTimer.getElapsedTime().asSeconds() >= 0.1f || getAnimSwitch())
	  {
	  currentFrame.top = 32.f;
            currentFrame.left += 32.f;
            if (currentFrame.left > 160.f)
	      currentFrame.left = 0;
	    
            animationTimer.restart();
            sprite.setTextureRect(currentFrame);
        }
	
        sprite.setScale(3.f, 3.f);
        sprite.setOrigin(0.f, 0.f);
    }
  else if (animState == PLAYER_ANIMATION_STATES::MOVING_LEFT)
  {
      if (animationTimer.getElapsedTime().asSeconds() >= 0.1f || getAnimSwitch())
	  {
	  currentFrame.top = 32.f;
            currentFrame.left += 32.f;
            if (currentFrame.left > 160.f)
	      currentFrame.left = 0;
	    
            animationTimer.restart();
            sprite.setTextureRect(currentFrame);
        }
	
        sprite.setScale(-3.f, 3.f);
        sprite.setOrigin(sprite.getGlobalBounds().width / 2.f, 0.f);
	
    }
    
 else
      animationTimer.restart();
}


void Player::update()
{
    updateMovement();
    updateAnimations();
    updatePhysics();
}
void Player::render(sf::RenderTarget & target)
{
    target.draw(sprite);
}


