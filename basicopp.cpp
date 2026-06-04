#include "basicopp.h"

BasicOpp::BasicOpp(const sf::Texture& texture) : Opponent(texture) {
    // kosntruktor...
}


void BasicOpp::movement(float deltaTime) {
    sprite.move(0.f, speed * deltaTime);
}