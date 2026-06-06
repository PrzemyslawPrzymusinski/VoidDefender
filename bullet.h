#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>

class Bullet
{
private:
    sf::Sprite sprite;
    float speed;
    bool destroyed = false;

public:
    Bullet(const sf::Texture& texture, sf::Vector2f pos);

    void movement(float deltaTime);
    bool isOffScreen();

    sf::FloatRect getBounds() const;
    void destroy();
    bool isDestroyed() const;

    void draw(sf::RenderWindow& window) const;
};

#endif // BULLET_H
