#include "bullet.h"

Bullet::Bullet(const sf::Texture texture, sf::Vector2f pos) {
    speed = 200.0; // zrobic zeby  bylo zmienne

    sf::FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(bounds.width / 2.0, bounds.height / 2.0);

    sprite.setTexture(texture);
    sprite.setScale(0.2, 0.2);
    sprite.setPosition(pos.x - 20.0, pos.y);
}

void Bullet::movement(float deltaTime) {
    sprite.move(0.f, -speed * deltaTime);
}

void Bullet::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}
