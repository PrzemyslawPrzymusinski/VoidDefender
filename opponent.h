#ifndef OPPONENT_H
#define OPPONENT_H
#include <SFML/Graphics.hpp>

class Opponent
{
private:
    sf::Sprite sprite;
    sf::Texture texture;
    float speed;
public:
    Opponent();

    void movement(float deltaTime);
    void draw(sf::RenderWindow& window);
};

#endif // OPPONENT_H
