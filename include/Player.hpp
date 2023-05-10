
#include <SFML/Graphics.hpp>
#include <iostream>

enum PLAYER_ANIMATION_STATES {IDLE = 0, MOVING_LEFT, MOVING_RIGHT, JUMPING};

class Player
{
private:
    sf::Sprite sprite;
    sf::Texture textureSheet;
    sf::Clock animationTimer;
  
    short animState;
    sf::IntRect currentFrame;
    bool animationSwitch;
    bool canjump;
    bool resetAnimation = false;
    sf::Vector2f velocity;
    float velocityMax;
    float velocityMin;
    float acceleration;
    float drag;
    float gravity;
    float velocityMaxY;
    float jumpingspeed;
  

  void initVariables();
    void initTexture();
    void initSprite();
    void initAnimations();
    void initPhysics();

public:
    Player();
 virtual  ~Player();

      
    const bool& getAnimSwitch();
    const sf::Vector2f getPosition();
    const sf::FloatRect getGlobalBounds() const;

    void setPosition(const float x, const float y);
    void resetVelocityY();

    void startjump();
    void resetAnimationTimer();
    void move(const float dir_x, const float dir_y);
    void updatePhysics();
    void updateMovement();
    void updateAnimations();
    void update();
    void render(sf::RenderTarget& target);

};
