#ifndef OPPONENT_H
#define OPPONENT_H
#include <SFML/Graphics.hpp>
#include "animation.h"

class Opponent {
protected:
    float speed;
    int lifes;
    bool destroyed = false;
    int points;
    std::vector<sf::IntRect> rectangles;

public:
    Opponent(const sf::Texture& texture);
    Opponent(const sf::Texture& texture, float _x);

    virtual ~Opponent() = default;

    virtual void movement(float deltaTime) = 0;
    void setAnimation();
    std::vector<sf::IntRect>& getRecte();

    sf::FloatRect getBounds() const;
    int getPoints() const;
    void destroy();
    bool isDestroyed() const;
};

#endif // OPPONENT_H
