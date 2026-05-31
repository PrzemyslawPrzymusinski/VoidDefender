#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>

class Player
{
private:
    sf::Sprite sprite;
    sf::Texture texture;
    float speed;
public:
    Player();

    void handleInput(float deltaTime);
    void draw(sf::RenderWindow& window);
};

#endif // PLAYER_H
