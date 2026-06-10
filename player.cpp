#include "player.h"
#include <cmath>
#include <iostream>

Player::Player() {
    speed = 250;
    shootCooldown = 0.5; // [s]
    lifes = 3;

    if (!texture.loadFromFile("textures/statek.png")) {
        std::cout << "Blad ladowania tesktury statku" << std::endl;
    }
    sprite.setTexture(texture);

    // ustawianie kotwicy na srodek
    sf::FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);

    // temp
    sprite.setScale(0.07, 0.07);

    sprite.setPosition(300.0, 700.0);
}

void Player::handleInput(float deltaTime, sf::Vector2f windowSize) {
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

    //blokowanie na krawedziach
    sf::Vector2f position = sprite.getPosition();
    sf::FloatRect bounds = sprite.getGlobalBounds();
    float y_offset = 110.0; // offset do blokowania przed ramka (110.0 jest +- ok)

    float halfWidth = bounds.width / 2.f;
    float halfHeight = bounds.height / 2.f;
    position.x = std::clamp(position.x, halfWidth, windowSize.x - halfWidth);
    position.y = std::clamp(position.y, halfHeight, windowSize.y - halfHeight - y_offset);

    sprite.setPosition(position);
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);

    // ramka do testowania
    /*sf::FloatRect bounds = sprite.getGlobalBounds();
    sf::RectangleShape debugRect(sf::Vector2f(bounds.width, bounds.height));
    debugRect.setPosition(bounds.left, bounds.top);
    debugRect.setFillColor(sf::Color::Transparent);
    debugRect.setOutlineColor(sf::Color::Red);
    debugRect.setOutlineThickness(2.f);
    window.draw(debugRect);*/
}

void Player::increaseSpeed() {
    speed += 50;
}

void Player::heal() {
    lifes +=1;
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
        std::cout << "Przyjeto obrazenia" << std::endl;
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

int Player::getLifes() const {
    return lifes;
}

void Player::updateInvincibility() {
    if (isInvincible) {
        if (damageTimer.getElapsedTime().asSeconds() >= invincibilityDuration) {
            isInvincible = false;
        }
    }
}
