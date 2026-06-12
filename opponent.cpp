#include "opponent.h"
#include <cmath>
#include <cstdlib>

Opponent::Opponent(const sf::Texture& texture) {
    setTexture(texture);

    setScale(0.3, 0.3);

    setPosition(300.0, -50.f);

    setAnimation();
    if (!rectangles.empty()) {
        setTextureRect(rectangles[0]);
    }
}

Opponent::Opponent(const sf::Texture& texture, float _x) {
    setTexture(texture);

    setScale(0.3, 0.3);

    setPosition(_x, -50.0);

    setAnimation();
    if (!rectangles.empty()) {
        setTextureRect(rectangles[0]);
    }
}

sf::FloatRect Opponent::getBounds() const {
    return getGlobalBounds();
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
