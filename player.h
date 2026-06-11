#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "animation.h"

enum class PlayerState {
    IDLE,       // Lot prosto
    LEFT,       // Skręt w lewo
    RIGHT       // Skręt w prawo
};

class Player:public animation{
private:
    sf::Texture texture;
    float speed;
    int lifes;
    bool destroyed = false;

    sf::Clock shootTimer;
    float shootCooldown;

    // zmienne od invincibility frames
    sf::Clock damageTimer;
    float invincibilityDuration = 1.0f;
    bool isInvincible = false;

    PlayerState currentState = PlayerState::IDLE;
    std::vector<sf::IntRect> idleFrames;
    std::vector<sf::IntRect> leftFrames;
    std::vector<sf::IntRect> rightFrames;

    void setAnimation();
public:
    Player();

    void handleInput(float deltaTime, sf::Vector2f windowSize);
    void draw(sf::RenderWindow& window);
    void updateAnimation(const sf::Time& elapsed);

    // upgrade'y
    void increaseSpeed();
    void decreaseShootCooldown();
    void heal();

    bool canShoot();
    void destroy(); // chodzi o damage nie tylko zniszczenie
    bool isDestroyed() const;
    sf::Vector2f getPosition() const;
    sf::FloatRect getBounds() const;
    int getLifes() const;
    void updateInvincibility();
};

#endif // PLAYER_H
