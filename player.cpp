#include "player.h"
#include <cmath>

Player::Player() {
    speed = 300.f;
    shootCooldown = 0.5; // [s]
    lifes = 3;

    if (!texture.loadFromFile("player.png")) {
        // TODO
    }
    sprite.setTexture(texture);

    // temp
    sprite.setScale(0.6, 0.6);
    sprite.rotate(180);

    sprite.setPosition(300.0, 700.0);
}

void Player::handleInput(float deltaTime) {
    sf::Vector2f movement(0.0, 0.0);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        movement.x -= speed * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        movement.x += speed * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        movement.y -= speed * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        movement.y += speed * deltaTime;
    }

    // normalizowie wektora zeby ukosny ruch byl odpowiedniej predkosci
    float length = std::sqrt(movement.x * movement.x + movement.y * movement.y);
    if (length != 0.f) {
        movement /= length;
    }

    sprite.move(movement * speed * deltaTime);
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

bool Player::canShoot() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        if (shootTimer.getElapsedTime().asSeconds() >= shootCooldown) {
            shootTimer.restart();
            return true;
        }
    }
    return false;
}

void Player::destroy() {
    if (!isInvincible) {
        lifes -= 1;
        if (lifes <= 0) {
            destroyed = true;
        }
        isInvincible = true;
        damageTimer.restart();
    }
}

bool Player::isDestroyed() const {
    return destroyed;
}

sf::Vector2f Player::getPosition() const {
    sf::FloatRect bounds = sprite.getGlobalBounds();

    // zwracanie srodka gracza pod Bullet
    float centerX = bounds.left + (bounds.width / 2.f);
    float centerY = bounds.top + (bounds.height / 2.f);

    return sf::Vector2f(centerX, centerY);
}


sf::FloatRect Player::getBounds() const {
    return sprite.getGlobalBounds();
}

void Player::updateInvincibility() {
    if (isInvincible) {
        if (damageTimer.getElapsedTime().asSeconds() >= invincibilityDuration) {
            isInvincible = false;
        }
    }
}