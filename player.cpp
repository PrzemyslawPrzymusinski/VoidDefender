#include "player.h"
#include <cmath>
#include <iostream>

Player::Player() {
    speed = 250;
    shootCooldown = 0.6; // [s]
    lifes = 3;

    if (!texture.loadFromFile("textures/statek.png")) {
        std::cout << "Blad ladowania tesktury statku" << std::endl;
    }
    setTexture(texture);

    setAnimation();

    if (!idleFrames.empty()) {
        setTextureRect(idleFrames[0]);
    }

    // ustawianie kotwicy na srodek
    sf::FloatRect bounds = getLocalBounds();
    setOrigin(bounds.width / 2.f, bounds.height / 2.f);

    // temp
    setScale(0.3, 0.3);

    setPosition(300.0, 700.0);
}

void Player::handleInput(float deltaTime, sf::Vector2f windowSize) {
    sf::Vector2f movement(0.0, 0.0);
    PlayerState newState = PlayerState::IDLE;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        movement.x -= speed * deltaTime;
        newState = PlayerState::LEFT;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        movement.x += speed * deltaTime;
        newState = PlayerState::RIGHT;
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

    if (newState != currentState){
        currentState = newState;
    }

    move(movement * speed * deltaTime);

    //blokowanie na krawedziach
    sf::Vector2f position = getPosition();
    sf::FloatRect bounds = getGlobalBounds();
    float y_offset = 110.0; // offset do blokowania przed ramka (110.0 jest +- ok)

    float halfWidth = bounds.width / 2.f;
    float halfHeight = bounds.height / 2.f;
    position.x = std::clamp(position.x, halfWidth, windowSize.x - halfWidth);
    position.y = std::clamp(position.y, halfHeight, windowSize.y - halfHeight - y_offset);

    setPosition(position);
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(*this);

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

void Player::decreaseShootCooldown() {
    if (shootCooldown > 0.25f) {
        shootCooldown -= 0.1f;
    }
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
        //std::cout << "Przyjeto obrazenia" << std::endl;
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
    sf::FloatRect bounds = getGlobalBounds();

    // zwracanie srodka gracza pod Bullet
    float centerX = bounds.left + (bounds.width / 2.f);
    float centerY = bounds.top + (bounds.height / 2.f);

    return sf::Vector2f(centerX, centerY);
}


sf::FloatRect Player::getBounds() const {
    return getGlobalBounds();
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

void Player:: updateAnimation(const sf::Time& elapsed){
    if (currentState == PlayerState::IDLE) {
        animate(elapsed, idleFrames);
    }
    else if (currentState == PlayerState::LEFT) {
        animate(elapsed, leftFrames);
    }
    else if (currentState == PlayerState::RIGHT) {
        animate(elapsed, rightFrames);
    }
}

void Player:: setAnimation(){
    add_animation_frame(sf::IntRect(0,0,315, 406), idleFrames);
    add_animation_frame(sf::IntRect(376,0,315, 406), idleFrames);
    add_animation_frame(sf::IntRect(757,0,315, 406), leftFrames);
    add_animation_frame(sf::IntRect(1136,0,315, 406), leftFrames);
    add_animation_frame(sf::IntRect(0,414,315, 406), rightFrames);
    add_animation_frame(sf::IntRect(376,414,315, 406), rightFrames);
}
