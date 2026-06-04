#include "opponent.h"
#include <cmath>
#include <cstdlib>

Opponent::Opponent(const sf::Texture& texture) {
    srand(time(0));
    speed = rand() % 200; // zrobic zeby  bylo zmienne

    sprite.setTexture(texture);

    sprite.setScale(0.5, 0.5);

    sprite.setPosition(300.0, 0.0);
}

void Opponent::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}
