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

void Opponent:: setAnimation(){
    add_animation_frame(sf::IntRect(0,0,330, 414), rectangles);
    add_animation_frame(sf::IntRect(408,0,330,414), rectangles);
}

std::vector<sf::IntRect>& Opponent:: getRecte(){
    return rectangles;
}
