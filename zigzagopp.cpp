#include "zigzagopp.h"

ZigZagOpp::ZigZagOpp(const sf::Texture& texture, float _x, float _windowWidth) : Opponent(texture, _x)
{
    sprite.setScale(0.075f, 0.075f);

    speed = (rand() % 100) + 50;
    points = 3;
    lifes = 1;
    speedHorizontal = (rand() % 100) + 50;
    windowWidth = _windowWidth;

    // losowy kierunek poczatkowy
    if (rand() % 2 == 0) {
        speedHorizontal = -speedHorizontal;
    }
}

void ZigZagOpp::movement(float deltaTime) {
    sprite.move(speedHorizontal * deltaTime, speed * deltaTime);

    sf::FloatRect bounds = sprite.getGlobalBounds();

    if (bounds.left <= 0.f) {
        sprite.setPosition(0.f, bounds.top);
        speedHorizontal = -speedHorizontal;
    }
    else if (bounds.left + bounds.width >= windowWidth) {
        sprite.setPosition(windowWidth - bounds.width, bounds.top);
        speedHorizontal = -speedHorizontal;
    }
}

