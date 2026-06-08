#include "opponent.h"
#include <cmath>
#include <cstdlib>

Opponent::Opponent(const sf::Texture& texture) {
    sprite.setTexture(texture);

    sprite.setScale(0.5, 0.5);

    sprite.setPosition(300.0, -50.f);
}

Opponent::Opponent(const sf::Texture& texture, float _x) {
    sprite.setTexture(texture);

    sprite.setScale(0.5, 0.5);

    sprite.setPosition(_x, -50.0);
}

void Opponent::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}

sf::FloatRect Opponent::getBounds() const {
    return sprite.getGlobalBounds();
}

int Opponent::getPoints() const {
    return points;
}

void Opponent::destroy() {
    lifes -=1;
    if (lifes <= 0) {
        destroyed = true;
    }
}

bool Opponent::isDestroyed() const {
    return destroyed;
}
