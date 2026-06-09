#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>

class Player
{
private:
    sf::Sprite sprite;
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
public:
    Player();

    void handleInput(float deltaTime, sf::Vector2f windowSize);
    void draw(sf::RenderWindow& window);

    // upgrade'y
    void increaseSpeed();
    void heal();

    bool canShoot();
    void destroy(); // chodzi o damage nie tylko zniszczenie
    bool isDestroyed() const;
    sf::Vector2f getPosition() const;
    sf::FloatRect getBounds() const;
    void updateInvincibility();
};

#endif // PLAYER_H
