#include "basicopp.h"

BasicOpp::BasicOpp(const sf::Texture& texture) : Opponent(texture, 1) {
    speed = rand() % 200;

    sprite.setScale(0.075f, 0.075f);
}

BasicOpp::BasicOpp(const sf::Texture& texture, float _x) : Opponent(texture, _x, 1) {
    speed = rand() % 200;

    sprite.setScale(0.075f, 0.075f);
}

void BasicOpp::movement(float deltaTime) {
    sprite.move(0.f, speed * deltaTime);
}
