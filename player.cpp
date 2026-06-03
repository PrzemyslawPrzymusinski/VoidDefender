#include "player.h"
#include <cmath>

Player::Player() {
    speed = 300.f; // zrobic zeby  bylo zmienne

    if (!texture.loadFromFile("player.png")) {
        //
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
