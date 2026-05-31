#include "player.h"

Player::Player() {
    speed = 300.f;

    if (!texture.loadFromFile("player.png")) {
        //
    }
    sprite.setTexture(texture);

    // temp
    sprite.setScale(0.6f, 0.6f);
    sprite.rotate(180);

    sprite.setPosition(300.f, 700.f);
}

void Player::handleInput(float deltaTime) {
        sf::Vector2f movement(0.f, 0.f);

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
        sprite.move(movement);
    }

void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
