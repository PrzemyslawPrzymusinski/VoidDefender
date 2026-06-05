#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>

class Bullet
{
private:
    sf::Sprite sprite;
    float speed;
public:
    Bullet(const sf::Texture texture, sf::Vector2f pos);

    void movement(float deltaTime);

    void draw(sf::RenderWindow& window) const;
};

#endif // BULLET_H
