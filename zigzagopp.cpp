#include "zigzagopp.h"

ZigZagOpp::ZigZagOpp(const sf::Texture& texture, float _x, float _windowWidth) : Opponent(texture, _x)
{
    setScale(0.2f, 0.2f);

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
    move(speedHorizontal * deltaTime, speed * deltaTime);

    sf::FloatRect bounds = getGlobalBounds();

    if (bounds.left <= 0.f) {
        setPosition(0.f, bounds.top);
        speedHorizontal = -speedHorizontal;
    }
    else if (bounds.left + bounds.width >= windowWidth) {
        setPosition(windowWidth - bounds.width, bounds.top);
        speedHorizontal = -speedHorizontal;
    }
}

