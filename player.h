#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>

class Player
{
private:
    sf::Sprite sprite;
    sf::Texture texture;
    float speed;

    sf::Clock shootTimer;
    float shootCooldown;
public:
    Player();

    void handleInput(float deltaTime);
    void draw(sf::RenderWindow& window);

    bool canShoot();
    sf::Vector2f getPosition() const;
};

#endif // PLAYER_H
