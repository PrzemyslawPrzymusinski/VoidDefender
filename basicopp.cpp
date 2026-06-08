#include "basicopp.h"

BasicOpp::BasicOpp(const sf::Texture& texture) : Opponent(texture) {
    speed = rand() % 200;
    lifes = 1;

    sprite.setScale(0.075f, 0.075f);
}

void BasicOpp::movement(float deltaTime) {
    sprite.move(0.f, speed * deltaTime);
}
