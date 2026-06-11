#include "basicopp.h"

BasicOpp::BasicOpp(const sf::Texture& texture) : Opponent(texture) {
    speed = rand() % 200;
    //lifes = 1;
    points = 1;

    setAnimation();

    setScale(0.3, 0.3);
}

BasicOpp::BasicOpp(const sf::Texture& texture, float _x) : Opponent(texture, _x) {
    speed = rand() % 150 + 100;
    points = 1;

    setScale(0.3, 0.3);
}

void BasicOpp::movement(float deltaTime) {
    move(0.f, speed * deltaTime);
}
