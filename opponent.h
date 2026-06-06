#ifndef OPPONENT_H
#define OPPONENT_H
#include <SFML/Graphics.hpp>

class Opponent {
protected:
    sf::Sprite sprite;
    float speed;
    int lifes;
    bool destroyed = false;

public:
    Opponent(const sf::Texture& texture);

    virtual ~Opponent() = default;

    virtual void movement(float deltaTime) = 0;
    void draw(sf::RenderWindow& window) const;

    sf::FloatRect getBounds() const;
    void destroy();
    bool isDestroyed() const;
};

#endif // OPPONENT_H