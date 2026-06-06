#include "basicopp.h"

BasicOpp::BasicOpp(const sf::Texture& texture) : Opponent(texture) {
    speed = rand() % 200;
    lifes = 2;
}

void BasicOpp::movement(float deltaTime) {
    sprite.move(0.f, speed * deltaTime);
}