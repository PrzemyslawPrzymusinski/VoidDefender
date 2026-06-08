#include "bullet.h"

Bullet::Bullet(const sf::Texture& texture, sf::Vector2f pos) {
    speed = 200.0; // zrobic zeby  bylo zmienne

    sf::FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(bounds.width / 2.0, bounds.height / 2.0);

    sprite.setTexture(texture);
    sprite.setScale(1, 1);
    sprite.setPosition(pos.x, pos.y -20.0f);
}

void Bullet::movement(float deltaTime) {
    sprite.move(0.f, -speed * deltaTime);
}

bool Bullet::isOffScreen() {
    if (sprite.getPosition().y < -50.f) {
        return true;
    }
    return false;
}

void Bullet::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}

sf::FloatRect Bullet::getBounds() const {
    return sprite.getGlobalBounds();
}

void Bullet::destroy() {
    destroyed = true;
}

bool Bullet::isDestroyed() const {
    return destroyed;
}

